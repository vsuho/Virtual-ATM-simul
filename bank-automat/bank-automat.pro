QT       += core gui
QT       += network
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    environment.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    otto.cpp \
    pin.cpp \
    saldo.cpp \
    tilinvalinta.cpp \
    transactions.cpp

HEADERS += \
    environment.h \
    mainmenu.h \
    mainwindow.h \
    otto.h \
    pin.h \
    saldo.h \
    tilinvalinta.h \
    transactions.h

FORMS += \
    mainmenu.ui \
    mainwindow.ui \
    otto.ui \
    pin.ui \
    saldo.ui \
    tilinvalinta.ui \
    transactions.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target







win32:CONFIG(release, debug|release): LIBS += -L$$PWD/rfidreader/build/release/ -lrfidreader
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/rfidreader/build/debug/ -lrfidreader
else:unix: LIBS += -L$$PWD/rfidreader/build/ -lrfidreader



win32: LIBS += -L$$PWD/rfidreader/build/debug/ -lrfidreader

INCLUDEPATH += $$PWD/rfidreader
DEPENDPATH += $$PWD/rfidreader

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/rfidreader/build/release/ -lrfidreader
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/rfidreader/build/debug/ -lrfidreader

INCLUDEPATH += $$PWD/rfidreader
DEPENDPATH += $$PWD/rfidreader
