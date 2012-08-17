/* !!! UTF-8 !!! 2012-08-14 */
#include "files_control.h"

files_control::files_control()
{
	dir_resources = new QDir(QDir::currentPath());

#ifdef Q_OS_MAC
	dir_resources->cdUp();
	dir_resources->cd("Resources");
#elif defined Q_OS_WIN
	dir_resources->cd("resources");
#endif
	file_actual = new QFile(dir_resources->path() + QDir::separator() + QString(FILE_XML_ACTUAL_NAME));
	xml_actual = new QXmlStreamReader(file_actual);


	xml_name_dir_database_png = new QString;
	xml_name_database_date = new QString;

	for(int i = 0; i < 13; i++)
	{
		xml_mixs_name[i] = new QString;
	}
	xml_actual_atrrs = new QXmlStreamAttributes;
	xml_name_database = new QString;
	xml_version_app = new int;
	xml_version_dat_png = new int;
	xml_version_dat_xml = new int;

	for (int int_mix = 0; int_mix < 13; int_mix++)
	{
		for (int int_frame = 0; int_frame < 5; int_frame++)
		{
			mix[int_mix].frame[int_frame].count = -1;
			for (int int_line = 0; int_line < 10; int_line++)
			{
				mix[int_mix].frame[int_frame].has_value[int_line] = false;
				mix[int_mix].frame[int_frame].value[int_line] = 0.00;
				mix[int_mix].frame[int_frame].text[int_line] = "NO_TEXT";
			}
		}
	}
}

void files_control::loadActual()
{
	if(file_actual->open(QFile::ReadOnly))
	{
		while (!xml_actual->atEnd())
		{
			xml_actual->readNextStartElement();
			*xml_actual_atrrs = xml_actual->attributes();

			if (xml_actual->name() == "version")
			{
				if (a2qstr(xml_actual_atrrs, "type") == "application")
				{
					*xml_version_app = QString(xml_actual->readElementText()).toInt();
				}
				else if (a2qstr(xml_actual_atrrs, "type") == "database_png")
				{
					*xml_version_dat_png = QString(xml_actual->readElementText()).toInt();
				}
				else if (a2qstr(xml_actual_atrrs, "type") == "database_xml")
				{
					*xml_version_dat_xml = QString(xml_actual->readElementText()).toInt();
				}
			}
			else if (xml_actual->name() == "name")
			{
				if (a2qstr(xml_actual_atrrs, "type") == "database_xml")
				{
					*xml_name_database = xml_actual->readElementText();
				}
				else if (a2qstr(xml_actual_atrrs, "type") == "database_xml_date")
				{
					*xml_name_database_date = xml_actual->readElementText();
				}
				else if (a2qstr(xml_actual_atrrs, "type") == "database_png")
				{
					*xml_name_dir_database_png = xml_actual->readElementText();
				}
				else if (a2qstr(xml_actual_atrrs, "type") == "mix")
				{
					*xml_mixs_name[QString(a2qstr(xml_actual_atrrs, "id")).toInt() - 1] = xml_actual->readElementText();
				}
			}
		}
		file_actual->close();

		file_database = new QFile;
		file_database->setFileName(dir_resources->path() + QDir::separator() + *xml_name_database);
		xml_database = new QXmlStreamReader(file_database);

		loadData();
	}
}

