TARGET = $$join(TARGET,,,_debug)

QT += testlib sql widgets gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += tst_pathing.cpp ../../app/pathing.cpp ../../app/dbmanager.cpp

HEADERS += ../../app/pathing.h ../../app/dbmanager.h
