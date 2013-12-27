/****************************************************************************
** Meta object code from reading C++ file 'kernel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kernel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kernel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Kernel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      17,    7,    7,    7, 0x08,
      43,    7,    7,    7, 0x08,
      55,    7,    7,    7, 0x08,
      68,    7,    7,    7, 0x08,
      81,    7,    7,    7, 0x08,
      94,    7,    7,    7, 0x08,
     118,    7,    7,    7, 0x08,
     144,    7,    7,    7, 0x08,
     170,    7,    7,    7, 0x08,
     185,  179,    7,    7, 0x08,
     210,  206,    7,    7, 0x08,
     231,    7,    7,    7, 0x08,
     257,    7,    7,    7, 0x08,
     283,    7,    7,    7, 0x08,
     309,    7,    7,    7, 0x08,
     335,    7,    7,    7, 0x08,
     361,    7,    7,    7, 0x08,
     388,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Kernel[] = {
    "Kernel\0\0Cerrar()\0on_pushButton_3_clicked()\0"
    "Comprobar()\0Comprobar1()\0Comprobar2()\0"
    "Comprobar3()\0on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_4_clicked()\0mibFin()\0"
    "valor\0mibEscribir(QString)\0Dat\0"
    "mibprogreso(QString)\0on_pushButton_9_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_11_clicked()\0"
};

void Kernel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Kernel *_t = static_cast<Kernel *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->Comprobar(); break;
        case 3: _t->Comprobar1(); break;
        case 4: _t->Comprobar2(); break;
        case 5: _t->Comprobar3(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->on_pushButton_4_clicked(); break;
        case 9: _t->mibFin(); break;
        case 10: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->mibprogreso((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->on_pushButton_9_clicked(); break;
        case 13: _t->on_pushButton_5_clicked(); break;
        case 14: _t->on_pushButton_6_clicked(); break;
        case 15: _t->on_pushButton_7_clicked(); break;
        case 16: _t->on_pushButton_8_clicked(); break;
        case 17: _t->on_pushButton_10_clicked(); break;
        case 18: _t->on_pushButton_11_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Kernel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Kernel::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Kernel,
      qt_meta_data_Kernel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Kernel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Kernel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Kernel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Kernel))
        return static_cast<void*>(const_cast< Kernel*>(this));
    return QDialog::qt_metacast(_clname);
}

int Kernel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void Kernel::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
