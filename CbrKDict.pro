#-------------------------------------------------
#
# Project created by QtCreator 2016-07-04T23:00:11
#
#-------------------------------------------------

QT       += sql core gui printsupport webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CbrKDict
TEMPLATE = app


SOURCES += main.cpp\
        MainForm.cpp\
        ckdbengine.cpp
HEADERS  += MainForm.h\
        ckdbengine.h

include(../CbrkDict/QtRptProject/QtRPT/QtRPT.pri)

DISTFILES += \
    debug/QtinyMCE/tinymce4_base.html
