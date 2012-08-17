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
	oAplikaci			*ui_oaplikaci;
	prehled				*ui_prehled;
	cenik				*ui_cenik;
	QList <podrobnosti*> list_podrobnosti;
	QList<podrobnosti_adv*> list_podrobnosti_plus;

	void				showSplashScreen(int timer);

private slots:
	void closeMainWindow(void *window);

	void showOAplikaci();

	void showPrehled();
	void closePrehled(void*);

	void showPodrobnosti(int index = 0);
	void closePodrobnosti(void *window);

	void showPodrobnostiPlus();
	void closePodrobnostiPlus(void*);

	void showCenik();
	void closeCenik(void*);

	void goHome();

	void action_checkForUpdateApp();


public slots:
	void showMainWindow();

signals:
	void checkForUpdateApp();

};

#endif // WINDOW_CONTROL_H
