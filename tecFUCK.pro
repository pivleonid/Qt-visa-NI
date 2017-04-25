QT += core gui
QT += widgets
TEMPLATE = app
#CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt
TARGET = tecFUCK
SOURCES += main.cpp \
         ipdialog.cpp\
       basedevice.cpp
INCLUDEPATH += ../../../../Program Files/IVI Foundation/VISA/Win64/Include/

LIBS += "C:/Program Files (x86)/IVI Foundation/VISA/WinNT/lib/msc/visa32.lib"
INCLUDEPATH += "C:/Program Files/IVI Foundation/VISA/Win64/Include"

FORMS += \
    ipdialog.ui

HEADERS += \
    ipdialog.h\
    basedevice.h



