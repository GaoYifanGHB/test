/********************************************************************************
** Form generated from reading UI file 'editdigitdialog.ui'
**
** Created: Mon Oct 23 18:38:40 2017
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIGITDIALOG_H
#define UI_EDITDIGITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_EditDigitDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditDigitDialog)
    {
        if (EditDigitDialog->objectName().isEmpty())
            EditDigitDialog->setObjectName(QString::fromUtf8("EditDigitDialog"));
        EditDigitDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(EditDigitDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(EditDigitDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditDigitDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditDigitDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditDigitDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDigitDialog)
    {
        EditDigitDialog->setWindowTitle(QApplication::translate("EditDigitDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditDigitDialog: public Ui_EditDigitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIGITDIALOG_H
