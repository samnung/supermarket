#include "splashscreen.h"

splashscreen::splashscreen()
{
	files = new files_control();

	label = new QLabel;
	label->setAttribute(Qt::WA_TranslucentBackground, true);				//pruhledny widget
	label->setWindowFlags(Qt::FramelessWindowHint);						//bez ramecku

	rect = new QRect(qApp->desktop()->screenGeometry());				// ziskání rozlišení obrazovky

	timer = new QTimer;
	timer->setInterval(1000);

	files->loadActual();
//	files->checkWorkFolder();

	pix = new QPixmap(files->pathImageSplash());

	label->setPixmap(*pix);
	label->setMask(pix->mask());
	label->setGeometry(((rect->right() + 1) / 2) - (pix->width() / 2),((rect->bottom() + 1) / 2) - (pix->height() / 2), pix->width(), pix->height());

	connect(timer, SIGNAL(timeout()), this, SLOT(finish()));

}
void splashscreen::show()
{
	label->show();
	timer->start();
}

void splashscreen::setTimer(int time) // nastaveni casovace a = ms
{
	timer->setInterval(time);
	timer->setSingleShot(true);
}

void splashscreen::finish()
{
	label->close();
	win = new window_control(files);
	win->showMainWindow();
	delete this;
}

splashscreen::~splashscreen()
{
	delete label;
	delete pix;
	delete timer;
	delete rect;
}
