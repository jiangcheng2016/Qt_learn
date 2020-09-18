#include "widget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btn = new QPushButton;
    btn->setParent(this);
    btn->setText("我的第一个按钮");
    btn->move(200,200);
    btn->show();

    // new 一个对象 QPushButton
    button = new QPushButton;
    //构造函数时，指定父对象
    //button = new QPushButton(this);
    //构造函数时 指定父对象和设置文本
    button = new QPushButton("按钮点这里",this);
    //this->resize(600,600);
    //如果不给按钮指定父对象，那么按钮和窗口是单独显示；如果给按钮指定了父对象，只要父对象显示，那么按钮也会显示
    button->show();
    //指定按钮的父类是窗口
    //button->setParent(this);

    button->resize(100,100);    //设置按钮的大小
    button->move(100,100);      //设置按钮在窗口的位置
    //button->setText("按钮点这里"); // 设置按钮的文本

    //新建MyPushButton按钮
    MyPushButton * myBtn = new MyPushButton;
    //设置属性
    myBtn->setParent(this);
    myBtn->setText("我自己的按钮");
    myBtn->move(200,0);
    myBtn->show();

    //需求：点击按钮，关闭当前窗口
    //使用connect函数，参数1 信号的发送者, 参数2 发送的具体信号， 参数3 信号的接收者， 参数4 信号的处理（槽）
    connect(btn, &QPushButton::clicked, this, &QWidget::close);
    connect(myBtn,&MyPushButton::clicked, this, &MyPushButton::close);

}

Widget::~Widget()
{
    qDebug() << "我的Widget析构函数";
}

