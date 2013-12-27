/****************************************************************************
** Meta object code from reading C++ file 'conversor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "conversor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'conversor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Conversor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   20,   10,   10, 0x08,
      71,   10,   10,   10, 0x08,
      97,   10,   10,   10, 0x08,
     123,   10,   10,   10, 0x08,
     147,   10,   10,   10, 0x08,
     173,   10,   10,   10, 0x08,
     199,   10,   10,   10, 0x08,
     226,   10,   10,   10, 0x08,
     253,   10,   10,   10, 0x08,
     280,   10,   10,   10, 0x08,
     307,   10,   10,   10, 0x08,
     334,   10,   10,   10, 0x08,
     361,   10,   10,   10, 0x08,
     387,   10,   10,   10, 0x08,
     402,  396,   10,   10, 0x08,
     435,  423,   10,   10, 0x08,
     462,  458,   10,   10, 0x08,
     494,  483,   10,   10, 0x08,
     516,   10,   10,   10, 0x08,
     525,   10,   10,   10, 0x08,
     551,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Conversor[] = {
    "Conversor\0\0Cerrar()\0seleccion\0"
    "on_comboBox_currentIndexChanged(QString)\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_17_clicked()\0"
    "on_pushButton_16_clicked()\0"
    "on_pushButton_15_clicked()\0"
    "on_pushButton_21_clicked()\0"
    "on_pushButton_20_clicked()\0"
    "on_pushButton_19_clicked()\0"
    "on_pushButton_2_clicked()\0mibFin()\0"
    "valor\0mibEscribir(QString)\0ValorComand\0"
    "ProcesarValor(QString)\0Dat\0"
    "mibprogreso(QString)\0row,column\0"
    "tableClicked(int,int)\0update()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_8_clicked()\0"
};

void Conversor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Conversor *_t = static_cast<Conversor *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_6_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_4_clicked(); break;
        case 6: _t->on_pushButton_5_clicked(); break;
        case 7: _t->on_pushButton_17_clicked(); break;
        case 8: _t->on_pushButton_16_clicked(); break;
        case 9: _t->on_pushButton_15_clicked(); break;
        case 10: _t->on_pushButton_21_clicked(); break;
        case 11: _t->on_pushButton_20_clicked(); break;
        case 12: _t->on_pushButton_19_clicked(); break;
        case 13: _t->on_pushButton_2_clicked(); break;
        case 14: _t->mibFin(); break;
        case 15: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->ProcesarValor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->mibprogreso((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->tableClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: _t->update(); break;
        case 20: _t->on_pushButton_7_clicked(); break;
        case 21: _t->on_pushButton_8_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Conversor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Conversor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Conversor,
      qt_meta_data_Conversor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Conversor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Conversor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Conversor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Conversor))
        return static_cast<void*>(const_cast< Conversor*>(this));
    return QDialog::qt_metacast(_clname);
}

int Conversor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void Conversor::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
