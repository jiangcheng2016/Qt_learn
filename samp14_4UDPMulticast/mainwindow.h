#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include    <QMainWindow>

#include    <QUdpSocket>
#include    <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QLabel  *LabSocketState;
    QUdpSocket  *udpSocket;//用于与连接的客户端通讯的QTcpSocket
    QHostAddress    groupAddress;//组播地址
    QString getLocalIP();//获取本机IP地址
    QTimer* myTimer = NULL;

    QByteArrayList dataList;    //保存数据

    int size = 0;
    int maxLen = 0;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
//自定义槽函数
    void    onSocketStateChange(QAbstractSocket::SocketState socketState);
    void    onSocketReadyRead();//读取socket传入的数据
//
    void on_actStart_triggered();

    void on_actStop_triggered();

    void on_actClear_triggered();

    void on_actHostInfo_triggered();

    void on_btnMulticast_clicked();

    void sendMsg();     //发送数据

    void readFile();    //读取文件


    QByteArray subByteArray(QByteArray& ary, int startIndex, int length);   //截取

    void on_btnSendTimer_clicked();

    void on_btnStopSend_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
