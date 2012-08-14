/****************************************************************************
** Meta object code from reading C++ file 'podrobnosti.h'
**
** Created: Tue Aug 14 08:56:21 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "podrobnosti.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'podrobnosti.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_podrobnosti[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x0a,
      30,   12,   12,   12, 0x08,
      48,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_podrobnosti[] = {
    "podrobnosti\0\0a\0selectMix(int)\0"
    "buttonPlusClick()\0buttonMinusClick()\0"
};

void podrobnosti::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        podrobnosti *_t = static_cast<podrobnosti *>(_o);
        switch (_id) {
        case 0: _t->selectMix((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->buttonPlusClick(); break;
        case 2: _t->buttonMinusClick(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData podrobnosti::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject podrobnosti::staticMetaObject = {
    { &SMainWindow::staticMetaObject, qt_meta_stringdata_podrobnosti,
      qt_meta_data_podrobnosti, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &podrobnosti::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *podrobnosti::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *podrobnosti::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_podrobnosti))
        return static_cast<void*>(const_cast< podrobnosti*>(this));
    return SMainWindow::qt_metacast(_clname);
}

int podrobnosti::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
