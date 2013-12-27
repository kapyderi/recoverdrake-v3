/****************************************************************************
** Meta object code from reading C++ file 'busca.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "busca.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'busca.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Busca[] = {

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
       7,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      16,    6,    6,    6, 0x08,
      42,    6,    6,    6, 0x08,
      68,    6,    6,    6, 0x08,
      92,    6,    6,    6, 0x08,
     118,    6,    6,    6, 0x08,
     133,  127,    6,    6, 0x08,
     160,  154,    6,    6, 0x08,
     202,    6,    6,    6, 0x08,
     214,    6,    6,    6, 0x08,
     226,    6,    6,    6, 0x08,
     252,    6,    6,    6, 0x08,
     261,    6,    6,    6, 0x08,
     287,    6,    6,    6, 0x08,
     313,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Busca[] = {
    "Busca\0\0Cerrar()\0on_pushButton_5_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_3_clicked()\0mibFin()\0"
    "valor\0mibEscribir(QString)\0index\0"
    "on_tableWidget_doubleClicked(QModelIndex)\0"
    "Comprobar()\0Verificar()\0"
    "on_pushButton_2_clicked()\0Contar()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_7_clicked()\0Menu()\0"
};

void Busca::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Busca *_t = static_cast<Busca *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->on_pushButton_5_clicked(); break;
        case 2: _t->on_pushButton_4_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        case 5: _t->mibFin(); break;
        case 6: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_tableWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->Comprobar(); break;
        case 9: _t->Verificar(); break;
        case 10: _t->on_pushButton_2_clicked(); break;
        case 11: _t->Contar(); break;
        case 12: _t->on_pushButton_6_clicked(); break;
        case 13: _t->on_pushButton_7_clicked(); break;
        case 14: _t->Menu(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Busca::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Busca::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Busca,
      qt_meta_data_Busca, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Busca::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Busca::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Busca::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Busca))
        return static_cast<void*>(const_cast< Busca*>(this));
    return QDialog::qt_metacast(_clname);
}

int Busca::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Busca::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
