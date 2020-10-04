#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动计时器1
    id1 = startTimer(1000);

    //计时器2
    id2 = startTimer(2000);
}


void Widget::timerEvent(QTimerEvent *ev)
{
    //lable2
    if (ev->timerId() == id1)
    {
        static int num = 1;
        ui->label_2->setText(QString().number(num ++));
    }
    //lable3
    if (ev->timerId() == id2)
    {    static int num2 = 1;
        ui->label_3->setText(QString().number(num2 ++));
    }
}


Widget::~Widget()
{
    delete ui;
}

