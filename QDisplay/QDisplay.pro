#-------------------------------------------------
#
# Project created by QtCreator 2016-07-29T14:27:51
#
#-------------------------------------------------


CONFIG += c++11

QT       += core gui sql network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QDisplay
TEMPLATE = app

unix:QMAKE_RPATHDIR += /opt/Queue/QtLib /opt/Queue/QtLib/Qt5
#unix:QMAKE_RPATHDIR += /home/dedy/QtProjects/QtLib/build-QtLib-Desktop_Qt_5_7_0_GCC_64bit-Debug

CONFIG += c++11

SOURCES += main.cpp\
        MainWindow/mainwindow.cpp \
    QPrintServer/printserver.cpp \
    bignode.cpp \
    MainWindow/mainwindowtest.cpp \
    MainWindow/mainwindowa.cpp \
    MainWindow/mainwindowbase.cpp \
    Node/nodea.cpp \
    ../SharedClass/ndhelper.cpp \
    ../SharedClass/rdhelper.cpp \
    ../SharedClass/server.cpp \
    ../SharedClass/socket.cpp \
    ../SharedClass/db.cpp \
    remotedisplay.cpp

HEADERS  += MainWindow/mainwindow.h \
    QPrintServer/printserver.h \
    bignode.h \
    MainWindow/mainwindowtest.h \
    config.h \
    MainWindow/mainwindowa.h \
    MainWindow/mainwindowbase.h \
    Node/nodea.h \
    ../SharedClass/ndhelper.h \
    ../SharedClass/rdhelper.h \
    ../SharedClass/server.h \
    ../SharedClass/socket.h \
    ../SharedClass/config.h \
    ../SharedClass/db.h \
    remotedisplay.h

FORMS    += MainWindow/mainwindow.ui \
    bignode.ui \
    MainWindow/mainwindowtest.ui \
    MainWindow/mainwindowa.ui \
    Node/nodea.ui

RESOURCES += \
    ../../QtLib/QtLib/Resources/resources.qrc

DISTFILES += \
    Extra/config.ini \
    Extra/config.inx \
    Extra/logo_jakarta.jpg \
    Extra/Logo.jpg \
    Extra/Logo.png \
    Extra/Logo2.png \
    Extra/TicketTemplate.html \
    ../../QtLib/QtLib/Stylesheet/QQueue.qss \
    Extra/Node.qss \
    Extra/Node_PR0C.qss \
    Extra/Node_CALL.qss \
    Extra/QDisplay_DisplayWindow.qss \
    Extra/QDisplay_BigNodeWindow.qss \
    Extra/QDisplay_NodeWindow.qss \
    Extra/NodeWindow_CALL.qss \
    Extra/NodeWindow_PR0CESS.qss \
    Extra/v_Queue.qss \
    Extra/QClient_ClientWindow.qss \
    Extra/QDisplay_BigNodeWindow_CALL.qss \
    Extra/QDisplay_NodeWindow_CALL.qss \
    Extra/QPrint_PrintWindow.qss \
    ../Docs/Screenshots/Untitled Folder/IMG_20160830_070843.jpg \
    ../Docs/Screenshots/Untitled Folder/IMG_20160830_070904.jpg \
    ../Docs/Screenshots/Untitled Folder/IMG_20160830_071242.jpg \
    ../Docs/Screenshots/Untitled Folder/IMG_20160830_071658.jpg \
    ../Docs/Screenshots/Untitled Folder/IMG_20160830_071716.jpg \
    ../Docs/Screenshots/Untitled Folder/IMG_20160830_072003.jpg \
    ../Docs/Screenshots/IMG_20160830_071453.jpg \
    ../Docs/Screenshots/IMG_20160830_071548.jpg \
    ../Docs/Screenshots/IMG_20160830_071555.jpg \
    ../Docs/Screenshots/IMG_20160830_071630.jpg \
    ../Docs/Screenshots/IMG_20160830_071640.jpg \
    ../Docs/Screenshots/IMG_20160830_071656.jpg \
    ../Docs/Screenshots/IMG_20160830_071713.jpg \
    ../Docs/Screenshots/IMG_20160830_071755.jpg \
    ../Docs/Screenshots/IMG_20160830_071834.jpg \
    ../Docs/Screenshots/IMG_20160830_071958.jpg \
    ../Docs/Screenshots/IMG_20160830_083344.jpg \
    ../Docs/Queue.png \
    ../readme.md

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
