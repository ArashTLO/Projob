QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    home.cpp \
    jobscompany.cpp \
    jobsuser.cpp \
    loginpage.cpp \
    main.cpp \
    me.cpp \
    messaging.cpp \
    mynetworkcompany.cpp \
    mynetworkuser.cpp \
    post.cpp \
    startpage.cpp \
    verificationpage.cpp

HEADERS += \
    home.h \
    jobscompany.h \
    jobsuser.h \
    loginpage.h \
    me.h \
    messaging.h \
    mynetworkcompany.h \
    mynetworkuser.h \
    post.h \
    startpage.h \
    verificationpage.h

FORMS += \
    home.ui \
    jobscompany.ui \
    jobsuser.ui \
    loginpage.ui \
    me.ui \
    messaging.ui \
    mynetworkcompany.ui \
    mynetworkuser.ui \
    post.ui \
    startpage.ui \
    verificationpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    captcha.qrc \
    images.qrc \
    navig.qrc
