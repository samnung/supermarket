#ifndef PREHLED_H
#define PREHLED_H

#include <QWidget>

namespace Ui {
	class prehled;
}

class prehled : public QWidget
{
	Q_OBJECT

public:
	explicit prehled(QWidget *parent = 0);
	~prehled();
public slots:

private:
	Ui::prehled *ui_prehled;

};

#endif // PREHLED_H
