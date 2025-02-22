QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cardioid.cpp \
    deltoid.cpp \
    expression.cpp \
    function.cpp \
    graphdrawer.cpp \
    main.cpp \
    parameters.cpp \
    parser.cpp \
    ploat.cpp \
    ploatbuilder.cpp \
    thread.cpp

HEADERS += \
    cardioid.h \
    deltoid.h \
    expression.h \
    function.h \
    graphdrawer.h \
    parameters.h \
    parser.h \
    ploat.h \
    ploatbuilder.h \
    thread.h

FORMS += \
    parameters.ui \
    ploatbuilder.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
