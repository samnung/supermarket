#include "sdownload.h"

SDownload::SDownload(const QUrl &url)
{
	qDebug() << "start sdownload";
	manager = new QNetworkAccessManager();
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(_downloadFinished(QNetworkReply*)));

	downloaded = false;
	request.setUrl(url);
}

void SDownload::_downloadFinished(QNetworkReply *data)
{
	downloaded = true;
	qDebug() << "downloading finished";

	file = new QByteArray(data->readAll().data());
	emit downloadFinished(file);

}

void SDownload::_downloadProgress( qint64 a, qint64 b )
{
	emit downloadProgress( a, b );
}

void SDownload::_timer()
{
	if ( downloaded == false )
	{
		QMessageBox::warning(NULL, APP_NAME, QString::fromUtf8("Nepodařilo se připojit k serveru."));
	}
	downloaded = false;
}
void SDownload::start()
{
	QTimer::singleShot(10 * 1000, this, SLOT(_timer()));
	manager->get(request);
	qDebug() << "starting download";
}

