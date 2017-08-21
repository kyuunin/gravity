TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    source/shape.cpp \
    source/canvas.cpp \
    source/sqrtfourier.cpp \
    source/game.cpp

HEADERS += \
    header/shape.h \
    header/canvas.h \
    header/sqrtfourier.h \
    header/game.h
