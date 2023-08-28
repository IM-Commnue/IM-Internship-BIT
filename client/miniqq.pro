QT       += core gui qml multimedia sql

QT       +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = RobotChat
TEMPLATE = app
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#material-sdk(组建地址)
LIBS += $$PWD/libs/libcomponents.a
INCLUDEPATH+=$$PWD/libs/include

SOURCES += \
    baiduvoice.cpp \
    chat.cpp \
    database.cpp \
    dialog.cpp \
    homepage.cpp \
    main.cpp \
    sign.cpp \
    tulingrobot.cpp \
    widget.cpp

HEADERS += \
    baiduvoice.h \
    chat.h \
    database.h \
    dialog.h \
    homepage.h \
    sign.h \
    tulingrobot.h \
    widget.h

FORMS += \
    chat.ui \
    dialog.ui \
    homepage.ui \
    sign.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../mnt/hgfs/乌班图/op/OIP (1).jfif \
    ../../../mnt/hgfs/乌班图/op/OIP (2).jfif \
    ../../../mnt/hgfs/乌班图/op/OIP (3).jfif \
    ../../../mnt/hgfs/乌班图/op/OIP (4).jfif \
    ../../../mnt/hgfs/乌班图/op/OIP.jfif \
    ../../../mnt/hgfs/乌班图/op/OIP.jpg

RESOURCES += \
    res.qrc
