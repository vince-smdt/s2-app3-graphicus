/********
 * Fichier: interfaceGUI.h
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 fevrier 2024 (creation)
 * Description: Definition de la classe InterfaceGUI. Cette classe redefinie
 * 				des methodes virtuelles de la librairie GraphicusGUI.
********/

#ifndef INTERFACEGUI_H
#define INTERFACEGUI_H

#include "graphicusGUI.h"

class InterfaceGUI : public GraphicusGUI
{
public:
	InterfaceGUI(const char* titre = nullptr);
};

#endif
