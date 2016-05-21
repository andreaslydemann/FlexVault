/****************************************************************************
** Meta object code from reading C++ file 'userconfiguration.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "userconfiguration.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userconfiguration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UserConfiguration[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   18,   18,   18, 0x08,
      72,   18,   18,   18, 0x08,
     102,   18,   18,   18, 0x08,
     128,   18,   18,   18, 0x08,
     152,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UserConfiguration[] = {
    "UserConfiguration\0\0privilegesButton_clicked()\0"
    "on_createButton_clicked()\0"
    "on_privilegesButton_clicked()\0"
    "on_deleteButton_clicked()\0"
    "on_backButton_clicked()\0updateUConf()\0"
};

void UserConfiguration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UserConfiguration *_t = static_cast<UserConfiguration *>(_o);
        switch (_id) {
        case 0: _t->privilegesButton_clicked(); break;
        case 1: _t->on_createButton_clicked(); break;
        case 2: _t->on_privilegesButton_clicked(); break;
        case 3: _t->on_deleteButton_clicked(); break;
        case 4: _t->on_backButton_clicked(); break;
        case 5: _t->updateUConf(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData UserConfiguration::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UserConfiguration::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserConfiguration,
      qt_meta_data_UserConfiguration, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UserConfiguration::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UserConfiguration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UserConfiguration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserConfiguration))
        return static_cast<void*>(const_cast< UserConfiguration*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserConfiguration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UserConfiguration::privilegesButton_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
