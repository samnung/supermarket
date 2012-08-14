#ifndef PODROBNOSTI_H
#define PODROBNOSTI_H

#include <QWidget>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QScrollBar>
#include <QSpacerItem>
#include "files_control.h"
#include "MyQToolButton.h"
#include "SMainWindow.h"

class podrobnosti : public SMainWindow
{
	Q_OBJECT

public:
	explicit podrobnosti(files_control *_files);
	~podrobnosti();
	void setup();
public slots:
	void selectMix(int a);

private:
	QGraphicsScene *Scene;
	QGraphicsView *View;
	int *mix_previous;

	QWidget	*centralWidget;
	QGridLayout *centralWidgetLayout;

	QGridLayout *layoutButtons;
	MyQToolButton *buttonArray[13];

	QToolButton *buttonPlus;
	QToolButton *buttonMinus;
	QLabel	*labelZoom;
	QLabel	*labelMix;

	QSpacerItem *horizontalSpacer_buttons_left;
	QSpacerItem *horizontalSpacer_buttons_right;

	files_control *files;
private slots:
	void buttonPlusClick();
	void buttonMinusClick();
};
#endif // PODROBNOSTI_H


