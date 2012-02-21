#ifndef CENIK_H
#define CENIK_H

#include "MyQMainWindow.h"
#include "define.h"
#include "files_control.h"


class cenik : public MyQMainWindow
{
public:
	cenik(files_control *_files);
private:
	void setup();

	QWidget *window;
	QGridLayout *layout;

	QFrame *lineV[14];
	QFrame *lineH[3];

	QLabel *label[4][14];
	QString *side_strings[4];

	files_control *files;
};

#endif // CENIK_H
