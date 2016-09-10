#-------------------------------------------------
#
# Project created by QtCreator 2016-09-08T12:55:22
#
#-------------------------------------------------

QT       += network sql multimedia

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

TARGET = QProcess
TEMPLATE = lib

DEFINES += QPROCESS_LIBRARY

SOURCES += qprocess.cpp \
    callersound.cpp \
    db.cpp \
    displayserver.cpp \
    ndhelper.cpp \
    rdhelper.cpp \
    remotedisplay.cpp \
    server.cpp \
    socket.cpp \
    app_globals.cpp

HEADERS += qprocess.h\
        qprocess_global.h \
    callersound.h \
    config.h \
    db.h \
    displayserver.h \
    ndhelper.h \
    rdhelper.h \
    remotedisplay.h \
    server.h \
    socket.h \
    app_globals.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../QtLib/QtConfig/release/ -lQtConfig
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../QtLib/QtConfig/debug/ -lQtConfig
else:unix:!macx: LIBS += -L$$OUT_PWD/../../QtLib/QtConfig/ -lQtConfig

INCLUDEPATH += $$PWD/../../QtLib/QtConfig
DEPENDPATH += $$PWD/../../QtLib/QtConfig

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../QtLib/QtLib/release/ -lQtLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../QtLib/QtLib/debug/ -lQtLib
else:unix:!macx: LIBS += -L$$OUT_PWD/../../QtLib/QtLib/ -lQtLib

INCLUDEPATH += $$PWD/../../QtLib/QtLib
DEPENDPATH += $$PWD/../../QtLib/QtLib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../QtLib/QtDB/release/ -lQtDB
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../QtLib/QtDB/debug/ -lQtDB
else:unix:!macx: LIBS += -L$$OUT_PWD/../../QtLib/QtDB/ -lQtDB

INCLUDEPATH += $$PWD/../../QtLib/QtDB
DEPENDPATH += $$PWD/../../QtLib/QtDB
