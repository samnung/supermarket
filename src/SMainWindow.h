#ifndef SMAINWINDOW_H
#define SMAINWINDOW_H

#include "define.h"

class SMainWindow : public QMainWindow
{
	Q_OBJECT
public:
	SMainWindow() {}
	virtual ~SMainWindow() {}
	virtual void closeEvent(QCloseEvent *e)
	{
	   emit windowClosing(this);
	   QMainWindow::closeEvent(e);
	}
signals:
	void windowClosing(void*);
};

#endif // SMAINWINDOW_H
