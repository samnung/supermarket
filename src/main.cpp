#include <QtGui/QApplication>
#include "splashscreen.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	splashscreen *splash = new splashscreen();
	splash->setTimer(1500);
	splash->show();

	return app.exec();
}
