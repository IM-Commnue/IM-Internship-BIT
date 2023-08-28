/****************************************************************************
** Meta object code from reading C++ file 'chat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../miniqq+database/chat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_chat_t {
    QByteArrayData data[15];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chat_t qt_meta_stringdata_chat = {
    {
QT_MOC_LITERAL(0, 0, 4), // "chat"
QT_MOC_LITERAL(1, 5, 9), // "changeV2T"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 11), // "changeUIANS"
QT_MOC_LITERAL(4, 28, 18), // "Tuling_replyFinish"
QT_MOC_LITERAL(5, 47, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 62, 5), // "reply"
QT_MOC_LITERAL(7, 68, 24), // "voice_Tuling_replyFinish"
QT_MOC_LITERAL(8, 93, 29), // "Baidu_VoiceToText_replyFinish"
QT_MOC_LITERAL(9, 123, 14), // "get_Token_slot"
QT_MOC_LITERAL(10, 138, 29), // "Baidu_TextToVoice_replyFinish"
QT_MOC_LITERAL(11, 168, 22), // "voice_post_Tuling_slot"
QT_MOC_LITERAL(12, 191, 18), // "on_SendBtn_clicked"
QT_MOC_LITERAL(13, 210, 19), // "on_VoiceBtn_pressed"
QT_MOC_LITERAL(14, 230, 20) // "on_VoiceBtn_released"

    },
    "chat\0changeV2T\0\0changeUIANS\0"
    "Tuling_replyFinish\0QNetworkReply*\0"
    "reply\0voice_Tuling_replyFinish\0"
    "Baidu_VoiceToText_replyFinish\0"
    "get_Token_slot\0Baidu_TextToVoice_replyFinish\0"
    "voice_post_Tuling_slot\0on_SendBtn_clicked\0"
    "on_VoiceBtn_pressed\0on_VoiceBtn_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chat[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   71,    2, 0x0a /* Public */,
       7,    1,   74,    2, 0x0a /* Public */,
       8,    1,   77,    2, 0x0a /* Public */,
       9,    1,   80,    2, 0x0a /* Public */,
      10,    0,   83,    2, 0x0a /* Public */,
      11,    0,   84,    2, 0x0a /* Public */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void chat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<chat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeV2T(); break;
        case 1: _t->changeUIANS(); break;
        case 2: _t->Tuling_replyFinish((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->voice_Tuling_replyFinish((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->Baidu_VoiceToText_replyFinish((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->get_Token_slot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->Baidu_TextToVoice_replyFinish(); break;
        case 7: _t->voice_post_Tuling_slot(); break;
        case 8: _t->on_SendBtn_clicked(); break;
        case 9: _t->on_VoiceBtn_pressed(); break;
        case 10: _t->on_VoiceBtn_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (chat::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chat::changeV2T)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (chat::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chat::changeUIANS)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject chat::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_chat.data,
    qt_meta_data_chat,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *chat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_chat.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int chat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void chat::changeV2T()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void chat::changeUIANS()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
