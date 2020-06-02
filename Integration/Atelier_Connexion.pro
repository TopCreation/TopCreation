#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql
QT += printsupport
QT += network
QT  += core gui multimedia multimediawidgets
QT += widgets multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    activity.cpp \
    dialog.cpp \
    dialog3.cpp \
    dialog4.cpp \
    dialog5.cpp \
    employe.cpp \
    enfant.cpp \
    equipement.cpp \
    evenement.cpp \
    fournisseurs.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    parent.cpp \
    poste.cpp \
    secdialog.cpp \
    smtp.cpp

HEADERS += \
    activity.h \
    dialog.h \
    dialog3.h \
    dialog4.h \
    dialog5.h \
    employe.h \
    enfant.h \
    equipement.h \
    evenement.h \
    fournisseurs.h \
        mainwindow.h \
    connection.h \
    parent.h \
    poste.h \
    secdialog.h \
    smtp.h

FORMS += \
        dialog.ui \
        dialog3.ui \
        dialog4.ui \
        dialog5.ui \
        mainwindow.ui \
        secdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
