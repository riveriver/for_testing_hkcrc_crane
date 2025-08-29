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
    QLabel *pathLengthLabel;
    QSpinBox *pathLengthAddrSpinBox;
    QSpinBox *pathLengthSpinBox;
    QLabel *slewPathLabel;
    QSpinBox *slewPathAddrSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *slewPathSpinBox1;
    QSpinBox *slewPathSpinBox2;
    QSpinBox *slewPathSpinBox3;
    QSpinBox *slewPathSpinBox4;
    QSpinBox *slewPathSpinBox5;
    QLabel *luffPathLabel;
    QSpinBox *luffPathAddrSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *luffPathSpinBox1;
    QSpinBox *luffPathSpinBox2;
    QSpinBox *luffPathSpinBox3;
    QSpinBox *luffPathSpinBox4;
    QSpinBox *luffPathSpinBox5;
    QLabel *hoistPathLabel;
    QSpinBox *hoistPathAddrSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *hoistPathSpinBox1;
    QSpinBox *hoistPathSpinBox2;
    QSpinBox *hoistPathSpinBox3;
    QSpinBox *hoistPathSpinBox4;
    QSpinBox *hoistPathSpinBox5;
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(parametersGroup->sizePolicy().hasHeightForWidth());
        parametersGroup->setSizePolicy(sizePolicy);
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
        controlModeAddrSpinBox->setDisplayIntegerBase(16);

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
        slewSpeedAddrSpinBox->setDisplayIntegerBase(16);

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
        luffSpeedAddrSpinBox->setDisplayIntegerBase(16);

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
        hoistSpeedAddrSpinBox->setDisplayIntegerBase(16);

        gridLayout->addWidget(hoistSpeedAddrSpinBox, 4, 1, 1, 1);

        hoistSpeedSpinBox = new QSpinBox(parametersGroup);
        hoistSpeedSpinBox->setObjectName(QString::fromUtf8("hoistSpeedSpinBox"));
        hoistSpeedSpinBox->setMinimum(0);
        hoistSpeedSpinBox->setMaximum(65535);

        gridLayout->addWidget(hoistSpeedSpinBox, 4, 2, 1, 1);

        pathLengthLabel = new QLabel(parametersGroup);
        pathLengthLabel->setObjectName(QString::fromUtf8("pathLengthLabel"));

        gridLayout->addWidget(pathLengthLabel, 5, 0, 1, 1);

        pathLengthAddrSpinBox = new QSpinBox(parametersGroup);
        pathLengthAddrSpinBox->setObjectName(QString::fromUtf8("pathLengthAddrSpinBox"));
        pathLengthAddrSpinBox->setMinimum(4);
        pathLengthAddrSpinBox->setMaximum(65535);
        pathLengthAddrSpinBox->setDisplayIntegerBase(16);

        gridLayout->addWidget(pathLengthAddrSpinBox, 5, 1, 1, 1);

        pathLengthSpinBox = new QSpinBox(parametersGroup);
        pathLengthSpinBox->setObjectName(QString::fromUtf8("pathLengthSpinBox"));
        pathLengthSpinBox->setMinimum(0);
        pathLengthSpinBox->setMaximum(65535);

        gridLayout->addWidget(pathLengthSpinBox, 5, 2, 1, 1);

        slewPathLabel = new QLabel(parametersGroup);
        slewPathLabel->setObjectName(QString::fromUtf8("slewPathLabel"));

        gridLayout->addWidget(slewPathLabel, 6, 0, 1, 1);

        slewPathAddrSpinBox = new QSpinBox(parametersGroup);
        slewPathAddrSpinBox->setObjectName(QString::fromUtf8("slewPathAddrSpinBox"));
        slewPathAddrSpinBox->setMinimum(5);
        slewPathAddrSpinBox->setMaximum(65535);
        slewPathAddrSpinBox->setDisplayIntegerBase(16);
        slewPathAddrSpinBox->setValue(5);

        gridLayout->addWidget(slewPathAddrSpinBox, 6, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        slewPathSpinBox1 = new QSpinBox(parametersGroup);
        slewPathSpinBox1->setObjectName(QString::fromUtf8("slewPathSpinBox1"));
        slewPathSpinBox1->setMinimum(0);
        slewPathSpinBox1->setMaximum(65535);

        horizontalLayout_3->addWidget(slewPathSpinBox1);

        slewPathSpinBox2 = new QSpinBox(parametersGroup);
        slewPathSpinBox2->setObjectName(QString::fromUtf8("slewPathSpinBox2"));
        slewPathSpinBox2->setMinimum(0);
        slewPathSpinBox2->setMaximum(65535);

        horizontalLayout_3->addWidget(slewPathSpinBox2);

        slewPathSpinBox3 = new QSpinBox(parametersGroup);
        slewPathSpinBox3->setObjectName(QString::fromUtf8("slewPathSpinBox3"));
        slewPathSpinBox3->setMinimum(0);
        slewPathSpinBox3->setMaximum(65535);

        horizontalLayout_3->addWidget(slewPathSpinBox3);

        slewPathSpinBox4 = new QSpinBox(parametersGroup);
        slewPathSpinBox4->setObjectName(QString::fromUtf8("slewPathSpinBox4"));
        slewPathSpinBox4->setMinimum(0);
        slewPathSpinBox4->setMaximum(65535);

        horizontalLayout_3->addWidget(slewPathSpinBox4);

        slewPathSpinBox5 = new QSpinBox(parametersGroup);
        slewPathSpinBox5->setObjectName(QString::fromUtf8("slewPathSpinBox5"));
        slewPathSpinBox5->setMinimum(0);
        slewPathSpinBox5->setMaximum(65535);

        horizontalLayout_3->addWidget(slewPathSpinBox5);


        gridLayout->addLayout(horizontalLayout_3, 6, 2, 1, 1);

        luffPathLabel = new QLabel(parametersGroup);
        luffPathLabel->setObjectName(QString::fromUtf8("luffPathLabel"));

        gridLayout->addWidget(luffPathLabel, 7, 0, 1, 1);

        luffPathAddrSpinBox = new QSpinBox(parametersGroup);
        luffPathAddrSpinBox->setObjectName(QString::fromUtf8("luffPathAddrSpinBox"));
        luffPathAddrSpinBox->setMinimum(6);
        luffPathAddrSpinBox->setMaximum(65535);
        luffPathAddrSpinBox->setDisplayIntegerBase(16);
        luffPathAddrSpinBox->setValue(10);

        gridLayout->addWidget(luffPathAddrSpinBox, 7, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        luffPathSpinBox1 = new QSpinBox(parametersGroup);
        luffPathSpinBox1->setObjectName(QString::fromUtf8("luffPathSpinBox1"));
        luffPathSpinBox1->setMinimum(0);
        luffPathSpinBox1->setMaximum(65535);

        horizontalLayout_4->addWidget(luffPathSpinBox1);

        luffPathSpinBox2 = new QSpinBox(parametersGroup);
        luffPathSpinBox2->setObjectName(QString::fromUtf8("luffPathSpinBox2"));
        luffPathSpinBox2->setMinimum(0);
        luffPathSpinBox2->setMaximum(65535);

        horizontalLayout_4->addWidget(luffPathSpinBox2);

        luffPathSpinBox3 = new QSpinBox(parametersGroup);
        luffPathSpinBox3->setObjectName(QString::fromUtf8("luffPathSpinBox3"));
        luffPathSpinBox3->setMinimum(0);
        luffPathSpinBox3->setMaximum(65535);

        horizontalLayout_4->addWidget(luffPathSpinBox3);

        luffPathSpinBox4 = new QSpinBox(parametersGroup);
        luffPathSpinBox4->setObjectName(QString::fromUtf8("luffPathSpinBox4"));
        luffPathSpinBox4->setMinimum(0);
        luffPathSpinBox4->setMaximum(65535);

        horizontalLayout_4->addWidget(luffPathSpinBox4);

        luffPathSpinBox5 = new QSpinBox(parametersGroup);
        luffPathSpinBox5->setObjectName(QString::fromUtf8("luffPathSpinBox5"));
        luffPathSpinBox5->setMinimum(0);
        luffPathSpinBox5->setMaximum(65535);

        horizontalLayout_4->addWidget(luffPathSpinBox5);


        gridLayout->addLayout(horizontalLayout_4, 7, 2, 1, 1);

        hoistPathLabel = new QLabel(parametersGroup);
        hoistPathLabel->setObjectName(QString::fromUtf8("hoistPathLabel"));

        gridLayout->addWidget(hoistPathLabel, 8, 0, 1, 1);

        hoistPathAddrSpinBox = new QSpinBox(parametersGroup);
        hoistPathAddrSpinBox->setObjectName(QString::fromUtf8("hoistPathAddrSpinBox"));
        hoistPathAddrSpinBox->setMinimum(7);
        hoistPathAddrSpinBox->setMaximum(65535);
        hoistPathAddrSpinBox->setDisplayIntegerBase(16);
        hoistPathAddrSpinBox->setValue(15);

        gridLayout->addWidget(hoistPathAddrSpinBox, 8, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        hoistPathSpinBox1 = new QSpinBox(parametersGroup);
        hoistPathSpinBox1->setObjectName(QString::fromUtf8("hoistPathSpinBox1"));
        hoistPathSpinBox1->setMinimum(0);
        hoistPathSpinBox1->setMaximum(65535);

        horizontalLayout_5->addWidget(hoistPathSpinBox1);

        hoistPathSpinBox2 = new QSpinBox(parametersGroup);
        hoistPathSpinBox2->setObjectName(QString::fromUtf8("hoistPathSpinBox2"));
        hoistPathSpinBox2->setMinimum(0);
        hoistPathSpinBox2->setMaximum(65535);

        horizontalLayout_5->addWidget(hoistPathSpinBox2);

        hoistPathSpinBox3 = new QSpinBox(parametersGroup);
        hoistPathSpinBox3->setObjectName(QString::fromUtf8("hoistPathSpinBox3"));
        hoistPathSpinBox3->setMinimum(0);
        hoistPathSpinBox3->setMaximum(65535);

        horizontalLayout_5->addWidget(hoistPathSpinBox3);

        hoistPathSpinBox4 = new QSpinBox(parametersGroup);
        hoistPathSpinBox4->setObjectName(QString::fromUtf8("hoistPathSpinBox4"));
        hoistPathSpinBox4->setMinimum(0);
        hoistPathSpinBox4->setMaximum(65535);

        horizontalLayout_5->addWidget(hoistPathSpinBox4);

        hoistPathSpinBox5 = new QSpinBox(parametersGroup);
        hoistPathSpinBox5->setObjectName(QString::fromUtf8("hoistPathSpinBox5"));
        hoistPathSpinBox5->setMinimum(0);
        hoistPathSpinBox5->setMaximum(65535);

        horizontalLayout_5->addWidget(hoistPathSpinBox5);


        gridLayout->addLayout(horizontalLayout_5, 8, 2, 1, 1);

        sendButton = new QPushButton(parametersGroup);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        gridLayout->addWidget(sendButton, 9, 1, 1, 2);


        horizontalLayout->addWidget(parametersGroup);

        connectionGroup = new QGroupBox(bottomWidget);
        connectionGroup->setObjectName(QString::fromUtf8("connectionGroup"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(connectionGroup->sizePolicy().hasHeightForWidth());
        connectionGroup->setSizePolicy(sizePolicy1);
        connectionGroup->setMinimumWidth(300);
        connectionGroup->setMaximumWidth(300);
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
        controlModeAddrSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "0x", nullptr));
        slewSpeedLabel->setText(QCoreApplication::translate("MainWindow", "Slew Speed", nullptr));
        slewSpeedAddrSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "0x", nullptr));
        luffSpeedLabel->setText(QCoreApplication::translate("MainWindow", "Luff Speed", nullptr));
        luffSpeedAddrSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "0x", nullptr));
        hoistSpeedLabel->setText(QCoreApplication::translate("MainWindow", "Hoist Speed", nullptr));
        hoistSpeedAddrSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "0x", nullptr));
        pathLengthLabel->setText(QCoreApplication::translate("MainWindow", "Path Length", nullptr));
        pathLengthAddrSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "0x", nullptr));
        slewPathLabel->setText(QCoreApplication::translate("MainWindow", "Slew Path", nullptr));
        slewPathAddrSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "0x", nullptr));
        luffPathLabel->setText(QCoreApplication::translate("MainWindow", "Luff Path", nullptr));
        luffPathAddrSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "0x", nullptr));
        hoistPathLabel->setText(QCoreApplication::translate("MainWindow", "Hoist Path", nullptr));
        hoistPathAddrSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "0x", nullptr));
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
