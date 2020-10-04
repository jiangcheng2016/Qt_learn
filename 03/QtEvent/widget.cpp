#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动计时器1
    id1 = startTimer(1000);

    //计时器2
    id2 = startTimer(2000);

    //定时器的第二种方式
    QTimer * timer = new QTimer;

    timer->start(500);

    connect(timer,&QTimer::timeout,[=](){
        //label4
        //每隔0.5s +1
        static int num = 1;

        ui->label_4->setText(QString().number(num ++));

    });
    //点击按钮，暂停+1
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        timer->stop();
    });
}


void Widget::timerEvent(QTimerEvent *ev)
{
    //lable2
    //每1秒 +1
    if (ev->timerId() == id1)
    {
        static int num = 1;
        ui->label_2->setText(QString().number(num ++));
    }
    //lable3
    //每两秒 +1
    if (ev->timerId() == id2)
    {    static int num2 = 1;
        ui->label_3->setText(QString().number(num2 ++));
    }
}


Widget::~Widget()
{
    delete ui;
}

