/****************************************************************************
** Meta object code from reading C++ file 'comparador.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "comparador.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comparador.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Comparador[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      21,   11,   11,   11, 0x08,
      45,   11,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     174,   11,   11,   11, 0x08,
     200,   11,   11,   11, 0x08,
     226,   11,   11,   11, 0x08,
     252,   11,   11,   11, 0x08,
     279,   11,   11,   11, 0x08,
     306,   11,   11,   11, 0x08,
     332,   11,   11,   11, 0x08,
     370,   11,   11,   11, 0x08,
     397,   11,   11,   11, 0x08,
     424,   11,   11,   11, 0x08,
     451,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Comparador[] = {
    "Comparador\0\0Cerrar()\0on_pushButton_clicked()\0"
    "Comprobar()\0Comprobar1()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_13_clicked()\0"
    "on_pushButton_15_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_tableWidget_itemSelectionChanged()\0"
    "on_pushButton_12_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_11_clicked()\0"
    "on_pushButton_14_clicked()\0"
};

void Comparador::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Comparador *_t = static_cast<Comparador *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->Comprobar(); break;
        case 3: _t->Comprobar1(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->on_pushButton_3_clicked(); break;
        case 6: _t->on_pushButton_5_clicked(); break;
        case 7: _t->on_pushButton_7_clicked(); break;
        case 8: _t->on_pushButton_8_clicked(); break;
        case 9: _t->on_pushButton_9_clicked(); break;
        case 10: _t->on_pushButton_4_clicked(); break;
        case 11: _t->on_pushButton_13_clicked(); break;
        case 12: _t->on_pushButton_15_clicked(); break;
        case 13: _t->on_pushButton_6_clicked(); break;
        case 14: _t->on_tableWidget_itemSelectionChanged(); break;
        case 15: _t->on_pushButton_12_clicked(); break;
        case 16: _t->on_pushButton_10_clicked(); break;
        case 17: _t->on_pushButton_11_clicked(); break;
        case 18: _t->on_pushButton_14_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Comparador::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Comparador::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Comparador,
      qt_meta_data_Comparador, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Comparador::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Comparador::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Comparador::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Comparador))
        return static_cast<void*>(const_cast< Comparador*>(this));
    return QDialog::qt_metacast(_clname);
}

int Comparador::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void Comparador::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
