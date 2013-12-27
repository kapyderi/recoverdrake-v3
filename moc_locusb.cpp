/****************************************************************************
** Meta object code from reading C++ file 'locusb.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "locusb.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'locusb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LocUsb[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      46,    7,    7,    7, 0x08,
      72,    7,    7,    7, 0x08,
      82,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LocUsb[] = {
    "LocUsb\0\0on_tableWidget_itemSelectionChanged()\0"
    "on_pushButton_7_clicked()\0UsbInfo()\0"
    "on_pushButton_8_clicked()\0"
};

void LocUsb::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LocUsb *_t = static_cast<LocUsb *>(_o);
        switch (_id) {
        case 0: _t->on_tableWidget_itemSelectionChanged(); break;
        case 1: _t->on_pushButton_7_clicked(); break;
        case 2: _t->UsbInfo(); break;
        case 3: _t->on_pushButton_8_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LocUsb::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LocUsb::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LocUsb,
      qt_meta_data_LocUsb, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LocUsb::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LocUsb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LocUsb::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LocUsb))
        return static_cast<void*>(const_cast< LocUsb*>(this));
    return QDialog::qt_metacast(_clname);
}

int LocUsb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
