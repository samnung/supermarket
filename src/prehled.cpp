#include "prehled.h"
#include "ui_prehled.h"

prehled::prehled(QWidget *parent) : QWidget(parent)
{
	ui_prehled = new Ui::prehled();
	ui_prehled->setupUi(this);
}

prehled::~prehled()
{
	delete ui_prehled;
}
