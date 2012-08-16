#include "supdate.h"

SUpdate::SUpdate()
{
}

void SUpdate::checkForUpdate()
{
	SDownload download(QUrl(WEB_ACTUAL));
	connect(&download, SIGNAL(downloadFinished(QTemporaryFile *)), this, SLOT(downloadedAppActual(const QTemporaryFile*)));
}

void SUpdate::downloadedAppActual(QTemporaryFile *file)
{
	file_actual = file;
	QDomDocument doc;
	doc.setContent(file);

	QDomNode dom_app = doc.elementsByTagName("application").at(0);
	int version_app = dom_app.firstChildElement("int").firstChild().nodeValue().toInt();
	QString path = dom_app.firstChildElement("path").firstChild().nodeValue();

	qDebug() << "Actual local version: " << APP_VERSION_INT ;
	qDebug() << "Actual web version: " << version_app ;

	if ( version_app > APP_VERSION_INT )
	{
		emit newVersionApp(path);
	}
}
