/********************************************************************************
** Form generated from reading UI file 'digitmainwindow.ui'
**
** Created: Wed Nov 1 10:38:44 2017
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QToolButton *toolButton;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *l_lab;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *w_lab;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *h_lab;

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
        layoutWidget = new QWidget(dockWidgetContents_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 49, 40));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        toolButton = new QToolButton(dockWidgetContents_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(20, 100, 37, 18));
        toolWidget->setWidget(dockWidgetContents_2);
        DigitMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), toolWidget);
        dockWidget = new QDockWidget(DigitMainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        layoutWidget1 = new QWidget(dockWidgetContents_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(9, 9, 58, 56));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        l_lab = new QLabel(layoutWidget1);
        l_lab->setObjectName(QString::fromUtf8("l_lab"));

        horizontalLayout_3->addWidget(l_lab);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        w_lab = new QLabel(layoutWidget1);
        w_lab->setObjectName(QString::fromUtf8("w_lab"));

        horizontalLayout_2->addWidget(w_lab);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        h_lab = new QLabel(layoutWidget1);
        h_lab->setObjectName(QString::fromUtf8("h_lab"));

        horizontalLayout->addWidget(h_lab);


        verticalLayout_2->addLayout(horizontalLayout);

        dockWidget->setWidget(dockWidgetContents_3);
        DigitMainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);

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
#ifndef QT_NO_TOOLTIP
        toolWidget->setToolTip(QApplication::translate("DigitMainWindow", "\345\267\245\345\205\267\346\240\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        radioButton->setText(QApplication::translate("DigitMainWindow", "\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("DigitMainWindow", "\347\247\273\345\212\250", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("DigitMainWindow", "\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dockWidget->setToolTip(QApplication::translate("DigitMainWindow", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("DigitMainWindow", "\351\225\277\357\274\232", 0, QApplication::UnicodeUTF8));
        l_lab->setText(QApplication::translate("DigitMainWindow", "1000", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DigitMainWindow", "\345\256\275\357\274\232", 0, QApplication::UnicodeUTF8));
        w_lab->setText(QApplication::translate("DigitMainWindow", "1200", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DigitMainWindow", "\351\253\230\357\274\232", 0, QApplication::UnicodeUTF8));
        h_lab->setText(QApplication::translate("DigitMainWindow", "300", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DigitMainWindow: public Ui_DigitMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIGITMAINWINDOW_H
