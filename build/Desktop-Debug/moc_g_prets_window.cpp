/****************************************************************************
** Meta object code from reading C++ file 'g_prets_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../g_prets_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'g_prets_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_g_prets_window_t {
    QByteArrayData data[14];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_g_prets_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_g_prets_window_t qt_meta_stringdata_g_prets_window = {
    {
QT_MOC_LITERAL(0, 0, 14), // "g_prets_window"
QT_MOC_LITERAL(1, 15, 23), // "on_nouveau_pret_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 23), // "on_lister_prets_clicked"
QT_MOC_LITERAL(4, 64, 23), // "on_retour_livre_clicked"
QT_MOC_LITERAL(5, 88, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(6, 110, 21), // "on_buttonBox_rejected"
QT_MOC_LITERAL(7, 132, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(8, 164, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 181, 4), // "item"
QT_MOC_LITERAL(10, 186, 17), // "traiterRetourPret"
QT_MOC_LITERAL(11, 204, 6), // "idPret"
QT_MOC_LITERAL(12, 211, 22), // "on_vider_liste_clicked"
QT_MOC_LITERAL(13, 234, 23) // "on_pushButton_4_clicked"

    },
    "g_prets_window\0on_nouveau_pret_clicked\0"
    "\0on_lister_prets_clicked\0"
    "on_retour_livre_clicked\0on_buttonBox_accepted\0"
    "on_buttonBox_rejected\0"
    "on_listWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0traiterRetourPret\0"
    "idPret\0on_vider_liste_clicked\0"
    "on_pushButton_4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_g_prets_window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    1,   64,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,
      12,    0,   70,    2, 0x08 /* Private */,
      13,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void g_prets_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<g_prets_window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_nouveau_pret_clicked(); break;
        case 1: _t->on_lister_prets_clicked(); break;
        case 2: _t->on_retour_livre_clicked(); break;
        case 3: _t->on_buttonBox_accepted(); break;
        case 4: _t->on_buttonBox_rejected(); break;
        case 5: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->traiterRetourPret((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_vider_liste_clicked(); break;
        case 8: _t->on_pushButton_4_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject g_prets_window::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_g_prets_window.data,
    qt_meta_data_g_prets_window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *g_prets_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *g_prets_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_g_prets_window.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int g_prets_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
