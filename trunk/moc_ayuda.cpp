/****************************************************************************
** Meta object code from reading C++ file 'ayuda.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ayuda.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ayuda.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ayuda[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      43,   31,    6,    6, 0x08,
      90,   85,    6,    6, 0x08,
     123,   31,    6,    6, 0x08,
     167,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Ayuda[] = {
    "Ayuda\0\0on_pushButton_clicked()\0"
    "currentText\0on_listWidget_currentTextChanged(QString)\0"
    "arg1\0on_lineEdit_textChanged(QString)\0"
    "on_listWidget_2_currentTextChanged(QString)\0"
    "Comprobar()\0"
};

void Ayuda::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Ayuda *_t = static_cast<Ayuda *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_listWidget_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_listWidget_2_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->Comprobar(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Ayuda::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Ayuda::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Ayuda,
      qt_meta_data_Ayuda, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ayuda::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ayuda::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ayuda::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ayuda))
        return static_cast<void*>(const_cast< Ayuda*>(this));
    return QDialog::qt_metacast(_clname);
}

int Ayuda::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE