/****************************************************************************
** Meta object code from reading C++ file 'adminmainmenu.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "adminmainmenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminmainmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdminMainMenu[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      40,   14,   14,   14, 0x08,
      66,   14,   14,   14, 0x08,
      89,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AdminMainMenu[] = {
    "AdminMainMenu\0\0on_usersButton_clicked()\0"
    "on_logOutButton_clicked()\0"
    "on_logButton_clicked()\0on_sdbButton_clicked()\0"
};

void AdminMainMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AdminMainMenu *_t = static_cast<AdminMainMenu *>(_o);
        switch (_id) {
        case 0: _t->on_usersButton_clicked(); break;
        case 1: _t->on_logOutButton_clicked(); break;
        case 2: _t->on_logButton_clicked(); break;
        case 3: _t->on_sdbButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AdminMainMenu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AdminMainMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AdminMainMenu,
      qt_meta_data_AdminMainMenu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdminMainMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdminMainMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdminMainMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdminMainMenu))
        return static_cast<void*>(const_cast< AdminMainMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int AdminMainMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
