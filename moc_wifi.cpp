/****************************************************************************
** Meta object code from reading C++ file 'wifi.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wifi.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wifi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_wifi[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      33,    5,    5,    5, 0x08,
      60,    5,    5,    5, 0x08,
      93,   86,    5,    5, 0x08,
     117,   86,    5,    5, 0x08,
     142,    5,    5,    5, 0x08,
     166,    5,    5,    5, 0x08,
     192,    5,    5,    5, 0x08,
     218,    5,    5,    5, 0x08,
     244,    5,    5,    5, 0x08,
     271,    5,    5,    5, 0x08,
     298,    5,    5,    5, 0x08,
     324,    5,    5,    5, 0x08,
     350,    5,    5,    5, 0x08,
     377,    5,    5,    5, 0x08,
     403,    5,    5,    5, 0x08,
     429,    5,    5,    5, 0x08,
     444,  438,    5,    5, 0x08,
     469,  465,    5,    5, 0x08,
     490,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_wifi[] = {
    "wifi\0\0on_pushButton_14_clicked()\0"
    "on_pushButton_13_clicked()\0"
    "on_pushButton_4_clicked()\0actual\0"
    "cambiaFila(QModelIndex)\0"
    "cambiaFila1(QModelIndex)\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_11_clicked()\0"
    "on_pushButton_12_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_6_clicked()\0mibFin()\0"
    "valor\0mibEscribir(QString)\0Dat\0"
    "mibprogreso(QString)\0lanzar()\0"
};

void wifi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        wifi *_t = static_cast<wifi *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_14_clicked(); break;
        case 1: _t->on_pushButton_13_clicked(); break;
        case 2: _t->on_pushButton_4_clicked(); break;
        case 3: _t->cambiaFila((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 4: _t->cambiaFila1((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->on_pushButton_3_clicked(); break;
        case 8: _t->on_pushButton_5_clicked(); break;
        case 9: _t->on_pushButton_11_clicked(); break;
        case 10: _t->on_pushButton_12_clicked(); break;
        case 11: _t->on_pushButton_7_clicked(); break;
        case 12: _t->on_pushButton_9_clicked(); break;
        case 13: _t->on_pushButton_10_clicked(); break;
        case 14: _t->on_pushButton_8_clicked(); break;
        case 15: _t->on_pushButton_6_clicked(); break;
        case 16: _t->mibFin(); break;
        case 17: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->mibprogreso((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->lanzar(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData wifi::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject wifi::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_wifi,
      qt_meta_data_wifi, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &wifi::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *wifi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *wifi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_wifi))
        return static_cast<void*>(const_cast< wifi*>(this));
    return QDialog::qt_metacast(_clname);
}

int wifi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
