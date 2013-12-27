/****************************************************************************
** Meta object code from reading C++ file 'orphans.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "orphans.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orphans.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_orphans[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      18,    8,    8,    8, 0x08,
      42,    8,    8,    8, 0x08,
      69,    8,    8,    8, 0x08,
      95,    8,    8,    8, 0x08,
     121,    8,    8,    8, 0x08,
     147,    8,    8,    8, 0x08,
     174,    8,    8,    8, 0x08,
     201,    8,    8,    8, 0x08,
     228,    8,    8,    8, 0x08,
     255,    8,    8,    8, 0x08,
     270,  264,    8,    8, 0x08,
     303,  291,    8,    8, 0x08,
     330,  326,    8,    8, 0x08,
     351,    8,    8,    8, 0x08,
     377,    8,    8,    8, 0x08,
     403,    8,    8,    8, 0x08,
     429,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_orphans[] = {
    "orphans\0\0Cerrar()\0on_pushButton_clicked()\0"
    "on_pushButton_14_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_12_clicked()\0"
    "on_pushButton_11_clicked()\0"
    "on_pushButton_13_clicked()\0mibFin()\0"
    "valor\0mibEscribir(QString)\0ValorComand\0"
    "ProcesarValor(QString)\0Dat\0"
    "mibprogreso(QString)\0on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_8_clicked()\0"
};

void orphans::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        orphans *_t = static_cast<orphans *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_14_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_pushButton_6_clicked(); break;
        case 5: _t->on_pushButton_7_clicked(); break;
        case 6: _t->on_pushButton_10_clicked(); break;
        case 7: _t->on_pushButton_12_clicked(); break;
        case 8: _t->on_pushButton_11_clicked(); break;
        case 9: _t->on_pushButton_13_clicked(); break;
        case 10: _t->mibFin(); break;
        case 11: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->ProcesarValor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->mibprogreso((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_3_clicked(); break;
        case 15: _t->on_pushButton_4_clicked(); break;
        case 16: _t->on_pushButton_5_clicked(); break;
        case 17: _t->on_pushButton_8_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData orphans::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject orphans::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_orphans,
      qt_meta_data_orphans, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &orphans::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *orphans::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *orphans::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_orphans))
        return static_cast<void*>(const_cast< orphans*>(this));
    return QDialog::qt_metacast(_clname);
}

int orphans::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void orphans::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
