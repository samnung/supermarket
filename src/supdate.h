#ifndef SUPDATE_H
#define SUPDATE_H

#include "define.h"
#include "sdownload.h"
#include "ui_updateAlert.h"

class SUpdate : public QObject
{
	Q_OBJECT
public:
	explicit SUpdate();
	void checkForUpdate();
private:
	QTemporaryFile *file_actual;
	Ui::updateAlert *ui;
signals:
	void newVersionApp(QString);
public slots:
	void downloadedAppActual(QTemporaryFile *);
};

#endif // SUPDATE_H
