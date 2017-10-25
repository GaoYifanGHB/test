/********************************************************************************
** Form generated from reading UI file 'digitmainwindow.ui'
**
** Created: Wed Oct 25 18:04:32 2017
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIGITMAINWINDOW_H
#define UI_DIGITMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DigitMainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *toolWidget;
    QWidget *dockWidgetContents_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QMainWindow *DigitMainWindow)
    {
        if (DigitMainWindow->objectName().isEmpty())
            DigitMainWindow->setObjectName(QString::fromUtf8("DigitMainWindow"));
        DigitMainWindow->resize(1000, 800);
        actionNew = new QAction(DigitMainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(DigitMainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(DigitMainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralWidget = new QWidget(DigitMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DigitMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DigitMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        DigitMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DigitMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DigitMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DigitMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DigitMainWindow->setStatusBar(statusBar);
        toolWidget = new QDockWidget(DigitMainWindow);
        toolWidget->setObjectName(QString::fromUtf8("toolWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        widget = new QWidget(dockWidgetContents_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 30, 49, 40));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(widget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        toolWidget->setWidget(dockWidgetContents_2);
        DigitMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), toolWidget);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addAction(actionSave);

        retranslateUi(DigitMainWindow);

        QMetaObject::connectSlotsByName(DigitMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DigitMainWindow)
    {
        DigitMainWindow->setWindowTitle(QApplication::translate("DigitMainWindow", "\346\225\260\347\240\201\350\277\267\345\275\251\347\224\237\346\210\220\345\231\250", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("DigitMainWindow", "\346\226\260\345\273\272(&N)", 0, QApplication::UnicodeUTF8));
        actionNew->setShortcut(QApplication::translate("DigitMainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("DigitMainWindow", "\346\211\223\345\274\200(&O)", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("DigitMainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("DigitMainWindow", "\344\277\235\345\255\230(&S)", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("DigitMainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("DigitMainWindow", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("DigitMainWindow", "\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("DigitMainWindow", "\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("DigitMainWindow", "\347\247\273\345\212\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DigitMainWindow: public Ui_DigitMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIGITMAINWINDOW_H
