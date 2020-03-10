QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        Articolo.cpp \
        finestratecnico.cpp \
        finestrautente.cpp \
        main.cpp \
        mainwindow.cpp \
        saveLoad.cpp \
        soldi.cpp

HEADERS += \
    Articolo.h \
    DList.h \
    Distributore.h \
    Molla.h \
    finestratecnico.h \
    finestrautente.h \
    mainwindow.h \
    soldi.h

FORMS += \
    finestratecnico.ui \
    finestrautente.ui \
    mainwindow.ui

RESOURCES += \
    risorse.qrc
