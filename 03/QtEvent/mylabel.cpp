#include "mylabel.h"
#include <QDebug>
#include <QString>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标移动监控
    setMouseTracking(true);

}

//鼠标进入事件
void MyLabel::enterEvent(QEvent *event){
    //qDebug() << "鼠标进入了区域";
}

//鼠标离开事件
void MyLabel::leaveEvent(QEvent *event){
    //qDebug() << "鼠标离开了区域";
}


//鼠标按压事件
void MyLabel::mousePressEvent(QMouseEvent *ev){
    if (ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标按压的位置为： x =%1 y = %2 globalx = %3  global4 = %4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str ;
    }
}

//鼠标释放事
void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
    if (ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标释放了 x =%1 y = %2 globalx = %3  global4 = %4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str ;
    }
}

//鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *ev){
    //if (ev->buttons() & Qt::LeftButton)
    //{
        QString str = QString("鼠标移动了 x =%1 y = %2 globalx = %3  global4 = %4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str ;
    //}
}
