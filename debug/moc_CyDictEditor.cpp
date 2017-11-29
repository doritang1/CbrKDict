/****************************************************************************
** Meta object code from reading C++ file 'CyDictEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CyDictEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CyDictEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CyDictEditor_t {
    QByteArrayData data[13];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CyDictEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CyDictEditor_t qt_meta_stringdata_CyDictEditor = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CyDictEditor"
QT_MOC_LITERAL(1, 13, 31), // "on_toolButtonFileSelect_clicked"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 26), // "on_pushButtonSplit_clicked"
QT_MOC_LITERAL(4, 73, 29), // "on_pushButtonValidate_clicked"
QT_MOC_LITERAL(5, 103, 26), // "on_pushButtonMerge_clicked"
QT_MOC_LITERAL(6, 130, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(7, 156, 24), // "on_listViewFiles_clicked"
QT_MOC_LITERAL(8, 181, 5), // "index"
QT_MOC_LITERAL(9, 187, 30), // "on_listViewWordFromMap_clicked"
QT_MOC_LITERAL(10, 218, 31), // "on_pushButtonCreateDict_clicked"
QT_MOC_LITERAL(11, 250, 31), // "on_listViewWordFromFile_clicked"
QT_MOC_LITERAL(12, 282, 21) // "on_pushButton_clicked"

    },
    "CyDictEditor\0on_toolButtonFileSelect_clicked\0"
    "\0on_pushButtonSplit_clicked\0"
    "on_pushButtonValidate_clicked\0"
    "on_pushButtonMerge_clicked\0"
    "on_pushButtonSave_clicked\0"
    "on_listViewFiles_clicked\0index\0"
    "on_listViewWordFromMap_clicked\0"
    "on_pushButtonCreateDict_clicked\0"
    "on_listViewWordFromFile_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CyDictEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    1,   69,    2, 0x08 /* Private */,
       9,    1,   72,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    1,   76,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,

       0        // eod
};

void CyDictEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CyDictEditor *_t = static_cast<CyDictEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_toolButtonFileSelect_clicked(); break;
        case 1: _t->on_pushButtonSplit_clicked(); break;
        case 2: _t->on_pushButtonValidate_clicked(); break;
        case 3: _t->on_pushButtonMerge_clicked(); break;
        case 4: _t->on_pushButtonSave_clicked(); break;
        case 5: _t->on_listViewFiles_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_listViewWordFromMap_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonCreateDict_clicked(); break;
        case 8: _t->on_listViewWordFromFile_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject CyDictEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CyDictEditor.data,
      qt_meta_data_CyDictEditor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CyDictEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CyDictEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CyDictEditor.stringdata0))
        return static_cast<void*>(const_cast< CyDictEditor*>(this));
    if (!strcmp(_clname, "Ui::CyDictEditor"))
        return static_cast< Ui::CyDictEditor*>(const_cast< CyDictEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int CyDictEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
