/****************************************************************************
** Meta object code from reading C++ file 'window_control.h'
**
** Created: Tue Aug 14 08:56:27 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "window_control.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_window_control[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   16,   15,   15, 0x08,
      46,   15,   15,   15, 0x08,
      62,   15,   15,   15, 0x08,
      82,   76,   15,   15, 0x08,
     103,   15,   15,   15, 0x28,
     121,   16,   15,   15, 0x08,
     145,   15,   15,   15, 0x08,
     167,   15,   15,   15, 0x08,
     195,   15,   15,   15, 0x08,
     207,   15,   15,   15, 0x08,
     216,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_window_control[] = {
    "window_control\0\0window\0closeMainWindow(void*)\0"
    "showOAplikaci()\0showPrehled()\0index\0"
    "showPodrobnosti(int)\0showPodrobnosti()\0"
    "closePodrobnosti(void*)\0showPodrobnostiPlus()\0"
    "closePodrobnostiPlus(void*)\0showCenik()\0"
    "goHome()\0showMainWindow()\0"
};

void window_control::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        window_control *_t = static_cast<window_control *>(_o);
        switch (_id) {
        case 0: _t->closeMainWindow((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 1: _t->showOAplikaci(); break;
        case 2: _t->showPrehled(); break;
        case 3: _t->showPodrobnosti((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->showPodrobnosti(); break;
        case 5: _t->closePodrobnosti((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 6: _t->showPodrobnostiPlus(); break;
        case 7: _t->closePodrobnostiPlus((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 8: _t->showCenik(); break;
        case 9: _t->goHome(); break;
        case 10: _t->showMainWindow(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData window_control::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject window_control::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_window_control,
      qt_meta_data_window_control, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &window_control::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *window_control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *window_control::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_window_control))
        return static_cast<void*>(const_cast< window_control*>(this));
    return QObject::qt_metacast(_clname);
}

int window_control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
