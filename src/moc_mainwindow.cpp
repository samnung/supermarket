/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Aug 14 08:56:24 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      30,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   50,   11,   11, 0x08,
      78,   11,   11,   11, 0x08,
      90,   50,   11,   11, 0x08,
     105,   50,   11,   11, 0x08,
     119,   50,   11,   11, 0x08,
     132,   50,   11,   11, 0x08,
     146,   50,   11,   11, 0x08,
     163,   11,   11,   11, 0x08,
     178,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0anyValueChanged()\0"
    "otaznikClicked(int)\0a\0rLineVlastniSelected(int)\0"
    "calculate()\0setPV(QString)\0setR(QString)\0"
    "setR(double)\0setT(QString)\0setPopl(QString)\0"
    "otaznikClick()\0poplatekChecked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->anyValueChanged(); break;
        case 1: _t->otaznikClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->rLineVlastniSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->calculate(); break;
        case 4: _t->setPV((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setR((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setR((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setT((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setPopl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->otaznikClick(); break;
        case 10: _t->poplatekChecked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &SMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return SMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::anyValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainWindow::otaznikClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
