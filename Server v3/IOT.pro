#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T20:16:04
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IOT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myserver.cpp \
    mymemory.cpp \
    mycpu.cpp \
    performances.cpp \
    flux.cpp \
    ../../IOT/Server/choice.cpp

HEADERS  += mainwindow.h \
    myserver.h \
    mymemory.h \
    mycpu.h \
    performances.h \
    flux.h \
    ../../IOT/Server/choice.h

FORMS    += mainwindow.ui \
    performances.ui \
    ../../IOT/Server/choice.ui
