/****************************************************************************
** Meta object code from reading C++ file 'campuscreator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../app/admin/campuscreator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'campuscreator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Admin__campusCreator_t {
    QByteArrayData data[7];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Admin__campusCreator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Admin__campusCreator_t qt_meta_stringdata_Admin__campusCreator = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Admin::campusCreator"
QT_MOC_LITERAL(1, 21, 16), // "acceptedWithName"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 4), // "name"
QT_MOC_LITERAL(4, 44, 24), // "on_NameField_textChanged"
QT_MOC_LITERAL(5, 69, 4), // "arg1"
QT_MOC_LITERAL(6, 74, 25) // "on_campusCreator_accepted"

    },
    "Admin::campusCreator\0acceptedWithName\0"
    "\0name\0on_NameField_textChanged\0arg1\0"
    "on_campusCreator_accepted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Admin__campusCreator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x08 /* Private */,
       6,    0,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void Admin::campusCreator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        campusCreator *_t = static_cast<campusCreator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->acceptedWithName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_NameField_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_campusCreator_accepted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (campusCreator::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&campusCreator::acceptedWithName)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Admin::campusCreator::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Admin__campusCreator.data,
      qt_meta_data_Admin__campusCreator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Admin::campusCreator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Admin::campusCreator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Admin__campusCreator.stringdata0))
        return static_cast<void*>(const_cast< campusCreator*>(this));
    return QDialog::qt_metacast(_clname);
}

int Admin::campusCreator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Admin::campusCreator::acceptedWithName(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