void files_control::loadData()
{
	if (file_database->open(QFile::ReadOnly))
	{
		while (!xml_database->atEnd())
		{
			*xml_actual_atrrs = xml_database->attributes();
			if (xml_database->name() == "mix")
			{
				actual_mix = a2int(xml_actual_atrrs, "ID") - 1;
				if (actual_mix != -1)
				{
					mix[actual_mix].mix_type = a2qstr(xml_actual_atrrs, "type");
					mix[actual_mix].mix_type_styleSheet = a2qstr(xml_actual_atrrs, "color");
				}
			}
			else if (xml_database->name() == "folder")
			{
				actual_folder = a2int(xml_actual_atrrs, "ID") - 1;
				if (actual_folder != -1 && actual_mix != -1)
				{
					mix[actual_mix].frame[actual_folder].count = a2int(xml_actual_atrrs, "count");
				}
			}
			else if (xml_database->name() == "item")
			{
				if (actual_folder != -1 && actual_mix != -1)
				{
					if (actual_folder == 5 || actual_folder == 6)
					{
						mix[actual_mix].frame[actual_folder].text[a2int(xml_actual_atrrs, "ID") - 1] = xml_database->readElementText();
						mix[actual_mix].frame[actual_folder].has_value[a2int(xml_actual_atrrs, "ID") - 1] = true;
					}
					else
					{
						mix[actual_mix].frame[actual_folder].value[a2int(xml_actual_atrrs, "ID") - 1] = QString(xml_database->readElementText()).toDouble();
						mix[actual_mix].frame[actual_folder].text[a2int(xml_actual_atrrs, "ID") - 1] = a2qstr(xml_actual_atrrs, "name");
						mix[actual_mix].frame[actual_folder].has_value[a2int(xml_actual_atrrs, "ID") - 1] = true;
					}
				}
			}
			else if (xml_database->name() == "price")
			{
				if (actual_mix != -1)
				{
					mix[actual_mix].price[a2int(xml_actual_atrrs, "ID") - 1] = QString(xml_database->readElementText()).toDouble();
				}
			}
			xml_database->readNextStartElement();
		}
		file_database->close();
		for (int i = 0; i < 13; i++)
		{
			if (mix[i].frame[0].value[5] != 0.00)
			{
				mix[i].PA = mix[i].frame[0].value[5];
			}
			else if (mix[i].frame[0].value[4] != 0.00)
			{
				mix[i].PA = mix[i].frame[0].value[4];
			}
			else if (mix[i].frame[0].value[3] != 0.00)
			{
				mix[i].PA = ((mix[i].frame[0].value[3] + mix[i].frame[0].value[2]) / 2);
			}
			else if (mix[i].frame[0].value[2] != 0.00)
			{
				mix[i].PA = ((mix[i].frame[0].value[2] + mix[i].frame[0].value[1]) / 2);
			}
			else if (mix[i].frame[0].value[1] != 0.00)
			{
				mix[i].PA = ((mix[i].frame[0].value[1] + mix[i].frame[0].value[0]) / 2);
			}
		}
	}
}

void files_control::dataToLabels(FRAME_WIDGET *frame[], int int_mix)
{
	for (int int_frame = 0; int_frame < 5; int_frame++)
	{
		frame[int_frame]->text[0]->show();
		frame[int_frame]->value[0]->show();
		frame[int_frame]->line[2]->show();
		for (int i = 0; i < mix[int_mix].frame[int_frame].count; i++)
		{
			frame[int_frame]->text[i]->setText(mix[int_mix].frame[int_frame].text[i]);
			if (mix[int_mix].frame[int_frame].value[i] != 0.00)
			{
				frame[int_frame]->value[i]->setText(QString("%L1").arg(mix[int_mix].frame[int_frame].value[i], 0, 'f', 2));
			}
			else
			{
				frame[int_frame]->value[i]->setText(QString("N/A"));
			}
		}
	}
	hideEmptyLabels(frame, int_mix, 2);
	hideEmptyLabels(frame, int_mix, 3);
	hideEmptyLabels(frame, int_mix, 4);
}

void files_control::hideEmptyLabels(FRAME_WIDGET *frame[], int int_mix, int int_frame)
{
	for (int i = 0; i < mix[int_mix].frame[int_frame].count; i++)
	{
		frame[int_frame]->text[i]->show();
		frame[int_frame]->value[i]->show();
	}
	for (int i = mix[int_mix].frame[int_frame].count; i < 10 ; i++)
	{
		frame[int_frame]->text[i]->hide();
		frame[int_frame]->value[i]->hide();
	}
	for (int i = 0; i < mix[int_mix].frame[int_frame].count - 1; i++)
		frame[int_frame]->line[i+2]->show();

	for (int i = mix[int_mix].frame[int_frame].count - 1; i < 9; i++)
		frame[int_frame]->line[i+2]->hide();

}

QString files_control::sideText(int mix, int frame)
{
	QString vysledek;
	for (int i = 0; i < this->mix[mix].frame[frame].count - 1; i++)
	{
		vysledek += this->mix[mix].frame[frame].text[i] + QString("\n\n");
	}
	vysledek += this->mix[mix].frame[frame].text[this->mix[mix].frame[frame].count - 1];
	return vysledek;
}

void files_control::pricesToLabels(int mix, QLabel *label_1, QLabel *label_2, QLabel *label_3)
{
	label_1->setText(QString("%L1").arg(this->mix[mix].price[0], 0, 'f', 2) + QString("%"));
	label_2->setText(QString("%L1").arg(this->mix[mix].price[1], 0, 'f', 2) + QString("%"));
	label_3->setText(QString("%L1").arg(this->mix[mix].price[2], 0, 'f', 2) + QString("%"));
}

void files_control::checkForUpdate(int type)
{
	update.checkForUpdate(type);
}
