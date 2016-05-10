#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T10:40:38
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlexVault
TEMPLATE = app


SOURCES += main.cpp\
    usercreationdialog.cpp \
    dbinterface.cpp \
    login.cpp \
    adminmainmenu.cpp \
    userprivileges.cpp \
    adduserprivileges.cpp \
    loginfaileddialog.cpp \
    userconfiguration.cpp \
    userboxaccess.cpp \
    boxretrieval.cpp \
    activitylog.cpp \
    qvirtualkeyboard.cpp \
    adminboxaccess.cpp \
    inactivityfilter.cpp \
    weightwarningdialog.cpp \
    spiinterface.cpp

HEADERS  += \
    usercreationdialog.h \
    dbinterface.h \
    login.h \
    adminmainmenu.h \
    userprivileges.h \
    adduserprivileges.h \
    loginfaileddialog.h \
    userconfiguration.h \
    userboxaccess.h \
    boxretrieval.h \
    activitylog.h \
    qvirtualkeyboard.h \
    adminboxaccess.h \
    inactivityfilter.h \
    weightwarningdialog.h \
    spiinterface.h

FORMS    += userconfiguration.ui \
    usercreationdialog.ui \
    login.ui \
    adminmainmenu.ui \
    userprivileges.ui \
    adduserprivileges.ui \
    loginfaileddialog.ui \
    userboxaccess.ui \
    boxretrieval.ui \
    activitylog.ui \
    adminboxaccess.ui \
    weightwarningdialog.ui
