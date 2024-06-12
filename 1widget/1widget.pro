QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcompany.cpp \
    comment.cpp \
    content.cpp \
    createjob.cpp \
    home.cpp \
    jobscompany.cpp \
    jobsuser.cpp \
    likelist.cpp \
    loginpage.cpp \
    main.cpp \
    me.cpp \
    messaging.cpp \
    mynetworkcompany.cpp \
    mynetworkuser.cpp \
    post.cpp \
    startpage.cpp \
    verificationpage.cpp \
    viewprofile.cpp

HEADERS += \
    addcompany.h \
    comment.h \
    content.h \
    createjob.h \
    home.h \
    jobscompany.h \
    jobsuser.h \
    likelist.h \
    loginpage.h \
    me.h \
    messaging.h \
    mynetworkcompany.h \
    mynetworkuser.h \
    post.h \
    startpage.h \
    verificationpage.h \
    viewprofile.h

FORMS += \
    addcompany.ui \
    comment.ui \
    createjob.ui \
    home.ui \
    jobscompany.ui \
    jobsuser.ui \
    likelist.ui \
    loginpage.ui \
    me.ui \
    messaging.ui \
    mynetworkcompany.ui \
    mynetworkuser.ui \
    post.ui \
    startpage.ui \
    verificationpage.ui \
    viewprofile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    captcha.qrc \
    images.qrc \
    navig.qrc

DISTFILES +=
