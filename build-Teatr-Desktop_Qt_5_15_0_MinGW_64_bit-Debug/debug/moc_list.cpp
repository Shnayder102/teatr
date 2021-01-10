/****************************************************************************
** Meta object code from reading C++ file 'list.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Teatr/list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_list_t {
    QByteArrayData data[16];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_list_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_list_t qt_meta_stringdata_list = {
    {
QT_MOC_LITERAL(0, 0, 4), // "list"
QT_MOC_LITERAL(1, 5, 9), // "listReady"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 11), // "listCreated"
QT_MOC_LITERAL(4, 28, 10), // "listOpened"
QT_MOC_LITERAL(5, 39, 8), // "fileName"
QT_MOC_LITERAL(6, 48, 9), // "listSaved"
QT_MOC_LITERAL(7, 58, 10), // "listClosed"
QT_MOC_LITERAL(8, 69, 16), // "on_add_triggered"
QT_MOC_LITERAL(9, 86, 18), // "refreshWindowTitle"
QT_MOC_LITERAL(10, 105, 7), // "newList"
QT_MOC_LITERAL(11, 113, 10), // "createlist"
QT_MOC_LITERAL(12, 124, 7), // "setlist"
QT_MOC_LITERAL(13, 132, 11), // "list_users*"
QT_MOC_LITERAL(14, 144, 17), // "on_save_triggered"
QT_MOC_LITERAL(15, 162, 18) // "saveNotebookToFile"

    },
    "list\0listReady\0\0listCreated\0listOpened\0"
    "fileName\0listSaved\0listClosed\0"
    "on_add_triggered\0refreshWindowTitle\0"
    "newList\0createlist\0setlist\0list_users*\0"
    "on_save_triggered\0saveNotebookToFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_list[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    1,   76,    2, 0x06 /* Public */,
       6,    0,   79,    2, 0x06 /* Public */,
       7,    0,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    1,   85,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    1,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    0,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void list::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<list *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listReady(); break;
        case 1: _t->listCreated(); break;
        case 2: _t->listOpened((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->listSaved(); break;
        case 4: _t->listClosed(); break;
        case 5: _t->on_add_triggered(); break;
        case 6: _t->refreshWindowTitle(); break;
        case 7: _t->newList(); break;
        case 8: _t->createlist(); break;
        case 9: _t->setlist((*reinterpret_cast< list_users*(*)>(_a[1]))); break;
        case 10: { bool _r = _t->on_save_triggered();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->saveNotebookToFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< list_users* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (list::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&list::listReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (list::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&list::listCreated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (list::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&list::listOpened)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (list::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&list::listSaved)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (list::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&list::listClosed)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject list::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_list.data,
    qt_meta_data_list,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *list::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *list::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_list.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int list::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void list::listReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void list::listCreated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void list::listOpened(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void list::listSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void list::listClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
