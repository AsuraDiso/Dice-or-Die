QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data/components/gamemanager.cpp \
    data/components/mapgenerator.cpp \
    data/components/musicmanager.cpp \
    data/screens/bossfightscreen.cpp \
    data/screens/creditsscreen.cpp \
    data/screens/fightscreen.cpp \
    data/screens/gamescreen.cpp \
    data/screens/mapscreen.cpp \
    data/screens/settingsscreen.cpp \
    data/screens/tutorialscreen.cpp \
    data/widgets/button.cpp \
    data/widgets/progressbar.cpp \
    data/widgets/scrollarea.cpp \
    data/widgets/textimage.cpp \
    data/widgets/widget.cpp \
    main.cpp \
    data/screens/mainmenuscreen.cpp \
    data/screens/screen.cpp \
    data/screens/window.cpp


HEADERS += \
    data/components/gamemanager.h \
    data/components/mapgenerator.h \
    data/components/musicmanager.h \
    data/screens/bossfightscreen.h \
    data/screens/creditsscreen.h \
    data/screens/fightscreen.h \
    data/screens/gamescreen.h \
    data/screens/mainmenuscreen.h \
    data/screens/mapscreen.h \
    data/screens/screen.h \
    data/screens/settingsscreen.h \
    data/screens/tutorialscreen.h \
    data/screens/window.h \
    data/widgets/button.h \
    data/widgets/progressbar.h \
    data/widgets/scrollarea.h \
    data/widgets/textimage.h \
    data/widgets/widget.h


FORMS += \
    data/screens/bossfightscreen.ui \
    data/screens/creditsscreen.ui \
    data/screens/fightscreen.ui \
    data/screens/gamescreen.ui \
    data/screens/mainmenuscreen.ui \
    data/screens/mapscreen.ui \
    data/screens/settingsscreen.ui \
    data/screens/tutorialscreen.ui \
    data/screens/window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    data/assets.qrc
