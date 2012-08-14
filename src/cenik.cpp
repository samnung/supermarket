#include "cenik.h"

cenik::cenik(files_control *_files)
{
	files = _files;

	setup();

	setWindowTitle(QString::fromUtf8("Ceník (platný od 1. září 2010)"));
	resize(670, 170);

	for (int i = 0; i < 13; i++)
	{
		files->pricesToLabels(i, label[1][i + 1], label[2][i + 1], label[3][i + 1]);
	}
}

void cenik::setup()
{
	layout = new QGridLayout(this);
	layout->setSpacing(0);
	layout->setMargin(0);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			label[i][j] = new QLabel(/*widget*/);
			label[i][j]->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
			label[i][j]->setWordWrap(true);
			layout->addWidget(label[i][j], i, j * 2);
		}
	}
	for (int i = 0; i < 13; i++)
	{
		lineV[i] = new QFrame;
		lineV[i]->setFrameShadow(QFrame::Plain);
		lineV[i]->setLineWidth(1);
		lineV[i]->setMidLineWidth(0);
		lineV[i]->setFrameShape(QFrame::VLine);
		lineV[i]->setStyleSheet(files->colorGrey());

		layout->addWidget(lineV[i], 0, (i*2)+1, 4, 1);
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 14 ; j++)
		{
			if (i == 0 || i == 2)
			{
				label[i][j]->setStyleSheet(files->colorGrayBackground());
			}
			else
			{
				label[i][j]->setStyleSheet(files->colorWhiteBackground());
			}
		}
	}

	this->setLayout(layout);
	setCentralWidget(this);

	label[0][0]->setText(QString::fromUtf8("Hodnota v Kč"));
	label[1][0]->setText(QString::fromUtf8("méně než 350.000"));
	label[2][0]->setText(QString::fromUtf8("od 350.000 včetně"));
	label[3][0]->setText(QString::fromUtf8("od 700.000 včetně"));

	for (int i = 1; i < 14; i++)
	{
		label[0][i]->setText(QString("MIX ") + QString().number(i));
	}
}
