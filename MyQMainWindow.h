#ifndef MYQMAINWINDOW_H
#define MYQMAINWINDOW_H

#include <QMainWindow>

class MyQMainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MyQMainWindow()
	{
		window_number = new int;
	}
	void setWindowNumber(int _number)
	{
		*window_number = _number;
	}
	int windowNumber()
	{
		return *window_number;
	}
	virtual void closeEvent(QCloseEvent *e)
	{
		emit windowClosed(*window_number);
		QMainWindow::closeEvent(e);
	}

protected:
	int *window_number;

signals:
	void windowClosed(int);
};

#endif // MYQMAINWINDOW_H
