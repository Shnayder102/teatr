/****************************************************************************
** Meta object code from reading C++ file 'more_actor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Teatr/more_actor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'more_actor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_more_actor_t {
    QByteArrayData data[10];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_more_actor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_more_actor_t qt_meta_stringdata_more_actor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "more_actor"
QT_MOC_LITERAL(1, 11, 8), // "setActor"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "Actor"
QT_MOC_LITERAL(4, 27, 5), // "actor"
QT_MOC_LITERAL(5, 33, 5), // "editn"
QT_MOC_LITERAL(6, 39, 3), // "act"
QT_MOC_LITERAL(7, 43, 14), // "disableButtons"
QT_MOC_LITERAL(8, 58, 13), // "enableButtons"
QT_MOC_LITERAL(9, 72, 6) // "accept"

    },
    "more_actor\0setActor\0\0Actor\0actor\0editn\0"
    "act\0disableButtons\0enableButtons\0"
    "accept"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_more_actor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,
       8,    0,   50,    2, 0x0a /* Public */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    0x80000000 | 3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void more_actor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<more_actor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setActor((*reinterpret_cast< Actor(*)>(_a[1]))); break;
        case 1: _t->editn(); break;
        case 2: { Actor _r = _t->act();
            if (_a[0]) *reinterpret_cast< Actor*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->disableButtons(); break;
        case 4: _t->enableButtons(); break;
        case 5: _t->accept(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject more_actor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_more_actor.data,
    qt_meta_data_more_actor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *more_actor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *more_actor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_more_actor.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int more_actor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
