QT += quick svg quickcontrols2 network networkauth

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cflow.cpp \
        cflowmodel.cpp \
        cquickflow.cpp \
        crestapi.cpp \
        crestrequest.cpp \
        cresult.cpp \
        cvariable.cpp \
        main.cpp

RESOURCES += qml.qrc\
    qtquickcontrols2.conf

TRANSLATIONS += \
    QuickFlow_fr_FR.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    qtquickcontrols2.conf

HEADERS += \
    cflow.h \
    cflowmodel.h \
    cquickflow.h \
    crestapi.h \
    crestrequest.h \
    cresult.h \
    cvariable.h



