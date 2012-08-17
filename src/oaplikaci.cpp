#include "oaplikaci.h"

oAplikaci::oAplikaci()
{
	setup();
	icon->setPixmap(QPixmap(":/img/icon.png"));
}

oAplikaci::~oAplikaci()
{
}
void oAplikaci::setup()
{
	resize(0, 0);

	font1 = new QFont("Arial", 20, false);
	font1->setBold(true);
	font2 = new QFont("Arial", 14);
	font3 = new QFont("Arial", 12);

	mainLayout = new QGridLayout(this);
	mainLayout->setSizeConstraint(QLayout::SetFixedSize);
	mainLayout->setContentsMargins(-1, 10, -1, 10);

	icon = new QLabel();
	icon->setScaledContents(false);
	icon->setAlignment(Qt::AlignCenter);

	mainLayout->addWidget(icon, 0, 0, 1, 3);

	gridLayout = new QGridLayout();
	gridLayout->setContentsMargins(10, 5, 10, 0);

	nazev_label = new QLabel(this);
	nazev_label->setFont(*font1);
	nazev_label->setAlignment(Qt::AlignCenter);

	gridLayout->addWidget(nazev_label, 0, 0, 1, 1);

	verze_label = new QLabel();
	verze_label->setFont(*font3);
	verze_label->setAlignment(Qt::AlignCenter);

	gridLayout->addWidget(verze_label, 1, 0, 1, 1);

	verticalSpacer = new QSpacerItem(15, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

	gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

	majitel_label = new QLabel();
	majitel_label->setFont(*font2);
	majitel_label->setAlignment(Qt::AlignCenter);

	gridLayout->addWidget(majitel_label, 3, 0, 1, 1);

	kontakt_label = new QLabel();
	kontakt_label->setFont(*font3);
	kontakt_label->setStyleSheet(QString::fromUtf8("color: rgb(150, 150, 150);"));
	kontakt_label->setFrameShadow(QFrame::Plain);
	kontakt_label->setTextFormat(Qt::AutoText);
	kontakt_label->setAlignment(Qt::AlignCenter);
	kontakt_label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

	gridLayout->addWidget(kontakt_label, 4, 0, 1, 1);

	mainLayout->addLayout(gridLayout, 1, 0, 1, 3);

	setWindowTitle("O Aplikaci");
	nazev_label->setText(APP_NAME);
	majitel_label->setText(QString::fromUtf8(APP_CREATOR));
	verze_label->setText(QString("verze ") + QString(APP_VERSION_STRING));
	kontakt_label->setText(APP_MAIL);
}
