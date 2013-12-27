/****************************************************************************
** Meta object code from reading C++ file 'sonido.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sonido.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sonido.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Sonido[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      75,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     130,    7,    7,    7, 0x08,
     156,    7,    7,    7, 0x08,
     182,    7,    7,    7, 0x08,
     212,  206,    7,    7, 0x08,
     248,  206,    7,    7, 0x08,
     286,  206,    7,    7, 0x08,
     324,  206,    7,    7, 0x08,
     362,  206,    7,    7, 0x08,
     400,  206,    7,    7, 0x08,
     438,  206,    7,    7, 0x08,
     476,  206,    7,    7, 0x08,
     514,  206,    7,    7, 0x08,
     552,  206,    7,    7, 0x08,
     591,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Sonido[] = {
    "Sonido\0\0"
    "Valor,band1,band2,band3,band4,band5,band6,band7,band8,band9,band10\0"
    "Sound(QString,int,int,int,int,int,int,int,int,int,int)\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0value\0"
    "on_verticalSlider_valueChanged(int)\0"
    "on_verticalSlider_2_valueChanged(int)\0"
    "on_verticalSlider_3_valueChanged(int)\0"
    "on_verticalSlider_4_valueChanged(int)\0"
    "on_verticalSlider_5_valueChanged(int)\0"
    "on_verticalSlider_6_valueChanged(int)\0"
    "on_verticalSlider_7_valueChanged(int)\0"
    "on_verticalSlider_8_valueChanged(int)\0"
    "on_verticalSlider_9_valueChanged(int)\0"
    "on_verticalSlider_10_valueChanged(int)\0"
    "Comprobar()\0"
};

void Sonido::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Sonido *_t = static_cast<Sonido *>(_o);
        switch (_id) {
        case 0: _t->Sound((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11]))); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_verticalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_verticalSlider_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_verticalSlider_3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_verticalSlider_4_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_verticalSlider_5_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_verticalSlider_6_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_verticalSlider_7_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_verticalSlider_8_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_verticalSlider_9_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_verticalSlider_10_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->Comprobar(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Sonido::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Sonido::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Sonido,
      qt_meta_data_Sonido, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Sonido::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Sonido::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Sonido::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Sonido))
        return static_cast<void*>(const_cast< Sonido*>(this));
    return QDialog::qt_metacast(_clname);
}

int Sonido::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Sonido::Sound(QString _t1, int _t2, int _t3, int _t4, int _t5, int _t6, int _t7, int _t8, int _t9, int _t10, int _t11)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
