/****************************************************************************
** Meta object code from reading C++ file 'examen.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "examen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'examen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_examen[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
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
      69,    7,    7,    7, 0x08,
      95,    7,    7,    7, 0x08,
     121,    7,    7,    7, 0x08,
     147,    7,    7,    7, 0x08,
     158,    7,    7,    7, 0x08,
     167,    7,    7,    7, 0x08,
     184,    7,    7,    7, 0x08,
     199,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_examen[] = {
    "examen\0\0Cerrar()\0on_pushButton_7_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_2_clicked()\0pregunta()\0"
    "ramdom()\0AccesoPregunta()\0AccesoRamdom()\0"
    "on_pushButton_3_clicked()\0"
};

void examen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        examen *_t = static_cast<examen *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->on_pushButton_7_clicked(); break;
        case 2: _t->on_pushButton_6_clicked(); break;
        case 3: _t->on_pushButton_5_clicked(); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->pregunta(); break;
        case 7: _t->ramdom(); break;
        case 8: _t->AccesoPregunta(); break;
        case 9: _t->AccesoRamdom(); break;
        case 10: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData examen::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject examen::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_examen,
      qt_meta_data_examen, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &examen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *examen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *examen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_examen))
        return static_cast<void*>(const_cast< examen*>(this));
    return QDialog::qt_metacast(_clname);
}

int examen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void examen::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
