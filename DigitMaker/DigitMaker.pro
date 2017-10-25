#-------------------------------------------------
#
# Project created by QtCreator 2017-10-25T15:13:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DigitMaker
TEMPLATE = app


SOURCES += main.cpp\
        digitmainwindow.cpp \
    widget.cpp \
    editdigitdialog.cpp \
    digitmananger.cpp \
    digit.cpp \
    setsizedialog.cpp \
    colorDialog/dialog.cpp \
    colorDialog/coloritem.cpp

HEADERS  += digitmainwindow.h \
    widget.h \
    editdigitdialog.h \
    digitmananger.h \
    digit.h \
    setsizedialog.h \
    colorDialog/dialog.h \
    colorDialog/coloritem.h

FORMS    += digitmainwindow.ui \
    widget.ui \
    editdigitdialog.ui \
    setsizedialog.ui \
    colorDialog/dialog.ui \
    colorDialog/coloritem.ui
