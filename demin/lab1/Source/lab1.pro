QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analizwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    qcustomplot.cpp \
    widget.cpp

HEADERS += \
    Res.h \
    analizwindow.h \
    mainwindow.h \
    menu.h \
    qcustomplot.h \
    square.h \
    widget.h

FORMS += \
    analizwindow.ui \
    mainwindow.ui \
    menu.ui \
    widget.ui
QMAKE_CXXFLAGS += -Ofast

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
