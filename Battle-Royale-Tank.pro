#-------------------------------------------------
#
# Project created by QtCreator 2018-03-18T18:35:23
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += widgets

CONFIG += c++14

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

SOURCES += $$files($$PWD/GameMenu/*.cpp)
SOURCES += $$files($$PWD/GameObjectsViews/*.cpp)
SOURCES += $$files($$PWD/GameObjects/*.cpp)
SOURCES += $$files($$PWD/GameViews/*.cpp)
SOURCES += $$files($$PWD/PlayScene/*.cpp)
SOURCES += $$files($$PWD/utils/*.cpp)
SOURCES += $$files($$PWD/Network/*.cpp)

HEADERS += $$files($$PWD/Network/*.h)
HEADERS += $$files($$PWD/GameMenu/*.h)
HEADERS += $$files($$PWD/GameObjectsViews/*.h)
HEADERS += $$files($$PWD/GameObjects/*.h)
HEADERS += $$files($$PWD/GameViews/*.h)
HEADERS += $$files($$PWD/PlayScene/*.h)
HEADERS += $$files($$PWD/utils/*.h)

SOURCES += \
    main.cpp \

FORMS += \
    playwidget.ui \
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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libconfig/lib/.libs/release/ -lconfig++
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libconfig/lib/.libs/debug/ -lconfig++
else:unix: LIBS += -L$$PWD/libconfig/lib/.libs/ -lconfig++

INCLUDEPATH += $$PWD/libconfig/lib/.libs
DEPENDPATH += $$PWD/libconfig/lib/.libs

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/libconfig/lib/.libs/release/libconfig++.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/libconfig/lib/.libs/debug/libconfig++.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/libconfig/lib/.libs/release/config++.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/libconfig/lib/.libs/debug/config++.lib
else:unix: PRE_TARGETDEPS += $$PWD/libconfig/lib/.libs/libconfig++.a
