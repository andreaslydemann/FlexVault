/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "login.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Login[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      29,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,    6,    6,    6, 0x08,
      75,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Login[] = {
    "Login\0\0loginButton_clicked()\0"
    "textChanged(QString)\0on_loginButton_clicked()\0"
    "lineEdit_textChanged()\0"
};

void Login::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Login *_t = static_cast<Login *>(_o);
        switch (_id) {
        case 0: _t->loginButton_clicked(); break;
        case 1: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_loginButton_clicked(); break;
        case 3: _t->lineEdit_textChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Login::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Login::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Login,
      qt_meta_data_Login, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Login::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Login::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Login::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Login))
        return static_cast<void*>(const_cast< Login*>(this));
    return QWidget::qt_metacast(_clname);
}

int Login::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Login::loginButton_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Login::textChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
