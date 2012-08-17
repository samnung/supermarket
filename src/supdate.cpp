#include "supdate.h"

SUpdate::SUpdate()
{
}

void SUpdate::checkForUpdate()
{
	this->checkForUpdate(NORMAL);
}

void SUpdate::checkForUpdate(int type)
{
	download = new SDownload(QUrl(WEB_ACTUAL));

	if ( type == FORCE )
	{
		widget_progress = new QWidget;
		ui_progress = new Ui::updateProgress;
		ui_progress->setupUi(widget_progress);
		ui_progress->label->setText(QString::fromUtf8("Ověřuje se dostupnost aktualizací"));
		ui_progress->progressBar->setValue(1);
		ui_progress->progressBar->setMaximum(100);
		widget_progress->show();
	}

	connect(download, SIGNAL(downloadFinished(QByteArray *)), this, SLOT(downloadedAppActual(QByteArray*)));
	download->start();
	_type = type;


}

void SUpdate::downloadedAppActual(QByteArray *file)
{
	// "if ( _type == FORCE )" – podmínka pro vyžádanou aktualizaci...
	// při automatické kontrole se ukazuje jen upozornění, při vyžádané i potvrzení, že není
	if ( _type == FORCE )
		ui_progress->progressBar->setValue(50);

	file_actual = file;
	QDomDocument doc;
	doc.setContent(*file);

	qDebug() << file->data();

	// Vyparsování aktuální verze aplikace z xml soboru ze serveru
	QDomNode dom_app = doc.elementsByTagName("application").at(0);
	int version_app = dom_app.firstChildElement("int").firstChild().nodeValue().toInt(); // web. verze
	QString version_app_string = dom_app.firstChildElement("string").firstChild().nodeValue(); // web. verze - řetězec
	QString path = dom_app.firstChildElement("path").firstChild().nodeValue(); // cesta k nové aktualizaci
	QString notes = dom_app.firstChildElement("notes").firstChild().nodeValue(); // cesta k html souboru pro novinky v novější verzi

	qDebug() << "Actual local version: " << APP_VERSION_INT ;
	qDebug() << "Actual web version: " << version_app ;

	if ( _type == FORCE )
	{
		ui_progress->progressBar->setValue(100);
		widget_progress->close();
	}

	if ( version_app > APP_VERSION_INT ) // pokud je webová verze aktuálnější
	{
		widget_alert = new QWidget();
		ui_alert = new Ui::updateAlert();
		ui_alert->setupUi(widget_alert);
		ui_alert->notes->setUrl(notes);
		ui_alert->text->setText(QString::fromUtf8("Je k dispozici Supermarket %1 - máte %2. Přejete si nyní stáhnout aktualizaci?").arg(version_app_string).arg(APP_VERSION_STRING));

		connect(ui_alert->install_update, SIGNAL(clicked()), this, SLOT(clickInstallUpdate()));
		connect(ui_alert->skip_version, SIGNAL(clicked()), this, SLOT(clickSkipVersion()));
		connect(ui_alert->remind_later, SIGNAL(clicked()), this, SLOT(clickRemindLater()));

		widget_alert->show();
		widget_alert->activateWindow();
	}
	else if ( _type == FORCE ) // pokud se vyžádala aktualizace –> nutné potvrdit, že lokální verze je aktuální
	{
		widget_actual = new QWidget();
		ui_actual = new Ui::updateActual();
		ui_actual->setupUi(widget_actual);
		ui_actual->label_2->setText(QString::fromUtf8("Supermarket %1 je nejnovější dostupná verze").arg(APP_VERSION_STRING));
		widget_actual->show();
		widget_actual->activateWindow();
	}
}

void SUpdate::clickInstallUpdate()
{

}

void SUpdate::clickRemindLater()
{
	widget_alert->close();
	delete ui_alert;
	widget_alert->deleteLater();
}

void SUpdate::clickSkipVersion()
{

}
