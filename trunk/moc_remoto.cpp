/****************************************************************************
** Meta object code from reading C++ file 'remoto.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "remoto.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'remoto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_remoto[] = {

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
       8,    7,    7,    7, 0x08,
      34,    7,    7,    7, 0x08,
      60,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_remoto[] = {
    "remoto\0\0on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0mibFin()\0"
};

void remoto::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        remoto *_t = static_cast<remoto *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_2_clicked(); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->mibFin(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData remoto::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject remoto::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_remoto,
      qt_meta_data_remoto, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &remoto::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *remoto::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *remoto::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_remoto))
        return static_cast<void*>(const_cast< remoto*>(this));
    return QDialog::qt_metacast(_clname);
}

int remoto::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
