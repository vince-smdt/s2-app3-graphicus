TEMPLATE     = vcapp
TARGET       = s2-app3-graphicus
CONFIG      += warn_on qt debug windows console
HEADERS     += canevas.h \
               carre.h \
               cercle.h \
               couche.h \
               forme.h \
               interfaceGUI.h \
               rectangle.h \
               tests.h \
               vecteur.h
SOURCES     += s2-app3-graphicus.cpp \
               canevas.cpp \
               carre.cpp \
               cercle.cpp \
               couche.cpp \
               forme.cpp \
               interfaceGUI.cpp \
               rectangle.cpp \
               tests.cpp \
               vecteur.cpp
INCLUDEPATH += GraphicusGUI
LIBS        += GraphicusGUI/graphicusGUI.lib
QT          += widgets