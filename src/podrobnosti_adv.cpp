#include "podrobnosti_adv.h"

podrobnosti_adv::podrobnosti_adv(files_control *_files)
{
	files = _files;

	mix_previous = new int(-1);
	mix_actual = new int(-1);

	setup();
	this->resize(800, 500);
	selectMix(0);
}

podrobnosti_adv::~podrobnosti_adv()
{
	delete centralwidget;
	delete centralWidgetLayout;

	delete horizontalSpacer_left;
	delete horizontalSpacer_middle_1;
	delete horizontalSpacer_middle_2;

	delete gridLayout_main;
	delete gridLayout_left;
	delete gridLayout_mid;

	delete verticalSpacer_top;
	delete verticalSpacer_left_1;
	delete verticalSpacer_left_4;
	delete verticalSpacer_right_1;
	delete verticalSpacer_right_2;
	delete verticalSpacer_left_2;
	delete verticalSpacer_left_3;

	delete scrollArea;
	delete scrollAreaWidgetContents;
}

void podrobnosti_adv::setup()
{
	centralwidget = new QWidget(this);

	centralWidgetLayout = new QGridLayout(centralwidget);
	centralWidgetLayout->setSpacing(0);
	centralWidgetLayout->setContentsMargins(0, 0, 0, 0);

	scrollArea = new QScrollArea(centralwidget);
	scrollArea->setFrameShape(QFrame::NoFrame);
	scrollArea->setFrameShadow(QFrame::Sunken);
	scrollArea->setLineWidth(0);
	scrollArea->setWidgetResizable(true);
	scrollArea->setAlignment(Qt::AlignTop);

	scrollAreaWidgetContents = new QWidget();
	scrollAreaWidgetContents->setStyleSheet(QString("background-color: rgb(226, 242, 246);"));

	gridLayout_main = new QGridLayout(scrollAreaWidgetContents);
	gridLayout_main->setSpacing(0);
	gridLayout_main->setContentsMargins(0, 0, 0, 0);

	gridLayout_left = new QGridLayout;
	gridLayout_left->setSpacing(0);

	gridLayout_mid = new QGridLayout;
	gridLayout_mid->setSpacing(0);

	gridLayout_right = new QGridLayout;
	gridLayout_right->setSpacing(0);

	frame[0] = new FRAME_WIDGET;
	setupFrame(frame[0], 6);
	frame[0]->title->setText(QString::fromUtf8("Simulovaná výkonnost portfolia"));
	frame[0]->subtitle_right->setText("%");
	gridLayout_left->addLayout(frame[0]->layout, 1, 0, 1, 1);

	frame[1] = new FRAME_WIDGET;
	setupFrame(frame[1], 8);
	frame[1]->title->setText(QString::fromUtf8("... v jednotlivých letech"));
	frame[1]->subtitle_right->setText("%");
	gridLayout_mid->addLayout(frame[1]->layout, 1, 0, 1, 1);

	frame[2] = new FRAME_WIDGET;
	setupFrame(frame[2]);
	frame[2]->title->setText(QString::fromUtf8("Složení portfolia podle fondů"));
	frame[2]->subtitle_left->setText("Fondy");
	frame[2]->subtitle_right->setText(QString::fromUtf8("Podíl na vl. kap. %"));
	gridLayout_left->addLayout(frame[2]->layout, 3, 0, 1, 1);

	frame[3] = new FRAME_WIDGET;
	setupFrame(frame[3]);
	frame[3]->title->setText(QString::fromUtf8("Složení portfolia podle tříd aktiv"));
	frame[3]->subtitle_left->setText("Fondy");
	frame[3]->subtitle_right->setText(QString::fromUtf8("Podíl na vl. kap. %"));
	gridLayout_mid->addLayout(frame[3]->layout, 3, 0, 1, 1);

	frame[4] = new FRAME_WIDGET;
	setupFrame(frame[4]);
	frame[4]->title->setText(QString::fromUtf8("Složení portfolia podle správců"));
	frame[4]->subtitle_left->setText(QString::fromUtf8("Správce"));
	frame[4]->subtitle_right->setText(QString::fromUtf8("Podíl na vl. kap. %"));
	gridLayout_left->addLayout(frame[4]->layout, 5, 0, 1, 1);

	gridLayout_main->addLayout(gridLayout_left, 1, 1, 1, 1);
	gridLayout_main->addLayout(gridLayout_mid, 1, 3, 1, 1);
	scrollArea->setWidget(scrollAreaWidgetContents);
	centralWidgetLayout->addWidget(scrollArea, 2, 0, 1, 1);

	title_layout = new QGridLayout();
	title_layout->setSpacing(0);
	title_layout->setSizeConstraint(QLayout::SetFixedSize);

	mix_date = new QLabel();
	mix_date->setFont(files->fontTitleDate());
	mix_date->setStyleSheet(files->colorTitleAntraciteBackground());
	mix_date->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
	mix_date->setIndent(18);
	mix_date->setText("DATE_LABEL");
	title_layout->addWidget(mix_date, 0, 1, 1, 1);

	mix_name = new QLabel();
	mix_name->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred));
	mix_name->setFont(files->fontTitleMix());
	mix_name->setStyleSheet(files->colorTitleAntraciteBackground());
	mix_name->setScaledContents(true);
	mix_name->setMargin(-1);
	mix_name->setIndent(20);
	mix_name->setText("PARTNERS_MIX_NUMBER_LABEL");
	title_layout->addWidget(mix_name, 0, 0, 1, 1);

	mix_type = new QLabel();
	mix_type->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
	mix_type->setFont(files->fontTitleDate());
	mix_type->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\nbackground-color: rgb(255, 255, 255);"));
	mix_type->setAlignment(Qt::AlignCenter);
	mix_type->setText(QString::fromUtf8("MIX_TYPE"));
	title_layout->addWidget(mix_type, 0, 3, 1, 1);

	title_verticalSpacer = new QSpacerItem(0, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

	title_layout->addItem(title_verticalSpacer, 0, 2, 1, 1);

	centralWidgetLayout->addLayout(title_layout, 1, 0, 1, 1);

	text_browsers_widget = new QWidget;
	text_browsers_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	text_browser_1_label = new QLabel;
	text_browser_1_label->setFont(files->fontFrameTitle());
	text_browser_1_label->setStyleSheet(files->colorAntracite() + files->colorGrayBackground());
	text_browser_1_label->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);
	text_browser_1_label->setIndent(10);
	text_browser_1_label->setMargin(0);
	text_browser_1_label->setWordWrap(true);
	text_browser_1_label->setText(QString::fromUtf8("Investiční profil klienta"));
	text_browser_1_label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

	text_browser_1_line = new QFrame();
	text_browser_1_line->setStyleSheet(files->colorAntracite());
	text_browser_1_line->setFrameShadow(QFrame::Plain);
	text_browser_1_line->setLineWidth(2);
	text_browser_1_line->setMidLineWidth(0);
	text_browser_1_line->setFrameShape(QFrame::HLine);
	text_browser_1_line->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

	text_browser_1 = new QTextBrowser();
	text_browser_1->setStyleSheet(files->colorGrey() + files->colorGrayBackground());
	text_browser_1->setFrameShape(QFrame::NoFrame);
	text_browser_1->setLineWidth(0);
	text_browser_1->setFont(files->fontFrameText());
	text_browser_1->setReadOnly(true);
	text_browser_1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	text_browser_1->setText("Text Text Text Text Text Text Text Text Text Text Text Text ");

	gridLayout_right->setContentsMargins(5, 10, 5, 0);
	gridLayout_right->setSizeConstraint(QLayout::SetNoConstraint);
	gridLayout_right->addWidget(text_browser_1_label, 0, 0, 1, 1);
	gridLayout_right->addWidget(text_browser_1_line, 1, 0, 1, 1);
	gridLayout_right->addWidget(text_browser_1, 2, 0, 1, 1);

	text_browser_2_label = new QLabel;
	text_browser_2_label->setFont(files->fontFrameTitle());
	text_browser_2_label->setStyleSheet(files->colorAntracite() + files->colorGrayBackground());
	text_browser_2_label->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);
	text_browser_2_label->setIndent(10);
	text_browser_2_label->setMargin(0);
	text_browser_2_label->setWordWrap(true);
	text_browser_2_label->setText(QString::fromUtf8("Poznámky"));
	text_browser_2_label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

	text_browser_2_line = new QFrame();
	text_browser_2_line->setStyleSheet(files->colorAntracite());
	text_browser_2_line->setFrameShadow(QFrame::Plain);
	text_browser_2_line->setLineWidth(2);
	text_browser_2_line->setMidLineWidth(0);
	text_browser_2_line->setFrameShape(QFrame::HLine);
	text_browser_1_line->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

	text_browser_2 = new QTextBrowser();
	text_browser_2->setStyleSheet(files->colorGrey() + files->colorGrayBackground());
	text_browser_2->setFrameShape(QFrame::NoFrame);
	text_browser_2->setLineWidth(0);
	text_browser_2->setFont(files->fontFrameText());
	text_browser_2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	text_browser_2->setText("Text Text Text Text Text Text Text Text Text Text Text Text ");

	gridLayout_right->setContentsMargins(5, 10, 5, 0);
	gridLayout_right->addWidget(text_browser_2_label, 4, 0, 1, 1);
	gridLayout_right->addWidget(text_browser_2_line, 5, 0, 1, 1);
	gridLayout_right->addWidget(text_browser_2, 6, 0, 1, 1);

	text_browsers_spacer_1 = new QSpacerItem(0, 5, QSizePolicy::Expanding, QSizePolicy::Fixed);
	gridLayout_right->addItem(text_browsers_spacer_1, 3, 0, 1, 1);

	text_browsers_spacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Preferred);
	gridLayout_right->addItem(text_browsers_spacer_2, 8, 0, 1, 1);


	text_browsers_widget->setLayout(gridLayout_right);
	text_browsers_widget->setStyleSheet(files->colorGrayBackground());

	gridLayout_main->addWidget(text_browsers_widget, 0, 5, 3, 1);

	//text_browsers_spacer_wide = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed);
	//gridLayout_main->addItem(text_browsers_spacer_wide, 2, 5, 1, 1);


	verticalSpacer_left_1 = new QSpacerItem(290, 0, QSizePolicy::Fixed, QSizePolicy::Fixed);

	gridLayout_left->addItem(verticalSpacer_left_1, 0, 0, 1, 1);

	verticalSpacer_left_2 = new QSpacerItem(20, 63, QSizePolicy::Minimum, QSizePolicy::Fixed);

	gridLayout_left->addItem(verticalSpacer_left_2, 2, 0, 1, 1);

	verticalSpacer_left_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

	gridLayout_left->addItem(verticalSpacer_left_3, 4, 0, 1, 1);

	verticalSpacer_left_4 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

	gridLayout_left->addItem(verticalSpacer_left_4, 6, 0, 1, 1);


	verticalSpacer_right_1 = new QSpacerItem(290, 25, QSizePolicy::Fixed, QSizePolicy::Fixed);

	gridLayout_mid->addItem(verticalSpacer_right_1, 2, 0, 1, 1);

	verticalSpacer_right_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

	gridLayout_mid->addItem(verticalSpacer_right_2, 4, 0, 1, 1);


	verticalSpacer_top = new QSpacerItem(0, 10, QSizePolicy::Ignored, QSizePolicy::Fixed);

	gridLayout_main->addItem(verticalSpacer_top, 0, 1, 1, 1);


	horizontalSpacer_left = new QSpacerItem(10, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored);

	gridLayout_main->addItem(horizontalSpacer_left, 1, 0, 1, 1);


	horizontalSpacer_middle_1 = new QSpacerItem(10, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored);

	gridLayout_main->addItem(horizontalSpacer_middle_1, 1, 2, 1, 1);

	horizontalSpacer_middle_2 = new QSpacerItem(10, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored);

	gridLayout_main->addItem(horizontalSpacer_middle_2, 1, 4, 1, 1);

	verticalSpacer_bottom = new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::Expanding);

	gridLayout_main->addItem(verticalSpacer_bottom, 2, 1, 1, 1);


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


	labelMix = new QLabel("Mix:");
	labelMix->setIndent(10);
	labelMix->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

	layoutButtons->addItem(horizontalSpacer_buttons_left, 0, 0, 1, 1);
	layoutButtons->addWidget(labelMix, 0, 1, 1, 1);
	layoutButtons->addItem(horizontalSpacer_buttons_right, 0, 15, 1, 1);

	centralWidgetLayout->addLayout(layoutButtons, 0, 0, 1, 1);

	actionNewWindow = new QAction(this);
	actionNewWindow->setText(QString::fromUtf8("Nové okno"));
	actionNewWindow->setShortcut(QApplication::translate("podrobnosti_adv", "Ctrl+N", 0, QApplication::UnicodeUTF8));
	actionCloseWindow = new QAction(this);
	actionCloseWindow->setText(QString::fromUtf8("Zavřít okno"));
	actionCloseWindow->setShortcut(QKeySequence("Ctrl+W"));

	connect(this->actionCloseWindow, SIGNAL(triggered()), this, SLOT(close()));

	menuBar = new QMenuBar(this);
	menuFile = new QMenu(menuBar);
	menuFile->setTitle("Soubor");
	menuFile->addAction(actionNewWindow);
	menuFile->addAction(actionCloseWindow);

	menuBar->addAction(menuFile->menuAction());

	this->setMenuBar(menuBar);
	this->mix_date->setText(files->titleDate());

	this->setCentralWidget(centralwidget);

	scrollArea->raise();
}

