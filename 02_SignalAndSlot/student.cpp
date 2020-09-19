#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "请老师吃饭";
}

void Student::treat(QString foodName)
{
    //QString -> char *
    //toUtf8() 将QString 转为 QByteArray
    //data() 将QByteAarry 转为 char *
    qDebug() << "老师想吃：" << foodName.toUtf8().data();
}
