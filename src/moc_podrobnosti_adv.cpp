/****************************************************************************
** Meta object code from reading C++ file 'podrobnosti_adv.h'
**
** Created: Tue Aug 14 08:56:26 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "podrobnosti_adv.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'podrobnosti_adv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_podrobnosti_adv[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   17,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_podrobnosti_adv[] = {
    "podrobnosti_adv\0\0a\0selectMix(int)\0"
};

void podrobnosti_adv::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        podrobnosti_adv *_t = static_cast<podrobnosti_adv *>(_o);
        switch (_id) {
        case 0: _t->selectMix((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData podrobnosti_adv::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject podrobnosti_adv::staticMetaObject = {
    { &SMainWindow::staticMetaObject, qt_meta_stringdata_podrobnosti_adv,
      qt_meta_data_podrobnosti_adv, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &podrobnosti_adv::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *podrobnosti_adv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *podrobnosti_adv::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_podrobnosti_adv))
        return static_cast<void*>(const_cast< podrobnosti_adv*>(this));
    return SMainWindow::qt_metacast(_clname);
}

int podrobnosti_adv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