void podrobnosti_adv::selectMix(int a)
{
	*mix_actual = a;

	this->mix_name->setText(QString(PARTNERS) + QString(" MIX ") + QString::number(a+1));
	this->setWindowTitle(QString("Podrobnosti mixu ") + QString::number(a+1));
	files->dataToLabels(frame, a);

	this->mix_type->setText(files->mixType(a));
	this->mix_type->setStyleSheet(files->styleMixType(a));
	this->buttonArray[a]->setStyleSheet(files->styleButtonsSelect());

	this->text_browser_1->setText(files->sideText(a, 5));
	this->text_browser_2->setText(files->sideText(a, 6));
	if (*mix_previous != -1 && *mix_previous != a)
	{
	   buttonArray[*mix_previous]->setStyleSheet(files->styleButtonsNormal());
	}
	*mix_previous = a;


}

void podrobnosti_adv::setupFrame(FRAME_WIDGET *frame, int count)
{
	frame->layout = new QGridLayout;
	frame->layout->setSpacing(0);

		   /* TITLE */

	frame->title = new QLabel;
	frame->title->setFont(files->fontFrameTitle());
	frame->title->setStyleSheet(files->colorAntracite());
	frame->title->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);
	frame->title->setIndent(10);
	frame->title->setMargin(0);
	frame->title->setWordWrap(true);

	frame->layout->addWidget(frame->title, 0, 0, 1, 3);

		   /* SUBTITLE */

	frame->subtitle_left = new QLabel;
	frame->subtitle_left->setFont(files->fontFrameSubtitle());
	frame->subtitle_left->setStyleSheet(files->colorGrey());
	frame->subtitle_left->setIndent(10);
	frame->subtitle_left->setMargin(0);

	frame->layout->addWidget(frame->subtitle_left, 2, 0, 1, 1);

	frame->subtitle_right = new QLabel;
	frame->subtitle_right->setFont(files->fontFrameSubtitle());
	frame->subtitle_right->setStyleSheet(files->colorGrey());
	frame->subtitle_right->setIndent(10);
	frame->subtitle_right->setMargin(0);
	frame->subtitle_right->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

	frame->layout->addWidget(frame->subtitle_right, 2, 1, 1, 2);

		   /* TEXTS & VALUES */
	for (int i = 0; i < 10; i++)
	   frame->showed[i] = new bool(false);

	for(int i = 0, j = 4; i < count; i++, j += 2)
	{
	   frame->text[i] = new QLabel("NO_TEXT");
	   frame->text[i]->setFont(files->fontFrameText());
	   frame->text[i]->setStyleSheet(files->colorGrey());
	   frame->text[i]->setIndent(10);
	   frame->text[i]->setMargin(0);
	   frame->text[i]->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

	   frame->layout->addWidget(frame->text[i], j, 0, 1, 2);

	   frame->value[i] = new QLabel("NO_VALUE");
	   frame->value[i]->setFont(files->fontFrameText());
	   frame->value[i]->setStyleSheet(files->colorGrey());
	   frame->value[i]->setIndent(10);
	   frame->value[i]->setMargin(0);
	   frame->value[i]->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
	   frame->value[i]->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);
	   frame->value[i]->setMaximumWidth(50);

	   frame->layout->addWidget(frame->value[i], j, 2, 1, 1);

	   *(frame->showed[i]) = true;
	}

		   /* LINES */

	for(int i = 0, j = 1; i < count + 2; i++, j += 2)
	{
	   frame->line[i] = new QFrame;
	   frame->line[i]->setStyleSheet(files->colorGrey());
	   frame->line[i]->setFrameShadow(QFrame::Plain);
	   frame->line[i]->setLineWidth(1);
	   frame->line[i]->setMidLineWidth(0);
	   frame->line[i]->setFrameShape(QFrame::HLine);

	   frame->layout->addWidget(frame->line[i], j, 0, 1, 3);
	}

	frame->line[0]->setStyleSheet(files->colorAntracite());
	frame->line[0]->setLineWidth(2);
	frame->line[1]->setLineWidth(2);
	frame->line[count+1]->setStyleSheet(files->colorAntracite());
	frame->line[count+1]->setLineWidth(2);
}

