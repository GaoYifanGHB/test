#-------------------------------------------------
#
# Project created by QtCreator 2017-10-19T13:08:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2dpaint
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    digit.cpp \
    digitmananger.cpp \
    editdigitdialog.cpp

HEADERS  += widget.h \
    digit.h \
    digitmananger.h \
    editdigitdialog.h

FORMS    += widget.ui \
    editdigitdialog.ui
