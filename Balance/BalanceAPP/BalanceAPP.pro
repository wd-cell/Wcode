#-------------------------------------------------
#
# Project created by QtCreator 2018-04-02T11:01:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = BalanceAPP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    netdialog.cpp \
    polarchart.cpp \
    qcustomplot.cpp \
    setchanneldialog.cpp \
    timedomchart.cpp

HEADERS  += mainwindow.h \
    netdialog.h \
    polarchart.h \
    qcustomplot.h \
    setchanneldialog.h \
    timedomchart.h

FORMS    += mainwindow.ui \
    netdialog.ui \
    setchanneldialog.ui

DEFINES += _HNC_DLL_IMP_

unix|win32: LIBS += -L$$PWD/../lib/ -lHncNetDllForCpp

INCLUDEPATH += $$PWD/../include
DEPENDPATH += $$PWD/../include
