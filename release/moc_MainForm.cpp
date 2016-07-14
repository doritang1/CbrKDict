/****************************************************************************
** Meta object code from reading C++ file 'MainForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainForm_t {
    QByteArrayData data[27];
    char stringdata0[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainForm_t qt_meta_stringdata_MainForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainForm"
QT_MOC_LITERAL(1, 9, 28), // "updateCategoryLevel2ListView"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 28), // "updateCategoryLevel3ListView"
QT_MOC_LITERAL(4, 68, 18), // "updateContentPanel"
QT_MOC_LITERAL(5, 87, 12), // "focusChanged"
QT_MOC_LITERAL(6, 100, 8), // "QWidget*"
QT_MOC_LITERAL(7, 109, 4), // "from"
QT_MOC_LITERAL(8, 114, 2), // "to"
QT_MOC_LITERAL(9, 117, 14), // "insertCategory"
QT_MOC_LITERAL(10, 132, 11), // "addCategory"
QT_MOC_LITERAL(11, 144, 14), // "deleteCategory"
QT_MOC_LITERAL(12, 159, 15), // "confirmCategory"
QT_MOC_LITERAL(13, 175, 10), // "addContent"
QT_MOC_LITERAL(14, 186, 13), // "deleteContent"
QT_MOC_LITERAL(15, 200, 14), // "confirmContent"
QT_MOC_LITERAL(16, 215, 14), // "currentContent"
QT_MOC_LITERAL(17, 230, 9), // "printBody"
QT_MOC_LITERAL(18, 240, 9), // "slotPrint"
QT_MOC_LITERAL(19, 250, 9), // "QPrinter*"
QT_MOC_LITERAL(20, 260, 11), // "printReport"
QT_MOC_LITERAL(21, 272, 8), // "setValue"
QT_MOC_LITERAL(22, 281, 5), // "recNo"
QT_MOC_LITERAL(23, 287, 9), // "paramName"
QT_MOC_LITERAL(24, 297, 9), // "QVariant&"
QT_MOC_LITERAL(25, 307, 10), // "paramValue"
QT_MOC_LITERAL(26, 318, 10) // "reportPage"

    },
    "MainForm\0updateCategoryLevel2ListView\0"
    "\0updateCategoryLevel3ListView\0"
    "updateContentPanel\0focusChanged\0"
    "QWidget*\0from\0to\0insertCategory\0"
    "addCategory\0deleteCategory\0confirmCategory\0"
    "addContent\0deleteContent\0confirmContent\0"
    "currentContent\0printBody\0slotPrint\0"
    "QPrinter*\0printReport\0setValue\0recNo\0"
    "paramName\0QVariant&\0paramValue\0"
    "reportPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    2,   97,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    1,  111,    2, 0x08 /* Private */,
      20,    0,  114,    2, 0x08 /* Private */,
      21,    4,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, 0x80000000 | 24, QMetaType::Int,   22,   23,   25,   26,

       0        // eod
};

void MainForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainForm *_t = static_cast<MainForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateCategoryLevel2ListView(); break;
        case 1: _t->updateCategoryLevel3ListView(); break;
        case 2: _t->updateContentPanel(); break;
        case 3: _t->focusChanged((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 4: _t->insertCategory(); break;
        case 5: _t->addCategory(); break;
        case 6: _t->deleteCategory(); break;
        case 7: _t->confirmCategory(); break;
        case 8: _t->addContent(); break;
        case 9: _t->deleteContent(); break;
        case 10: _t->confirmContent(); break;
        case 11: _t->currentContent(); break;
        case 12: _t->printBody(); break;
        case 13: _t->slotPrint((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        case 14: _t->printReport(); break;
        case 15: _t->setValue((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainForm.data,
      qt_meta_data_MainForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainForm.stringdata0))
        return static_cast<void*>(const_cast< MainForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
