/****************************************************************************
** Meta object code from reading C++ file 'makefile.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "makefile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'makefile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_makefile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
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
      95,    9,    9,    9, 0x08,
     121,    9,    9,    9, 0x08,
     147,    9,    9,    9, 0x08,
     158,    9,    9,    9, 0x08,
     172,    9,    9,    9, 0x08,
     198,    9,    9,    9, 0x08,
     210,    9,    9,    9, 0x08,
     225,  219,    9,    9, 0x08,
     246,    9,    9,    9, 0x08,
     260,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_makefile[] = {
    "makefile\0\0Cerrar()\0on_pushButton_6_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_2_clicked()\0Instalar()\0"
    "Desinstalar()\0on_pushButton_3_clicked()\0"
    "Comprobar()\0mibFin()\0valor\0"
    "mibEscribir(QString)\0Instalacion()\0"
    "Desinstalacion()\0"
};

void makefile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        makefile *_t = static_cast<makefile *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->on_pushButton_6_clicked(); break;
        case 2: _t->on_pushButton_5_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->Instalar(); break;
        case 7: _t->Desinstalar(); break;
        case 8: _t->on_pushButton_3_clicked(); break;
        case 9: _t->Comprobar(); break;
        case 10: _t->mibFin(); break;
        case 11: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->Instalacion(); break;
        case 13: _t->Desinstalacion(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData makefile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject makefile::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_makefile,
      qt_meta_data_makefile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &makefile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *makefile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *makefile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_makefile))
        return static_cast<void*>(const_cast< makefile*>(this));
    return QDialog::qt_metacast(_clname);
}

int makefile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void makefile::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
