/****************************************************************************
** Meta object code from reading C++ file 'ihm_serveur.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ServeurAgenceBDD/ihm_serveur.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ihm_serveur.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSIHM_ServeurENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSIHM_ServeurENDCLASS = QtMocHelpers::stringData(
    "IHM_Serveur",
    "on_pushButtonLancer_clicked",
    "",
    "onQTcpSocket_connected",
    "onQTcpSocket_disconnected",
    "onQTcpSocket_readyRead",
    "onQTcpSocket_errorOccured",
    "QAbstractSocket::SocketError",
    "socketError",
    "onQTcpServer_newConnection"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSIHM_ServeurENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[12];
    char stringdata1[28];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[26];
    char stringdata5[23];
    char stringdata6[26];
    char stringdata7[29];
    char stringdata8[12];
    char stringdata9[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSIHM_ServeurENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSIHM_ServeurENDCLASS_t qt_meta_stringdata_CLASSIHM_ServeurENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "IHM_Serveur"
        QT_MOC_LITERAL(12, 27),  // "on_pushButtonLancer_clicked"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 22),  // "onQTcpSocket_connected"
        QT_MOC_LITERAL(64, 25),  // "onQTcpSocket_disconnected"
        QT_MOC_LITERAL(90, 22),  // "onQTcpSocket_readyRead"
        QT_MOC_LITERAL(113, 25),  // "onQTcpSocket_errorOccured"
        QT_MOC_LITERAL(139, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(168, 11),  // "socketError"
        QT_MOC_LITERAL(180, 26)   // "onQTcpServer_newConnection"
    },
    "IHM_Serveur",
    "on_pushButtonLancer_clicked",
    "",
    "onQTcpSocket_connected",
    "onQTcpSocket_disconnected",
    "onQTcpSocket_readyRead",
    "onQTcpSocket_errorOccured",
    "QAbstractSocket::SocketError",
    "socketError",
    "onQTcpServer_newConnection"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSIHM_ServeurENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    1,   54,    2, 0x08,    5 /* Private */,
       9,    0,   57,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject IHM_Serveur::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSIHM_ServeurENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSIHM_ServeurENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSIHM_ServeurENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<IHM_Serveur, std::true_type>,
        // method 'on_pushButtonLancer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpSocket_connected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpSocket_disconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpSocket_readyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onQTcpSocket_errorOccured'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'onQTcpServer_newConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void IHM_Serveur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IHM_Serveur *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButtonLancer_clicked(); break;
        case 1: _t->onQTcpSocket_connected(); break;
        case 2: _t->onQTcpSocket_disconnected(); break;
        case 3: _t->onQTcpSocket_readyRead(); break;
        case 4: _t->onQTcpSocket_errorOccured((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 5: _t->onQTcpServer_newConnection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject *IHM_Serveur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IHM_Serveur::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSIHM_ServeurENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int IHM_Serveur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
