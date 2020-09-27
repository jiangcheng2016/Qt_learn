#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    //自定义封装控件
    //SpinBox 数值增加，Slider相应滑动
    //因为QSpinBox的Signal有重载，所以要用指针
    void(QSpinBox:: * spin)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,spin,ui->horizontalSlider,&QSlider::setValue);

    //Slider 滑动 SpinBox数值变动
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);



}

//获取当前值
int SmallWidget::getValue(){
    return ui->spinBox->value();
}

//重置数值
void SmallWidget::setValue(int value){
    ui->spinBox->setValue(value);
}

SmallWidget::~SmallWidget()
{
    delete ui;
}
