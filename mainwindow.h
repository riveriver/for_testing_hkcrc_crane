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
    void setupModbusClient(const QString &ip, quint16 port);
    void setupUI();
    void logMessage(const QString &msg);
    quint8 getFunctionCode() const;
};
#endif // MAINWINDOW_H