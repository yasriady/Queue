#-------------------------------------------------
#
# Project created by QtCreator 2016-08-02T21:08:31
#
#-------------------------------------------------

CONFIG += c++11

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QClient
TEMPLATE = app

unix:QMAKE_RPATHDIR += /opt/Queue/QtLib /opt/Queue/QtLib/Qt5
#unix:QMAKE_RPATHDIR += /home/dedy/QtProjects/QtLib/build-QtLib-Desktop_Qt_5_7_0_GCC_64bit-Debug

SOURCES +=\
    main.cpp \
    mysocket.cpp \
    statusbarwidget.cpp \
    client.cpp \
    mainwindow.cpp \
    statusbar.cpp \
    ../QDisplay/ndhelper.cpp \
    ../QDisplay/rdhelper.cpp

HEADERS  += \
    mysocket.h \
    statusbarwidget.h \
    client.h \
    mainwindow.h \
    statusbar.h \
    ../QDisplay/config.h \
    ../WiFiClient_LCD/arduino.h \
    ../QDisplay/ndhelper.h \
    ../QDisplay/rdhelper.h

FORMS    += \
    statusbarwidget.ui \
    client.ui \
    mainwindow.ui

RESOURCES += \
    ../../QtLib/QtLib/Resources/resources.qrc

DISTFILES += \
    Extra/Queue.db \
    Extra/config.ini \
    Extra/logo_jakarta.jpg \
    Extra/Logo.jpg \
    Extra/Logo.png \
    Extra/Logo2.png \
    Extra/TicketTemplate.html \
    Extra/config.inx \
    Extra/QClient_ClientWindow.qss \
    Extra/QDisplay_BigNodeWindow.qss \
    Extra/QDisplay_DisplayWindow.qss \
    Extra/QDisplay_NodeWindow.qss \
    Extra/QPrint_PrintWindow.qss \
    Extra/v_Queue.qss \
    Extra/QDisplay_NodeWindow_CALL.qss \
    Extra/QDisplay_BigNodeWindow_CALL.qss

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
