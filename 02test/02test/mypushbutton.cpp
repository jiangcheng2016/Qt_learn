#include "mypushbutton.h"
#include "qdebug.h"

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "我的按钮类构造调用";
}

MyPushButton::~MyPushButton()
{
    qDebug() << "我的析构函数调用";
}
