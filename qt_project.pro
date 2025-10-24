QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    g_lecteurs_window.cpp \
    g_livres_window.cpp \
    g_prets_window.cpp \
    g_rapports_stat.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    g_lecteurs_window.h \
    g_livres_window.h \
    g_prets_window.h \
    g_rapports_stat.h \
    mainwindow.h

FORMS += \
    g_lecteurs_window.ui \
    g_livres_window.ui \
    g_prets_window.ui \
    g_rapports_stat.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    styl.qss \
    styles.qss
