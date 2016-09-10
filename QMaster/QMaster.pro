#-------------------------------------------------
#
# Project created by QtCreator 2016-09-07T13:47:40
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMaster
TEMPLATE = app

# Ddy:
#unix:QMAKE_RPATHDIR += /opt/Queue/QtLib /opt/Queue/QtLib/Qt5
INCLUDEPATH += $$PWD/../SharedClass

SOURCES += main.cpp\
        mainwindow.cpp \
    ../SharedClass/StatusBar/statusbarwidget.cpp \
    dialog.cpp \
    NodeList/formnodelist.cpp \
    formgrouplist.cpp \
    formreport.cpp \
    formwelcome.cpp \
    NodeList/nodelist.cpp

HEADERS  += mainwindow.h \
    ../SharedClass/StatusBar/statusbarwidget.h \
    dialog.h \
    NodeList/formnodelist.h \
    formgrouplist.h \
    formreport.h \
    formwelcome.h \
    NodeList/nodelist.h

FORMS    += mainwindow.ui \
    ../SharedClass/StatusBar/statusbarwidget.ui \
    dialog.ui \
    NodeList/formnodelist.ui \
    formgrouplist.ui \
    formreport.ui \
    formwelcome.ui

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QProcess/release/ -lQProcess
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QProcess/debug/ -lQProcess
else:unix:!macx: LIBS += -L$$OUT_PWD/../QProcess/ -lQProcess

INCLUDEPATH += $$PWD/../QProcess
DEPENDPATH += $$PWD/../QProcess

DISTFILES += \
    ../Extra/QMaster.ini \
    ../Extra/QMaster.inx
