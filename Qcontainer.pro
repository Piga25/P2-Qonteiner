#-------------------------------------------------
#
# Project created by QtCreator 2019-05-14T13:47:43
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = Qcontainer
TEMPLATE = app
CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp\
    view/mainwindow.cpp \
    logica/cinema.cpp \
    logica/concerto.cpp \
    logica/evento.cpp \
    logica/sport.cpp \
    logica/stadio.cpp \
    logica/teatro.cpp \
    view/widgets.cpp \
    view/ricercaitemw.cpp

HEADERS  += view/mainwindow.h \
    logica/cinema.h \
    logica/concerto.h \
    logica/container.h \
    logica/evento.h \
    logica/sport.h \
    logica/stadio.h \
    logica/teatro.h \
    logica/deepptr.h \
    view/widgets.h \
    view/ricercaitemw.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
