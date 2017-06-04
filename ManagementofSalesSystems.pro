#-------------------------------------------------
#
# Project created by QtCreator 2017-06-03T22:15:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

TARGET = ManagementofSalesSystems
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwidget.cpp \
    core/buycommoditywidget.cpp \
    core/sellcommoditywidget.cpp \
    core/addnewarrivalwidget.cpp \
    core/commodityinfowidget.cpp \
    core/buyrecordwidget.cpp \
    core/sellrecordwidget.cpp \
    db/initdb.cpp \
    db/connectdb.cpp

HEADERS += \
        mainwidget.h \
    core/buycommoditywidget.h \
    core/sellcommoditywidget.h \
    core/addnewarrivalwidget.h \
    core/commodityinfowidget.h \
    core/buyrecordwidget.h \
    core/sellrecordwidget.h \
    db/initdb.h \
    db/connectdb.h
