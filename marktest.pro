#-------------------------------------------------
#
# Project created by QtCreator 2015-07-30T08:44:09
#
#-------------------------------------------------

QT       += core gui

qtHaveModule(printsupport): QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = marktest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
