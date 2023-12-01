/****************************************************************************
** Meta object code from reading C++ file 'dab_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ClientAgence/dab_window.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dab_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDAB_WindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDAB_WindowENDCLASS = QtMocHelpers::stringData(
    "DAB_Window",
    "on_pushButtonValider_clicked",
    "",
    "on_pushButtonConnexion_clicked",
    "onQComboBox_currentIndexChanged",
    "index",
    "onQTcpSocket_connected",
    "onQTcpSocket_disconnected",
    "onQTcpSocket_readyRead",
    "onQTcpSocket_errorOccured",
    "QAbstractSocket::SocketError",
    "socketError"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDAB_WindowENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[11];
    char stringdata1[29];
    char stringdata2[1];
    char stringdata3[31];
    char stringdata4[32];
    char stringdata5[6];
    char stringdata6[23];
    char stringdata7[26];
    char stringdata8[23];
    char stringdata9[26];
    char stringdata10[29];
    char stringdata11[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDAB_WindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDAB_WindowENDCLASS_t qt_meta_stringdata_CLASSDAB_WindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "DAB_Window"
        QT_MOC_LITERAL(11, 28),  // "on_pushButtonValider_clicked"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 30),  // "on_pushButtonConnexion_clicked"
        QT_MOC_LITERAL(72, 31),  // "onQComboBox_currentIndexChanged"
        QT_MOC_LITERAL(104, 5),  // "index"
        QT_MOC_LITERAL(110, 22),  // "onQTcpSocket_connected"
        QT_MOC_LITERAL(133, 25),  // "onQTcpSocket_disconnected"
        QT_MOC_LITERAL(159, 22),  // "onQTcpSocket_readyRead"
        QT_MOC_LITERAL(182, 25),  // "onQTcpSocket_errorOccured"
        QT_MOC_LITERAL(208, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(237, 11)   // "socketError"
    },
    "DAB_Window",
    "on_pushButtonValider_clicked",
    "",
    "on_pushButtonConnexion_clicked",
    "onQComboBox_currentIndexChanged",
    "index",
    "onQTcpSocket_connected",
    "onQTcpSocket_disconnected",
    "onQTcpSocket_readyRead",
    "onQTcpSocket_errorOccured",
    "QAbstractSocket::SocketError",
    "socketError"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDAB_WindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    1,   58,    2, 0x08,    3 /* Private */,
       6,    0,   61,    2, 0x08,    5 /* Private */,
       7,    0,   62,    2, 0x08,    6 /* Private */,
       8,    0,   63,    2, 0x08,    7 /* Private */,
       9,    1,   64,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject DAB_Window::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSDAB_WindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDAB_WindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDAB_WindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DAB_Window, std::true_type>,
        // method 'on_pushButtonValider_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonConnexion_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQComboBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onQTcpSocket_connected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpSocket_disconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpSocket_readyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpSocket_errorOccured'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>
    >,
    nullptr
} };

void DAB_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DAB_Window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButtonValider_clicked(); break;
        case 1: _t->on_pushButtonConnexion_clicked(); break;
        case 2: _t->onQComboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->onQTcpSocket_connected(); break;
        case 4: _t->onQTcpSocket_disconnected(); break;
        case 5: _t->onQTcpSocket_readyRead(); break;
        case 6: _t->onQTcpSocket_errorOccured((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject *DAB_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DAB_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDAB_WindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DAB_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
