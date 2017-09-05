QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
QT += widgets
TEMPLATE = app
TARGET = tecFUCK
SOURCES += main.cpp \
           basedevice.cpp \
           fsl.cpp \
           tds2024c.cpp \
#           C:/Qt/qcustomplot/qcustomplot.cpp \
           mainwindow.cpp \
               pr100.cpp \
    lecroy.cpp

INCLUDEPATH += "D:/projects/tecFUCK/fftw/"
LIBS +=  D:/projects/tecFUCK/fftw/libfftw3-3.a\
         D:/projects/tecFUCK/fftw/libfftw3f-3.a\
         D:/projects/tecFUCK/fftw/libfftw3l-3.a


INCLUDEPATH += ../../../../Program Files/IVI Foundation/VISA/Win64/Include/
INCLUDEPATH += "C:/Program Files/IVI Foundation/VISA/Win64/Include"
LIBS += "C:/Program Files (x86)/IVI Foundation/VISA/WinNT/lib/msc/visa32.lib"

#INCLUDEPATH += "C:/Qt/qcustomplot"

FORMS +=

HEADERS += \
    basedevice.h \
    fsl.h \
    tds2024c.h \
#    C:/Qt/qcustomplot/qcustomplot.h \
    mainwindow.h \
    pr100.h \
    lecroy.h \
    rto1024.h \
    visanamespace.h



#DEFINES += LINUXBASE



#QT += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = vxiqt
#TEMPLATE = app

#DEFINES += QT_DEPRECATED_WARNINGS


#SOURCES += \
#main.cpp \
#mainwindow.cpp \
#../../Загрузки/vxi11_1.10/vxi11_user.cc \
#../../Загрузки/vxi11_1.10/vxi11_clnt.c \
#../../Загрузки/vxi11_1.10/vxi11_xdr.c \
#basedevice.cpp

#HEADERS += \
#mainwindow.h \
#../../Загрузки/vxi11_1.10/vxi11_user.h \
#../../Загрузки/vxi11_1.10/vxi11.h \
#basedevice.h

#FORMS += \
#mainwindow.ui

#DISTFILES += \
#../../Загрузки/vxi11_1.10/vxi11.x \
#../../Загрузки/vxi11_1.10/vxi11.x
