#ifndef QTCONTROL_H
#define QTCONTROL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class QtControl; }
QT_END_NAMESPACE

class QtControl : public QWidget
{
    Q_OBJECT

public:
    QtControl(QWidget *parent = nullptr);
    ~QtControl();

private:
    Ui::QtControl *ui;
};
#endif // QTCONTROL_H
