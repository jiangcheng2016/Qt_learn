#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //栈控件使用

    //默认stackedWidget页面
    ui->stackedWidget->setCurrentIndex(0);

    //ScrollArea 控件
    connect(ui->btn_scrollArea,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    //ToolBox 控件
    connect(ui->btn_toolBox,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //TabBox 控件
    connect(ui->btn_tabWidget,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //combo Box下拉框
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("奥迪");

    //点击选中宝马按钮，下拉框填充宝马
    connect(ui->btn_select,&QPushButton::clicked,[=](){
        //ui->comboBox->setCurrentIndex(1);
        ui->comboBox->setCurrentText("宝马");
    });

    //QLale 显示图片
    ui->label_image->setPixmap(QPixmap(":/Image/butterfly.png"));

    //QLable 显示动图
    QMovie *moive = new QMovie(":/Image/mario.gif");
    ui->label_gif->setMovie(moive);
    moive->start();

}

Widget::~Widget()
{
    delete ui;
}

