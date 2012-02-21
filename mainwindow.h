#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "seznam.h"
#include "prehled.h"
#include "podrobnosti.h"
#include "podrobnosti_adv.h"
#include "MyQMainWindow.h"
#include "define.h"


namespace Ui {
	class MainWindow;
}

class MainWindow : public MyQMainWindow
{
	Q_OBJECT
public:
	explicit	MainWindow(files_control *files, int _window_number = 0);
	~MainWindow();
	Ui::MainWindow	*ui;

private:
	seznam				*seznam_;

	long double			*PV;
	double				*R;
	unsigned short int	*T;
	double				*popl;
	double				*popl_last;
	QString				*vysledna_hodnota;
	files_control		*files;
	//virtual void resizeEvent(QResizeEvent *e);

private slots:
	void	rLineVlastniSelected(int a);
	void	calculate();
	void	setPV(QString a);
	void	setR(QString a);
	void	setR(double a);
	void	setT(QString a);
	void	setPopl(QString a);
	void	otaznikClick();
	void	poplatekChecked();

signals:
	void	anyValueChanged();
	void	otaznikClicked(int);
};

#endif // MAINWINDOW_H
