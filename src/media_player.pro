#-------------------------------------------------
#
# Project created by QtCreator 2017-12-02T15:01:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = media_player
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

#ifdef __linux__
LIBS += -L"/usr/libs/x86_64-linux-gnu"
INCLUDEPATH += "/usr/include/SFML"
DEPENDPATH += "/usr/include/SFML"
#elif _WIN32
LIBS += -L"C:\SFML\lib"
INCLUDEPATH += "C:\SFML\include"
DEPENDPATH += "C:\SFML\include"
#endif
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += "/usr/include/SFML"
DEPENDPATH += "/usr/include/SFML"


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    assets.qrc \
    assets.qrc
