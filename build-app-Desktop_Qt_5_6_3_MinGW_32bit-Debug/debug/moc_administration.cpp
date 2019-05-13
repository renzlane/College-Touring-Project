/****************************************************************************
** Meta object code from reading C++ file 'administration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../app/admin/administration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'administration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_administration_t {
    QByteArrayData data[25];
    char stringdata0[440];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_administration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_administration_t qt_meta_stringdata_administration = {
    {
QT_MOC_LITERAL(0, 0, 14), // "administration"
QT_MOC_LITERAL(1, 15, 15), // "reloadDistances"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 15), // "reloadSouvenirs"
QT_MOC_LITERAL(4, 48, 20), // "on_campusInfoChanged"
QT_MOC_LITERAL(5, 69, 17), // "on_addedNewCampus"
QT_MOC_LITERAL(6, 87, 4), // "name"
QT_MOC_LITERAL(7, 92, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 114, 36), // "on_campusSelector_currentItem..."
QT_MOC_LITERAL(9, 151, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 168, 7), // "current"
QT_MOC_LITERAL(11, 176, 8), // "previous"
QT_MOC_LITERAL(12, 185, 23), // "on_renameButton_clicked"
QT_MOC_LITERAL(13, 209, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(14, 233, 29), // "on_distancesTable_cellChanged"
QT_MOC_LITERAL(15, 263, 3), // "row"
QT_MOC_LITERAL(16, 267, 6), // "column"
QT_MOC_LITERAL(17, 274, 35), // "on_souvenirTable_currentCellC..."
QT_MOC_LITERAL(18, 310, 10), // "currentRow"
QT_MOC_LITERAL(19, 321, 13), // "currentColumn"
QT_MOC_LITERAL(20, 335, 11), // "previousRow"
QT_MOC_LITERAL(21, 347, 14), // "previousColumn"
QT_MOC_LITERAL(22, 362, 28), // "on_souvenirTable_cellChanged"
QT_MOC_LITERAL(23, 391, 22), // "on_souvenirAdd_clicked"
QT_MOC_LITERAL(24, 414, 25) // "on_souvenirDelete_clicked"

    },
    "administration\0reloadDistances\0\0"
    "reloadSouvenirs\0on_campusInfoChanged\0"
    "on_addedNewCampus\0name\0on_pushButton_clicked\0"
    "on_campusSelector_currentItemChanged\0"
    "QListWidgetItem*\0current\0previous\0"
    "on_renameButton_clicked\0on_deleteButton_clicked\0"
    "on_distancesTable_cellChanged\0row\0"
    "column\0on_souvenirTable_currentCellChanged\0"
    "currentRow\0currentColumn\0previousRow\0"
    "previousColumn\0on_souvenirTable_cellChanged\0"
    "on_souvenirAdd_clicked\0on_souvenirDelete_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_administration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    2,   86,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    2,   93,    2, 0x08 /* Private */,
      17,    4,   98,    2, 0x08 /* Private */,
      22,    2,  107,    2, 0x08 /* Private */,
      23,    0,  112,    2, 0x08 /* Private */,
      24,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   18,   19,   20,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void administration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        administration *_t = static_cast<administration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reloadDistances(); break;
        case 1: _t->reloadSouvenirs(); break;
        case 2: _t->on_campusInfoChanged(); break;
        case 3: _t->on_addedNewCampus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_campusSelector_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 6: _t->on_renameButton_clicked(); break;
        case 7: _t->on_deleteButton_clicked(); break;
        case 8: _t->on_distancesTable_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->on_souvenirTable_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 10: _t->on_souvenirTable_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->on_souvenirAdd_clicked(); break;
        case 12: _t->on_souvenirDelete_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject administration::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_administration.data,
      qt_meta_data_administration,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *administration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *administration::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_administration.stringdata0))
        return static_cast<void*>(const_cast< administration*>(this));
    return QDialog::qt_metacast(_clname);
}

int administration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
