#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "define.h"
#include "window_control.h"

class splashscreen : public QObject
{
	Q_OBJECT
public:
	splashscreen();
	~splashscreen();
	void show();
	void setTimer(int a); /* nastaveni casovace v ms */

private:
	QLabel *label;
	QPixmap *pix;
	QRect *rect;
	QTimer *timer;

	window_control *win;
	files_control *files;
public slots:
	void finish();
};

#endif // SPLASHSCREEN_H
