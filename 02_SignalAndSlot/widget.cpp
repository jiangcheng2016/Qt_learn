#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QDebug>

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
    //classIsOver();

    //点击按钮，触发下课
    QPushButton *btn = new QPushButton;
    this->resize(500,400);
    btn->setText("下课");
    btn->move(100,100);
    btn->setParent(this);
    //connect(btn,&QPushButton::clicked, this,&Widget::classIsOver);

    //无参信号和槽连接
    void(Teacher:: *teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: *studentSlot2)(void) = &Student::treat;
    connect(ls,teacherSignal2,st,studentSlot2);

    //信号连接信号
    connect(btn,&QPushButton::clicked,ls,teacherSignal2);
    //断开信号
    //disconnect(ls,teacherSignal2,st,studentSlot2);

    QPushButton *btn2 = new QPushButton;

    //lambda 表达式
    [=](){
        btn->setText("test");
        btn2->setText("btn2");
        btn2->setParent(this);//若[]里面为btn，则函数体只识别btn, 故btn2无法识别
    }();  //没有(),函数就不会调用，此时不执行；加上()，函数调用，btn属性改变

    //mutable 关键字
    //mutable 用于修饰值传递的变量，修改的是拷贝，而不是本体
    QPushButton *myBtn =new QPushButton("myBtn",this);
    QPushButton *myBtn2 = new QPushButton("myBtn2",this);

    int m = 10;

    myBtn->move(300,300);
    myBtn2->move(350,350);

    connect(myBtn,&QPushButton::clicked,this,[m]()mutable {m = 100 + 10; qDebug() << m;});
    connect(myBtn2,&QPushButton::clicked,this,[=](){
        qDebug() << m;
    });
    qDebug() << m;

    //使用lambda表达式实现点击按钮关闭窗口
    QPushButton *btn3 = new QPushButton;
    btn3->setText("关闭");
    btn3->move(100,0);
    btn3->setParent(this);
    connect(btn3, &QPushButton::clicked, this, [=](){
        //this->close();
        //emit ls->hungry("北京烤鸭");

        btn3->setText("宫爆鸡丁");
    });
    //lambda 常用表达式 [](){}

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

