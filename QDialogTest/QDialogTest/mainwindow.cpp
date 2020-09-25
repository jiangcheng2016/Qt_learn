#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击新建 弹出一个对话框
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框 Dialog  分类
        // 模态对话框（不可以对其他窗口操作)      非模态对话框(可以对其他窗口进行操作）

        //模态创建
//        QDialog dig(this);
//        dig.exec();

//        qDebug() << "aaa";

        //非模态创建

        /*

        QDialog dig2(this);
        dig2.show();
        如果使用这种情况，那么dig2在栈上面，当执行完 dig2.show() 以后窗口就会关闭，所以看不到
        此时，把它放到堆上面
        */

//        QDialog * dig2 = new QDialog(this);
//        dig2->show();
//        dig2->setAttribute(Qt::WA_DeleteOnClose);   //55号属性
//        qDebug() << "fei mo tai";


        //消息对话框
        //错误对话框
        QMessageBox::critical(this,"critical","错误");

        //信息对话框
        QMessageBox::information(this,"information","信息");

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

