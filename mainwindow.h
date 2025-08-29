#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSendButtonClicked();
    void onConnectButtonClicked();
    void onRegisterTypeChanged(int index);

private:
    Ui::MainWindow *ui;
    QTcpSocket *modbusSocket;
    void setupUI();
    void setupModbusClient(const QString &ip, quint16 port);
    void logMessage(const QString &msg);
    void toggleMessageScrolling();
    void clearMessages();
    void saveParameters();
    void loadParameters();
    quint8 getFunctionCode() const;
    
private:
    bool m_messageScrollingEnabled;
    QString m_messageBuffer;
};
#endif // MAINWINDOW_H