#include "podrobnosti.h"

podrobnosti::podrobnosti(files_control *_files)
{
	files = _files;
	mix_previous = new int(-1);
	setup();
}

podrobnosti::~podrobnosti()
{
}

void podrobnosti::setup()
{
	this->resize(640, 480);
	centralWidget = new QWidget(this);
	centralWidgetLayout = new QGridLayout(centralWidget);
	centralWidgetLayout->setSpacing(0);
	centralWidgetLayout->setMargin(0);
	centralWidgetLayout->setContentsMargins(0, 0, 0, 0);

	layoutButtons = new QGridLayout();

	for(int i = 0; i < 13; i++)
	{
	   buttonArray[i] = new MyQToolButton();
	   buttonArray[i]->setText(QString::number(i+1));
	   buttonArray[i]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	   buttonArray[i]->setMinimumWidth(30);
	   buttonArray[i]->setNumber(i);
	   buttonArray[i]->setStyleSheet(files->styleButtonsNormal());
	   buttonArray[i]->setFont(QFont("Arial Black", 10));
	   connect(this->buttonArray[i], SIGNAL(clicked(int)), this, SLOT(selectMix(int)));
	   layoutButtons->addWidget(buttonArray[i], 0, i+2, 1, 1);
	}

	horizontalSpacer_buttons_left = new QSpacerItem(10, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
	horizontalSpacer_buttons_right = new QSpacerItem(10, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
	buttonPlus = new QToolButton();
	buttonMinus = new QToolButton();

	buttonPlus->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	buttonPlus->setMinimumWidth(30);

	buttonMinus->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	buttonMinus->setMinimumWidth(30);

	labelZoom = new QLabel("Zoom");
	labelMix = new QLabel("Mix:");

	buttonPlus->setText("+");
	buttonPlus->setFont(QFont("Arial Black", 10));
	buttonPlus->setStyleSheet(files->styleButtonsNormal());
	buttonMinus->setText("-");
	buttonMinus->setFont(QFont("Arial Black", 10));
	buttonMinus->setStyleSheet(files->styleButtonsNormal());

	labelZoom->setIndent(10);
	labelMix->setIndent(10);

	labelZoom->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	labelMix->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

	layoutButtons->addItem(horizontalSpacer_buttons_left, 0, 0, 1, 1);
	layoutButtons->addWidget(labelMix, 0, 1, 1, 1);
	layoutButtons->addItem(horizontalSpacer_buttons_right, 0, 15, 1, 1);
	layoutButtons->addWidget(labelZoom, 0, 16, 1, 1);
	layoutButtons->addWidget(buttonMinus, 0, 17, 1, 1);
	layoutButtons->addWidget(buttonPlus, 0, 18, 1, 1);

	centralWidgetLayout->addLayout(layoutButtons, 0, 0, 1, 1);

	connect(this->buttonMinus, SIGNAL(clicked()), this, SLOT(buttonMinusClick()));
	connect(this->buttonPlus, SIGNAL(clicked()), this, SLOT(buttonPlusClick()));

	Scene = new QGraphicsScene();
	View = new QGraphicsView(Scene);
	View->scale(0.5, 0.5);

	centralWidgetLayout->addWidget(View, 1 , 0 , 1 , 1);

	this->setCentralWidget(centralWidget);
}

void podrobnosti::buttonMinusClick()
{
	View->scale(0.9,0.9);
	View->update();
}

void podrobnosti::buttonPlusClick()
{
	View->scale(1.1,1.1);
	View->update();
}

void podrobnosti::selectMix(int a)
{
	delete Scene;
	this->setWindowTitle(QString("Podrobnosti mixu ") + QString::number(a+1));
	Scene = new QGraphicsScene();
	View->setScene(Scene);
	Scene->addPixmap(QPixmap(files->pathMixDetails(a)));
	//View->centerOn(0,0);
	View->update();
	View->setFocus();
	this->buttonArray[a]->setStyleSheet(files->styleButtonsSelect());
	if (*mix_previous != -1 && *mix_previous != a)
	{
	   buttonArray[*mix_previous]->setStyleSheet(files->styleButtonsNormal());
	}
	*mix_previous = a;
}
