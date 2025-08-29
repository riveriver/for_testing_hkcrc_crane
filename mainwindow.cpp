#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDataStream>
#include <QDateTime>
#include <QThread>
#include <QTimer>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , modbusSocket(nullptr)
{
    setupUI();
    loadParameters();  // 加载保存的参数
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
    
    // 连接消息栏按钮信号
    connect(ui->pauseResumeButton, &QPushButton::clicked, this, &MainWindow::toggleMessageScrolling);
    connect(ui->clearMessagesButton, &QPushButton::clicked, this, &MainWindow::clearMessages);
    
    // 初始化消息滚动状态
    m_messageScrollingEnabled = true;
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

void MainWindow::saveParameters()
{
    QSettings settings("HKCRC", "CraneTesting");
    
    // 保存连接参数
    settings.setValue("ip", ui->ipEdit->text());
    settings.setValue("port", ui->portSpinBox->value());
    settings.setValue("slave", ui->slaveSpinBox->value());
    settings.setValue("registerType", ui->registerTypeCombo->currentIndex());
    
    // 保存Modbus参数
    settings.setValue("controlModeAddr", ui->controlModeAddrSpinBox->value());
    settings.setValue("controlModeValue", ui->controlModeSpinBox->value());
    settings.setValue("slewSpeedAddr", ui->slewSpeedAddrSpinBox->value());
    settings.setValue("slewSpeedValue", ui->slewSpeedSpinBox->value());
    settings.setValue("luffSpeedAddr", ui->luffSpeedAddrSpinBox->value());
    settings.setValue("luffSpeedValue", ui->luffSpeedSpinBox->value());
    settings.setValue("hoistSpeedAddr", ui->hoistSpeedAddrSpinBox->value());
    settings.setValue("hoistSpeedValue", ui->hoistSpeedSpinBox->value());
    settings.setValue("pathLengthAddr", ui->pathLengthAddrSpinBox->value());
    settings.setValue("pathLengthValue", ui->pathLengthSpinBox->value());
    
    // 保存路径参数
    settings.setValue("slewPathAddr", ui->slewPathAddrSpinBox->value());
    settings.setValue("slewPathValue1", ui->slewPathSpinBox1->value());
    settings.setValue("slewPathValue2", ui->slewPathSpinBox2->value());
    settings.setValue("slewPathValue3", ui->slewPathSpinBox3->value());
    settings.setValue("slewPathValue4", ui->slewPathSpinBox4->value());
    settings.setValue("slewPathValue5", ui->slewPathSpinBox5->value());
    
    settings.setValue("luffPathAddr", ui->luffPathAddrSpinBox->value());
    settings.setValue("luffPathValue1", ui->luffPathSpinBox1->value());
    settings.setValue("luffPathValue2", ui->luffPathSpinBox2->value());
    settings.setValue("luffPathValue3", ui->luffPathSpinBox3->value());
    settings.setValue("luffPathValue4", ui->luffPathSpinBox4->value());
    settings.setValue("luffPathValue5", ui->luffPathSpinBox5->value());
    
    settings.setValue("hoistPathAddr", ui->hoistPathAddrSpinBox->value());
    settings.setValue("hoistPathValue1", ui->hoistPathSpinBox1->value());
    settings.setValue("hoistPathValue2", ui->hoistPathSpinBox2->value());
    settings.setValue("hoistPathValue3", ui->hoistPathSpinBox3->value());
    settings.setValue("hoistPathValue4", ui->hoistPathSpinBox4->value());
    settings.setValue("hoistPathValue5", ui->hoistPathSpinBox5->value());
}

void MainWindow::loadParameters()
{
    QSettings settings("HKCRC", "CraneTesting");
    
    // 加载连接参数
    ui->ipEdit->setText(settings.value("ip", "192.168.1.100").toString());
    ui->portSpinBox->setValue(settings.value("port", 502).toInt());
    ui->slaveSpinBox->setValue(settings.value("slave", 1).toInt());
    ui->registerTypeCombo->setCurrentIndex(settings.value("registerType", 0).toInt());
    
    // 加载Modbus参数
    ui->controlModeAddrSpinBox->setValue(settings.value("controlModeAddr", 0).toInt());
    ui->controlModeSpinBox->setValue(settings.value("controlModeValue", 0).toInt());
    ui->slewSpeedAddrSpinBox->setValue(settings.value("slewSpeedAddr", 1).toInt());
    ui->slewSpeedSpinBox->setValue(settings.value("slewSpeedValue", 0).toInt());
    ui->luffSpeedAddrSpinBox->setValue(settings.value("luffSpeedAddr", 2).toInt());
    ui->luffSpeedSpinBox->setValue(settings.value("luffSpeedValue", 0).toInt());
    ui->hoistSpeedAddrSpinBox->setValue(settings.value("hoistSpeedAddr", 3).toInt());
    ui->hoistSpeedSpinBox->setValue(settings.value("hoistSpeedValue", 0).toInt());
    ui->pathLengthAddrSpinBox->setValue(settings.value("pathLengthAddr", 4).toInt());
    ui->pathLengthSpinBox->setValue(settings.value("pathLengthValue", 0).toInt());
    
    // 加载路径参数
    ui->slewPathAddrSpinBox->setValue(settings.value("slewPathAddr", 5).toInt());
    ui->slewPathSpinBox1->setValue(settings.value("slewPathValue1", 0).toInt());
    ui->slewPathSpinBox2->setValue(settings.value("slewPathValue2", 0).toInt());
    ui->slewPathSpinBox3->setValue(settings.value("slewPathValue3", 0).toInt());
    ui->slewPathSpinBox4->setValue(settings.value("slewPathValue4", 0).toInt());
    ui->slewPathSpinBox5->setValue(settings.value("slewPathValue5", 0).toInt());
    
    ui->luffPathAddrSpinBox->setValue(settings.value("luffPathAddr", 6).toInt());
    ui->luffPathSpinBox1->setValue(settings.value("luffPathValue1", 0).toInt());
    ui->luffPathSpinBox2->setValue(settings.value("luffPathValue2", 0).toInt());
    ui->luffPathSpinBox3->setValue(settings.value("luffPathValue3", 0).toInt());
    ui->luffPathSpinBox4->setValue(settings.value("luffPathValue4", 0).toInt());
    ui->luffPathSpinBox5->setValue(settings.value("luffPathValue5", 0).toInt());
    
    ui->hoistPathAddrSpinBox->setValue(settings.value("hoistPathAddr", 7).toInt());
    ui->hoistPathSpinBox1->setValue(settings.value("hoistPathValue1", 0).toInt());
    ui->hoistPathSpinBox2->setValue(settings.value("hoistPathValue2", 0).toInt());
    ui->hoistPathSpinBox3->setValue(settings.value("hoistPathValue3", 0).toInt());
    ui->hoistPathSpinBox4->setValue(settings.value("hoistPathValue4", 0).toInt());
    ui->hoistPathSpinBox5->setValue(settings.value("hoistPathValue5", 0).toInt());
}

void MainWindow::onSendButtonClicked()
{
    if (!modbusSocket || modbusSocket->state() != QTcpSocket::ConnectedState) {
        logMessage("Modbus socket not connected");
        return;
    }
    
    // 保存当前参数
    saveParameters();

    // 读取连接参数
    quint8 slaveAddr = static_cast<quint8>(ui->slaveSpinBox->value());
    quint8 functionCode = getFunctionCode();
    // 读取参数地址和值
    quint16 controlModeAddr = ui->controlModeAddrSpinBox->value();
    quint16 controlModeValue = ui->controlModeSpinBox->value();
    // 这个变量在后续代码中没有使用，可以移除
    // quint16 slewSpeedAddr = ui->slewSpeedSpinBox->value();
    quint16 slewSpeedValue = ui->slewSpeedSpinBox->value();
    quint16 luffSpeedValue = ui->luffSpeedSpinBox->value();
    quint16 hoistSpeedValue = ui->hoistSpeedSpinBox->value();
    quint16 pathLengthValue = ui->pathLengthSpinBox->value();
    // 使用数组保存路径参数值，添加显式类型转换
    quint16 slewPathValues[5] = {
        static_cast<quint16>(ui->slewPathSpinBox1->value()),
        static_cast<quint16>(ui->slewPathSpinBox2->value()),
        static_cast<quint16>(ui->slewPathSpinBox3->value()),
        static_cast<quint16>(ui->slewPathSpinBox4->value()),
        static_cast<quint16>(ui->slewPathSpinBox5->value())
    };
    
    quint16 luffPathValues[5] = {
        static_cast<quint16>(ui->luffPathSpinBox1->value()),
        static_cast<quint16>(ui->luffPathSpinBox2->value()),
        static_cast<quint16>(ui->luffPathSpinBox3->value()),
        static_cast<quint16>(ui->luffPathSpinBox4->value()),
        static_cast<quint16>(ui->luffPathSpinBox5->value())
    };
    
    quint16 hoistPathValues[5] = {
        static_cast<quint16>(ui->hoistPathSpinBox1->value()),
        static_cast<quint16>(ui->hoistPathSpinBox2->value()),
        static_cast<quint16>(ui->hoistPathSpinBox3->value()),
        static_cast<quint16>(ui->hoistPathSpinBox4->value()),
        static_cast<quint16>(ui->hoistPathSpinBox5->value())
    };

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
        stream << quint16(22);      // Quantity of registers (原12 + 新增10)
        stream << quint8(44);       // Byte count (原24 + 新增20)
        stream << controlModeValue;
        stream << slewSpeedValue;
        stream << luffSpeedValue;
        stream << hoistSpeedValue;
        stream << pathLengthValue;

        // 使用循环写入数组中的值
        for (int i = 0; i < pathLengthValue; ++i) {
            stream << slewPathValues[i];
        }

        for (int i = 0; i < pathLengthValue; ++i) {
            stream << luffPathValues[i];
        }

        for (int i = 0; i < pathLengthValue; ++i) {
            stream << hoistPathValues[i];
        }
    } else if (functionCode == 0x06) { // Write Single Register
        stream << controlModeAddr;
        stream << controlModeValue;
    }
    
    // 更新长度字段
    request[4] = static_cast<char>((request.size() - 6) >> 8);
    request[5] = static_cast<char>(request.size() - 6);

    if (modbusSocket->write(request) != -1) {
        logMessage("Modbus request data: " + request.toHex(' '));
    } else {
        logMessage("Write request failed: " + modbusSocket->errorString());
    }
}

void MainWindow::logMessage(const QString &msg)
{
    if (m_messageScrollingEnabled) {
        ui->messageTextEdit->appendPlainText(QDateTime::currentDateTime().toString() + ": " + msg);
    } else {
        // 如果暂停滚动，将消息添加到缓冲区
        m_messageBuffer.append(QDateTime::currentDateTime().toString() + ": " + msg + "\n");
    }
}

void MainWindow::toggleMessageScrolling()
{
    m_messageScrollingEnabled = !m_messageScrollingEnabled;
    
    if (m_messageScrollingEnabled) {
        ui->pauseResumeButton->setText("Pause Scrolling");
        // 恢复滚动时，输出缓冲区中的消息
        if (!m_messageBuffer.isEmpty()) {
            ui->messageTextEdit->appendPlainText(m_messageBuffer);
            m_messageBuffer.clear();
        }
    } else {
        ui->pauseResumeButton->setText("Resume scrolling");
    }
}

void MainWindow::clearMessages()
{
    ui->messageTextEdit->clear();
    m_messageBuffer.clear();
}