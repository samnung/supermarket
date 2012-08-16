#ifndef SDOWNLOAD_H
#define SDOWNLOAD_H

#include "define.h"

class SDownload : public QObject
{
	Q_OBJECT
public:
	explicit SDownload(const QUrl &url);
	~SDownload() {}
private:
	QNetworkAccessManager  *manager;
	QNetworkRequest request;
	QTemporaryFile *file;
signals:
	void downloadFinished(QTemporaryFile *);
	void downloadProgress(qint64,qint64);

private slots:
	void _downloadFinished(QNetworkReply *);
	void _downloadProgress(qint64,qint64);

};

#endif // SDOWNLOAD_H
