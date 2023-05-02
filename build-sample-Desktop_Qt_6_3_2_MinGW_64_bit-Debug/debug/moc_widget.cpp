/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../stage2/widget.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    uint offsetsAndSizes[46];
    char stringdata0[7];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[13];
    char stringdata5[12];
    char stringdata6[7];
    char stringdata7[12];
    char stringdata8[5];
    char stringdata9[23];
    char stringdata10[26];
    char stringdata11[26];
    char stringdata12[8];
    char stringdata13[10];
    char stringdata14[6];
    char stringdata15[21];
    char stringdata16[22];
    char stringdata17[21];
    char stringdata18[22];
    char stringdata19[24];
    char stringdata20[26];
    char stringdata21[21];
    char stringdata22[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Widget_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
        QT_MOC_LITERAL(0, 6),  // "Widget"
        QT_MOC_LITERAL(7, 13),  // "updatedisplay"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(44, 12),  // "receieveData"
        QT_MOC_LITERAL(57, 11),  // "QTcpSocket*"
        QT_MOC_LITERAL(69, 6),  // "client"
        QT_MOC_LITERAL(76, 11),  // "NetworkData"
        QT_MOC_LITERAL(88, 4),  // "data"
        QT_MOC_LITERAL(93, 22),  // "receieveDataFromServer"
        QT_MOC_LITERAL(116, 25),  // "onClientSendButtonClicked"
        QT_MOC_LITERAL(142, 25),  // "onServerSendButtonClicked"
        QT_MOC_LITERAL(168, 7),  // "reStart"
        QT_MOC_LITERAL(176, 9),  // "reConnect"
        QT_MOC_LITERAL(186, 5),  // "reSet"
        QT_MOC_LITERAL(192, 20),  // "on_CREADY_OP_clicked"
        QT_MOC_LITERAL(213, 21),  // "on_CREJECT_OP_clicked"
        QT_MOC_LITERAL(235, 20),  // "on_SREADY_OP_clicked"
        QT_MOC_LITERAL(256, 21),  // "on_SREJECT_OP_clicked"
        QT_MOC_LITERAL(278, 23),  // "on_CilentGiveup_clicked"
        QT_MOC_LITERAL(302, 25),  // "on_ServerGiveup_2_clicked"
        QT_MOC_LITERAL(328, 20),  // "on_CLEAVE_OP_clicked"
        QT_MOC_LITERAL(349, 20)   // "on_SLEAVE_OP_clicked"
    },
    "Widget",
    "updatedisplay",
    "",
    "on_pushButton_clicked",
    "receieveData",
    "QTcpSocket*",
    "client",
    "NetworkData",
    "data",
    "receieveDataFromServer",
    "onClientSendButtonClicked",
    "onServerSendButtonClicked",
    "reStart",
    "reConnect",
    "reSet",
    "on_CREADY_OP_clicked",
    "on_CREJECT_OP_clicked",
    "on_SREADY_OP_clicked",
    "on_SREJECT_OP_clicked",
    "on_CilentGiveup_clicked",
    "on_ServerGiveup_2_clicked",
    "on_CLEAVE_OP_clicked",
    "on_SLEAVE_OP_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x0a,    1 /* Public */,
       3,    0,  117,    2, 0x08,    2 /* Private */,
       4,    2,  118,    2, 0x08,    3 /* Private */,
       9,    1,  123,    2, 0x08,    6 /* Private */,
      10,    0,  126,    2, 0x08,    8 /* Private */,
      11,    0,  127,    2, 0x08,    9 /* Private */,
      12,    0,  128,    2, 0x08,   10 /* Private */,
      13,    0,  129,    2, 0x08,   11 /* Private */,
      14,    0,  130,    2, 0x08,   12 /* Private */,
      15,    0,  131,    2, 0x08,   13 /* Private */,
      16,    0,  132,    2, 0x08,   14 /* Private */,
      17,    0,  133,    2, 0x08,   15 /* Private */,
      18,    0,  134,    2, 0x08,   16 /* Private */,
      19,    0,  135,    2, 0x08,   17 /* Private */,
      20,    0,  136,    2, 0x08,   18 /* Private */,
      21,    0,  137,    2, 0x08,   19 /* Private */,
      22,    0,  138,    2, 0x08,   20 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
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

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updatedisplay(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->receieveData((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<NetworkData>>(_a[2]))); break;
        case 3: _t->receieveDataFromServer((*reinterpret_cast< std::add_pointer_t<NetworkData>>(_a[1]))); break;
        case 4: _t->onClientSendButtonClicked(); break;
        case 5: _t->onServerSendButtonClicked(); break;
        case 6: _t->reStart(); break;
        case 7: _t->reConnect(); break;
        case 8: _t->reSet(); break;
        case 9: _t->on_CREADY_OP_clicked(); break;
        case 10: _t->on_CREJECT_OP_clicked(); break;
        case 11: _t->on_SREADY_OP_clicked(); break;
        case 12: _t->on_SREJECT_OP_clicked(); break;
        case 13: _t->on_CilentGiveup_clicked(); break;
        case 14: _t->on_ServerGiveup_2_clicked(); break;
        case 15: _t->on_CLEAVE_OP_clicked(); break;
        case 16: _t->on_SLEAVE_OP_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.offsetsAndSizes,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Widget_t
, QtPrivate::TypeAndForceComplete<Widget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>, QtPrivate::TypeAndForceComplete<NetworkData, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<NetworkData, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
