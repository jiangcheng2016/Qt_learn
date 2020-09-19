#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QPushButton *btn = new QPushButton;
//    btn->setText("自定义");
//    btn->move(100,100);
//    btn->setParent(this);
//    btn->show();

    //创建一个老师对象
    this->ls = new Teacher(this);


    //创建一个学生对象
    this->st = new Student(this);

    //连接
    //connect(ls, &Teacher::hungry, st, &Student::treat);

    //因为涉及到参数，所以这里用函数指针 明确指向函数的地址
    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlot)(QString) = &Student::treat;
    connect(ls,teacherSignal,st,studentSlot);
    //调用下课函数
    classIsOver();


}

void Widget::classIsOver()
{
    //下课函数，点击后，触发老师饿了的信号，连接学生请吃饭
    //emit ls->hungry();
    emit ls->hungry("北京烤鸭");
}

Widget::~Widget()
{
    delete ui;
}

