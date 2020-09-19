#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    //public slot
    //早期的qt版本，必须写道public slot下，高级版本可以写到public或者全局下，这里没有public slot ，所以写到public 下
    //返回值是void 需要证明，也需要实现
    void treat();
signals:

};

#endif // STUDENT_H
