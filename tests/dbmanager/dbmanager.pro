
TARGET = $$join(TARGET,,,_debug)

QT += testlib sql widgets gui
#QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_dbmanager.cpp ../../app/dbmanager.cpp

HEADERS += ../../app/dbmanager.h
