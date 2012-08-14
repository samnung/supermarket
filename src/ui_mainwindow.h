/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Aug 14 08:56:00 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_quit;
    QAction *action_new_window;
    QAction *action_close_window;
    QAction *actionO_programu;
    QAction *actionO_Qt;
    QAction *actionPrehled;
    QAction *actionPodrobnosti;
    QAction *action_go_home;
    QAction *actionMail;
    QAction *actionPodrobnosti_2;
    QAction *actionCen_k;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *pv_label_1;
    QLabel *pv_label_2;
    QCheckBox *poplatek_check;
    QLineEdit *poplatek_line;
    QLabel *procento;
    QLabel *skutecny_label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *t_label_1;
    QLabel *t_label_2;
    QLabel *r_label_1;
    QToolButton *otaznik_button;
    QLineEdit *pv_line;
    QLineEdit *t_line;
    QComboBox *r_combo;
    QLineEdit *r_line;
    QLabel *r_label_3;
    QLabel *vysledny_label;
    QMenuBar *menuBar;
    QMenu *menuSoubor;
    QMenu *menuZobrazit;
    QMenu *menuN_pov_da;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(559, 142);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setIconSize(QSize(24, 24));
        MainWindow->setAnimated(true);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Triangular);
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks|QMainWindow::VerticalTabs);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        action_quit = new QAction(MainWindow);
        action_quit->setObjectName(QString::fromUtf8("action_quit"));
        action_quit->setMenuRole(QAction::QuitRole);
        action_new_window = new QAction(MainWindow);
        action_new_window->setObjectName(QString::fromUtf8("action_new_window"));
        action_close_window = new QAction(MainWindow);
        action_close_window->setObjectName(QString::fromUtf8("action_close_window"));
        actionO_programu = new QAction(MainWindow);
        actionO_programu->setObjectName(QString::fromUtf8("actionO_programu"));
        actionO_programu->setMenuRole(QAction::AboutRole);
        actionO_Qt = new QAction(MainWindow);
        actionO_Qt->setObjectName(QString::fromUtf8("actionO_Qt"));
        actionO_Qt->setCheckable(false);
        actionO_Qt->setMenuRole(QAction::AboutQtRole);
        actionPrehled = new QAction(MainWindow);
        actionPrehled->setObjectName(QString::fromUtf8("actionPrehled"));
        actionPodrobnosti = new QAction(MainWindow);
        actionPodrobnosti->setObjectName(QString::fromUtf8("actionPodrobnosti"));
        action_go_home = new QAction(MainWindow);
        action_go_home->setObjectName(QString::fromUtf8("action_go_home"));
        actionMail = new QAction(MainWindow);
        actionMail->setObjectName(QString::fromUtf8("actionMail"));
        actionPodrobnosti_2 = new QAction(MainWindow);
        actionPodrobnosti_2->setObjectName(QString::fromUtf8("actionPodrobnosti_2"));
        actionCen_k = new QAction(MainWindow);
        actionCen_k->setObjectName(QString::fromUtf8("actionCen_k"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(7);
        gridLayout->setVerticalSpacing(8);
        pv_label_1 = new QLabel(centralWidget);
        pv_label_1->setObjectName(QString::fromUtf8("pv_label_1"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pv_label_1->sizePolicy().hasHeightForWidth());
        pv_label_1->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(11);
        pv_label_1->setFont(font);
        pv_label_1->setFocusPolicy(Qt::NoFocus);
        pv_label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(pv_label_1, 0, 0, 1, 1);

        pv_label_2 = new QLabel(centralWidget);
        pv_label_2->setObjectName(QString::fromUtf8("pv_label_2"));
        sizePolicy1.setHeightForWidth(pv_label_2->sizePolicy().hasHeightForWidth());
        pv_label_2->setSizePolicy(sizePolicy1);
        pv_label_2->setFont(font);

        gridLayout->addWidget(pv_label_2, 0, 4, 1, 1);

        poplatek_check = new QCheckBox(centralWidget);
        poplatek_check->setObjectName(QString::fromUtf8("poplatek_check"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(poplatek_check->sizePolicy().hasHeightForWidth());
        poplatek_check->setSizePolicy(sizePolicy2);
        poplatek_check->setMinimumSize(QSize(70, 0));
        poplatek_check->setFont(font);

        gridLayout->addWidget(poplatek_check, 0, 6, 1, 1);

        poplatek_line = new QLineEdit(centralWidget);
        poplatek_line->setObjectName(QString::fromUtf8("poplatek_line"));
        sizePolicy.setHeightForWidth(poplatek_line->sizePolicy().hasHeightForWidth());
        poplatek_line->setSizePolicy(sizePolicy);
        poplatek_line->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(poplatek_line, 0, 7, 1, 1);

        procento = new QLabel(centralWidget);
        procento->setObjectName(QString::fromUtf8("procento"));
        sizePolicy.setHeightForWidth(procento->sizePolicy().hasHeightForWidth());
        procento->setSizePolicy(sizePolicy);
        procento->setMaximumSize(QSize(15, 16777215));
        procento->setFont(font);

        gridLayout->addWidget(procento, 0, 8, 1, 1);

        skutecny_label = new QLabel(centralWidget);
        skutecny_label->setObjectName(QString::fromUtf8("skutecny_label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(skutecny_label->sizePolicy().hasHeightForWidth());
        skutecny_label->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        skutecny_label->setFont(font1);

        gridLayout->addWidget(skutecny_label, 0, 9, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(0, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 10, 1, 1);

        t_label_1 = new QLabel(centralWidget);
        t_label_1->setObjectName(QString::fromUtf8("t_label_1"));
        sizePolicy2.setHeightForWidth(t_label_1->sizePolicy().hasHeightForWidth());
        t_label_1->setSizePolicy(sizePolicy2);
        t_label_1->setFont(font);
        t_label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(t_label_1, 1, 0, 1, 1);

        t_label_2 = new QLabel(centralWidget);
        t_label_2->setObjectName(QString::fromUtf8("t_label_2"));
        sizePolicy.setHeightForWidth(t_label_2->sizePolicy().hasHeightForWidth());
        t_label_2->setSizePolicy(sizePolicy);
        t_label_2->setFont(font);

        gridLayout->addWidget(t_label_2, 1, 4, 1, 1);

        r_label_1 = new QLabel(centralWidget);
        r_label_1->setObjectName(QString::fromUtf8("r_label_1"));
        sizePolicy2.setHeightForWidth(r_label_1->sizePolicy().hasHeightForWidth());
        r_label_1->setSizePolicy(sizePolicy2);
        r_label_1->setFont(font);
        r_label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(r_label_1, 2, 0, 1, 1);

        otaznik_button = new QToolButton(centralWidget);
        otaznik_button->setObjectName(QString::fromUtf8("otaznik_button"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(otaznik_button->sizePolicy().hasHeightForWidth());
        otaznik_button->setSizePolicy(sizePolicy4);
        otaznik_button->setMaximumSize(QSize(20, 20));
        otaznik_button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(otaznik_button, 2, 4, 1, 1);

        pv_line = new QLineEdit(centralWidget);
        pv_line->setObjectName(QString::fromUtf8("pv_line"));
        sizePolicy.setHeightForWidth(pv_line->sizePolicy().hasHeightForWidth());
        pv_line->setSizePolicy(sizePolicy);
        pv_line->setMinimumSize(QSize(144, 0));
        pv_line->setMaximumSize(QSize(144, 16777215));
        pv_line->setInputMethodHints(Qt::ImhNone);
        pv_line->setMaxLength(32803);
        pv_line->setFrame(true);

        gridLayout->addWidget(pv_line, 0, 2, 1, 1);

        t_line = new QLineEdit(centralWidget);
        t_line->setObjectName(QString::fromUtf8("t_line"));
        sizePolicy.setHeightForWidth(t_line->sizePolicy().hasHeightForWidth());
        t_line->setSizePolicy(sizePolicy);
        t_line->setMinimumSize(QSize(144, 0));
        t_line->setMaximumSize(QSize(144, 16777215));

        gridLayout->addWidget(t_line, 1, 2, 1, 1);

        r_combo = new QComboBox(centralWidget);
        r_combo->setObjectName(QString::fromUtf8("r_combo"));
        sizePolicy.setHeightForWidth(r_combo->sizePolicy().hasHeightForWidth());
        r_combo->setSizePolicy(sizePolicy);
        r_combo->setMinimumSize(QSize(150, 0));
        r_combo->setMaximumSize(QSize(150, 16777215));
        r_combo->setEditable(false);
        r_combo->setMaxVisibleItems(14);
        r_combo->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        r_combo->setDuplicatesEnabled(false);

        gridLayout->addWidget(r_combo, 2, 2, 1, 1);

        r_line = new QLineEdit(centralWidget);
        r_line->setObjectName(QString::fromUtf8("r_line"));
        r_line->setEnabled(true);
        sizePolicy.setHeightForWidth(r_line->sizePolicy().hasHeightForWidth());
        r_line->setSizePolicy(sizePolicy);
        r_line->setMinimumSize(QSize(144, 0));
        r_line->setMaximumSize(QSize(144, 16777215));
        r_line->setFrame(true);

        gridLayout->addWidget(r_line, 3, 2, 1, 1);

        r_label_3 = new QLabel(centralWidget);
        r_label_3->setObjectName(QString::fromUtf8("r_label_3"));
        sizePolicy.setHeightForWidth(r_label_3->sizePolicy().hasHeightForWidth());
        r_label_3->setSizePolicy(sizePolicy);
        r_label_3->setFont(font);

        gridLayout->addWidget(r_label_3, 3, 4, 1, 1);

        vysledny_label = new QLabel(centralWidget);
        vysledny_label->setObjectName(QString::fromUtf8("vysledny_label"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(vysledny_label->sizePolicy().hasHeightForWidth());
        vysledny_label->setSizePolicy(sizePolicy5);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(28);
        font2.setBold(false);
        font2.setWeight(50);
        vysledny_label->setFont(font2);
        vysledny_label->setFrameShape(QFrame::NoFrame);
        vysledny_label->setFrameShadow(QFrame::Plain);
        vysledny_label->setTextFormat(Qt::PlainText);
        vysledny_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(vysledny_label, 1, 6, 2, 5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 559, 22));
        menuSoubor = new QMenu(menuBar);
        menuSoubor->setObjectName(QString::fromUtf8("menuSoubor"));
        menuZobrazit = new QMenu(menuBar);
        menuZobrazit->setObjectName(QString::fromUtf8("menuZobrazit"));
        menuN_pov_da = new QMenu(menuBar);
        menuN_pov_da->setObjectName(QString::fromUtf8("menuN_pov_da"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuSoubor->menuAction());
        menuBar->addAction(menuZobrazit->menuAction());
        menuBar->addAction(menuN_pov_da->menuAction());
        menuSoubor->addAction(action_new_window);
        menuSoubor->addAction(action_close_window);
        menuSoubor->addSeparator();
        menuSoubor->addAction(action_quit);
        menuZobrazit->addAction(actionPrehled);
        menuZobrazit->addAction(actionCen_k);
        menuZobrazit->addAction(actionPodrobnosti);
        menuZobrazit->addAction(actionPodrobnosti_2);
        menuN_pov_da->addAction(action_go_home);
        menuN_pov_da->addSeparator();
        menuN_pov_da->addAction(actionO_Qt);
        menuN_pov_da->addAction(actionO_programu);

        retranslateUi(MainWindow);

        r_combo->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Supermarket", 0, QApplication::UnicodeUTF8));
        action_quit->setText(QApplication::translate("MainWindow", "Konec", 0, QApplication::UnicodeUTF8));
        action_quit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_new_window->setText(QApplication::translate("MainWindow", "Nov\303\251 okno", 0, QApplication::UnicodeUTF8));
        action_new_window->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        action_close_window->setText(QApplication::translate("MainWindow", "Zav\305\231\303\255t okno", 0, QApplication::UnicodeUTF8));
        action_close_window->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionO_programu->setText(QApplication::translate("MainWindow", "O programu", 0, QApplication::UnicodeUTF8));
        actionO_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
        actionPrehled->setText(QApplication::translate("MainWindow", "P\305\231ehled", 0, QApplication::UnicodeUTF8));
        actionPodrobnosti->setText(QApplication::translate("MainWindow", "Podrobnosti", 0, QApplication::UnicodeUTF8));
        action_go_home->setText(QApplication::translate("MainWindow", "P\305\231ej\303\255t na domovsk\303\251 str\303\241nky", 0, QApplication::UnicodeUTF8));
        actionMail->setText(QApplication::translate("MainWindow", "Poslat e-mail ", 0, QApplication::UnicodeUTF8));
        actionPodrobnosti_2->setText(QApplication::translate("MainWindow", "Podrobnosti +", 0, QApplication::UnicodeUTF8));
        actionCen_k->setText(QApplication::translate("MainWindow", "Cen\303\255k", 0, QApplication::UnicodeUTF8));
        pv_label_1->setText(QApplication::translate("MainWindow", "Investi\304\215n\303\255 \304\215\303\241stka", 0, QApplication::UnicodeUTF8));
        pv_label_2->setText(QApplication::translate("MainWindow", "K\304\215", 0, QApplication::UnicodeUTF8));
        poplatek_check->setText(QApplication::translate("MainWindow", "poplatek", 0, QApplication::UnicodeUTF8));
        procento->setText(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        skutecny_label->setText(QApplication::translate("MainWindow", "Skute\304\215n\303\241 vlo\305\276en\303\241 \304\215\303\241stka", 0, QApplication::UnicodeUTF8));
        t_label_1->setText(QApplication::translate("MainWindow", "Investi\304\215n\303\255 horizont", 0, QApplication::UnicodeUTF8));
        t_label_2->setText(QApplication::translate("MainWindow", "let", 0, QApplication::UnicodeUTF8));
        r_label_1->setText(QApplication::translate("MainWindow", "Partners MIX", 0, QApplication::UnicodeUTF8));
        otaznik_button->setText(QString());
        pv_line->setInputMask(QString());
        r_label_3->setText(QApplication::translate("MainWindow", "p.a.", 0, QApplication::UnicodeUTF8));
        vysledny_label->setText(QApplication::translate("MainWindow", "0.00K\304\215", 0, QApplication::UnicodeUTF8));
        menuSoubor->setTitle(QApplication::translate("MainWindow", "Soubor", 0, QApplication::UnicodeUTF8));
        menuZobrazit->setTitle(QApplication::translate("MainWindow", "Zobrazit", 0, QApplication::UnicodeUTF8));
        menuN_pov_da->setTitle(QApplication::translate("MainWindow", "N\303\241pov\304\233da", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
