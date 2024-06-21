QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Cinema.cpp \
    changeorder.cpp \
    genre.cpp \
    main.cpp \
    mainwindow.cpp \
    movie.cpp \
    nomovie.cpp \
    price.cpp \
    secondgenre.cpp \
    secondmovie.cpp

HEADERS += \
    Cinema.h \
    changeorder.h \
    genre.h \
    mainwindow.h \
    movie.h \
    nomovie.h \
    price.h \
    secondgenre.h \
    secondmovie.h

FORMS += \
    changeorder.ui \
    genre.ui \
    mainwindow.ui \
    movie.ui \
    nomovie.ui \
    price.ui \
    secondgenre.ui \
    secondmovie.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
