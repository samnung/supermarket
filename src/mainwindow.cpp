#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(files_control *files) : /*QMainWindow(parent) , */ui(new Ui::MainWindow)
{
	this->files = files;
	ui->setupUi(this);

	resize(minimumWidth(), minimumHeight());

	seznam_ = new seznam();
	PV = new long double(0);
	R = new double(0);
	T = new unsigned short int(0);
	popl = new double(0);
	popl_last = new double(0);
	vysledna_hodnota = new QString();

	ui->r_line->hide();
	ui->r_label_3->hide();

	ui->poplatek_line->hide();
	ui->skutecny_label->hide();
	ui->procento->hide();

	ui->poplatek_line->setText("0,00");

	//********** doplnovani comboboxu ************
	for(int i = 0; i < 13; i++)
	{
	   ui->r_combo->addItem(QString("MIX %1: %2 %3").arg(i+1).arg(files->PA(i),6, 'f', 2).arg("p.a.", 5));
	}
	ui->r_combo->addItem(QString::fromUtf8("Vlastní hodnota"));

	//********** dosazovani hodnot ************
	connect(this->ui->r_combo, SIGNAL(currentIndexChanged(int)), this , SLOT(rLineVlastniSelected(int)));
	connect(this->ui->pv_line, SIGNAL(textChanged(QString)), this , SLOT(setPV(QString)));
	connect(this->ui->t_line, SIGNAL(textChanged(QString)), this, SLOT(setT(QString)));
	connect(this->ui->r_line, SIGNAL(textChanged(QString)), this, SLOT(setR(QString)));
	connect(this, SIGNAL(anyValueChanged()), this, SLOT(calculate()));
	connect(this->ui->otaznik_button, SIGNAL(clicked()), this, SLOT(otaznikClick()));
	connect(this->ui->action_close_window, SIGNAL(triggered()), this, SLOT(close()));
	connect(this->ui->poplatek_check, SIGNAL(clicked()), this, SLOT(poplatekChecked()));
	connect(this->ui->poplatek_line, SIGNAL(textChanged(QString)), this, SLOT(setPopl(QString)));

	rLineVlastniSelected(1);

	this->setWindowTitle(APP_NAME);

	this->ui->otaznik_button->setIcon(QIcon(QPixmap(":/img/info.png")));
}

MainWindow::~MainWindow()
{
	delete ui;
	delete R;
	delete PV;
	delete T;
	delete seznam_;
}

void MainWindow::rLineVlastniSelected(int a)
{
	if (a == 13)//pokud je v comboboxu zvoleny "Vlastni hodnota"
	{
	   ui->r_line->show();								//odkryti r_line(vlastni hodnota)
	   ui->r_line->setFocus();						//focus na r_line (vlastni hodnota)
	   ui->r_line->setSelection(0,255);				//oznaceni celeho radku
	   ui->r_label_3->show();							//odkryti labelu (p.a.) vedle r_line (vlastni hodnoty)

	   ui->otaznik_button->hide();					//skryti tlacitka otaznik

	   setR(QString(""));								//nastaveni registru R na nulu
	}
	else
	{
	   ui->r_line->hide();								//skryti r_line(vlastni hodnota)
	   ui->r_label_3->hide();							//skryti labelu (p.a.)

	   ui->otaznik_button->show();					//odkryti tlacitka Otaznik

	   setR(files->PA(a));							//dosazeni zvolene aktualni hodnoty do registru R
	}
}

void MainWindow::setR(QString a) //prevede z QStringu a dosadi do registru R
{
	*R = a.toDouble();
	emit anyValueChanged();
}

void MainWindow::setR(double a) // dosadi do registru R
{
	*R = a;
	emit anyValueChanged();
}

void MainWindow::setPV(QString a) //prevede z QStringu a dosadi do registru PV
{
	*PV = a.toInt();
	//ui->pv_line->setText(QString("%L1").arg(a.toInt()));
	emit anyValueChanged();
}

void MainWindow::setT(QString a) //prevede z QStringu a dosadi do registru T
{
	*T = a.toInt();
	emit anyValueChanged();
}

void MainWindow::setPopl(QString a)
{
	*popl = a.toDouble();
	emit anyValueChanged();
}

void MainWindow::calculate() //provadi vypocet
{
	if ((QString(ui->poplatek_line->text()).toDouble() == 0.00))
	{
	   this->ui->skutecny_label->setText(QString::fromUtf8("Skutečná vložená částka"));
	}
	else
	{
	   this->ui->skutecny_label->setText(QString("%L1").arg(*PV * (1 - (*popl / 100)), 0, 'f', 2) + QString::fromUtf8(" Kč"));
	}
	*vysledna_hodnota = QString("%L1").arg(seznam_->vypocet(*PV, *R / 100, *T, *popl / 100),0,'f',2);
	ui->vysledny_label->setText(*vysledna_hodnota + QString::fromUtf8(" Kč"));


	resize(0, 0);
}

void MainWindow::otaznikClick()
{
	emit otaznikClicked(ui->r_combo->currentIndex());
}

void MainWindow::poplatekChecked()
{
	if (ui->poplatek_check->isChecked())
	{
	   ui->poplatek_line->show();
	   ui->skutecny_label->show();
	   ui->procento->show();
	   ui->poplatek_line->setText(QString::number(*popl_last));

	}
	else
	{
	   ui->poplatek_line->hide();
	   ui->skutecny_label->hide();
	   ui->procento->hide();
	   *popl_last = QString(ui->poplatek_line->text()).toDouble();
	   ui->poplatek_line->setText(QString("0"));
	   updateGeometry();
	   resize(0,0);
	}
	emit anyValueChanged();
}
//void MainWindow::resizeEvent(QResizeEvent *e)
//{
//	this->ui->vysledny_label->setText(QString::number(this->width()));

//}
