/****************************************************************************
** Meta object code from reading C++ file 'colordiagram.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../medicine/colordiagram.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colordiagram.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ColorDiagram_t {
    QByteArrayData data[8];
    char stringdata[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ColorDiagram_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ColorDiagram_t qt_meta_stringdata_ColorDiagram = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 31),
QT_MOC_LITERAL(2, 45, 0),
QT_MOC_LITERAL(3, 46, 8),
QT_MOC_LITERAL(4, 55, 8),
QT_MOC_LITERAL(5, 64, 18),
QT_MOC_LITERAL(6, 83, 19),
QT_MOC_LITERAL(7, 103, 19)
    },
    "ColorDiagram\0on_horizontalSlider_sliderMoved\0"
    "\0position\0nextStep\0on_playBtn_clicked\0"
    "on_scalaBtn_pressed\0on_sbrosBtn_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorDiagram[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08,
       4,    0,   42,    2, 0x08,
       5,    0,   43,    2, 0x08,
       6,    0,   44,    2, 0x08,
       7,    0,   45,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ColorDiagram::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ColorDiagram *_t = static_cast<ColorDiagram *>(_o);
        switch (_id) {
        case 0: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->nextStep(); break;
        case 2: _t->on_playBtn_clicked(); break;
        case 3: _t->on_scalaBtn_pressed(); break;
        case 4: _t->on_sbrosBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ColorDiagram::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ColorDiagram.data,
      qt_meta_data_ColorDiagram,  qt_static_metacall, 0, 0}
};


const QMetaObject *ColorDiagram::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorDiagram::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorDiagram.stringdata))
        return static_cast<void*>(const_cast< ColorDiagram*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ColorDiagram::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
