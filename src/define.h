#ifndef DEFINE_H
#define DEFINE_H

#define APP_NAME "Supermarket"
#define APP_VERSION_INT 200
#define APP_VERSION_STRING "0.3b"
#define APP_CREATOR "Roman Kříž"

#define APP_MAIL "samnung@gmail.com"
#define APP_WWW "https://code.google.com/p/supermarket-app"
#define WEB_ACTUAL "http://pokus-samnung.wz.cz/supermarket/actual_version.xml"

#define FILE_XML_ACTUAL_NAME "actual.xml"
#define FILE_XML_DATABASE "database-20110630.xml"

#define FILE_IMAGE_SPLASH "splash.png"

#define PARTNERS "Partners"

#include <QDir>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>

#include <QMainWindow>
#include <QWidget>


#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QToolButton>

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>

#include <QtGui/QApplication>
#include <QPixmap>
#include <QLabel>
#include <QBitmap>
#include <QDesktopWidget>
#include <QRect>
#include <QTimer>

#include <QDesktopServices>
#include <QObject>

#include <QMouseEvent>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>
#include <QtGui/QMenuBar>
#include <QtGui/QMenu>
#include <QtGui/QAction>
#include <QShortcut>

#include <QNetworkReply>
#include <QList>
#include <QIODevice>
#include <QTemporaryFile>
#include <QRegExp>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>
#include <QDebug>
#include <QtWebKit/QWebView>


struct FRAME_WIDGET
{
	QGridLayout *layout;

	QLabel *title;
	QLabel *subtitle_left;
	QLabel *subtitle_right;

	QLabel *value[10];
	QLabel *text[10];
	QFrame *line[12];
	bool *showed[10];
};

struct FRAME
{
	QString text[10];
	double value[10];
	bool has_value[10];
	int count;
};

struct MIX
{
	FRAME frame[7];
	QString mix_type;
	QString mix_type_styleSheet;
	double price[3];
	double PA;
};

enum normal_force { NORMAL, FORCE };

#endif
