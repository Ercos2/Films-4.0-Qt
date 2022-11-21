QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog_add1.cpp \
    dialog_change1.cpp \
    dialog_select1.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Func.h \
    Functions.h \
    dialog_add1.h \
    dialog_change1.h \
    dialog_select1.h \
    mainwindow.h

FORMS += \
    dialog_add1.ui \
    dialog_change1.ui \
    dialog_select1.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
