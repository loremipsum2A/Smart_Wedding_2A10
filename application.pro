QT       += core gui sql
CONFIG += console
QT += printsupport
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    conge.cpp \
    connection.cpp \
    employe.cpp \
    gestion_cong.cpp \
    gestion_emp.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    conge.h \
    connection.h \
    employe.h \
    gestion_cong.h \
    gestion_emp.h \
    mainwindow.h

FORMS += \
    gestion_cong.ui \
    gestion_emp.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressources.qrc
