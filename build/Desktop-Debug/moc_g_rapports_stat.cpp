/****************************************************************************
** Meta object code from reading C++ file 'g_rapports_stat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../g_rapports_stat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'g_rapports_stat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_g_rapports_stat_t {
    QByteArrayData data[7];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_g_rapports_stat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_g_rapports_stat_t qt_meta_stringdata_g_rapports_stat = {
    {
QT_MOC_LITERAL(0, 0, 15), // "g_rapports_stat"
QT_MOC_LITERAL(1, 16, 29), // "on_btn_stats_lecteurs_clicked"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 27), // "on_btn_stats_livres_clicked"
QT_MOC_LITERAL(4, 75, 26), // "on_btn_stats_prets_clicked"
QT_MOC_LITERAL(5, 102, 28), // "on_btn_stats_general_clicked"
QT_MOC_LITERAL(6, 131, 21) // "on_btn_retour_clicked"

    },
    "g_rapports_stat\0on_btn_stats_lecteurs_clicked\0"
    "\0on_btn_stats_livres_clicked\0"
    "on_btn_stats_prets_clicked\0"
    "on_btn_stats_general_clicked\0"
    "on_btn_retour_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_g_rapports_stat[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void g_rapports_stat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<g_rapports_stat *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_stats_lecteurs_clicked(); break;
        case 1: _t->on_btn_stats_livres_clicked(); break;
        case 2: _t->on_btn_stats_prets_clicked(); break;
        case 3: _t->on_btn_stats_general_clicked(); break;
        case 4: _t->on_btn_retour_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject g_rapports_stat::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_g_rapports_stat.data,
    qt_meta_data_g_rapports_stat,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *g_rapports_stat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *g_rapports_stat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_g_rapports_stat.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int g_rapports_stat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
