#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T12:45:41
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Schachbrett
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
CONFIG += MAC_CONFIG

MAC_CONFIG {
    QMAKE_CXXFLAGS = -std=c++11 -stdlib=libc++ -mmacosx-version-min=10.9
    QMAKE_LFLAGS = -std=c++11 -stdlib=libc++ -mmacosx-version-min=10.9
}
include(opencv.pri)
