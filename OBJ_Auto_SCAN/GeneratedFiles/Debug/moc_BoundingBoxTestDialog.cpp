/****************************************************************************
** Meta object code from reading C++ file 'BoundingBoxTestDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/ui/BoundingBoxTestDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BoundingBoxTestDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BoundingBoxTestDialog_t {
    QByteArrayData data[12];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoundingBoxTestDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoundingBoxTestDialog_t qt_meta_stringdata_BoundingBoxTestDialog = {
    {
QT_MOC_LITERAL(0, 0, 21), // "BoundingBoxTestDialog"
QT_MOC_LITERAL(1, 22, 12), // "TestFinished"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "minX"
QT_MOC_LITERAL(4, 41, 4), // "maxX"
QT_MOC_LITERAL(5, 46, 4), // "minY"
QT_MOC_LITERAL(6, 51, 4), // "maxY"
QT_MOC_LITERAL(7, 56, 4), // "minZ"
QT_MOC_LITERAL(8, 61, 4), // "maxZ"
QT_MOC_LITERAL(9, 66, 18), // "SetBoundingBoxSlot"
QT_MOC_LITERAL(10, 85, 10), // "AcceptSlot"
QT_MOC_LITERAL(11, 96, 10) // "RejectSlot"

    },
    "BoundingBoxTestDialog\0TestFinished\0\0"
    "minX\0maxX\0minY\0maxY\0minZ\0maxZ\0"
    "SetBoundingBoxSlot\0AcceptSlot\0RejectSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoundingBoxTestDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   47,    2, 0x0a /* Public */,
      10,    0,   48,    2, 0x0a /* Public */,
      11,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,    3,    4,    5,    6,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BoundingBoxTestDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BoundingBoxTestDialog *_t = static_cast<BoundingBoxTestDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TestFinished((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6]))); break;
        case 1: _t->SetBoundingBoxSlot(); break;
        case 2: _t->AcceptSlot(); break;
        case 3: _t->RejectSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BoundingBoxTestDialog::*_t)(float , float , float , float , float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BoundingBoxTestDialog::TestFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject BoundingBoxTestDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BoundingBoxTestDialog.data,
      qt_meta_data_BoundingBoxTestDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BoundingBoxTestDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoundingBoxTestDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BoundingBoxTestDialog.stringdata0))
        return static_cast<void*>(const_cast< BoundingBoxTestDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int BoundingBoxTestDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void BoundingBoxTestDialog::TestFinished(float _t1, float _t2, float _t3, float _t4, float _t5, float _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
