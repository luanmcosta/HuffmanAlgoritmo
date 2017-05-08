TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    no.cpp \
    funcoes.cpp \
    decodificar.cpp \
    huffman.cpp

HEADERS += \
    no.h \
    funcoes.h \
    decodificar.h \
    huffman.h
