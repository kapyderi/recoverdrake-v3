/****************************************************************************
** Meta object code from reading C++ file 'Mrpm.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Mrpm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Mrpm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Mrpm[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      15,    5,    5,    5, 0x08,
      41,    5,    5,    5, 0x08,
      67,    5,    5,    5, 0x08,
      93,    5,    5,    5, 0x08,
     119,    5,    5,    5, 0x08,
     145,    5,    5,    5, 0x08,
     169,    5,    5,    5, 0x08,
     184,  178,    5,    5, 0x08,
     217,  205,    5,    5, 0x08,
     244,  240,    5,    5, 0x08,
     265,    5,    5,    5, 0x08,
     291,    5,    5,    5, 0x08,
     318,    5,    5,    5, 0x08,
     345,    5,    5,    5, 0x08,
     371,    5,    5,    5, 0x08,
     398,    5,    5,    5, 0x08,
     424,    5,    5,    5, 0x08,
     451,    5,    5,    5, 0x08,
     478,    5,    5,    5, 0x08,
     505,    5,    5,    5, 0x08,
     517,    5,    5,    5, 0x08,
     549,  544,    5,    5, 0x08,
     582,    5,    5,    5, 0x08,
     609,    5,    5,    5, 0x08,
     636,    5,    5,    5, 0x08,
     646,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Mrpm[] = {
    "Mrpm\0\0Cerrar()\0on_pushButton_2_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_clicked()\0mibFin()\0valor\0"
    "mibEscribir(QString)\0ValorComand\0"
    "ProcesarValor(QString)\0Dat\0"
    "mibprogreso(QString)\0on_pushButton_8_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_12_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_11_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_13_clicked()\0"
    "on_pushButton_14_clicked()\0"
    "on_pushButton_15_clicked()\0Comprobar()\0"
    "on_pushButton_16_clicked()\0arg1\0"
    "on_lineEdit_textChanged(QString)\0"
    "on_pushButton_17_clicked()\0"
    "on_pushButton_18_clicked()\0Recibir()\0"
    "on_pushButton_19_clicked()\0"
};

void Mrpm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Mrpm *_t = static_cast<Mrpm *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_4_clicked(); break;
        case 3: _t->on_pushButton_5_clicked(); break;
        case 4: _t->on_pushButton_6_clicked(); break;
        case 5: _t->on_pushButton_7_clicked(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->mibFin(); break;
        case 8: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->ProcesarValor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->mibprogreso((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_8_clicked(); break;
        case 12: _t->on_pushButton_10_clicked(); break;
        case 13: _t->on_pushButton_12_clicked(); break;
        case 14: _t->on_pushButton_3_clicked(); break;
        case 15: _t->on_pushButton_11_clicked(); break;
        case 16: _t->on_pushButton_9_clicked(); break;
        case 17: _t->on_pushButton_13_clicked(); break;
        case 18: _t->on_pushButton_14_clicked(); break;
        case 19: _t->on_pushButton_15_clicked(); break;
        case 20: _t->Comprobar(); break;
        case 21: _t->on_pushButton_16_clicked(); break;
        case 22: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->on_pushButton_17_clicked(); break;
        case 24: _t->on_pushButton_18_clicked(); break;
        case 25: _t->Recibir(); break;
        case 26: _t->on_pushButton_19_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Mrpm::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Mrpm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Mrpm,
      qt_meta_data_Mrpm, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Mrpm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Mrpm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Mrpm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Mrpm))
        return static_cast<void*>(const_cast< Mrpm*>(this));
    return QDialog::qt_metacast(_clname);
}

int Mrpm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void Mrpm::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
