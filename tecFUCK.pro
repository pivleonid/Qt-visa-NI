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
    rto1024.h



