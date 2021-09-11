QT       += core gui
QT       += network
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -LQnetwork/OpenSSL-Win64
LIBS += -LQnetwork/OpenSSL-Win64/bin
LIBS += -LQnetwork/OpenSSL-Win64/lib
LIBS += -llibssl

SOURCES += \
    file.cpp \
    html.cpp \
    main.cpp \
    mainwindow.cpp \
    parser.cpp

HEADERS += \
    file.h \
    html.h \
    mainwindow.h \
    parser.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
