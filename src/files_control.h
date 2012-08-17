#ifndef FILES_CONTROL_H
#define FILES_CONTROL_H

#include "define.h"
#include "supdate.h"

class files_control : QObject
{
public:
	explicit files_control();
	void loadActual();
	void loadData();

	/*
		Path methods - vrací cestu k náležitým souborům
	*/
	QString pathMixDetails(int a)		{ return (dir_resources->path() + QDir::separator() + *xml_name_dir_database_png + QDir::separator() + *xml_mixs_name[a]); }


	/*
		Date methods - vrací datum aktuality mixu
	*/
	QString titleDate()					{ return *xml_name_database_date; }

	/*
		Font methods - vrací QFont nastavený pro určitý typ textu
	*/
	QFont fontFrameTitle()				{ return QFont(QString("Arial"), 12); }
	QFont fontFrameText()				{ return QFont(QString("Arial"), 10); }
	QFont fontFrameSubtitle()			{ QFont font(QString("Arial"), 10); font.setBold(true); return font; }
	QFont fontTitleDate()				{ return QFont(QString("Arial"), 12); }
	QFont fontTitleMix()				{ QFont font(QString("Arial Black"), 15); font.setBold(true); font.setWeight(75); return font;}


	/*
		Color methods - vrací řetězec pro nastavení barvy
	*/
	QString colorGrey()						{ return QString("color: rgb(73, 86, 79);"); }
	QString colorWhiteBackground()			{ return QString("background-color: rgb(255, 255, 255);"); }
	QString colorAntracite()				{ return QString("color: rgb(27, 122, 132);"); }
	QString colorGrayBackground()			{ return QString("background-color: rgb(235, 237, 236);"); }
	QString colorTitleAntraciteBackground() { return QString("color: rgb(255, 255, 255);\nbackground-color: rgb(0, 156, 181);"); }

	/*
		Style methods - vrací řetězec pro nastavení StyleSheet
	*/
	QString styleButtonsNormal()	{ return QString("background-color: rgb(237, 237, 237); border-top-color: rgb(0, 0, 0); border-bottom-color: rgb(0, 0, 0); border-left-color: rgb(0, 0, 0); border-right-color: rgb(0, 0, 0); color:rgb(0, 0, 0);"); }
	QString styleButtonsSelect()	{ return QString("background-color:rgba(27, 122, 132, 255); border-top-color: rgb(0, 0, 0); color:rgb(255, 255, 255);"); }
	QString styleMixType(int mix_number)	{ return mix[mix_number].mix_type_styleSheet; }

	/*
		Converse methods - metody pro konverzi QXMLStreamAttributes na řetěze a
	*/
	QString a2qstr(QXmlStreamAttributes *att, QString str)	{ return QStringRef(att->value(str)).toString(); }
	int a2int(QXmlStreamAttributes *att, QString str)		{ return a2qstr(att,str).toInt(); }


	/*
		Get methods - metody pro přístup k datům
	*/
	QString mixType(int mix_number)		{ return mix[mix_number].mix_type; }
	double PA(int mix)						{ return this->mix[mix].PA; }
	QString sideText(int mix, int frame);


	void dataToLabels(FRAME_WIDGET *frame[], int int_mix);
	void pricesToLabels(int mix, QLabel *label_1, QLabel *label_2, QLabel *label_3);


	void checkForUpdate(int type);

protected:
	void	hideEmptyLabels(FRAME_WIDGET *frame[], int int_mix, int a);



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
	QString *xml_name_dir_database_png;
	QString *xml_name_database_date;

	int actual_folder;
	int actual_mix;

	MIX mix[13];
	SUpdate update;
};



#endif // FILES_CONTROL_H
