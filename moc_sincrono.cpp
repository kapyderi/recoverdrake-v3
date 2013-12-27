/****************************************************************************
** Meta object code from reading C++ file 'sincrono.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sincrono.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sincrono.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_sincrono[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,    9,    9,    9, 0x08,
      71,    9,    9,    9, 0x08,
      98,    9,    9,    9, 0x08,
     125,    9,    9,    9, 0x08,
     151,    9,    9,    9, 0x08,
     177,    9,    9,    9, 0x08,
     203,    9,    9,    9, 0x08,
     229,    9,    9,    9, 0x08,
     253,    9,    9,    9, 0x08,
     279,    9,    9,    9, 0x08,
     305,    9,    9,    9, 0x08,
     331,    9,    9,    9, 0x08,
     358,    9,    9,    9, 0x08,
     385,    9,    9,    9, 0x08,
     400,  394,    9,    9, 0x08,
     425,  421,    9,    9, 0x08,
     446,    9,    9,    9, 0x08,
     458,    9,    9,    9, 0x08,
     485,    9,    9,    9, 0x08,
     517,  512,    9,    9, 0x08,
     552,  512,    9,    9, 0x08,
     597,  585,    9,    9, 0x08,
     620,    9,    9,    9, 0x08,
     652,    9,    9,    9, 0x08,
     682,    9,    9,    9, 0x08,
     692,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_sincrono[] = {
    "sincrono\0\0Valor,Value\0Terminado(int,QString)\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_13_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_11_clicked()\0"
    "on_pushButton_12_clicked()\0mibFin()\0"
    "valor\0mibEscribir(QString)\0Dat\0"
    "mibprogreso(QString)\0Comprobar()\0"
    "on_pushButton_14_clicked()\0"
    "on_pushButton_15_clicked()\0arg1\0"
    "on_lineEdit_2_textChanged(QString)\0"
    "on_lineEdit_textChanged(QString)\0"
    "ValorComand\0ProcesarValor(QString)\0"
    "on_lineEdit_2_editingFinished()\0"
    "on_lineEdit_editingFinished()\0Montaje()\0"
    "Verificar()\0"
};

void sincrono::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        sincrono *_t = static_cast<sincrono *>(_o);
        switch (_id) {
        case 0: _t->Terminado((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_5_clicked(); break;
        case 2: _t->on_pushButton_10_clicked(); break;
        case 3: _t->on_pushButton_13_clicked(); break;
        case 4: _t->on_pushButton_7_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_pushButton_9_clicked(); break;
        case 7: _t->on_pushButton_8_clicked(); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_pushButton_3_clicked(); break;
        case 10: _t->on_pushButton_4_clicked(); break;
        case 11: _t->on_pushButton_6_clicked(); break;
        case 12: _t->on_pushButton_11_clicked(); break;
        case 13: _t->on_pushButton_12_clicked(); break;
        case 14: _t->mibFin(); break;
        case 15: _t->mibEscribir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->mibprogreso((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->Comprobar(); break;
        case 18: _t->on_pushButton_14_clicked(); break;
        case 19: _t->on_pushButton_15_clicked(); break;
        case 20: _t->on_lineEdit_2_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->ProcesarValor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->on_lineEdit_2_editingFinished(); break;
        case 24: _t->on_lineEdit_editingFinished(); break;
        case 25: _t->Montaje(); break;
        case 26: _t->Verificar(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData sincrono::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject sincrono::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_sincrono,
      qt_meta_data_sincrono, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &sincrono::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *sincrono::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *sincrono::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_sincrono))
        return static_cast<void*>(const_cast< sincrono*>(this));
    return QDialog::qt_metacast(_clname);
}

int sincrono::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void sincrono::Terminado(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
