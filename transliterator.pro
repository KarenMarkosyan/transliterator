#-------------------------------------------------
#
# Project created by QtCreator 2015-08-06T19:01:06
#
#-------------------------------------------------

QT       += core testlib

QT       -= gui

TARGET = transliterator
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
QMAKE_CXXFLAGS_DEBUG += -pg
QMAKE_LFLAGS_DEBUG += -pg


SOURCES += main.cpp \
    functions.cpp \
    tests/testtexttowords.cpp \
    tests/testiscorrecttext.cpp \
    tests/testiscorrectrules.cpp \
    tests/testanalyze.cpp \
    tests/testwordstotexts.cpp

HEADERS += \
    functions.h \
    tests/testtexttowords.h \
    tests/testiscorrecttext.h \
    tests/testiscorrectrules.h \
    tests/testanalyze.h \
    tests/testwordstotexts.h
