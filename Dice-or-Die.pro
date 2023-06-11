QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data/actioncards/actioncard.cpp \
    data/actioncards/bandage.cpp \
    data/actioncards/shield.cpp \
    data/actioncards/sword.cpp \
    data/chars/archer.cpp \
    data/chars/character.cpp \
    data/chars/knight.cpp \
    data/chars/witch.cpp \
    data/components/gamemanager.cpp \
    data/components/mapgenerator.cpp \
    data/components/musicmanager.cpp \
    data/enemies/enemy.cpp \
    data/enemies/spider.cpp \
    data/entity.cpp \
    data/screens/bossfightscreen.cpp \
    data/screens/characterchoosescreen.cpp \
    data/screens/chestscreen.cpp \
    data/screens/creditsscreen.cpp \
    data/screens/deathscreen.cpp \
    data/screens/fightscreen.cpp \
    data/screens/gamescreen.cpp \
    data/screens/mapscreen.cpp \
    data/screens/settingsscreen.cpp \
    data/screens/shopscreen.cpp \
    data/screens/tutorialscreen.cpp \
    data/widgets/button.cpp \
    data/widgets/checkbox.cpp \
    data/widgets/dice.cpp \
    data/widgets/progressbar.cpp \
    data/widgets/scrollarea.cpp \
    data/widgets/slider.cpp \
    data/widgets/stackedwidget.cpp \
    data/widgets/textimage.cpp \
    data/widgets/widget.cpp \
    main.cpp \
    data/screens/mainmenuscreen.cpp \
    data/screens/screen.cpp \
    data/screens/window.cpp


HEADERS += \
    data/actioncards/actioncard.h \
    data/actioncards/bandage.h \
    data/actioncards/shield.h \
    data/actioncards/sword.h \
    data/chars/archer.h \
    data/chars/character.h \
    data/chars/knight.h \
    data/chars/witch.h \
    data/components/gamemanager.h \
    data/components/mapgenerator.h \
    data/components/musicmanager.h \
    data/enemies/enemy.h \
    data/enemies/spider.h \
    data/entity.h \
    data/screens/bossfightscreen.h \
    data/screens/characterchoosescreen.h \
    data/screens/chestscreen.h \
    data/screens/creditsscreen.h \
    data/screens/deathscreen.h \
    data/screens/fightscreen.h \
    data/screens/gamescreen.h \
    data/screens/mainmenuscreen.h \
    data/screens/mapscreen.h \
    data/screens/screen.h \
    data/screens/settingsscreen.h \
    data/screens/shopscreen.h \
    data/screens/tutorialscreen.h \
    data/screens/window.h \
    data/widgets/button.h \
    data/widgets/checkbox.h \
    data/widgets/dice.h \
    data/widgets/progressbar.h \
    data/widgets/scrollarea.h \
    data/widgets/slider.h \
    data/widgets/stackedwidget.h \
    data/widgets/textimage.h \
    data/widgets/widget.h


FORMS += \
    data/screens/bossfightscreen.ui \
    data/screens/characterchoosescreen.ui \
    data/screens/chestscreen.ui \
    data/screens/creditsscreen.ui \
    data/screens/deathscreen.ui \
    data/screens/fightscreen.ui \
    data/screens/gamescreen.ui \
    data/screens/mainmenuscreen.ui \
    data/screens/mapscreen.ui \
    data/screens/settingsscreen.ui \
    data/screens/shopscreen.ui \
    data/screens/tutorialscreen.ui \
    data/screens/window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    data/assets.qrc
