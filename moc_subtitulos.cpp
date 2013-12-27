/****************************************************************************
** Meta object code from reading C++ file 'subtitulos.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "subtitulos.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'subtitulos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Subtitulos[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      90,   11,   11,   11, 0x08,
     114,   11,   11,   11, 0x08,
     140,   11,   11,   11, 0x08,
     155,  149,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Subtitulos[] = {
    "Subtitulos\0\0on_pushButton_4_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_5_clicked()\0mibFin()\0"
    "valor\0mibEscribir(QString)\0"
};

void Subtitulos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Subtitulos *_t = static_cast<Subtitulos *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_4_clicked(); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_5_clicked(); break;
        case 5: _t->mibFin(); break;
        case 6: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Subtitulos::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Subtitulos::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Subtitulos,
      qt_meta_data_Subtitulos, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Subtitulos::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Subtitulos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Subtitulos::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Subtitulos))
        return static_cast<void*>(const_cast< Subtitulos*>(this));
    return QDialog::qt_metacast(_clname);
}

int Subtitulos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
