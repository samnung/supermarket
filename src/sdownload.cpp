#include "sdownload.h"

SDownload::SDownload(const QUrl &url)
{
	manager = new QNetworkAccessManager();
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(_downloadFinished(QNetworkReply*)));

	request.setUrl(url);
	connect(manager->get(request), SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));

	file = new QTemporaryFile(QString(url.toString()).replace(QRegExp("[^:]+://[^:]*/([^?#/]+)"), "\\1"));
}

void SDownload::_downloadFinished(QNetworkReply *data)
{
	if ( file->open() )
	{
		file->write(data->readAll());
		emit downloadFinished(file);
	}
}

void SDownload::_downloadProgress( qint64 a, qint64 b )
{
	emit downloadProgress( a, b );
}
