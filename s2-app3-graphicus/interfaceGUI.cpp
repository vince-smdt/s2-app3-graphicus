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

void InterfaceGUI::reinitialiserCanevas() { _canevas.reinitialiser(); }

void InterfaceGUI::coucheAjouter() {}

void InterfaceGUI::coucheRetirer() {}

void InterfaceGUI::coucheTranslater(int deltaX, int deltaY) {}

void InterfaceGUI::ajouterCerclee(int x, int y, int rayon) {}

void InterfaceGUI::ajouterRectangle(int x, int y, int longueur, int largeur) {}

void InterfaceGUI::ajouterCarre(int x, int y, int cote) {}

void InterfaceGUI::retirerForme() {}

void InterfaceGUI::modePileChange(bool mode) {}

void InterfaceGUI::couchePremiere() { 
	if (_canevas.premiereCouche() == false)
		messageErreur("Erreur lors de la séléction de la première couche!");
}

void InterfaceGUI::couchePrecedente() {
	if (_canevas.precedenteCouche() == false)
		messageErreur("Erreur lors de la séléction de la couche précédente!");
}

void InterfaceGUI::coucheSuivante() {
	if (_canevas.prochaineCouche() == false)
		messageErreur("Erreur lors de la séléction de la couche suivante!");
}

void InterfaceGUI::coucheDerniere() { 
	if (_canevas.derniereCouche() == false)
		messageErreur("Erreur lors de la séléction de la dernière couche!");
}

void InterfaceGUI::formePremiere() {
	if (_canevas.obtenirCoucheActive()->premiereForme() == false)
		messageErreur("Erreur lors de la séléction de la premiere forme de la couche!");
}

void InterfaceGUI::formePrecedente() {
	if (_canevas.obtenirCoucheActive()->precedenteForme() == false)
		messageErreur("Erreur lors de la séléction de la forme précédente de la couche!");
}

void InterfaceGUI::formeSuivante() {
	if (_canevas.obtenirCoucheActive()->prochaineForme() == false)
		messageErreur("Erreur lors de la séléction de la forme suivante de la couche!");
}

void InterfaceGUI::formeDerniere() {
	if (_canevas.obtenirCoucheActive()->derniereForme() == false)
		messageErreur("Erreur lors de la séléction de la derniere forem de la couche!");
}
