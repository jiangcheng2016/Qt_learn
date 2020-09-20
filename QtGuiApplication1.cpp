#include "stdafx.h"
#include "QtGuiApplication1.h"
#include "QPushButton"

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QPushButton *btn = new QPushButton;

	this->resize(600, 600);
	btn->setText("Start Game");
	btn->setParent(this);
	btn->move(200, 200);

}
