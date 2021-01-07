QT       += core gui sql
CONFIG += console
QT += printsupport
QT += multimedia
QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    capteurtemp.cpp \
    client.cpp \
    conge.cpp \
    connection.cpp \
    decorateur.cpp \
    employe.cpp \
    gestion_cong.cpp \
    gestion_de_salle.cpp \
    gestion_emp.cpp \
    gestion_salle.cpp \
    gestionoffre.cpp \
    gestionreclamation.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    offre.cpp \
    reclamation.cpp \
    reservation.cpp \
    uimayssa.cpp

HEADERS += \
    arduino.h \
    capteurtemp.h \
    client.h \
    conge.h \
    connection.h \
    decorateur.h \
    employe.h \
    gestion_cong.h \
    gestion_de_salle.h \
    gestion_emp.h \
    gestion_salle.h \
    gestionoffre.h \
    gestionreclamation.h \
    mainwindow.h \
    menu.h \
    offre.h \
    reclamation.h \
    reservation.h \
    uimayssa.h

FORMS += \
    capteurtemp.ui \
    gestion_cong.ui \
    gestion_de_salle.ui \
    gestion_emp.ui \
    gestionoffre.ui \
    gestionreclamation.ui \
    mainwindow.ui \
    menu.ui \
    uimayssa.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressources.qrc
