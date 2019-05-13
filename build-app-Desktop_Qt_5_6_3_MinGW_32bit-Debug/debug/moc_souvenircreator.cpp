/****************************************************************************
** Meta object code from reading C++ file 'souvenircreator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../app/admin/souvenircreator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'souvenircreator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Admin__souvenirCreator_t {
    QByteArrayData data[6];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Admin__souvenirCreator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Admin__souvenirCreator_t qt_meta_stringdata_Admin__souvenirCreator = {
    {
QT_MOC_LITERAL(0, 0, 22), // "Admin::souvenirCreator"
QT_MOC_LITERAL(1, 23, 13), // "afterAccepted"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 24), // "on_nameField_textChanged"
QT_MOC_LITERAL(4, 63, 4), // "arg1"
QT_MOC_LITERAL(5, 68, 21) // "on_buttonBox_accepted"

    },
    "Admin::souvenirCreator\0afterAccepted\0"
    "\0on_nameField_textChanged\0arg1\0"
    "on_buttonBox_accepted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Admin__souvenirCreator[] = {

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
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

       0        // eod
};

void Admin::souvenirCreator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        souvenirCreator *_t = static_cast<souvenirCreator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->afterAccepted(); break;
        case 1: _t->on_nameField_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (souvenirCreator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&souvenirCreator::afterAccepted)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Admin::souvenirCreator::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Admin__souvenirCreator.data,
      qt_meta_data_Admin__souvenirCreator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Admin::souvenirCreator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Admin::souvenirCreator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Admin__souvenirCreator.stringdata0))
        return static_cast<void*>(const_cast< souvenirCreator*>(this));
    return QDialog::qt_metacast(_clname);
}

int Admin::souvenirCreator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Admin::souvenirCreator::afterAccepted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
