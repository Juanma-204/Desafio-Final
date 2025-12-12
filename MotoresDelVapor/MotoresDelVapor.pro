QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    objetomovil.cpp \
    obstaculo.cpp \
    vehiculo.cpp

HEADERS += \
    mainwindow.h \
    objetomovil.h \
    obstaculo.h \
    vehiculo.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc \
    recursos.qrc \
    recursos.qrc

DISTFILES += \
    sprites/Nivel 1.png \
    sprites/Nivel 1.png \
    sprites/Nivel 1.png \
    sprites/Nivel 2.png \
    sprites/Nivel 2.png \
    sprites/Nivel 2.png \
    sprites/Nivel 3.png \
    sprites/Nivel 3.png \
    sprites/Nivel 3.png \
    sprites/Nivel1.png \
    sprites/Nivel2.png \
    sprites/Nivel3.png \
    sprites/Pinchos.png \
    sprites/Piston.png \
    sprites/Velocimetro.png \
    sprites/carro1.png \
    sprites/carro2.png \
    sprites/carro3.png \
    sprites/carrobots.png
