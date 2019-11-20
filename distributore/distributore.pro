TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Articolo.cpp \
        Distributore.cpp \
        Molla.cpp \
        main.cpp

HEADERS += \
    Articolo.h \
    DList.h \
    Distributore.h \
    Distributore_copy.h \
    Molla.h
