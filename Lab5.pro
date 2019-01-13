#-------------------------------------------------
#
# Project created by QtCreator 2016-02-05T12:33:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    technique.cpp \
    container.cpp \
    tank.cpp \
    ship.cpp \
    choosetype.cpp \
    tankdialog.cpp \
    shipdialog.cpp

HEADERS  += mainwindow.h \
    container.h \
    technique.h \
    ship.h \
    tank.h \
    choosetype.h \
    tankdialog.h \
    shipdialog.h

FORMS    += mainwindow.ui \
    choosetype.ui \
    tankdialog.ui \
    shipdialog.ui
