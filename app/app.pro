#-------------------------------------------------
#
# Project created by QtCreator 2018-09-21T21:48:20
#
#-------------------------------------------------

QT       += core gui sql widgets

TARGET = CollegeTouring
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
souvenirParser.cpp \
dbmanager.cpp \
student.cpp \
    pathing.cpp \
    customtrip.cpp \
    asu.cpp \
    checkout.cpp \
    admin/campuscreator.cpp \
    admin/administration.cpp \
    admin/souvenircreator.cpp \
    displayinfoclass.cpp \
    chooserouteclass.cpp \
    chosencampusclass.cpp \
    tablebuilders.cpp

HEADERS += \
        mainwindow.h \
souvenirParser.h \
dbmanager.h \
student.h \
    pathing.h \
    customtrip.h \
    asu.h \
    checkout.h \
    admin/campuscreator.h \
    admin/administration.h \
    admin/souvenircreator.h \
    displayinfoclass.h \
    chooserouteclass.h \
    chosencampusclass.h \
    tablebuilders.h


FORMS += \
mainwindow.ui \
    customtrip.ui \
    asu.ui \
student.ui \
checkout.ui \
    admin/campuscreator.ui \
    admin/administration.ui \
    admin/souvenircreator.ui \
    displayinfoclass.ui \
    chooserouteclass.ui \
    chosencampusclass.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
