QT += core
QT += network
QT -= gui

TARGET = IOT_Project
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myserver.cpp \
    mymemory.cpp \
    mycpu.cpp

HEADERS += \
    myserver.h \
    mymemory.h \
    mycpu.h

