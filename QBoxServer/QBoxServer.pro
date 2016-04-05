#-------------------------------------------------
#
# Project created by QtCreator 2016-03-17T16:45:20
#
#-------------------------------------------------

QT       += core gui sql
QT       += network
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QBoxServer
TEMPLATE = app


SOURCES += main.cpp\
    window.cpp \
    tools.cpp \
    network.cpp \
    dbhelp.cpp \
    qboxprotocol.cpp \
    mytcpserver.cpp \
    myclientsocket.cpp

HEADERS  += \
    window.h \
    tools.h \
    network.h \
    dbhelp.h \
    qboxprotocol.h \
    mytcpserver.h \
    myclientsocket.h

FORMS    += \
    window.ui

RESOURCES += \
    resource.qrc
