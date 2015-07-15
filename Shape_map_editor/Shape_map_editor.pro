#-------------------------------------------------
#
# Project created by QtCreator 2015-07-13T21:12:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Shape_map_editor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    map.cpp \
    tileset.cpp \
    tilesetmanager.cpp \
    addtileset.cpp

HEADERS  += mainwindow.h \
    map.h \
    tileset.h \
    tilesetmanager.h \
    addtileset.h

FORMS    += mainwindow.ui \
    addtileset.ui
