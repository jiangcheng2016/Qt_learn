#include "qtcontrol.h"
#include "ui_qtcontrol.h"
#include <QDebug>
#include <QWidgetItem>

QtControl::QtControl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtControl)
{
    ui->setupUi(this);
    //设置单选按钮  默认是选中男
    ui->rBtnMan->setChecked(true);

    //选中女后 打印
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
        qDebug() << "选中了女";
    });

    //多选按钮 1是选中，0是未选 (在以前版本中，2是选中，0是未选)
    connect(ui->serviceGood,&QCheckBox::clicked,[=](int state){
        qDebug() << state;
    });

    //利用ListView 写诗

//    QListWidgetItem * item = new QListWidgetItem("锄禾日当午");
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignCenter);

      QStringList list;
      list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
      //利用addItems 添加QStringList
      ui->listWidget->addItems(list);


}

QtControl::~QtControl()
{
    delete ui;
}

