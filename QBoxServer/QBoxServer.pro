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
    dbhelp.cpp \
    qboxprotocol.cpp \
    mytcpserver.cpp \
    myclientsocket.cpp \
    fullScreenWidget.cpp

HEADERS  += \
    window.h \
    tools.h \
    dbhelp.h \
    qboxprotocol.h \
    mytcpserver.h \
    myclientsocket.h \
    fullScreenWidget.h

FORMS    += \
    window.ui


OTHER_FILES += \
    icon.rc
RC_FILE += icon.rc
