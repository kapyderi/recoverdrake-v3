/****************************************************************************
** Meta object code from reading C++ file 'update.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "update.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'update.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Update[] = {

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
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      17,    7,    7,    7, 0x08,
      44,    7,    7,    7, 0x08,
      70,    7,    7,    7, 0x08,
      97,    7,    7,    7, 0x08,
     123,    7,    7,    7, 0x08,
     149,    7,    7,    7, 0x08,
     175,    7,    7,    7, 0x08,
     190,  184,    7,    7, 0x08,
     223,  211,    7,    7, 0x08,
     250,  246,    7,    7, 0x08,
     271,    7,    7,    7, 0x08,
     298,    7,    7,    7, 0x08,
     325,    7,    7,    7, 0x08,
     351,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Update[] = {
    "Update\0\0Cerrar()\0on_pushButton_13_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_14_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_3_clicked()\0mibFin()\0"
    "valor\0mibEscribir(QString)\0ValorComand\0"
    "ProcesarValor(QString)\0Dat\0"
    "mibprogreso(QString)\0on_pushButton_10_clicked()\0"
    "on_pushButton_12_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_11_clicked()\0"
};

void Update::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Update *_t = static_cast<Update *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->on_pushButton_13_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_14_clicked(); break;
        case 4: _t->on_pushButton_6_clicked(); break;
        case 5: _t->on_pushButton_7_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->mibFin(); break;
        case 8: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->ProcesarValor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->mibprogreso((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_10_clicked(); break;
        case 12: _t->on_pushButton_12_clicked(); break;
        case 13: _t->on_pushButton_8_clicked(); break;
        case 14: _t->on_pushButton_11_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Update::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Update::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Update,
      qt_meta_data_Update, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Update::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Update::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Update::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Update))
        return static_cast<void*>(const_cast< Update*>(this));
    return QDialog::qt_metacast(_clname);
}

int Update::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Update::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
