#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(600,400);

    //创建一个菜单栏
    QMenuBar * bar =  menuBar();

    //将菜单栏放入到窗口中
    setMenuBar(bar);

    //创建菜单
    QMenu * fileMenu = bar->addMenu("文件");
    QMenu * editMenu = bar->addMenu("编辑");

    //创建菜单项
    QAction *fileAction =  fileMenu->addAction("新建");
    fileMenu->addSeparator();
    QAction *openAction =  fileMenu->addAction("打开");

    editMenu->addAction("撤销");

    //创建工具栏
    QToolBar * toolBar = new QToolBar(this);
    //将工具栏添加到窗口（可设定初始位置，上/下/左/右均可）
    addToolBar(Qt::LeftToolBarArea, toolBar);
    //设置工具栏 允许停靠区域，是否可浮动，是否可移动
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    toolBar->setFloatable(true);
    toolBar->setMovable(true);

    //添加菜单项
    toolBar->addAction(fileAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    QPushButton * btn = new QPushButton;
    btn->setText("按钮");
    //添加按钮控件
    toolBar->addWidget(btn);


}

MainWindow::~MainWindow()
{
}

