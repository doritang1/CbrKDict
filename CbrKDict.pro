#-------------------------------------------------
#
# Project created by QtCreator 2016-07-04T23:00:11
#
#-------------------------------------------------

QT       += sql core gui xml printsupport webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CbrKDict
TEMPLATE = app


SOURCES += main.cpp\
        MainForm.cpp\
        ckdbengine.cpp \
        document.cpp \
        CyDictEditor.cpp \
        htmlnamedentityresolver.cpp
HEADERS += MainForm.h\
        ckdbengine.h \
        document.h \
        CyDictEditor.h \
        htmlnamedentityresolver.h

FORMS   += CyDictEditor.ui

RESOURCES = \
    resources/markdowneditor.qrc

include(../CbrkDict/QtRptProject/QtRPT/QtRPT.pri)

DISTFILES += \
    3RDPARTY.md
