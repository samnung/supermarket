#ifndef FILES_CONTROL_H
#define FILES_CONTROL_H

#include "define.h"



class files_control : QObject
{
public:
	files_control();
//	bool checkWorkFolder();
	void loadActual();
	void loadData();

	QString pathMixPodrobnosti(int a)	{ return (dir_resources->path() + QDir::separator() + *xml_name_dir_database_png + QDir::separator() + *xml_mixs_name[a]); }
	QString pathImageSplash()			{ return (dir_resources->path() + QDir::separator() + *xml_name_splash_image); }
	QString pathImageInfo()				{ return (dir_resources->path() + QDir::separator() + *xml_name_info_icon); }
	QString pathImageIcon()				{ return (dir_resources->path() + QDir::separator() + *xml_name_app_icon); }

	QString titleDate()			{ return *xml_name_database_date; }

	QFont fontFrameTitle()		{ return QFont(QString("Arial"), 12); }
	QFont fontFrameText()		{ return QFont(QString("Arial"), 10); }
	QFont fontFrameSubtitle()	{ QFont font(QString("Arial"), 10); font.setBold(true); return font; }
	QFont fontTitleDate()		{ return QFont(QString("Arial"), 12); }
	QFont fontTitleMix()		{ QFont font(QString("Arial Black"), 15); font.setBold(true); font.setWeight(75); return font;}

	QString colorGrey() { return QString("color: rgb(73, 86, 79);"); }
	QString colorWhiteBackground() { return QString("background-color: rgb(255, 255, 255);"); }
	QString colorAntracite() { return QString("color: rgb(27, 122, 132);"); }
	QString colorGrayBackground() { return QString("background-color: rgb(235, 237, 236);"); }
	QString colorTitleAntraciteBackground() { return QString("color: rgb(255, 255, 255);\nbackground-color: rgb(0, 156, 181);"); }

	QString styleButtonsNormal()	{ return QString("background-color: rgb(237, 237, 237); border-top-color: rgb(0, 0, 0); border-bottom-color: rgb(0, 0, 0); border-left-color: rgb(0, 0, 0); border-right-color: rgb(0, 0, 0); color:rgb(0, 0, 0);"); }
	QString styleButtonsSelect()	{ return QString("background-color:rgba(27, 122, 132, 255); border-top-color: rgb(0, 0, 0); color:rgb(255, 255, 255);"); }

	QString a2QStr(QXmlStreamAttributes *att, QString str)	{ return QStringRef(att->value(str)).toString(); }
	int a2Int(QXmlStreamAttributes *att, QString str)		{ return QString(QStringRef(att->value(str)).toString()).toInt(); }

	QString getMixType(int mix_number)		{ return mix[mix_number].mix_type; }
	QString styleMixType(int mix_number)	{ return mix[mix_number].mix_type_styleSheet; }
	double PA(int mix) { return this->mix[mix].PA; }

	void dataToLabels(FRAME_WIDGET *frame[], int int_mix);
	void pricesToLabels(int mix, QLabel *label_1, QLabel *label_2, QLabel *label_3);
	QString sideText(int mix, int frame);

protected:
	void	hideEmptyLabels(FRAME_WIDGET *frame[], int int_mix, int a);


//	QDir	*dir_work;
//	QDir	*dir_apps;
	QDir	*dir_resources;

	QFile	*file_actual;
	QXmlStreamReader *xml_actual;

	QFile *file_database;
	QXmlStreamReader *xml_database;

	QString *xml_mixs_name[13];
	QXmlStreamAttributes *xml_actual_atrrs;

	int	*xml_version_app;
	int *xml_version_dat_png;
	int *xml_version_dat_xml;

	QString *xml_name_database;
	QString *xml_name_splash_image;
	QString *xml_name_info_icon;
	QString *xml_name_app_icon;
	QString *xml_name_dir_database_png;
	QString *xml_name_database_date;

	int actual_folder;
	int actual_mix;

	MIX mix[13];
	QNetworkReply *reply;

	void downloadFile(const QString *url, const QString *file);
protected slots:
	void finished();
};



#endif // FILES_CONTROL_H
