#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include <QtNetwork>

QString MainWindow::getLocalIP()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);
    QString   localIP="";

    QList<QHostAddress> addList=hostInfo.addresses();//

    if (!addList.isEmpty())
    for (int i=0;i<addList.count();i++)
    {
        QHostAddress aHost=addList.at(i);
        if (QAbstractSocket::IPv4Protocol==aHost.protocol())
        {
            localIP=aHost.toString();
//            break;
        }
    }
    return localIP;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    LabSocketState=new QLabel("Socket状态：");//
    LabSocketState->setMinimumWidth(200);
    ui->statusBar->addWidget(LabSocketState);

    QString localIP=getLocalIP();//本地主机名
    this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP);

    udpSocket=new QUdpSocket(this);//用于与连接的客户端通讯的QTcpSocket
//Multicast路由层次，1表示只在同一局域网内
    //组播TTL: 生存时间，每跨1个路由会减1，多播无法跨过大多数路由所以为1
    //默认值是1，表示数据包只能在本地的子网中传送。
    udpSocket->setSocketOption(QAbstractSocket::MulticastTtlOption,1);
//    udpSocket->setSocketOption(QAbstractSocket::MulticastTtlOption,ui->spinTTL->value());

    connect(udpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    onSocketStateChange(udpSocket->state());

    connect(udpSocket,SIGNAL(readyRead()),
            this,SLOT(onSocketReadyRead()));

    //读取文件
    this->readFile();
}



MainWindow::~MainWindow()
{
    udpSocket->abort();
    delete udpSocket;
    delete ui;

    if (this->myTimer != NULL)
        delete this->myTimer;
}

void MainWindow::onSocketStateChange(QAbstractSocket::SocketState socketState)
{
    switch(socketState)
    {
    case QAbstractSocket::UnconnectedState:
        LabSocketState->setText("scoket状态：UnconnectedState");
        break;
    case QAbstractSocket::HostLookupState:
        LabSocketState->setText("scoket状态：HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        LabSocketState->setText("scoket状态：ConnectingState");
        break;

    case QAbstractSocket::ConnectedState:
        LabSocketState->setText("scoket状态：ConnectedState");
        break;

    case QAbstractSocket::BoundState:
        LabSocketState->setText("scoket状态：BoundState");
        break;

    case QAbstractSocket::ClosingState:
        LabSocketState->setText("scoket状态：ClosingState");
        break;

    case QAbstractSocket::ListeningState:
        LabSocketState->setText("scoket状态：ListeningState");
    }
}

void MainWindow::onSocketReadyRead()
{//读取数据报
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray   datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress    peerAddr;
        quint16 peerPort;
        udpSocket->readDatagram(datagram.data(),datagram.size(),&peerAddr,&peerPort);

//        udpSocket->readDatagram(datagram.data(),datagram.size());
        QString str=datagram.toHex().data();

        QString peer="[From "+peerAddr.toString()+":"+QString::number(peerPort)+"] ";

        ui->plainTextEdit->appendPlainText(peer+str);
    }
}

void MainWindow::on_actStart_triggered()
{//加入组播
    QString     IP=ui->comboIP->currentText();
    groupAddress=QHostAddress(IP);//多播组地址
    quint16     groupPort=ui->spinPort->value();//端口

    if (udpSocket->bind(QHostAddress::AnyIPv4, groupPort, QUdpSocket::ShareAddress))//先绑定端口
    {
        udpSocket->joinMulticastGroup(groupAddress); //加入多播组
        ui->plainTextEdit->appendPlainText("**加入组播成功");
        ui->plainTextEdit->appendPlainText("**组播地址IP："+IP);
        ui->plainTextEdit->appendPlainText("**绑定端口："+QString::number(groupPort));
        ui->actStart->setEnabled(false);
        ui->actStop->setEnabled(true);
        ui->comboIP->setEnabled(false);
    }
    else
        ui->plainTextEdit->appendPlainText("**绑定端口失败");
}

void MainWindow::on_actStop_triggered()
{//退出组播
    udpSocket->leaveMulticastGroup(groupAddress);//退出组播
    udpSocket->abort(); //解除绑定
    ui->actStart->setEnabled(true);
    ui->actStop->setEnabled(false);
    ui->comboIP->setEnabled(true);
    ui->plainTextEdit->appendPlainText("**已退出组播,解除端口绑定");
}

void MainWindow::on_actClear_triggered()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_actHostInfo_triggered()
{
    QString hostName=QHostInfo::localHostName();//本地主机名
    ui->plainTextEdit->appendPlainText("本机主机名："+hostName+"\n");
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);

    QList<QHostAddress> addList=hostInfo.addresses();//
    if (!addList.isEmpty())
    for (int i=0;i<addList.count();i++)
    {
        QHostAddress aHost=addList.at(i);
        if (QAbstractSocket::IPv4Protocol==aHost.protocol())
        {
            QString IP=aHost.toString();
            ui->plainTextEdit->appendPlainText("本机IP地址："+aHost.toString());
            if (ui->comboIP->findText(IP)<0)
                ui->comboIP->addItem(IP);
        }
    }
}

void MainWindow::on_btnMulticast_clicked()
{//发送组播消息
    quint16     groupPort=ui->spinPort->value();
    QString  msg=ui->editMsg->text();
    QByteArray  datagram=msg.toUtf8();

    udpSocket->writeDatagram(datagram,groupAddress,groupPort);
}


//读取文件
void MainWindow::readFile(){
    QString filePath = "D:/20210820_2_5.dat";
    QFile file(filePath);
    if (file.exists() == false)
    {
        qDebug() << "the file is not exist!";
        return;
    }
    if (file.open(QIODevice::ReadOnly) == false)
        return;
    //3-读取数据
    QByteArray fileData = file.readAll();
    int numOfData = fileData.size() / 65;
    maxLen = numOfData;
    qDebug() << "channel file length:" << fileData.size() << " num of data:" << numOfData;
   // ui->plainTextEdit->appendPlainText(fileData.toHex());


    QByteArray buffer;
    for(int i = 0; i < numOfData; i ++)
    {
        buffer = this->subByteArray(fileData,i * 65, 65);
        dataList.append(buffer);

        /*
        ui->plainTextEdit->appendPlainText(buffer.toHex());
        ui->plainTextEdit->appendPlainText("\n");*/
    }

}

void MainWindow::sendMsg(){


    if(size >= maxLen){
        //如果size超过了最大，停止定时器
        this->myTimer->stop();
        if(this->myTimer != NULL)
            delete myTimer;
    }

    QByteArray buffer = dataList[size ++];

    quint16     groupPort=ui->spinPort->value();

    udpSocket->writeDatagram(buffer,groupAddress,groupPort);

}


QByteArray MainWindow::subByteArray(QByteArray& ary, int startIndex, int length)
{
    QByteArray ret;
    for(int i = 0;i < length; ++ i)
    {
        ret.append(ary[startIndex + i]);
    }
    return ret;
}

void MainWindow::on_btnSendTimer_clicked()
{
    //定时器
    this->myTimer = new QTimer(this);
    this->connect(this->myTimer, &QTimer::timeout, this, &MainWindow::sendMsg);
    this->myTimer->start(1000);
}

void MainWindow::on_btnStopSend_clicked()
{
    if(this->myTimer != NULL)
        this->myTimer->stop();
}
