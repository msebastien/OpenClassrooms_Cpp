TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .

# Input
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    generatedclasswindow.cpp

HEADERS += \
    mainwindow.h \
    generatedclasswindow.h

TRANSLATIONS = cppclassgenerator_en.ts zeroclassgenerator_es.ts

QT += core widgets
