/****************************************************************************
** Meta object code from reading C++ file 'chosencampusclass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../app/chosencampusclass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chosencampusclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_chosencampusclass_t {
    QByteArrayData data[7];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chosencampusclass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chosencampusclass_t qt_meta_stringdata_chosencampusclass = {
    {
QT_MOC_LITERAL(0, 0, 17), // "chosencampusclass"
QT_MOC_LITERAL(1, 18, 24), // "on_finish_button_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 44), // "on_choosecampus_listwidget_it..."
QT_MOC_LITERAL(4, 89, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 106, 4), // "item"
QT_MOC_LITERAL(6, 111, 45) // "on_choosecampus_listwidget2_i..."

    },
    "chosencampusclass\0on_finish_button_clicked\0"
    "\0on_choosecampus_listwidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0"
    "on_choosecampus_listwidget2_itemDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chosencampusclass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    1,   30,    2, 0x08 /* Private */,
       6,    1,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void chosencampusclass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chosencampusclass *_t = static_cast<chosencampusclass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_finish_button_clicked(); break;
        case 1: _t->on_choosecampus_listwidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_choosecampus_listwidget2_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject chosencampusclass::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_chosencampusclass.data,
      qt_meta_data_chosencampusclass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *chosencampusclass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chosencampusclass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_chosencampusclass.stringdata0))
        return static_cast<void*>(const_cast< chosencampusclass*>(this));
    return QDialog::qt_metacast(_clname);
}

int chosencampusclass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
