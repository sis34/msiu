#-------------------------------------------------
#
# Project created by QtCreator 2014-08-27T14:34:51
#
#-------------------------------------------------

QT       += core gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = medicine
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    colordiagram.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    colordiagram.h

FORMS    += mainwindow.ui \
    dialog.ui \
    colordiagram.ui
