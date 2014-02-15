/****************************************************************************
** Meta object code from reading C++ file 'dbclaves.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dbclaves.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbclaves.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dbclaves[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      19,    9,    9,    9, 0x08,
      45,    9,    9,    9, 0x08,
      71,    9,    9,    9, 0x08,
      88,   83,    9,    9, 0x08,
     121,   83,    9,    9, 0x08,
     167,  158,  154,    9, 0x08,
     184,    9,    9,    9, 0x08,
     203,  196,    9,    9, 0x08,
     227,   83,    9,    9, 0x08,
     262,   83,    9,    9, 0x08,
     297,    9,    9,    9, 0x08,
     309,    9,    9,    9, 0x08,
     324,    9,    9,    9, 0x08,
     348,    9,    9,    9, 0x08,
     374,    9,    9,    9, 0x08,
     400,    9,    9,    9, 0x08,
     426,    9,    9,    9, 0x08,
     452,    9,    9,    9, 0x08,
     479,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dbclaves[] = {
    "dbclaves\0\0Cerrar()\0on_pushButton_4_clicked()\0"
    "on_pushButton_6_clicked()\0Comprobar()\0"
    "arg1\0on_comboBox_2_activated(QString)\0"
    "on_lineEdit_textChanged(QString)\0int\0"
    "low,high\0randInt(int,int)\0ramdomize()\0"
    "actual\0cambiaFila(QModelIndex)\0"
    "on_lineEdit_2_textChanged(QString)\0"
    "on_lineEdit_6_textChanged(QString)\0"
    "Encriptar()\0Desencriptar()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_11_clicked()\0"
    "on_pushButton_10_clicked()\0"
};

void dbclaves::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        dbclaves *_t = static_cast<dbclaves *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->on_pushButton_4_clicked(); break;
        case 2: _t->on_pushButton_6_clicked(); break;
        case 3: _t->Comprobar(); break;
        case 4: _t->on_comboBox_2_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: { int _r = _t->randInt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: _t->ramdomize(); break;
        case 8: _t->cambiaFila((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_lineEdit_2_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_lineEdit_6_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->Encriptar(); break;
        case 12: _t->Desencriptar(); break;
        case 13: _t->on_pushButton_clicked(); break;
        case 14: _t->on_pushButton_7_clicked(); break;
        case 15: _t->on_pushButton_8_clicked(); break;
        case 16: _t->on_pushButton_2_clicked(); break;
        case 17: _t->on_pushButton_3_clicked(); break;
        case 18: _t->on_pushButton_11_clicked(); break;
        case 19: _t->on_pushButton_10_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dbclaves::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dbclaves::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dbclaves,
      qt_meta_data_dbclaves, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dbclaves::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dbclaves::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dbclaves::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dbclaves))
        return static_cast<void*>(const_cast< dbclaves*>(this));
    return QDialog::qt_metacast(_clname);
}

int dbclaves::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void dbclaves::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
