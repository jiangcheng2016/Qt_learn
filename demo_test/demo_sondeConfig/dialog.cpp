#include "dialog.h"
#include "ui_dialog.h"
#include "qtablewidget.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


   //下拉框
    ui->ParamType->addItem("类型一");
    ui->ParamType->addItem("类型二");
    ui->ParamType->addItem("类型三");

    ui->ParamSpec->addItem("规格一");
    ui->ParamSpec->addItem("规格二");
    ui->ParamSpec->addItem("规格三");

    QStringList headerText;
    headerText << "探空仪编号" << "参数1" << "参数2" << "参数3" ;
    ui->tableWidget->setColumnCount(headerText.count());
    ui->tableWidget->setHorizontalHeaderLabels(headerText);
    ui->tableWidget->setRowCount(2);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{color:white;background-color:#204C7D}");
    ui->tableWidget->verticalHeader()->setStyleSheet("QHeaderView::section{color:white;background-color:#204C7D}");

    QTableWidgetItem *item = new QTableWidgetItem();
    item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsEditable);        //设置单元格可双击修改
    //item->setBackgroundColor(Qt::red); //设置单元格背景色


    //设置正文

    QStringList nameList;
    nameList << "001" << "002";
    QStringList cs1;
    cs1 << "温度1 " << "温度2";
    QStringList cs2;
    cs2 << "方向" << "方向2";
    QStringList cs3;
    cs3 << "速度1" << "速度2";

    for (int i = 0; i < 2; i ++)
    {
      int col = 0;
      ui->tableWidget->setItem(i,col ++, new QTableWidgetItem(nameList[i]));
      ui->tableWidget->setItem(i,col ++, new QTableWidgetItem(cs1[i]));
      ui->tableWidget->setItem(i,col ++, new QTableWidgetItem(cs2[i]));
      ui->tableWidget->setItem(i,col ++, new QTableWidgetItem(cs3[i]));
    }



}

Dialog::~Dialog()
{
    delete ui;
}

