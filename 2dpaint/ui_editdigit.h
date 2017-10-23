/********************************************************************************
** Form generated from reading UI file 'editdigit.ui'
**
** Created: Mon Oct 23 16:19:08 2017
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIGIT_H
#define UI_EDITDIGIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditDigit
{
public:

    void setupUi(QWidget *EditDigit)
    {
        if (EditDigit->objectName().isEmpty())
            EditDigit->setObjectName(QString::fromUtf8("EditDigit"));
        EditDigit->resize(400, 300);

        retranslateUi(EditDigit);

        QMetaObject::connectSlotsByName(EditDigit);
    } // setupUi

    void retranslateUi(QWidget *EditDigit)
    {
        EditDigit->setWindowTitle(QApplication::translate("EditDigit", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditDigit: public Ui_EditDigit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIGIT_H
