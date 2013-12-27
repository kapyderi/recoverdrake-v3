/****************************************************************************
** Meta object code from reading C++ file 'opciones.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "opciones.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'opciones.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_opciones[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x08,
      37,    9,    9,    9, 0x08,
      64,    9,    9,    9, 0x08,
      92,   90,    9,    9, 0x08,
     135,   90,    9,    9, 0x08,
     176,   90,    9,    9, 0x08,
     218,    9,    9,    9, 0x08,
     244,    9,    9,    9, 0x08,
     268,    9,    9,    9, 0x08,
     301,  294,    9,    9, 0x08,
     325,    9,    9,    9, 0x08,
     351,    9,    9,    9, 0x08,
     377,    9,    9,    9, 0x08,
     403,    9,    9,    9, 0x08,
     429,    9,    9,    9, 0x08,
     455,    9,    9,    9, 0x08,
     461,    9,    9,    9, 0x08,
     468,    9,    9,    9, 0x08,
     478,    9,    9,    9, 0x08,
     488,    9,    9,    9, 0x08,
     515,    9,    9,    9, 0x08,
     542,    9,    9,    9, 0x08,
     569,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_opciones[] = {
    "opciones\0\0stilo\0changeStyle(QString)\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_9_clicked()\0f\0"
    "on_comboBox_2_currentIndexChanged(QString)\0"
    "on_comboBox_currentIndexChanged(QString)\0"
    "on_fontComboBox_currentFontChanged(QFont)\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_3_clicked()\0actual\0"
    "cambiaFila(QModelIndex)\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_8_clicked()\0Eth()\0Wlan()\0"
    "Spanish()\0English()\0on_pushButton_11_clicked()\0"
    "on_pushButton_12_clicked()\0"
    "on_pushButton_13_clicked()\0Comprobar()\0"
};

void opciones::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        opciones *_t = static_cast<opciones *>(_o);
        switch (_id) {
        case 0: _t->changeStyle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_10_clicked(); break;
        case 2: _t->on_pushButton_9_clicked(); break;
        case 3: _t->on_comboBox_2_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_fontComboBox_currentFontChanged((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_pushButton_3_clicked(); break;
        case 9: _t->cambiaFila((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_4_clicked(); break;
        case 11: _t->on_pushButton_6_clicked(); break;
        case 12: _t->on_pushButton_7_clicked(); break;
        case 13: _t->on_pushButton_5_clicked(); break;
        case 14: _t->on_pushButton_8_clicked(); break;
        case 15: _t->Eth(); break;
        case 16: _t->Wlan(); break;
        case 17: _t->Spanish(); break;
        case 18: _t->English(); break;
        case 19: _t->on_pushButton_11_clicked(); break;
        case 20: _t->on_pushButton_12_clicked(); break;
        case 21: _t->on_pushButton_13_clicked(); break;
        case 22: _t->Comprobar(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData opciones::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject opciones::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_opciones,
      qt_meta_data_opciones, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &opciones::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *opciones::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *opciones::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_opciones))
        return static_cast<void*>(const_cast< opciones*>(this));
    return QDialog::qt_metacast(_clname);
}

int opciones::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
