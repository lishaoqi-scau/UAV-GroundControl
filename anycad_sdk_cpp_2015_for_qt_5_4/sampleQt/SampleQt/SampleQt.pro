#-------------------------------------------------
#
# Project created by QtCreator 2015-05-10T20:49:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SampleQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    anycad_qtui_auwindow3d.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/release/ -lAnyPlatformQt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/debug/ -lAnyPlatformQt

INCLUDEPATH += $$PWD/../../inc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/release/ -lAnyPlatformAPI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/debug/ -lAnyPlatformAPI

release {
    DESTDIR = $$PWD/../../bin/Release
}

debug {
    DESTDIR = $$PWD/../../bin/debug
}
