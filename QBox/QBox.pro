#-------------------------------------------------
#
# Project created by QtCreator 2016-03-09T19:49:47
#
#-------------------------------------------------

QT       += core gui sql xml
QT       += network
QT       += multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QBox
TEMPLATE = app


SOURCES += main.cpp\
    login.cpp \
    qboxclient.cpp \
    register.cpp \
    forgetpassword.cpp \
    network.cpp \
    qboxprotocol.cpp \
    dbhelp.cpp \
    setting.cpp \
    groupsetting.cpp \
    tools.cpp \
    qmenubutton.cpp \
    friendwindow.cpp \
    talkwindow.cpp \
    frienditem.cpp \
    messageitem.cpp \
    groupitem.cpp

HEADERS  += \
    login.h \
    qboxclient.h \
    register.h \
    forgetpassword.h \
    network.h \
    qboxprotocol.h \
    dbhelp.h \
    setting.h \
    groupsetting.h \
    tools.h \
    qmenubutton.h \
    friendwindow.h \
    talkwindow.h \
    frienditem.h \
    messageitem.h \
    groupitem.h

FORMS    += \
    login.ui \
    register.ui \
    forgetpassword.ui \
    friendwindow.ui \
    talkwindow.ui \
    messageitem.ui \
    groupitem.ui

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    icon.rc
RC_FILE += icon.rc
