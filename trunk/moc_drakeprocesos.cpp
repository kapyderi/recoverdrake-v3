/****************************************************************************
** Meta object code from reading C++ file 'drakeprocesos.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "drakeprocesos.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drakeprocesos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DrakeProcesos[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   15,   14,   14, 0x05,
      44,   14,   14,   14, 0x05,
      65,   57,   14,   14, 0x05,
      90,   85,   14,   14, 0x05,
     120,  108,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     147,  139,   14,   14, 0x08,
     197,  177,   14,   14, 0x08,
     234,   14,   14,   14, 0x08,
     246,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DrakeProcesos[] = {
    "DrakeProcesos\0\0valor\0publicarDatos(QString)\0"
    "finProceso()\0comando\0DatoComand(QString)\0"
    "Dato\0progreso(QString)\0ValorComand\0"
    "ValorDato(QString)\0errores\0"
    "error(QProcess::ProcessError)\0"
    "exitCode,exitStatus\0"
    "finalizado(int,QProcess::ExitStatus)\0"
    "leerError()\0leerOutput()\0"
};

void DrakeProcesos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DrakeProcesos *_t = static_cast<DrakeProcesos *>(_o);
        switch (_id) {
        case 0: _t->publicarDatos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->finProceso(); break;
        case 2: _t->DatoComand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->progreso((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->ValorDato((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->error((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 6: _t->finalizado((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 7: _t->leerError(); break;
        case 8: _t->leerOutput(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DrakeProcesos::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DrakeProcesos::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DrakeProcesos,
      qt_meta_data_DrakeProcesos, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DrakeProcesos::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DrakeProcesos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DrakeProcesos::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DrakeProcesos))
        return static_cast<void*>(const_cast< DrakeProcesos*>(this));
    return QObject::qt_metacast(_clname);
}

int DrakeProcesos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DrakeProcesos::publicarDatos(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DrakeProcesos::finProceso()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void DrakeProcesos::DatoComand(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DrakeProcesos::progreso(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DrakeProcesos::ValorDato(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
