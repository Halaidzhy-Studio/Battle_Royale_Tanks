#-------------------------------------------------
#
# Project created by QtCreator 2018-03-18T18:35:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Battle-Royale-Tank
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES +=  QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += "Box2D/"

SOURCES += \
        main.cpp \
    GameMenu/multiplayermenu.cpp \
    GameMenu/gamemenu.cpp \
    GameMenu/roomlistelement.cpp \
    GameMenu/gameroom.cpp \
    PlayScene/gameinstance.cpp \
    GameObjectsViews/tankview.cpp \
    GameObjectsViews/bulletview.cpp \
    GameObjectsViews/wallview.cpp \
    GameObjectsViews/tankturretview.cpp \
    GameObjects/tank.cpp \
    GameMenu/singleplayermenu.cpp \
    gamescene.cpp

HEADERS += \
    GameMenu/multiplayermenu.h \
    GameMenu/gamemenu.h \
    GameMenu/roomlistelement.h \
    packages.h \
    GameMenu/gameroom.h \
    PlayScene/gameinstance.h \
    GameObjectsViews/tankview.h \
    GameObjectsViews/bulletview.h \
    GameObjectsViews/wallview.h \
    GameObjectsViews/tankturretview.h \
    GameObjects/tank.h \
    GameMenu/singleplayermenu.h \
    gamescene.h

FORMS += \
    playwidget.ui \
    PlayScene/singleplayer.ui \
    GameMenu/multiplayermenu.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./release/ -lBox2d
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./debug/ -lBox2d
else:unix: LIBS += -L$$PWD/./ -lBox2d

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/./release/libBox2d.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/./debug/libBox2d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/./release/Box2d.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/./debug/Box2d.lib
else:unix: PRE_TARGETDEPS += $$PWD/./libBox2d.a
