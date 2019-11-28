TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Articolo.cpp \
        main.cpp \
        saveLoad.cpp

HEADERS += \
    Articolo.h \
    DList.h \
    Distributore.h \
    Molla.h
