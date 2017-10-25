#-------------------------------------------------
#
# Project created by QtCreator 2017-10-25T12:56:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Te
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    widget.cpp \
    editdigitdialog.cpp \
    digitmananger.cpp \
    digit.cpp

HEADERS  += mainwindow.h \
    widget.h \
    editdigitdialog.h \
    digitmananger.h \
    digit.h

FORMS    += mainwindow.ui \
    widget.ui \
    editdigitdialog.ui
