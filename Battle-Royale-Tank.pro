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

SOURCES += \
    main.cpp \
    engineqt.cpp\

HEADERS += \
    engine.h \
    engineqt.h \

SOURCES += $$files($$PWD/Graphics/*.cpp)
HEADERS += $$files($$PWD/Graphics/*.h)

SOURCES += $$files($$PWD/Physics/*.cpp)
HEADERS += $$files($$PWD/Physics/*.h)

SOURCES += $$files($$PWD/GameMenu/*.cpp)
HEADERS += $$files($$PWD/GameMenu/*.h)

SOURCES += $$files($$PWD/utils/*.cpp)
SOURCES += $$files($$PWD/utils/data/*.cpp)
SOURCES += $$files($$PWD/utils/gamedata/*.cpp)
HEADERS += $$files($$PWD/utils/*.h)
HEADERS += $$files($$PWD/utils/data/*.h)
HEADERS += $$files($$PWD/utils/data/menu/*.h)
HEADERS += $$files($$PWD/utils/gamedata/*.h)

SOURCES += $$files($$PWD/components/*.cpp)
SOURCES += $$files($$PWD/components/body/*.cpp)
SOURCES += $$files($$PWD/components/circle/*.cpp)
HEADERS += $$files($$PWD/components/body/*.h)
HEADERS += $$files($$PWD/components/circle/*.h)
HEADERS += $$files($$PWD/components/*.h)
HEADERS += $$files($$PWD/components/interfaces/*.h)

SOURCES += $$files($$PWD/builders/*.cpp)
SOURCES += $$files($$PWD/builders/impl/*.cpp)
SOURCES += $$files($$PWD/builders/impl/body/*.cpp)
SOURCES += $$files($$PWD/builders/impl/turret/*.cpp)
SOURCES += $$files($$PWD/builders/impl/tank/*.cpp)
SOURCES += $$files($$PWD/builders/impl/circle/*.cpp)

HEADERS += $$files($$PWD/builders/*.h)
HEADERS += $$files($$PWD/builders/impl/*.h)
HEADERS += $$files($$PWD/builders/interfaces/*.h)
HEADERS += $$files($$PWD/builders/impl/body/*.h)
HEADERS += $$files($$PWD/builders/impl/turret/*.h)
HEADERS += $$files($$PWD/builders/impl/tank/*.h)
HEADERS += $$files($$PWD/builders/impl/circle/*.h)

SOURCES += $$files($$PWD/objects/commands/*.cpp)
HEADERS += $$files($$PWD/objects/commands/*.h)

SOURCES += $$files($$PWD/objects/*.cpp)
HEADERS += $$files($$PWD/objects/*.h)

RESOURCES += \
    config.qrc \
    images.qrc

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

