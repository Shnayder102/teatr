QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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

SOURCES += \
    actor.cpp \
    l_performance.cpp \
    list.cpp \
    list_actors.cpp \
    list_tickets.cpp \
    list_users.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    more_actor.cpp \
    more_performances.cpp \
    more_ticket.cpp \
    performance.cpp \
    registration.cpp \
    ticket.cpp \
    users.cpp

HEADERS += \
    actor.h \
    l_performance.h \
    list.h \
    list_actors.h \
    list_tickets.h \
    list_users.h \
    login.h \
    mainwindow.h \
    more_actor.h \
    more_performances.h \
    more_ticket.h \
    performance.h \
    registration.h \
    ticket.h \
    users.h

FORMS += \
    list.ui \
    login.ui \
    mainwindow.ui \
    more_actor.ui \
    more_performances.ui \
    more_ticket.ui \
    registration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    actors.bin \
    icons/Note-add.svg \
    icons/Note-remove.svg \
    icons/Notebook-open.svg \
    icons/Notebook-save-as.svg \
    icons/Notebook-save.svg \
    l_performance.bin \
    users.bin \
    viewer.bin

RESOURCES += \
    resources.qrc
