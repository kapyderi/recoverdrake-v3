/****************************************************************************
** Meta object code from reading C++ file 'calendario.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "calendario.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendario.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Calendario[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x08,
      33,   11,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      83,   11,   11,   11, 0x08,
     109,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     161,   11,   11,   11, 0x08,
     173,   11,   11,   11, 0x08,
     186,   11,   11,   11, 0x08,
     212,   11,   11,   11, 0x08,
     227,  221,   11,   11, 0x08,
     252,  248,   11,   11, 0x08,
     273,   11,   11,   11, 0x08,
     283,   11,   11,   11, 0x08,
     309,   11,   11,   11, 0x08,
     336,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Calendario[] = {
    "Calendario\0\0date\0Calendar(QDate)\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0Comprobar()\0"
    "Comprobar1()\0on_pushButton_7_clicked()\0"
    "mibFin()\0valor\0mibEscribir(QString)\0"
    "Dat\0mibprogreso(QString)\0Consola()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_12_clicked()\0"
};

void Calendario::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Calendario *_t = static_cast<Calendario *>(_o);
        switch (_id) {
        case 0: _t->Calendar((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->on_pushButton_5_clicked(); break;
        case 6: _t->Comprobar(); break;
        case 7: _t->Comprobar1(); break;
        case 8: _t->on_pushButton_7_clicked(); break;
        case 9: _t->mibFin(); break;
        case 10: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->mibprogreso((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->Consola(); break;
        case 13: _t->on_pushButton_9_clicked(); break;
        case 14: _t->on_pushButton_10_clicked(); break;
        case 15: _t->on_pushButton_12_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Calendario::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Calendario::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Calendario,
      qt_meta_data_Calendario, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Calendario::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Calendario::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Calendario::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Calendario))
        return static_cast<void*>(const_cast< Calendario*>(this));
    return QDialog::qt_metacast(_clname);
}

int Calendario::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
