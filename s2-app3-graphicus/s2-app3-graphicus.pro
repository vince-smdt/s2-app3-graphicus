TEMPLATE     = vcapp
TARGET       = s2-app3-graphicus
CONFIG      += warn_on qt debug windows console
HEADERS     += monInterface.h 
SOURCES     += s2-app3-graphicus.cpp monInterface.cpp
INCLUDEPATH += ../GraphicusGUI
LIBS        += ../GraphicusGUI/graphicusGUI.lib
QT          += widgets