/****************************************************************************
** Meta object code from reading C++ file 'g_lecteurs_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../g_lecteurs_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'g_lecteurs_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_G_Lecteurs_Window_t {
    QByteArrayData data[13];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_G_Lecteurs_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_G_Lecteurs_Window_t qt_meta_stringdata_G_Lecteurs_Window = {
    {
QT_MOC_LITERAL(0, 0, 17), // "G_Lecteurs_Window"
QT_MOC_LITERAL(1, 18, 19), // "on_but_rech_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(4, 63, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(5, 87, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 111, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 133, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(8, 155, 21), // "on_buttonBox_rejected"
QT_MOC_LITERAL(9, 177, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(10, 209, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(11, 226, 4), // "item"
QT_MOC_LITERAL(12, 231, 25) // "on_tout_supprimer_clicked"

    },
    "G_Lecteurs_Window\0on_but_rech_clicked\0"
    "\0on_pushButton_4_clicked\0"
    "on_pushButton_3_clicked\0on_pushButton_2_clicked\0"
    "on_pushButton_clicked\0on_buttonBox_accepted\0"
    "on_buttonBox_rejected\0"
    "on_listWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_tout_supprimer_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_G_Lecteurs_Window[] = {

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
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      12,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,

       0        // eod
};

void G_Lecteurs_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<G_Lecteurs_Window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_but_rech_clicked(); break;
        case 1: _t->on_pushButton_4_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_buttonBox_accepted(); break;
        case 6: _t->on_buttonBox_rejected(); break;
        case 7: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->on_tout_supprimer_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject G_Lecteurs_Window::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_G_Lecteurs_Window.data,
    qt_meta_data_G_Lecteurs_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *G_Lecteurs_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *G_Lecteurs_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_G_Lecteurs_Window.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int G_Lecteurs_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
