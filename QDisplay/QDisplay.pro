#-------------------------------------------------
#
# Project created by QtCreator 2016-09-03T16:01:31
#
#-------------------------------------------------

QT       += core gui sql network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += core gui sql network multimedia
TARGET = QDisplay
TEMPLATE = app

# Ddy:
#unix:QMAKE_RPATHDIR += /opt/Queue/QtLib /opt/Queue/QtLib/Qt5

SOURCES += main.cpp \
    ../SharedClass/BaseUi/bignodebase.cpp \
    ../SharedClass/BaseUi/mainwindowbase.cpp \
    ../SharedClass/BaseUi/nodebase.cpp \
    mainwindow.cpp \
    node.cpp \
    bignode.cpp \
    displayserver.cpp \
    ../SharedClass/db.cpp \
    ../SharedClass/ndhelper.cpp \
    ../SharedClass/rdhelper.cpp \
    ../SharedClass/server.cpp \
    RemoteDisplay/remotedisplay.cpp \
    ../SharedClass/StatusBar/statusbarwidget.cpp \
    ../SharedClass/callersound.cpp

HEADERS  += \
    ../SharedClass/BaseUi/bignodebase.h \
    ../SharedClass/BaseUi/mainwindowbase.h \
    ../SharedClass/BaseUi/nodebase.h \
    mainwindow.h \
    node.h \
    bignode.h \
    displayserver.h \
    ../SharedClass/config.h \
    ../SharedClass/db.h \
    ../SharedClass/ndhelper.h \
    ../SharedClass/rdhelper.h \
    ../SharedClass/server.h \
    RemoteDisplay/remotedisplay.h \
    ../SharedClass/StatusBar/statusbarwidget.h \
    ../SharedClass/callersound.h

FORMS    += \
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
    Extra/QClient_ClientWindow.qss \
    Extra/QDisplay__CALL.qss \
    Extra/QDisplay_.qss \
    Extra/QDisplay_BigNodeWindow_.qss \
    Extra/QDisplay_BigNodeWindow_CALL.qss \
    Extra/QDisplay_BigNodeWindow.qss \
    Extra/QDisplay_DisplayWindow.qss \
    Extra/QDisplay_NodeWindow_.qss \
    Extra/QDisplay_NodeWindow_CALL.qss \
    Extra/QDisplay_NodeWindow.qss \
    Extra/QPrint_PrintWindow.qss \
    Extra/QRemoteDisplay_.qss \
    Extra/QRemoteDisplay_BigNode_CALL.qss \
    Extra/QRemoteDisplay_BigNode.qss \
    Extra/QRemoteDisplay_MainWindow.qss \
    Extra/QRemoteDisplay_Node_CALL.qss \
    Extra/QRemoteDisplay_Node.qss \
    Extra/v_Queue.qss \
    Extra/QDisplay.ini \
    Extra/QDisplay.inx \
    Extra/qss/QDisplay_.qss \
    Extra/qss/QDisplay_BigNode_CALL.qss \
    Extra/qss/QDisplay_BigNode.qss \
    Extra/qss/QDisplay_MainWindow.qss \
    Extra/qss/QDisplay_Node_CALL.qss \
    Extra/qss/QDisplay_Node_INIT.qss \
    Extra/qss/QDisplay_Node.qss
