#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class SmallWidget;
}

class SmallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmallWidget(QWidget *parent = nullptr);
    ~SmallWidget();

    //定义接口
    //获取当前值
    int getValue();

    //重置数值
    void setValue(int value);

private:
    Ui::SmallWidget *ui;
};

#endif // SMALLWIDGET_H
