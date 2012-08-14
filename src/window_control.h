#ifndef WINDOW_CONTROL_H
#define WINDOW_CONTROL_H

#include "mainwindow.h"
#include "oaplikaci.h"
#include "files_control.h"
#include "cenik.h"
#include "define.h"

#include "ui_mainwindow.h"


class window_control  :  QObject
{
	Q_OBJECT
public:
	window_control(files_control *_files);
	~window_control() {}

private:
	files_control *files;

	QList <MainWindow*> list_main_window;
	MainWindow			*mainwin[10];
	bool				*mainwin_showed[10];
	bool				*mainwin_alloced[10];

	oAplikaci			*ui_oaplikaci;
	bool				*ui_oaplikaci_alloced;

	prehled				*ui_prehled;
	bool				*ui_prehled_alloced;

	cenik				*ui_cenik;
	bool				*ui_cenik_alloced;

	QList <podrobnosti*> list_podrobnosti;
	podrobnosti			*ui_podrobnosti[10];
	bool				*ui_podrobnosti_showed[10];
	bool				*ui_podrobnosti_alloced[10];

	QList<podrobnosti_adv*> list_podrobnosti_plus;
	podrobnosti_adv		*ui_podrobnosti_plus[10];
	bool				*ui_podrobnosti_plus_showed[10];
	bool				*ui_podrobnosti_plus_alloced[10];

	void				showSplashScreen(int timer);
	int					findFirstFree(bool *array[], int maximum);

private slots:
	void closeMainWindow(void *window);

	void showOAplikaci();

	void showPrehled();

	void showPodrobnosti(int index = 0);
	void closePodrobnosti(void *window);

	void showPodrobnostiPlus();
	void closePodrobnostiPlus(void*);

	void showCenik();

	void goHome();


public slots:
	void showMainWindow();

};

#endif // WINDOW_CONTROL_H
