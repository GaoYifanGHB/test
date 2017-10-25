/********************************************************************************
** Form generated from reading UI file 'setsizedialog.ui'
**
** Created: Wed Oct 25 20:52:25 2017
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETSIZEDIALOG_H
#define UI_SETSIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_setSizeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *len_et;
    QLabel *label_2;
    QLineEdit *wid_et;
    QLabel *label_3;
    QLineEdit *hei_et;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *setSizeDialog)
    {
        if (setSizeDialog->objectName().isEmpty())
            setSizeDialog->setObjectName(QString::fromUtf8("setSizeDialog"));
        setSizeDialog->resize(191, 133);
        verticalLayout = new QVBoxLayout(setSizeDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(setSizeDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        len_et = new QLineEdit(setSizeDialog);
        len_et->setObjectName(QString::fromUtf8("len_et"));

        gridLayout->addWidget(len_et, 0, 1, 1, 1);

        label_2 = new QLabel(setSizeDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        wid_et = new QLineEdit(setSizeDialog);
        wid_et->setObjectName(QString::fromUtf8("wid_et"));

        gridLayout->addWidget(wid_et, 1, 1, 1, 1);

        label_3 = new QLabel(setSizeDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        hei_et = new QLineEdit(setSizeDialog);
        hei_et->setObjectName(QString::fromUtf8("hei_et"));

        gridLayout->addWidget(hei_et, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(setSizeDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(setSizeDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(setSizeDialog);

        QMetaObject::connectSlotsByName(setSizeDialog);
    } // setupUi

    void retranslateUi(QDialog *setSizeDialog)
    {
        setSizeDialog->setWindowTitle(QApplication::translate("setSizeDialog", "\350\257\267\351\200\211\346\213\251\345\260\272\345\257\270", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("setSizeDialog", "\351\225\277\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("setSizeDialog", "\345\256\275\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("setSizeDialog", "\351\253\230\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("setSizeDialog", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("setSizeDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class setSizeDialog: public Ui_setSizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETSIZEDIALOG_H
