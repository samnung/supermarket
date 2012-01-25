#ifndef OAPLIKACI_H
#define OAPLIKACI_H

#include "define.h"
#include "files_control.h"

namespace Ui {
	class oAplikaci;
}

class oAplikaci : public QWidget
{
	Q_OBJECT

public:
	explicit	oAplikaci(files_control *_files);
				~oAplikaci();

private:
	void setup();
	QGridLayout *mainLayout;
	QLabel *icon;
	QGridLayout *gridLayout;
	QLabel *nazev_label;
	QLabel *majitel_label;
	QLabel *verze_label;
	QSpacerItem *verticalSpacer;
	QLabel *kontakt_label;

	QFont *font1;
	QFont *font2;
	QFont *font3;
	QFont *font4;

};

#endif // OAPLIKACI_H
