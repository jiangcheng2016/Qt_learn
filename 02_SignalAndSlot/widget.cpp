#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *btn = new QPushButton;
    btn->setText("自定义");
    btn->move(100,100);
    btn->setParent(this);
    btn->show();


}

Widget::~Widget()
{
    delete ui;
}

