/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created: Tue Oct 31 15:49:23 2017
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../colorDialog/dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,    7,    7,    7, 0x08,
      72,    7,    7,    7, 0x08,
      98,    7,    7,    7, 0x08,
     124,    7,    7,    7, 0x08,
     152,    7,    7,    7, 0x08,
     180,    7,    7,    7, 0x08,
     206,    7,    7,    7, 0x08,
     234,    7,    7,    7, 0x08,
     262,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dialog[] = {
    "Dialog\0\0,\0sendColor(vector<QColor>,vector<int>)\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_radioButton_2_released()\0"
    "on_radioButton_3_released()\0"
    "on_radioButton_released()\0"
    "on_radioButton_4_released()\0"
    "on_radioButton_5_released()\0"
    "on_pushButton_4_clicked()\0"
};

const QMetaObject Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog,
      qt_meta_data_Dialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog))
        return static_cast<void*>(const_cast< Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendColor((*reinterpret_cast< vector<QColor>(*)>(_a[1])),(*reinterpret_cast< vector<int>(*)>(_a[2]))); break;
        case 1: on_pushButton_clicked(); break;
        case 2: on_pushButton_3_clicked(); break;
        case 3: on_pushButton_2_clicked(); break;
        case 4: on_radioButton_2_released(); break;
        case 5: on_radioButton_3_released(); break;
        case 6: on_radioButton_released(); break;
        case 7: on_radioButton_4_released(); break;
        case 8: on_radioButton_5_released(); break;
        case 9: on_pushButton_4_clicked(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Dialog::sendColor(vector<QColor> _t1, vector<int> _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
