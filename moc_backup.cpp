/****************************************************************************
** Meta object code from reading C++ file 'backup.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "backup.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Backup[] = {

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
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      17,    7,    7,    7, 0x08,
      43,    7,    7,    7, 0x08,
      67,    7,    7,    7, 0x08,
      79,    7,    7,    7, 0x08,
     111,  105,    7,    7, 0x08,
     149,  144,    7,    7, 0x08,
     190,    7,    7,    7, 0x08,
     203,    7,    7,    7, 0x08,
     229,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Backup[] = {
    "Backup\0\0Cerrar()\0on_pushButton_3_clicked()\0"
    "on_pushButton_clicked()\0Comprobar()\0"
    "on_pushButton_2_clicked()\0index\0"
    "on_tabWidget_currentChanged(int)\0arg1\0"
    "on_comboBox_currentIndexChanged(QString)\0"
    "Comprobar1()\0on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
};

void Backup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Backup *_t = static_cast<Backup *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->Comprobar(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->Comprobar1(); break;
        case 8: _t->on_pushButton_4_clicked(); break;
        case 9: _t->on_pushButton_5_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Backup::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Backup::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Backup,
      qt_meta_data_Backup, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Backup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Backup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Backup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Backup))
        return static_cast<void*>(const_cast< Backup*>(this));
    return QDialog::qt_metacast(_clname);
}

int Backup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Backup::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
