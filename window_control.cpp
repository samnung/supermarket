#include "window_control.h"

window_control::window_control(files_control *_files)
{
	files = _files;
	ui_oaplikaci_alloced = new bool(false);
	ui_prehled_alloced = new bool(false);
	ui_cenik_alloced = new bool(false);

	for(int i = 0; i < 10; i++)
	{
		mainwin_showed[i] = new bool(false);
		mainwin_alloced[i] = new bool(false);
		ui_podrobnosti_showed[i] = new bool(false);
		ui_podrobnosti_alloced[i] = new bool(false);
		ui_podrobnosti_plus_showed[i] = new bool(false);
		ui_podrobnosti_plus_alloced[i] = new bool(false);
	}
}

void window_control::showMainWindow()
{
	int a = findFirstFree(mainwin_showed, APP_WINDOW_MAX);
	if (a != -1) {
		if (*mainwin_alloced[a] == false)
		{
			mainwin[a] = new MainWindow(files, a);
			mainwin[a]->show();
			*mainwin_alloced[a] = true;
			*mainwin_showed[a] = true;

			connect(mainwin[a]->ui->action_new_window, SIGNAL(triggered()), this, SLOT(showMainWindow()));
			connect(mainwin[a], SIGNAL(windowClosed(int)), this, SLOT(closeMainWindow(int)));

			connect(mainwin[a]->ui->actionO_programu, SIGNAL(triggered()), this, SLOT(showOAplikaci()));
			connect(mainwin[a]->ui->actionO_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

			connect(mainwin[a]->ui->actionCen_k, SIGNAL(triggered()), this, SLOT(showCenik()));

			connect(mainwin[a]->ui->actionPrehled, SIGNAL(triggered()), this, SLOT(showPrehled()));

			connect(mainwin[a]->ui->actionPodrobnosti, SIGNAL(triggered()), this, SLOT(showPodrobnosti()));
			connect(mainwin[a], SIGNAL(otaznikClicked(int)), this, SLOT(showPodrobnosti(int)));

			connect(mainwin[a]->ui->actionPodrobnosti_2, SIGNAL(triggered()), this, SLOT(showPodrobnostiPlus()));

			connect(mainwin[a]->ui->action_go_home, SIGNAL(triggered()), this, SLOT(goHome()));

			connect(mainwin[a]->ui->action_quit, SIGNAL(triggered()), qApp, SLOT(quit()));
		}
		else
		{
			*mainwin_showed[a] = true;
			mainwin[a]->show();
			mainwin[a]->activateWindow();
		}
		mainwin[a]->show();
	}
}

void window_control::closeMainWindow(int a)
{
	*mainwin_showed[a] = false;
}


void window_control::showOAplikaci()
{
	if (*ui_oaplikaci_alloced == false)
	{
		ui_oaplikaci = new oAplikaci(files);
		ui_oaplikaci->show();
		*ui_oaplikaci_alloced = true;
	}
	else
	{
		ui_oaplikaci->show();
	}

}




int window_control::showPodrobnosti(int selected_mix)
{
	int index = findFirstFree(ui_podrobnosti_showed, APP_WINDOW_MAX);
	if (*ui_podrobnosti_alloced[index] == false)
	{
		ui_podrobnosti[index] = new podrobnosti(files, index);
		ui_podrobnosti[index]->show();
		*ui_podrobnosti_alloced[index] = true;
		*ui_podrobnosti_showed[index] = true;

		connect(ui_podrobnosti[index], SIGNAL(windowClosed(int)), this, SLOT(closePodrobnosti(int)));
	}
	else
	{
		ui_podrobnosti[index]->show();
		ui_podrobnosti[index]->activateWindow();
		*ui_podrobnosti_showed[index] = true;
	}
	ui_podrobnosti[index]->selectMix(selected_mix);

	return index;
}

void window_control::closePodrobnosti(int number)
{
	*ui_podrobnosti_showed[number] = false;
}



void window_control::showPodrobnostiPlus()
{
	int a = findFirstFree(ui_podrobnosti_plus_showed, APP_WINDOW_MAX);
	if (*ui_podrobnosti_plus_alloced[a] == false)
	{
		ui_podrobnosti_plus[a] = new podrobnosti_adv(files, a);
		ui_podrobnosti_plus[a]->show();
		*ui_podrobnosti_plus_alloced[a] = true;
		*ui_podrobnosti_plus_showed[a] = true;

		connect(ui_podrobnosti_plus[a]->actionNewWindow, SIGNAL(triggered()), this, SLOT(showPodrobnostiPlus()));
		connect(ui_podrobnosti_plus[a], SIGNAL(windowClosed(int)), this, SLOT(closePodrobnostiPlus(int)));
	}
	else
	{
		ui_podrobnosti_plus[a]->show();
		ui_podrobnosti_plus[a]->activateWindow();
		*ui_podrobnosti_plus_showed[a] = true;
	}
}

void window_control::closePodrobnostiPlus(int window)
{
	*ui_podrobnosti_plus_showed[window] = false;
}


void window_control::showCenik()
{
	if (*ui_cenik_alloced == false)
	{
		ui_cenik = new cenik(files);
		ui_cenik->show();
		*ui_cenik_alloced = true;
	}
	else
	{
		ui_cenik->show();
	}
}

void window_control::showPrehled()
{
	if (*ui_prehled_alloced == false)
	{
		ui_prehled = new prehled();
		ui_prehled->show();
		*ui_prehled_alloced = true;
	}
	else
	{
		ui_prehled->show();
	}
}

int window_control::findFirstFree(bool *array[], int maximum)
{
	for(int i = 0; i < maximum; i++)
	{
		if(*array[i] == false)
		{
			return i;
		}
	}
	QMessageBox::warning(NULL, APP_NAME, QString::fromUtf8("Dosažen maximální počet oken"));
	return -1;
}

void window_control::goHome() // otevre webovy prohlizec s adresou
{
	if (!QDesktopServices::openUrl(QUrl(APP_WWW)))
	{
		QMessageBox::warning(NULL, APP_NAME,tr("Nepodařilo se připojit k \"%1\"; nemáte přístup k internetu, nebo špatně nastaven webový prohlížeč")
							 .arg("https://code.google.com/p/supermarket"));
	}
}
