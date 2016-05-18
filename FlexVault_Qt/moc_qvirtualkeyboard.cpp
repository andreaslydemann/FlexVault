/****************************************************************************
** Meta object code from reading C++ file 'qvirtualkeyboard.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qvirtualkeyboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qvirtualkeyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qvirtualkeyboard[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      34,   17,   17,   17, 0x08,
      52,   17,   17,   17, 0x08,
      68,   17,   17,   17, 0x08,
      89,   17,   17,   17, 0x08,
     108,   17,   17,   17, 0x08,
     127,   17,   17,   17, 0x08,
     146,   17,   17,   17, 0x08,
     183,  165,   17,   17, 0x08,
     197,  165,   17,   17, 0x08,
     216,   17,   17,   17, 0x08,
     238,  165,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qvirtualkeyboard[] = {
    "qvirtualkeyboard\0\0createButtons()\0"
    "displayAlphabet()\0displayNumber()\0"
    "displaySpecialChar()\0buttonC2Function()\0"
    "buttonC3Function()\0buttonC4Function()\0"
    "buttonC5Function()\0indexOfCharToSend\0"
    "sendChar(int)\0buttonPressed(int)\0"
    "displayAccentedChar()\0sendAccentedChar(int)\0"
};

void qvirtualkeyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qvirtualkeyboard *_t = static_cast<qvirtualkeyboard *>(_o);
        switch (_id) {
        case 0: _t->createButtons(); break;
        case 1: _t->displayAlphabet(); break;
        case 2: _t->displayNumber(); break;
        case 3: _t->displaySpecialChar(); break;
        case 4: _t->buttonC2Function(); break;
        case 5: _t->buttonC3Function(); break;
        case 6: _t->buttonC4Function(); break;
        case 7: _t->buttonC5Function(); break;
        case 8: _t->sendChar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->buttonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->displayAccentedChar(); break;
        case 11: _t->sendAccentedChar((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qvirtualkeyboard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qvirtualkeyboard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_qvirtualkeyboard,
      qt_meta_data_qvirtualkeyboard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qvirtualkeyboard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qvirtualkeyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qvirtualkeyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qvirtualkeyboard))
        return static_cast<void*>(const_cast< qvirtualkeyboard*>(this));
    return QWidget::qt_metacast(_clname);
}

int qvirtualkeyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
