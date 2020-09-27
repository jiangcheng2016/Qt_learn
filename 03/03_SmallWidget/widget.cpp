#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "smallwidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击按钮获取当前值
    connect(ui->btn_get,&QPushButton::clicked,[=](){
        qDebug() << ui->widget->getValue();
    });

    //点击重置按钮 重置一半
    connect(ui->btn_set,&QPushButton::clicked,[=](){
        ui->widget->setValue(50);
    });
}

Widget::~Widget()
{
    delete ui;
}

