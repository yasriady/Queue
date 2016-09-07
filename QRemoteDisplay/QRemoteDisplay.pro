#-------------------------------------------------
#
# Project created by QtCreator 2016-09-04T13:02:49
#
#-------------------------------------------------

QT       += core gui sql network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRemoteDisplay
TEMPLATE = app

# Ddy:
#unix:QMAKE_RPATHDIR += /opt/Queue/QtLib /opt/Queue/QtLib/Qt5
INCLUDEPATH += $$PWD/../SharedClass $$PWD

SOURCES += main.cpp\
        mainwindow.cpp \
    ../SharedClass/BaseUi/bignodebase.cpp \
    ../SharedClass/BaseUi/mainwindowbase.cpp \
    ../SharedClass/BaseUi/nodebase.cpp \
    bignode.cpp \
    node.cpp \
    ../SharedClass/db.cpp \
    ../SharedClass/ndhelper.cpp \
    displayclient.cpp \
    ../SharedClass/socket.cpp \
    ../SharedClass/StatusBar/statusbarwidget.cpp \
    ../SharedClass/callersound.cpp

HEADERS  += mainwindow.h \
    ../SharedClass/BaseUi/bignodebase.h \
    ../SharedClass/BaseUi/mainwindowbase.h \
    ../SharedClass/BaseUi/nodebase.h \
    bignode.h \
    node.h \
    ../SharedClass/db.h \
    ../SharedClass/ndhelper.h \
    displayclient.h \
    ../SharedClass/config.h \
    ../SharedClass/socket.h \
    ../SharedClass/StatusBar/statusbarwidget.h \
    ../SharedClass/callersound.h

FORMS    += mainwindow.ui \
    ../SharedClass/BaseUi/bignodebase.ui \
    ../SharedClass/BaseUi/mainwindowbase.ui \
    ../SharedClass/BaseUi/nodebase.ui \
    ../SharedClass/StatusBar/statusbarwidget.ui

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

unix:!macx: LIBS += -lasound

DISTFILES += \
    Extra/QRemoteDisplay.ini \
    Extra/QRemoteDisplay.inx \
    Extra/qss/QRemoteDisplay_.qss \
    Extra/qss/QRemoteDisplay_BigNode_CALL.qss \
    Extra/qss/QRemoteDisplay_BigNode.qss \
    Extra/qss/QRemoteDisplay_MainWindow.qss \
    Extra/qss/QRemoteDisplay_Node_CALL.qss \
    Extra/qss/QRemoteDisplay_Node.qss
