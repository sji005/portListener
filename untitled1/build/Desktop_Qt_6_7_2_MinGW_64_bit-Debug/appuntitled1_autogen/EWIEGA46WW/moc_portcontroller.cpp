/****************************************************************************
** Meta object code from reading C++ file 'portcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../portcontroller.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'portcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
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
struct qt_meta_stringdata_CLASSPortControllerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPortControllerENDCLASS = QtMocHelpers::stringData(
    "PortController",
    "QML.Element",
    "auto",
    "portSwitchError",
    "",
    "readSig",
    "data",
    "baudRateChanged",
    "bitRateChanged",
    "comCountChanged",
    "inputChanged",
    "outputChanged",
    "verifyChanged",
    "stopNumChanged",
    "hardwareStreamChanged",
    "dtrChanged",
    "rtsChanged",
    "openChanged",
    "errorChanged",
    "indexChanged",
    "handleReadyRead",
    "getAllPorts",
    "openPort",
    "closePort",
    "read",
    "write",
    "input",
    "updatePinOut",
    "QList<bool>",
    "baudRate",
    "bitRate",
    "comCount",
    "output",
    "verify",
    "stopNum",
    "hardwareStream",
    "dtr",
    "rts",
    "open",
    "error",
    "index"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPortControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      22,   16, // methods
      13,  174, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  148,    4, 0x06,   14 /* Public */,
       5,    1,  149,    4, 0x06,   15 /* Public */,
       7,    0,  152,    4, 0x06,   17 /* Public */,
       8,    0,  153,    4, 0x06,   18 /* Public */,
       9,    0,  154,    4, 0x06,   19 /* Public */,
      10,    0,  155,    4, 0x06,   20 /* Public */,
      11,    0,  156,    4, 0x06,   21 /* Public */,
      12,    0,  157,    4, 0x06,   22 /* Public */,
      13,    0,  158,    4, 0x06,   23 /* Public */,
      14,    0,  159,    4, 0x06,   24 /* Public */,
      15,    0,  160,    4, 0x06,   25 /* Public */,
      16,    0,  161,    4, 0x06,   26 /* Public */,
      17,    0,  162,    4, 0x06,   27 /* Public */,
      18,    0,  163,    4, 0x06,   28 /* Public */,
      19,    0,  164,    4, 0x06,   29 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      20,    0,  165,    4, 0x08,   30 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      21,    0,  166,    4, 0x02,   31 /* Public */,
      22,    0,  167,    4, 0x02,   32 /* Public */,
      23,    0,  168,    4, 0x02,   33 /* Public */,
      24,    0,  169,    4, 0x02,   34 /* Public */,
      25,    1,  170,    4, 0x02,   35 /* Public */,
      27,    0,  173,    4, 0x02,   37 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::QStringList,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   26,
    0x80000000 | 28,

 // properties: name, type, flags
      29, QMetaType::Int, 0x00015903, uint(2), 0,
      30, QMetaType::Int, 0x00015903, uint(3), 0,
      31, QMetaType::Int, 0x00015903, uint(4), 0,
      26, QMetaType::QString, 0x00015903, uint(5), 0,
      32, QMetaType::QString, 0x00015903, uint(6), 0,
      33, QMetaType::Int, 0x00015903, uint(7), 0,
      34, QMetaType::Int, 0x00015903, uint(8), 0,
      35, QMetaType::Bool, 0x00015903, uint(9), 0,
      36, QMetaType::Bool, 0x00015903, uint(10), 0,
      37, QMetaType::Bool, 0x00015903, uint(11), 0,
      38, QMetaType::Bool, 0x00015903, uint(12), 0,
      39, QMetaType::Int, 0x00015903, uint(13), 0,
      40, QMetaType::Int, 0x00015903, uint(14), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject PortController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSPortControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPortControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'baudRate'
        int,
        // property 'bitRate'
        int,
        // property 'comCount'
        int,
        // property 'input'
        QString,
        // property 'output'
        QString,
        // property 'verify'
        int,
        // property 'stopNum'
        int,
        // property 'hardwareStream'
        bool,
        // property 'dtr'
        bool,
        // property 'rts'
        bool,
        // property 'open'
        bool,
        // property 'error'
        int,
        // property 'index'
        int,
        // Q_OBJECT / Q_GADGET
        PortController,
        // method 'portSwitchError'
        void,
        // method 'readSig'
        void,
        QByteArray,
        // method 'baudRateChanged'
        void,
        // method 'bitRateChanged'
        void,
        // method 'comCountChanged'
        void,
        // method 'inputChanged'
        void,
        // method 'outputChanged'
        void,
        // method 'verifyChanged'
        void,
        // method 'stopNumChanged'
        void,
        // method 'hardwareStreamChanged'
        void,
        // method 'dtrChanged'
        void,
        // method 'rtsChanged'
        void,
        // method 'openChanged'
        void,
        // method 'errorChanged'
        void,
        // method 'indexChanged'
        void,
        // method 'handleReadyRead'
        void,
        // method 'getAllPorts'
        QStringList,
        // method 'openPort'
        void,
        // method 'closePort'
        void,
        // method 'read'
        QString,
        // method 'write'
        void,
        QString,
        // method 'updatePinOut'
        QList<bool>
    >,
    nullptr
} };

