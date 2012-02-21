#ifndef PODROBNOSTI_ADV_H
#define PODROBNOSTI_ADV_H

#include "MyQToolButton.h"
#include "MyQMainWindow.h"
#include "define.h"
#include "files_control.h"



class podrobnosti_adv : public MyQMainWindow
{
    Q_OBJECT

public:
	explicit podrobnosti_adv(files_control *_files, int number);
    ~podrobnosti_adv();
	QAction *actionNewWindow;
	QAction *actionCloseWindow;

private:
    void setup();
	void setupFrame(FRAME_WIDGET *frame, int count = 10);

    QWidget *centralwidget;

    QGridLayout *centralWidgetLayout;

    QScrollArea *scrollArea;

    QWidget *scrollAreaWidgetContents;

    QGridLayout *gridLayout_main;
    QGridLayout *gridLayout_left;
	QGridLayout *gridLayout_mid;
	QGridLayout *gridLayout_right;

	QSpacerItem *verticalSpacer_top;
	QSpacerItem *verticalSpacer_bottom;
	QSpacerItem *verticalSpacer_left_1;
	QSpacerItem *horizontalSpacer_left;
	QSpacerItem *verticalSpacer_left_4;
	QSpacerItem *horizontalSpacer_middle_1;
	QSpacerItem *horizontalSpacer_middle_2;
	QSpacerItem *verticalSpacer_right_1;
	QSpacerItem *verticalSpacer_right_2;
	QSpacerItem *verticalSpacer_left_2;
	QSpacerItem *verticalSpacer_left_3;

    QSpacerItem *title_verticalSpacer;
    QGridLayout *title_layout;

    QLabel *mix_date;
    QLabel *mix_name;
    QLabel *mix_type;

	FRAME_WIDGET *frame[5];

	QWidget *text_browsers_widget;
	QLabel *text_browser_1_label;
	QFrame *text_browser_1_line;
	QTextBrowser *text_browser_1;
	QLabel *text_browser_2_label;
	QFrame *text_browser_2_line;
	QTextBrowser *text_browser_2;

	QSpacerItem *text_browsers_spacer_1;
	QSpacerItem *text_browsers_spacer_2;
	QSpacerItem *text_browsers_spacer_wide;

	QMenuBar *menuBar;
	QMenu *menuFile;

	QGridLayout *layoutButtons;
	MyQToolButton *buttonArray[13];
	QSpacerItem *horizontalSpacer_buttons_left;
	QSpacerItem *horizontalSpacer_buttons_right;
	QLabel	*labelMix;

	files_control *files;

	int *mix_previous;
	int *mix_actual;

private slots:
	void selectMix(int a);
};

#endif // PODROBNOSTI_ADV_H
