#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>  // 所有控件的基类  就是一个窗口

class Widget : public QWidget //继承QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
