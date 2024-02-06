/********
 * Fichier: interfaceGUI.cpp
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 fevrier 2024 (creation)
 * Description: Implementation des methodes de la classe InterfaceGUI.h.
********/

#include "interfaceGUI.h"

InterfaceGUI::InterfaceGUI(const char* titre) : GraphicusGUI(titre) {}

bool InterfaceGUI::ouvrirFichier(const char* nom) { return 0; }

bool InterfaceGUI::sauvegarderFichier(const char* nom) { return 0; }

void InterfaceGUI::reinitialiserCanevas() { _canevas.reinitialiser();  }

void InterfaceGUI::coucheAjouter() {}

void InterfaceGUI::coucheRetirer() {}

void InterfaceGUI::coucheTranslater(int deltaX, int deltaY) {}

void InterfaceGUI::ajouterCerclee(int x, int y, int rayon) {}

void InterfaceGUI::ajouterRectangle(int x, int y, int longueur, int largeur) {}

void InterfaceGUI::ajouterCarre(int x, int y, int cote) {}

void InterfaceGUI::retirerForme() {}

void InterfaceGUI::modePileChange(bool mode) {}

void InterfaceGUI::couchePremiere() {}

void InterfaceGUI::couchePrecedente() {}

void InterfaceGUI::coucheSuivante() {}

void InterfaceGUI::coucheDerniere() {}

void InterfaceGUI::formePremiere() {}

void InterfaceGUI::formePrecedente() {}

void InterfaceGUI::formeSuivante() {}

void InterfaceGUI::formeDerniere() {}
