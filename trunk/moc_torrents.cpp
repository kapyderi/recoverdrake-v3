/****************************************************************************
** Meta object code from reading C++ file 'torrents.h'
**
** Created: Mon Oct 8 10:46:45 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "torrents.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'torrents.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_torrents[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      36,    9,    9,    9, 0x08,
      62,    9,    9,    9, 0x08,
      86,    9,    9,    9, 0x08,
     112,    9,    9,    9, 0x08,
     124,    9,    9,    9, 0x08,
     139,  133,    9,    9, 0x08,
     167,  160,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_torrents[] = {
    "torrents\0\0on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_4_clicked()\0Comprobar()\0"
    "mibFin()\0valor\0mibEscribir(QString)\0"
    "reason\0iconActivated(QSystemTrayIcon::ActivationReason)\0"
};

void torrents::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        torrents *_t = static_cast<torrents *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_3_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        case 4: _t->Comprobar(); break;
        case 5: _t->mibFin(); break;
        case 6: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData torrents::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject torrents::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_torrents,
      qt_meta_data_torrents, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &torrents::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *torrents::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *torrents::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_torrents))
        return static_cast<void*>(const_cast< torrents*>(this));
    return QDialog::qt_metacast(_clname);
}

int torrents::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
