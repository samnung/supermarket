#ifndef PREHLED_H
#define PREHLED_H

#include <QWidget>

namespace Ui {
    class prehled;
}

class prehled : public QWidget
{
    Q_OBJECT

public:
    explicit prehled(QWidget *parent = 0);
    ~prehled();
    virtual void closeEvent(QCloseEvent *e)
    {
       emit windowClosing(this);
       QWidget::closeEvent(e);
    }

private:
    Ui::prehled *ui_prehled;

signals:
    void windowClosing(void*);

};

#endif // PREHLED_H
