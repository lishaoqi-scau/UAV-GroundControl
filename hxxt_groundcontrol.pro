#-------------------------------------------------
#
# Project created by QtCreator 2017-08-10T22:00:05
#
#-------------------------------------------------

QT       += core gui  webkit

TARGET = hxxt_groundcontrol
TEMPLATE = app

INCLUDEPATH +=  $$PWD/libvlc_include/
SOURCES += main.cpp\
        mainwindow.cpp \
    readini.cpp \
    googlemapweb.cpp \
    vlcplayer.cpp

HEADERS  += mainwindow.h \
    vlcplayer.h \
    readini.h \
    googlemapweb.h \
    vlcplayer.h \
    googlemapweb.h

LIBS += -L ./ -llibvlc -llibvlccore  -laxvlc  -lnpvlc

INCLUDEPATH += $$PWD/libvlc_lib
DEPENDPATH += $$PWD/libvlc_lib

FORMS    += mainwindow.ui

OTHER_FILES += \
    hxxt_groundcontrol.pro.user
