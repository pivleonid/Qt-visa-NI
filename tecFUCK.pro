QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
QT += widgets
TEMPLATE = app
#CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt
TARGET = tecFUCK
SOURCES += main.cpp \
           basedevice.cpp \
           fsl.cpp \
           tds2024c.cpp \
           C:/Qt/qcustomplot/qcustomplot.cpp \
           mainwindow.cpp \
    pr100.cpp \
    lecroy.cpp
INCLUDEPATH += ../../../../Program Files/IVI Foundation/VISA/Win64/Include/

LIBS += "C:/Program Files (x86)/IVI Foundation/VISA/WinNT/lib/msc/visa32.lib"
INCLUDEPATH += "C:/Program Files/IVI Foundation/VISA/Win64/Include"
INCLUDEPATH += "C:/Qt/qcustomplot"

FORMS += \
    mainwindow.ui

HEADERS += \
    basedevice.h \
    fsl.h \
    tds2024c.h \
    C:/Qt/qcustomplot/qcustomplot.h \
    mainwindow.h \
    pr100.h \
    lecroy.h \
    rto1024.h



