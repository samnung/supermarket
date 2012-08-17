#include "window_control.h"

window_control::window_control(files_control *_files)
{
	files = _files;
	ui_cenik = NULL;
	ui_prehled = NULL;
}

void window_control::showMainWindow()
{
	MainWindow *window = new MainWindow(files);
	if (window != NULL) {
		window->show();

		connect(window->ui->action_new_window, SIGNAL(triggered()), this, SLOT(showMainWindow()));
		connect(window, SIGNAL(windowClosing(void*)), this, SLOT(closeMainWindow(void*)));
		connect(window->ui->actionO_programu, SIGNAL(triggered()), this, SLOT(showOAplikaci()));
		connect(window->ui->actionO_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
		connect(window->ui->actionCen_k, SIGNAL(triggered()), this, SLOT(showCenik()));
		connect(window->ui->actionPrehled, SIGNAL(triggered()), this, SLOT(showPrehled()));
		connect(window->ui->actionPodrobnosti, SIGNAL(triggered()), this, SLOT(showPodrobnosti()));
		connect(window, SIGNAL(otaznikClicked(int)), this, SLOT(showPodrobnosti(int)));
		connect(window->ui->actionPodrobnosti_2, SIGNAL(triggered()), this, SLOT(showPodrobnostiPlus()));
		connect(window->ui->action_go_home, SIGNAL(triggered()), this, SLOT(goHome()));
		connect(window->ui->action_quit, SIGNAL(triggered()), qApp, SLOT(quit()));
		connect(window->ui->action_check_for_update, SIGNAL(triggered()), this, SLOT(action_checkForUpdateApp()));

		list_main_window.append(window);
	}
}

void window_control::closeMainWindow(void *window)
{
	list_main_window.removeOne((MainWindow*)window);
	((MainWindow*)window)->close();
	delete (MainWindow*)window;
}


void window_control::showOAplikaci()
{
	if (ui_oaplikaci != NULL) {
		ui_oaplikaci->show();
		ui_oaplikaci->activateWindow();
	}
	else {
		ui_oaplikaci = new oAplikaci();
		if (ui_oaplikaci != NULL) {
			ui_oaplikaci->show();
			connect(ui_oaplikaci, SIGNAL(windowClosing(void*)), this, SLOT(closeCenik(void*)));
		}
	}
}




void window_control::showPodrobnosti(int selected_mix)
{
	podrobnosti *window = new podrobnosti(files);
	if (window != NULL) {
		window->show();

		connect(window, SIGNAL(windowClosing(void*)), this, SLOT(closePodrobnosti(void*)));
		window->selectMix(selected_mix);

		list_podrobnosti.append(window);
	}
}
void window_control::closePodrobnosti(void *window)
{
	list_podrobnosti.removeOne((podrobnosti*)window);
	((podrobnosti*)window)->close();
	delete (podrobnosti*)window;
}



void window_control::showPodrobnostiPlus()
{
	podrobnosti_adv *window = new podrobnosti_adv(files);
	if (window != NULL) {
		window->show();

		connect(window, SIGNAL(windowClosing(void*)), this, SLOT(closePodrobnostiPlus(void*)));
		connect(window->actionNewWindow, SIGNAL(triggered()), this, SLOT(showPodrobnostiPlus()));

		list_podrobnosti_plus.append(window);
	}
}

void window_control::closePodrobnostiPlus(void * window)
{
	list_podrobnosti_plus.removeOne((podrobnosti_adv*)window);
	((podrobnosti_adv*)window)->close();
	delete (podrobnosti_adv*)window;
}


void window_control::showCenik()
{
	if (ui_cenik != NULL) {
		ui_cenik->show();
		ui_cenik->activateWindow();
	}
	else {
		ui_cenik = new cenik(files);
		if (ui_cenik != NULL) {
			ui_cenik->show();
			connect(ui_cenik, SIGNAL(windowClosing(void*)), this, SLOT(closeCenik(void*)));
		}
	}
}
void window_control::closeCenik(void *)
{
	ui_cenik->close();
	delete ui_cenik;
	ui_cenik = NULL;
}

void window_control::showPrehled()
{
	if (ui_prehled != NULL) {
		ui_prehled->show();
		ui_prehled->activateWindow();
	}
	else {
		ui_prehled = new prehled();
		if (ui_prehled != NULL) {
			ui_prehled->show();
			connect(ui_prehled, SIGNAL(windowClosing(void*)), this, SLOT(closePrehled(void*)));
		}
	}
}
void window_control::closePrehled(void*)
{
	ui_prehled->close();
	delete ui_prehled;
	ui_prehled = NULL;
}


void window_control::goHome() // otevre webovy prohlizec s adresou
{
	if (!QDesktopServices::openUrl(QUrl(APP_WWW)))
	{
		QMessageBox::warning(NULL , APP_NAME, tr("Nepodařilo se připojit k \"%1\"; nemáte přístup k internetu, nebo špatně nastaven webový prohlížeč").arg("https://code.google.com/p/supermarket"));
	}
}

void window_control::action_checkForUpdateApp()
{
	files->checkForUpdate(FORCE);
}