void PortController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PortController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->portSwitchError(); break;
        case 1: _t->readSig((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 2: _t->baudRateChanged(); break;
        case 3: _t->bitRateChanged(); break;
        case 4: _t->comCountChanged(); break;
        case 5: _t->inputChanged(); break;
        case 6: _t->outputChanged(); break;
        case 7: _t->verifyChanged(); break;
        case 8: _t->stopNumChanged(); break;
        case 9: _t->hardwareStreamChanged(); break;
        case 10: _t->dtrChanged(); break;
        case 11: _t->rtsChanged(); break;
        case 12: _t->openChanged(); break;
        case 13: _t->errorChanged(); break;
        case 14: _t->indexChanged(); break;
        case 15: _t->handleReadyRead(); break;
        case 16: { QStringList _r = _t->getAllPorts();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->openPort(); break;
        case 18: _t->closePort(); break;
        case 19: { QString _r = _t->read();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->write((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: { QList<bool> _r = _t->updatePinOut();
            if (_a[0]) *reinterpret_cast< QList<bool>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::portSwitchError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PortController::*)(QByteArray );
            if (_t _q_method = &PortController::readSig; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::baudRateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::bitRateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::comCountChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::inputChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::outputChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::verifyChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::stopNumChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::hardwareStreamChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::dtrChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::rtsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::openChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::errorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (PortController::*)();
            if (_t _q_method = &PortController::indexChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<PortController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getBaudRate(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getBitRate(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getComCount(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getInput(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getOutput(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getVerify(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->getStopNum(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->getHardwareStream(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->getDtr(); break;
        case 9: *reinterpret_cast< bool*>(_v) = _t->getRts(); break;
        case 10: *reinterpret_cast< bool*>(_v) = _t->getOpen(); break;
        case 11: *reinterpret_cast< int*>(_v) = _t->getError(); break;
        case 12: *reinterpret_cast< int*>(_v) = _t->getIndex(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<PortController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBaudRate(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setBitRate(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setComCount(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setInput(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setOutput(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setVerify(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setStopNum(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setHardwareStream(*reinterpret_cast< bool*>(_v)); break;
        case 8: _t->setDtr(*reinterpret_cast< bool*>(_v)); break;
        case 9: _t->setRts(*reinterpret_cast< bool*>(_v)); break;
        case 10: _t->setOpen(*reinterpret_cast< bool*>(_v)); break;
        case 11: _t->setError(*reinterpret_cast< int*>(_v)); break;
        case 12: _t->setIndex(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *PortController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PortController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPortControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PortController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 22;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void PortController::portSwitchError()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PortController::readSig(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PortController::baudRateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PortController::bitRateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PortController::comCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void PortController::inputChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void PortController::outputChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void PortController::verifyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void PortController::stopNumChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void PortController::hardwareStreamChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void PortController::dtrChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void PortController::rtsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void PortController::openChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void PortController::errorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void PortController::indexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}
QT_WARNING_POP
