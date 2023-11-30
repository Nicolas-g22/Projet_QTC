QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogparametrageequilibreuse.cpp \
    experience.cpp \
    main.cpp \
    equilibreuse.cpp \
    pointdecourbe.cpp \
    rapportmesures.cpp \
    vuegraphique.cpp

HEADERS += \
    constante.h \
    dialogparametrageequilibreuse.h \
    equilibreuse.h \
    experience.h \
    pointdecourbe.h \
    rapportmesures.h \
    vuegraphique.h

FORMS += \
    dialogparametrageequilibreuse.ui \
    equilibreuse.ui

TRANSLATIONS += \
    Equilibreuse_fr_FR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
