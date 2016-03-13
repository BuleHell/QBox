/****************************************************************************
** Meta object code from reading C++ file 'forgetpassword.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QBox/forgetpassword.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'forgetpassword.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ForgetPassword[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ForgetPassword[] = {
    "ForgetPassword\0\0on_btnClose_clicked()\0"
};

void ForgetPassword::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ForgetPassword *_t = static_cast<ForgetPassword *>(_o);
        switch (_id) {
        case 0: _t->on_btnClose_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ForgetPassword::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ForgetPassword::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ForgetPassword,
      qt_meta_data_ForgetPassword, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ForgetPassword::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ForgetPassword::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ForgetPassword::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ForgetPassword))
        return static_cast<void*>(const_cast< ForgetPassword*>(this));
    return QWidget::qt_metacast(_clname);
}

int ForgetPassword::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
