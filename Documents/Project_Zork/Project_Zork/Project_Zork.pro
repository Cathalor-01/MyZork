TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        zork/Character.cpp \
        zork/Command.cpp \
        zork/CommandWords.cpp \
        zork/Parser.cpp \
        zork/Room.cpp \
        zork/ZorkUL.cpp \
        zork/item.cpp

HEADERS += \
    zork/Character.h \
    zork/Command.h \
    zork/CommandWords.h \
    zork/Parser.h \
    zork/Room.h \
    zork/ZorkUL.h \
    zork/item.h
