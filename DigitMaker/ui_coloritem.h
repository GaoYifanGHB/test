/********************************************************************************
** Form generated from reading UI file 'coloritem.ui'
**
** Created: Wed Oct 25 21:33:14 2017
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORITEM_H
#define UI_COLORITEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorItem
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ColorItem)
    {
        if (ColorItem->objectName().isEmpty())
            ColorItem->setObjectName(QString::fromUtf8("ColorItem"));
        ColorItem->resize(183, 26);
        layoutWidget = new QWidget(ColorItem);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 176, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(35, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(ColorItem);

        QMetaObject::connectSlotsByName(ColorItem);
    } // setupUi

    void retranslateUi(QWidget *ColorItem)
    {
        ColorItem->setWindowTitle(QApplication::translate("ColorItem", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ColorItem: public Ui_ColorItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORITEM_H
