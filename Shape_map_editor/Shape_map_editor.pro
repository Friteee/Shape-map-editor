#-------------------------------------------------
#
# Project created by QtCreator 2015-07-13T21:12:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Shape_map_editor
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    map.cpp \
    tileset.cpp \
    tilesetmanager.cpp \
    addtileset.cpp \
    objecttype.cpp \
    currenttype.cpp \
    object.cpp \
    mapsettings.cpp

HEADERS  += mainwindow.h \
    map.h \
    tileset.h \
    tilesetmanager.h \
    addtileset.h \
    objecttype.h \
    currenttype.h \
    object.h \
    mapsettings.h

FORMS    += mainwindow.ui \
    addtileset.ui \
    mapsettings.ui
