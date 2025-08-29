/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *messagesGroup;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *messageTextEdit;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *parametersGroup;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *controlModeLabel;
    QSpinBox *controlModeAddrSpinBox;
    QSpinBox *controlModeSpinBox;
    QLabel *slewSpeedLabel;
    QSpinBox *slewSpeedAddrSpinBox;
    QSpinBox *slewSpeedSpinBox;
    QLabel *luffSpeedLabel;
    QSpinBox *luffSpeedAddrSpinBox;
    QSpinBox *luffSpeedSpinBox;
    QLabel *hoistSpeedLabel;
    QSpinBox *hoistSpeedAddrSpinBox;
    QSpinBox *hoistSpeedSpinBox;
    QPushButton *sendButton;
    QGroupBox *connectionGroup;
    QFormLayout *formLayout_2;
    QLabel *ipLabel;
    QLineEdit *ipEdit;
    QLabel *portLabel;
    QSpinBox *portSpinBox;
    QLabel *slaveLabel;
    QSpinBox *slaveSpinBox;
    QLabel *registerTypeLabel;
    QComboBox *registerTypeCombo;
    QPushButton *connectButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        messagesGroup = new QGroupBox(centralWidget);
        messagesGroup->setObjectName(QString::fromUtf8("messagesGroup"));
        verticalLayout_2 = new QVBoxLayout(messagesGroup);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        messageTextEdit = new QPlainTextEdit(messagesGroup);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        messageTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(messageTextEdit);


        verticalLayout->addWidget(messagesGroup);

        bottomWidget = new QWidget(centralWidget);
        bottomWidget->setObjectName(QString::fromUtf8("bottomWidget"));
        horizontalLayout = new QHBoxLayout(bottomWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        parametersGroup = new QGroupBox(bottomWidget);
        parametersGroup->setObjectName(QString::fromUtf8("parametersGroup"));
        gridLayout = new QGridLayout(parametersGroup);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(parametersGroup);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(parametersGroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(parametersGroup);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        controlModeLabel = new QLabel(parametersGroup);
        controlModeLabel->setObjectName(QString::fromUtf8("controlModeLabel"));

        gridLayout->addWidget(controlModeLabel, 1, 0, 1, 1);

        controlModeAddrSpinBox = new QSpinBox(parametersGroup);
        controlModeAddrSpinBox->setObjectName(QString::fromUtf8("controlModeAddrSpinBox"));
        controlModeAddrSpinBox->setMinimum(0);
        controlModeAddrSpinBox->setMaximum(65535);

        gridLayout->addWidget(controlModeAddrSpinBox, 1, 1, 1, 1);

        controlModeSpinBox = new QSpinBox(parametersGroup);
        controlModeSpinBox->setObjectName(QString::fromUtf8("controlModeSpinBox"));
        controlModeSpinBox->setMinimum(0);
        controlModeSpinBox->setMaximum(65535);

        gridLayout->addWidget(controlModeSpinBox, 1, 2, 1, 1);

        slewSpeedLabel = new QLabel(parametersGroup);
        slewSpeedLabel->setObjectName(QString::fromUtf8("slewSpeedLabel"));

        gridLayout->addWidget(slewSpeedLabel, 2, 0, 1, 1);

        slewSpeedAddrSpinBox = new QSpinBox(parametersGroup);
        slewSpeedAddrSpinBox->setObjectName(QString::fromUtf8("slewSpeedAddrSpinBox"));
        slewSpeedAddrSpinBox->setMinimum(1);
        slewSpeedAddrSpinBox->setMaximum(65535);

        gridLayout->addWidget(slewSpeedAddrSpinBox, 2, 1, 1, 1);

        slewSpeedSpinBox = new QSpinBox(parametersGroup);
        slewSpeedSpinBox->setObjectName(QString::fromUtf8("slewSpeedSpinBox"));
        slewSpeedSpinBox->setMinimum(0);
        slewSpeedSpinBox->setMaximum(65535);

        gridLayout->addWidget(slewSpeedSpinBox, 2, 2, 1, 1);

        luffSpeedLabel = new QLabel(parametersGroup);
        luffSpeedLabel->setObjectName(QString::fromUtf8("luffSpeedLabel"));

        gridLayout->addWidget(luffSpeedLabel, 3, 0, 1, 1);

        luffSpeedAddrSpinBox = new QSpinBox(parametersGroup);
        luffSpeedAddrSpinBox->setObjectName(QString::fromUtf8("luffSpeedAddrSpinBox"));
        luffSpeedAddrSpinBox->setMinimum(2);
        luffSpeedAddrSpinBox->setMaximum(65535);

        gridLayout->addWidget(luffSpeedAddrSpinBox, 3, 1, 1, 1);

        luffSpeedSpinBox = new QSpinBox(parametersGroup);
        luffSpeedSpinBox->setObjectName(QString::fromUtf8("luffSpeedSpinBox"));
        luffSpeedSpinBox->setMinimum(0);
        luffSpeedSpinBox->setMaximum(65535);

        gridLayout->addWidget(luffSpeedSpinBox, 3, 2, 1, 1);

        hoistSpeedLabel = new QLabel(parametersGroup);
        hoistSpeedLabel->setObjectName(QString::fromUtf8("hoistSpeedLabel"));

        gridLayout->addWidget(hoistSpeedLabel, 4, 0, 1, 1);

        hoistSpeedAddrSpinBox = new QSpinBox(parametersGroup);
        hoistSpeedAddrSpinBox->setObjectName(QString::fromUtf8("hoistSpeedAddrSpinBox"));
        hoistSpeedAddrSpinBox->setMinimum(3);
        hoistSpeedAddrSpinBox->setMaximum(65535);

        gridLayout->addWidget(hoistSpeedAddrSpinBox, 4, 1, 1, 1);

        hoistSpeedSpinBox = new QSpinBox(parametersGroup);
        hoistSpeedSpinBox->setObjectName(QString::fromUtf8("hoistSpeedSpinBox"));
        hoistSpeedSpinBox->setMinimum(0);
        hoistSpeedSpinBox->setMaximum(65535);

        gridLayout->addWidget(hoistSpeedSpinBox, 4, 2, 1, 1);

        sendButton = new QPushButton(parametersGroup);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        gridLayout->addWidget(sendButton, 5, 1, 1, 2);


        horizontalLayout->addWidget(parametersGroup);

        connectionGroup = new QGroupBox(bottomWidget);
        connectionGroup->setObjectName(QString::fromUtf8("connectionGroup"));
        formLayout_2 = new QFormLayout(connectionGroup);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        ipLabel = new QLabel(connectionGroup);
        ipLabel->setObjectName(QString::fromUtf8("ipLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, ipLabel);

        ipEdit = new QLineEdit(connectionGroup);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, ipEdit);

        portLabel = new QLabel(connectionGroup);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, portLabel);

        portSpinBox = new QSpinBox(connectionGroup);
        portSpinBox->setObjectName(QString::fromUtf8("portSpinBox"));
        portSpinBox->setMinimum(1);
        portSpinBox->setMaximum(65535);
        portSpinBox->setValue(502);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, portSpinBox);

        slaveLabel = new QLabel(connectionGroup);
        slaveLabel->setObjectName(QString::fromUtf8("slaveLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, slaveLabel);

        slaveSpinBox = new QSpinBox(connectionGroup);
        slaveSpinBox->setObjectName(QString::fromUtf8("slaveSpinBox"));
        slaveSpinBox->setMinimum(1);
        slaveSpinBox->setMaximum(247);
        slaveSpinBox->setValue(1);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, slaveSpinBox);

        registerTypeLabel = new QLabel(connectionGroup);
        registerTypeLabel->setObjectName(QString::fromUtf8("registerTypeLabel"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, registerTypeLabel);

        registerTypeCombo = new QComboBox(connectionGroup);
        registerTypeCombo->addItem(QString());
        registerTypeCombo->addItem(QString());
        registerTypeCombo->addItem(QString());
        registerTypeCombo->addItem(QString());
        registerTypeCombo->setObjectName(QString::fromUtf8("registerTypeCombo"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, registerTypeCombo);

        connectButton = new QPushButton(connectionGroup);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, connectButton);


        horizontalLayout->addWidget(connectionGroup);


        verticalLayout->addWidget(bottomWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "For HKCRC Crane Testing", nullptr));
        messagesGroup->setTitle(QCoreApplication::translate("MainWindow", "Messages", nullptr));
        parametersGroup->setTitle(QCoreApplication::translate("MainWindow", "Modbus Parameters", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Parameter", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        controlModeLabel->setText(QCoreApplication::translate("MainWindow", "Control Mode", nullptr));
        slewSpeedLabel->setText(QCoreApplication::translate("MainWindow", "Slew Speed", nullptr));
        luffSpeedLabel->setText(QCoreApplication::translate("MainWindow", "Luff Speed", nullptr));
        hoistSpeedLabel->setText(QCoreApplication::translate("MainWindow", "Hoist Speed", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        connectionGroup->setTitle(QCoreApplication::translate("MainWindow", "Connection Settings", nullptr));
        ipLabel->setText(QCoreApplication::translate("MainWindow", "Server IP:", nullptr));
        ipEdit->setText(QCoreApplication::translate("MainWindow", "192.168.1.100", nullptr));
        portLabel->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        slaveLabel->setText(QCoreApplication::translate("MainWindow", "Slave Address:", nullptr));
        registerTypeLabel->setText(QCoreApplication::translate("MainWindow", "Register Type:", nullptr));
        registerTypeCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Holding Registers", nullptr));
        registerTypeCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Input Registers", nullptr));
        registerTypeCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Coils", nullptr));
        registerTypeCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Discrete Inputs", nullptr));

        connectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
