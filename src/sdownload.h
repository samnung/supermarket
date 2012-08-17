#ifndef SDOWNLOAD_H
#define SDOWNLOAD_H

#include "define.h"

class SDownload : public QObject
{
	Q_OBJECT
public:
	explicit SDownload(const QUrl &url);
	~SDownload() {}
	void start();

private:
	QNetworkAccessManager  *manager;
	QNetworkRequest request;
	QByteArray *file;
	bool downloaded;

signals:
	void downloadFinished(QByteArray *);
	void downloadProgress(qint64,qint64);

private slots:
	void _downloadFinished(QNetworkReply *);
	void _downloadProgress(qint64,qint64);
public slots:
	void _timer();

};

#endif // SDOWNLOAD_H
