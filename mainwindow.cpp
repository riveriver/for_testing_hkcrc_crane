#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDataStream>
#include <QDateTime>
#include <QThread>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , modbusSocket(nullptr)
{
    setupUI();
    setupModbusClient(ui->ipEdit->text(), static_cast<quint16>(ui->portSpinBox->value()));
}

MainWindow::~MainWindow()
{
    if (modbusSocket)
        modbusSocket->disconnectFromHost();
    delete ui;
}

void MainWindow::setupUI()
{
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::onSendButtonClicked);
    connect(ui->connectButton, &QPushButton::clicked, this, &MainWindow::onConnectButtonClicked);
    connect(ui->registerTypeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onRegisterTypeChanged);
}

void MainWindow::setupModbusClient(const QString &ip, quint16 port)
{
    // 直接在主线程执行，不涉及任何线程切换
    if (modbusSocket) {
        if (modbusSocket->state() == QAbstractSocket::ConnectedState) {
            modbusSocket->disconnectFromHost();
            modbusSocket->waitForDisconnected(1000);
        }
        delete modbusSocket;
    }
    
    modbusSocket = new QTcpSocket(this);
    connect(modbusSocket, &QTcpSocket::connected, this, [this]() {
        logMessage("Connected to Modbus server");
    });
    connect(modbusSocket, &QTcpSocket::disconnected, this, [this]() {
        logMessage("Disconnected from Modbus server");
    });
    connect(modbusSocket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError) {
        logMessage("Connection error: " + modbusSocket->errorString());
    });
    
    logMessage(QString("Connecting to %1:%2...").arg(ip).arg(port));
    modbusSocket->connectToHost(ip, port);
    if (!modbusSocket->waitForConnected(3000)) {
        logMessage("Connection timeout: " + modbusSocket->errorString());
    }
}

quint8 MainWindow::getFunctionCode() const
{
    switch (ui->registerTypeCombo->currentIndex()) {
        case 0: return 0x10; // Write Multiple Holding Registers
        case 1: return 0x06; // Write Single Register (Input Registers are read-only)
        case 2: return 0x05; // Write Single Coil
        case 3: return 0x0F; // Write Multiple Coils
        default: return 0x10;
    }
}

void MainWindow::onConnectButtonClicked()
{
    QString ip = ui->ipEdit->text();
    if (ip.isEmpty()) {
        logMessage("Error: IP address cannot be empty");
        return;
    }
    
    quint16 port = static_cast<quint16>(ui->portSpinBox->value());
    setupModbusClient(ip, port);
}

void MainWindow::onRegisterTypeChanged(int index)
{
    // 根据寄存器类型调整UI
    bool isRegister = (index == 0 || index == 1);
    ui->controlModeSpinBox->setVisible(isRegister);
    ui->slewSpeedSpinBox->setVisible(isRegister);
    ui->luffSpeedSpinBox->setVisible(isRegister);
    ui->hoistSpeedSpinBox->setVisible(isRegister);
}

void MainWindow::onSendButtonClicked()
{
    if (!modbusSocket || modbusSocket->state() != QTcpSocket::ConnectedState) {
        logMessage("Modbus socket not connected");
        return;
    }

    // 读取连接参数
    quint8 slaveAddr = static_cast<quint8>(ui->slaveSpinBox->value());
    quint8 functionCode = getFunctionCode();

    // 读取参数地址和值
    quint16 controlModeAddr = ui->controlModeAddrSpinBox->value();
    quint16 controlModeValue = ui->controlModeSpinBox->value();
    quint16 slewSpeedAddr = ui->slewSpeedSpinBox->value();
    quint16 slewSpeedValue = ui->slewSpeedSpinBox->value();
    quint16 luffSpeedAddr = ui->luffSpeedSpinBox->value();
    quint16 luffSpeedValue = ui->luffSpeedSpinBox->value();
    quint16 hoistSpeedAddr = ui->hoistSpeedSpinBox->value();
    quint16 hoistSpeedValue = ui->hoistSpeedSpinBox->value();

    // 创建Modbus TCP请求帧
    QByteArray request;
    QDataStream stream(&request, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);
    
    // Modbus TCP ADU Header
    stream << quint16(0x0000); // Transaction ID
    stream << quint16(0x0000); // Protocol ID
    stream << quint16(0x0000); // Length (临时值，后面更新)
    
    // Modbus PDU
    stream << slaveAddr;       // Unit ID
    stream << functionCode;    // Function code
    
    // 根据寄存器类型构建请求体
    if (functionCode == 0x10) { // Write Multiple Holding Registers
        stream << controlModeAddr; // Starting address
        stream << quint16(4);      // Quantity of registers
        stream << quint8(8);       // Byte count
        stream << controlModeValue;
        stream << slewSpeedValue;
        stream << luffSpeedValue;
        stream << hoistSpeedValue;
    } else if (functionCode == 0x06) { // Write Single Register
        stream << controlModeAddr;
        stream << controlModeValue;
    }
    
    // 更新长度字段
    request[4] = static_cast<char>((request.size() - 6) >> 8);
    request[5] = static_cast<char>(request.size() - 6);

    if (modbusSocket->write(request) != -1) {
        logMessage(QString("Sent request: slave=%1, function=%2, control_mode=%3:%4, slew_speed=%5:%6, luff_speed=%7:%8, hoist_speed=%9:%10")
                  .arg(slaveAddr).arg(functionCode, 2, 16, QChar('0'))
                  .arg(controlModeAddr).arg(controlModeValue)
                  .arg(slewSpeedAddr).arg(slewSpeedValue)
                  .arg(luffSpeedAddr).arg(luffSpeedValue)
                  .arg(hoistSpeedAddr).arg(hoistSpeedValue));
    } else {
        logMessage("Write request failed: " + modbusSocket->errorString());
    }
}

void MainWindow::logMessage(const QString &msg)
{
    ui->messageTextEdit->appendPlainText(QDateTime::currentDateTime().toString() + ": " + msg);
}