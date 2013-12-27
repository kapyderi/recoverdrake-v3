/****************************************************************************
** Meta object code from reading C++ file 'acceso.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "acceso.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'acceso.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_acceso[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      34,    7,    7,    7, 0x08,
      60,    7,    7,    7, 0x08,
      84,    7,    7,    7, 0x08,
     131,  122,  118,    7, 0x08,
     148,    7,    7,    7, 0x08,
     174,    7,    7,    7, 0x08,
     186,    7,    7,    7, 0x08,
     198,    7,    7,    7, 0x08,
     208,    7,    7,    7, 0x08,
     225,  219,    7,    7, 0x08,
     260,    7,    7,    7, 0x08,
     270,    7,    7,    7, 0x08,
     280,    7,    7,    7, 0x08,
     290,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_acceso[] = {
    "acceso\0\0on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_comboBox_currentIndexChanged()\0int\0"
    "low,high\0randInt(int,int)\0"
    "on_pushButton_4_clicked()\0ramdomize()\0"
    "Comprobar()\0Mostrar()\0Mostrar1()\0Value\0"
    "on_lineEdit_2_textChanged(QString)\0"
    "Spanish()\0English()\0Cambiar()\0hora()\0"
};

void acceso::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        acceso *_t = static_cast<acceso *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_3_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_comboBox_currentIndexChanged(); break;
        case 4: { int _r = _t->randInt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: _t->on_pushButton_4_clicked(); break;
        case 6: _t->ramdomize(); break;
        case 7: _t->Comprobar(); break;
        case 8: _t->Mostrar(); break;
        case 9: _t->Mostrar1(); break;
        case 10: _t->on_lineEdit_2_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->Spanish(); break;
        case 12: _t->English(); break;
        case 13: _t->Cambiar(); break;
        case 14: _t->hora(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData acceso::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject acceso::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_acceso,
      qt_meta_data_acceso, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &acceso::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *acceso::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *acceso::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_acceso))
        return static_cast<void*>(const_cast< acceso*>(this));
    return QDialog::qt_metacast(_clname);
}

int acceso::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
