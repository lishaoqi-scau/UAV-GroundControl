#-------------------------------------------------
#
# Project created by QtCreator 2017-09-20T10:09:29
#
#-------------------------------------------------

QT       += core gui webenginewidgets  webchannel qml quick quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyGroundControl
TEMPLATE = app
CONFIG += c++11
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH +=  $$PWD/libvlc_include/
INCLUDEPATH += $$PWD/libvlc_lib
DEPENDPATH += $$PWD/libvlc_lib
LIBS += -L$$PWD/libvlc_lib -llibvlc -llibvlccore  -lopengl32

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    gcsdisplay.cpp \
    vlcplayer.cpp \
    googlemapweb.cpp \
    qmlcommunicate.cpp \
    serialsettingwidget.cpp \
    menuwidgetmanager.cpp \
    flypreparewidget.cpp \
    readini.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    gcsdisplay.h \
    vlcplayer.h \
    googlemapweb.h \
    qmlcommunicate.h \
    serialsettingwidget.h \
    menuwidgetmanager.h \
    flypreparewidget.h \
    readini.h \
    glwidget.h

FORMS    += mainwindow.ui \
    gcsdisplay.ui

RESOURCES += \
    image.qrc \
    qml.qrc
