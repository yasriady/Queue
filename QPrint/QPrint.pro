#-------------------------------------------------
#
# Project created by QtCreator 2016-08-07T07:00:27
#
#-------------------------------------------------

CONFIG += c++11

QT       += core gui sql multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = QPrint
TEMPLATE = app

# Ddy:
unix:QMAKE_RPATHDIR += /opt/Queue/QtLib /opt/Queue/QtLib/Qt5
#unix:QMAKE_RPATHDIR += /home/dedy/QtProjects/QtLib/build-QtLib-Desktop_Qt_5_7_0_GCC_64bit-Debug
#unix:QMAKE_RPATHDIR += /home/dedy/QtProjects/QtLib/build-QtDB-Desktop_Qt_5_7_0_GCC_64bit-Debug
#unix:QMAKE_RPATHDIR += /opt/Queue/QtLib
INCLUDEPATH += $$PWD/../SharedClass


SOURCES += main.cpp\
    print.cpp \
    ticketdata.cpp \
    statusbar.cpp \
    statusbarwidget.cpp \
    ticket.cpp \
    mainwindow.cpp

HEADERS  += print.h \
    ticketdata.h \
    statusbar.h \
    statusbarwidget.h \
    ticket.h \
    mainwindow.h

FORMS    += \
    statusbarwidget.ui \
    ticket.ui \
    mainwindow.ui

RESOURCES += \
    ../../QtLib/QtLib/Resources/resources.qrc

DISTFILES += \
    TicketTemplate.html \
    qprint2.qmodel \
    Extra/Queue.db \
    Extra/Logo.png \
    Extra/config.ini \
    Extra/logo_jakarta.jpg \
    Extra/Logo.jpg \
    Extra/Logo2.png \
    Extra/TicketTemplate.html \
    Extra/config.inx \
    ../_Extra/_QQueue.qss \
    Extra/QPrint_PrintWindow.qss \
    Extra/NodeWindow_CALL.qss \
    Extra/QDisplay_BigNodeWindow.qss \
    Extra/QDisplay_DisplayWindow.qss \
    Extra/QDisplay_NodeWindow.qss \
    Extra/v_Queue.qss \
    Extra/QPrint.ini \
    Extra/QPrint.inx

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QProcess/release/ -lQProcess
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QProcess/debug/ -lQProcess
else:unix:!macx: LIBS += -L$$OUT_PWD/../QProcess/ -lQProcess

INCLUDEPATH += $$PWD/../QProcess
DEPENDPATH += $$PWD/../QProcess

INCLUDEPATH += $$PWD/../../QtLib/QtDB
DEPENDPATH += $$PWD/../../QtLib/QtDB
