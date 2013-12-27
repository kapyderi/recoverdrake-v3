/****************************************************************************
** Meta object code from reading C++ file 'totalsincrono.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "totalsincrono.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'totalsincrono.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TotalSincrono[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   24,   14,   14, 0x0a,
      59,   14,   14,   14, 0x08,
      86,   14,   14,   14, 0x08,
      95,   14,   14,   14, 0x08,
     129,  122,   14,   14, 0x08,
     153,   14,   14,   14, 0x08,
     179,   14,   14,   14, 0x08,
     205,   14,   14,   14, 0x08,
     238,  232,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TotalSincrono[] = {
    "TotalSincrono\0\0Cerrar()\0Valor,Value\0"
    "Refrescar(int,QString)\0"
    "on_pushButton_12_clicked()\0inicio()\0"
    "on_pushButton_10_clicked()\0actual\0"
    "cambiaFila(QModelIndex)\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_14_clicked()\0index\0"
    "on_tableView_doubleClicked(QModelIndex)\0"
};

void TotalSincrono::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TotalSincrono *_t = static_cast<TotalSincrono *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->Refrescar((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->on_pushButton_12_clicked(); break;
        case 3: _t->inicio(); break;
        case 4: _t->on_pushButton_10_clicked(); break;
        case 5: _t->cambiaFila((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_4_clicked(); break;
        case 7: _t->on_pushButton_5_clicked(); break;
        case 8: _t->on_pushButton_14_clicked(); break;
        case 9: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TotalSincrono::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TotalSincrono::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TotalSincrono,
      qt_meta_data_TotalSincrono, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TotalSincrono::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TotalSincrono::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TotalSincrono::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TotalSincrono))
        return static_cast<void*>(const_cast< TotalSincrono*>(this));
    return QDialog::qt_metacast(_clname);
}

int TotalSincrono::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void TotalSincrono::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
