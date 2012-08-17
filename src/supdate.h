#ifndef SUPDATE_H
#define SUPDATE_H

#include "define.h"
#include "sdownload.h"
#include "ui_updateAlert.h"
#include "ui_updateActual.h"
#include "ui_updateProgress.h"

class SUpdate : public QObject
{
	Q_OBJECT

public:
	explicit SUpdate();
	void checkForUpdate(int type);
private:
	QByteArray *file_actual;
	Ui::updateAlert *ui_alert;
	Ui::updateActual *ui_actual;
	Ui::updateProgress *ui_progress;

	QWidget *widget_alert;
	QWidget *widget_actual;
	QWidget *widget_progress;
	int _type;
	SDownload *download;

private slots:
	void clickSkipVersion();
	void clickRemindLater();
	void clickInstallUpdate();

public slots:
	void downloadedAppActual(QByteArray *);
	void checkForUpdate();
};

#endif // SUPDATE_H
