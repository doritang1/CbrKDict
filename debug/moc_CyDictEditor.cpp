/****************************************************************************
** Meta object code from reading C++ file 'CyDictEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CyDictEditor/CyDictEditor.h"
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
    QByteArrayData data[15];
    char stringdata0[332];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CyDictEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CyDictEditor_t qt_meta_stringdata_CyDictEditor = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CyDictEditor"
QT_MOC_LITERAL(1, 13, 11), // "textWritten"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 31), // "on_toolButtonFileSelect_clicked"
QT_MOC_LITERAL(4, 58, 26), // "on_pushButtonSplit_clicked"
QT_MOC_LITERAL(5, 85, 29), // "on_pushButtonValidate_clicked"
QT_MOC_LITERAL(6, 115, 26), // "on_pushButtonMerge_clicked"
QT_MOC_LITERAL(7, 142, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(8, 168, 24), // "on_listViewFiles_clicked"
QT_MOC_LITERAL(9, 193, 5), // "index"
QT_MOC_LITERAL(10, 199, 30), // "on_listViewWordFromMap_clicked"
QT_MOC_LITERAL(11, 230, 31), // "on_pushButtonCreateDict_clicked"
QT_MOC_LITERAL(12, 262, 31), // "on_listViewWordFromFile_clicked"
QT_MOC_LITERAL(13, 294, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(14, 316, 15) // "slotTextWritten"

    },
    "CyDictEditor\0textWritten\0\0"
    "on_toolButtonFileSelect_clicked\0"
    "on_pushButtonSplit_clicked\0"
    "on_pushButtonValidate_clicked\0"
    "on_pushButtonMerge_clicked\0"
    "on_pushButtonSave_clicked\0"
    "on_listViewFiles_clicked\0index\0"
    "on_listViewWordFromMap_clicked\0"
    "on_pushButtonCreateDict_clicked\0"
    "on_listViewWordFromFile_clicked\0"
    "on_pushButton_clicked\0slotTextWritten"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CyDictEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   77,    2, 0x08 /* Private */,
       4,    0,   78,    2, 0x08 /* Private */,
       5,    0,   79,    2, 0x08 /* Private */,
       6,    0,   80,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    1,   82,    2, 0x08 /* Private */,
      10,    1,   85,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    1,   89,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    1,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void CyDictEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CyDictEditor *_t = static_cast<CyDictEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->textWritten((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_toolButtonFileSelect_clicked(); break;
        case 2: _t->on_pushButtonSplit_clicked(); break;
        case 3: _t->on_pushButtonValidate_clicked(); break;
        case 4: _t->on_pushButtonMerge_clicked(); break;
        case 5: _t->on_pushButtonSave_clicked(); break;
        case 6: _t->on_listViewFiles_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_listViewWordFromMap_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_pushButtonCreateDict_clicked(); break;
        case 9: _t->on_listViewWordFromFile_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: _t->slotTextWritten((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CyDictEditor::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CyDictEditor::textWritten)) {
                *result = 0;
                return;
            }
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CyDictEditor::textWritten(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
