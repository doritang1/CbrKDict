/****************************************************************************
** Meta object code from reading C++ file 'document.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../document.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'document.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Document_t {
    QByteArrayData data[14];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Document_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Document_t qt_meta_stringdata_Document = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Document"
QT_MOC_LITERAL(1, 9, 11), // "textChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "text"
QT_MOC_LITERAL(4, 27, 16), // "dataCountChanged"
QT_MOC_LITERAL(5, 44, 15), // "plainTextLoaded"
QT_MOC_LITERAL(6, 60, 9), // "plainText"
QT_MOC_LITERAL(7, 70, 16), // "htmlTextReceived"
QT_MOC_LITERAL(8, 87, 7), // "setHtml"
QT_MOC_LITERAL(9, 95, 5), // "html2"
QT_MOC_LITERAL(10, 101, 12), // "setDataCount"
QT_MOC_LITERAL(11, 114, 12), // "setPlainText"
QT_MOC_LITERAL(12, 127, 8), // "htmlText"
QT_MOC_LITERAL(13, 136, 9) // "dataCount"

    },
    "Document\0textChanged\0\0text\0dataCountChanged\0"
    "plainTextLoaded\0plainText\0htmlTextReceived\0"
    "setHtml\0html2\0setDataCount\0setPlainText\0"
    "htmlText\0dataCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Document[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       4,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,
       7,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   59,    2, 0x0a /* Public */,
      10,    0,   62,    2, 0x0a /* Public */,
      11,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495803,
       6, QMetaType::QString, 0x00495803,
      12, QMetaType::QString, 0x00495803,
      13, QMetaType::Int, 0x00495803,

 // properties: notify_signal_id
       0,
       2,
       3,
       1,

       0        // eod
};

void Document::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Document *_t = static_cast<Document *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->dataCountChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->plainTextLoaded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->htmlTextReceived(); break;
        case 4: _t->setHtml((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setDataCount(); break;
        case 6: _t->setPlainText(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Document::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::textChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Document::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::dataCountChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Document::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::plainTextLoaded)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Document::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Document::htmlTextReceived)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Document *_t = static_cast<Document *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->m_text; break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->m_plainText; break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->m_html; break;
        case 3: *reinterpret_cast< int*>(_v) = _t->m_dataNum; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Document *_t = static_cast<Document *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_text != *reinterpret_cast< QString*>(_v)) {
                _t->m_text = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->textChanged(_t->m_text);
            }
            break;
        case 1:
            if (_t->m_plainText != *reinterpret_cast< QString*>(_v)) {
                _t->m_plainText = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->plainTextLoaded(_t->m_plainText);
            }
            break;
        case 2:
            if (_t->m_html != *reinterpret_cast< QString*>(_v)) {
                _t->m_html = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->htmlTextReceived();
            }
            break;
        case 3:
            if (_t->m_dataNum != *reinterpret_cast< int*>(_v)) {
                _t->m_dataNum = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->dataCountChanged(_t->m_dataNum);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Document::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Document.data,
      qt_meta_data_Document,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Document::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Document::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Document.stringdata0))
        return static_cast<void*>(const_cast< Document*>(this));
    return QObject::qt_metacast(_clname);
}

int Document::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Document::textChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Document::dataCountChanged(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Document::plainTextLoaded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Document::htmlTextReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
