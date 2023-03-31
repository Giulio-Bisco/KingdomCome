QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    baseClasses/buff.cpp \
    baseClasses/creature.cpp \
    baseClasses/creatures/human.cpp \
    baseClasses/creatures/humans/warrior.cpp \
    baseClasses/creatures/humans/wizard.cpp \
    baseClasses/creatures/humans/archer.cpp \
    baseClasses/creatures/monster.cpp \
    baseClasses/creatures/monsters/undead.cpp \
    baseClasses/creatures/monsters/slime.cpp \
    baseClasses/creatures/monsters/animal.cpp \
    baseClasses/item.cpp \
    baseClasses/items/consumable.cpp \
    baseClasses/items/consumables/buffpotion.cpp \
    baseClasses/items/consumables/bundle.cpp \
    baseClasses/items/consumables/restorePotion.cpp \
    baseClasses/items/equippable.cpp \
    baseClasses/items/equippables/armor.cpp \
    baseClasses/items/equippables/weapon.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    baseClasses/buff.h \
    baseClasses/creature.h \
    baseClasses/creatures/human.h \
    baseClasses/creatures/humans/warrior.h \
    baseClasses/creatures/humans/wizard.h \
    baseClasses/creatures/humans/archer.h \
    baseClasses/creatures/monster.h \
    baseClasses/creatures/monsters/undead.h \
    baseClasses/creatures/monsters/slime.h \
    baseClasses/creatures/monsters/animal.h \
    baseClasses/item.h \
    baseClasses/items/consumable.h \
    baseClasses/items/consumables/buffpotion.h \
    baseClasses/items/consumables/bundle.h \
    baseClasses/items/consumables/restorePotion.h \
    baseClasses/items/equippable.h \
    baseClasses/items/equippables/armor.h \
    baseClasses/items/equippables/weapon.h \
    dlist.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
