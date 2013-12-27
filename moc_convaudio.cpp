/****************************************************************************
** Meta object code from reading C++ file 'convaudio.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "convaudio.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'convaudio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConvAudio[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      87,   20,   10,   10, 0x08,
     146,   10,   10,   10, 0x08,
     172,   10,   10,   10, 0x08,
     199,   10,   10,   10, 0x08,
     214,  208,   10,   10, 0x08,
     247,  235,   10,   10, 0x08,
     274,  270,   10,   10, 0x08,
     295,   10,   10,   10, 0x08,
     304,   10,   10,   10, 0x08,
     331,   10,   10,   10, 0x08,
     358,   10,   10,   10, 0x08,
     396,  385,   10,   10, 0x08,
     418,   10,   10,   10, 0x08,
     445,   10,   10,   10, 0x08,
     472,   10,   10,   10, 0x08,
     498,   10,   10,   10, 0x08,
     525,   10,   10,   10, 0x08,
     552,   10,   10,   10, 0x08,
     579,   10,   10,   10, 0x08,
     606,   10,   10,   10, 0x08,
     633,   10,   10,   10, 0x08,
     660,   10,   10,   10, 0x08,
     684,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConvAudio[] = {
    "ConvAudio\0\0Cerrar()\0"
    "Valor,band1,band2,band3,band4,band5,band6,band7,band8,band9,band10\0"
    "Ecualizar(QString,int,int,int,int,int,int,int,int,int,int)\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_27_clicked()\0mibFin()\0"
    "valor\0mibEscribir(QString)\0ValorComand\0"
    "ProcesarValor(QString)\0Dat\0"
    "mibprogreso(QString)\0update()\0"
    "on_pushButton_12_clicked()\0"
    "on_pushButton_13_clicked()\0"
    "on_pushButton_14_clicked()\0row,column\0"
    "tableClicked(int,int)\0on_pushButton_24_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_22_clicked()\0"
    "on_pushButton_23_clicked()\0"
    "on_pushButton_18_clicked()\0"
    "on_pushButton_25_clicked()\0"
    "on_pushButton_26_clicked()\0"
    "on_pushButton_11_clicked()\0"
    "on_pushButton_clicked()\0final()\0"
};

void ConvAudio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConvAudio *_t = static_cast<ConvAudio *>(_o);
        switch (_id) {
        case 0: _t->Cerrar(); break;
        case 1: _t->Ecualizar((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11]))); break;
        case 2: _t->on_pushButton_9_clicked(); break;
        case 3: _t->on_pushButton_27_clicked(); break;
        case 4: _t->mibFin(); break;
        case 5: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->ProcesarValor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->mibprogreso((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->update(); break;
        case 9: _t->on_pushButton_12_clicked(); break;
        case 10: _t->on_pushButton_13_clicked(); break;
        case 11: _t->on_pushButton_14_clicked(); break;
        case 12: _t->tableClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->on_pushButton_24_clicked(); break;
        case 14: _t->on_pushButton_10_clicked(); break;
        case 15: _t->on_pushButton_8_clicked(); break;
        case 16: _t->on_pushButton_22_clicked(); break;
        case 17: _t->on_pushButton_23_clicked(); break;
        case 18: _t->on_pushButton_18_clicked(); break;
        case 19: _t->on_pushButton_25_clicked(); break;
        case 20: _t->on_pushButton_26_clicked(); break;
        case 21: _t->on_pushButton_11_clicked(); break;
        case 22: _t->on_pushButton_clicked(); break;
        case 23: _t->final(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConvAudio::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConvAudio::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConvAudio,
      qt_meta_data_ConvAudio, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConvAudio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConvAudio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConvAudio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConvAudio))
        return static_cast<void*>(const_cast< ConvAudio*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConvAudio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void ConvAudio::Cerrar()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
