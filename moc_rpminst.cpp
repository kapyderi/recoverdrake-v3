/****************************************************************************
** Meta object code from reading C++ file 'rpminst.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rpminst.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rpminst.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rpminst[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      18,    8,    8,    8, 0x08,
      45,    8,    8,    8, 0x08,
      72,    8,    8,    8, 0x08,
      98,    8,    8,    8, 0x08,
     125,    8,    8,    8, 0x08,
     152,    8,    8,    8, 0x08,
     179,    8,    8,    8, 0x08,
     194,  188,    8,    8, 0x08,
     227,  215,    8,    8, 0x08,
     254,  250,    8,    8, 0x08,
     275,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_rpminst[] = {
    "rpminst\0\0Cerrar()\0on_pushButton_15_clicked()\0"
    "on_pushButton_14_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_12_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_13_clicked()\0mibFin()\0"
    "valor\0mibEscribir(QString)\0ValorComand\0"
    "ProcesarValor(QString)\0Dat\0"
    "mibprogreso(QString)\0Recuento()\0"
};

void rpminst::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        rpminst *_t = static_cast<rpminst *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->on_pushButton_15_clicked(); break;
        case 2: _t->on_pushButton_14_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_pushButton_12_clicked(); break;
        case 5: _t->on_pushButton_10_clicked(); break;
        case 6: _t->on_pushButton_13_clicked(); break;
        case 7: _t->mibFin(); break;
        case 8: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->ProcesarValor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->mibprogreso((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->Recuento(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rpminst::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rpminst::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_rpminst,
      qt_meta_data_rpminst, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rpminst::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rpminst::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rpminst::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rpminst))
        return static_cast<void*>(const_cast< rpminst*>(this));
    return QDialog::qt_metacast(_clname);
}

int rpminst::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void rpminst::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
