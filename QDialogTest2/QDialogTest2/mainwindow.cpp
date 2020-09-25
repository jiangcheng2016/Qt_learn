#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "测试 kits";

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

        QDialog * dig2 = new QDialog(this);
        dig2->show();
        dig2->setAttribute(Qt::WA_DeleteOnClose);   //55号属性
        qDebug() << "fei mo tai";


        //消息对话框
        //错误对话框
        QMessageBox::critical(this,"critical","错误");

        //信息对话框
        QMessageBox::information(this,"information","信息");

        //提问对话框 question
        //参数1 父亲 参数2 标题 参数3 提示内容 参数4 按键类型 参数5 默认关联回车键
        if (QMessageBox::Save == QMessageBox::question(this,"question","确定保存",QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel))
        {
            qDebug() << "选择了保存";
        }
        else
        {
            qDebug() << "选择了取消";
        }

//        //警告对话框
        QMessageBox::warning(this,"warning","警告");

        //其他标准对话框
        //颜色对话框
        QColor color = QColorDialog::getColor(QColor(255,0,0));
        qDebug() << "r = " << color.red() << "g = " << color.green() << " b = " << color.blue();

        //文件对话框 参数1 父亲， 参数2 标题， 参数3 默认打开路径， 参数4 过滤文件格式
        QString str =  QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\Administrator\\Desktop","*.txt");
        // toUtf8 转为成ByteAarry, data 转化为 char *
        qDebug() << str.toUtf8().data();

          //字体对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag,QFont("华文彩云",36));
        qDebug() << "字体：" << font.family().toUtf8().data() << "字号：" << font.pointSize() << "是否加粗：" << font.bold() << "是否倾斜:" << font.italic();



    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

