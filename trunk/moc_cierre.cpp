/****************************************************************************
** Meta object code from reading C++ file 'cierre.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cierre.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cierre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Cierre[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      34,    7,    7,    7, 0x08,
      58,    7,    7,    7, 0x08,
      70,   65,    7,    7, 0x08,
      99,   65,    7,    7, 0x08,
     130,   65,    7,    7, 0x08,
     161,   65,    7,    7, 0x08,
     192,   65,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Cierre[] = {
    "Cierre\0\0on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0hora()\0arg1\0"
    "on_spinBox_valueChanged(int)\0"
    "on_spinBox_2_valueChanged(int)\0"
    "on_spinBox_6_valueChanged(int)\0"
    "on_spinBox_4_valueChanged(int)\0"
    "on_spinBox_5_valueChanged(int)\0"
};

void Cierre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Cierre *_t = static_cast<Cierre *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_2_clicked(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->hora(); break;
        case 3: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_spinBox_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_spinBox_6_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_spinBox_4_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_spinBox_5_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Cierre::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Cierre::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Cierre,
      qt_meta_data_Cierre, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Cierre::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Cierre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Cierre::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Cierre))
        return static_cast<void*>(const_cast< Cierre*>(this));
    return QDialog::qt_metacast(_clname);
}

int Cierre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
