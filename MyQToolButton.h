#ifndef MYQTOOLBUTTON_H
#define MYQTOOLBUTTON_H

#include <QToolButton>

class MyQToolButton : public QToolButton
{
	Q_OBJECT
public:
	MyQToolButton()
	{
		number = new int;
		connect(this, SIGNAL(clicked()), this, SLOT(clickInt()));
	}
	void setNumber(int _number)
	{
		*number = _number;
	}
signals:
	void clicked(int);

protected:
	int *number;

protected slots:
	void clickInt()
	{
		emit clicked(*number);
	}

};

#endif // MYQTOOLBUTTON_H
