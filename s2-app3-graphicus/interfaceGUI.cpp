/********
 * Fichier: interfaceGUI.cpp
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 fevrier 2024 (creation)
 * Description: Implementation des methodes de la classe InterfaceGUI.h.
********/

#include "interfaceGUI.h"
#include <iostream>
#include <fstream>
#include <string>

InterfaceGUI::InterfaceGUI(const char* titre) : GraphicusGUI(titre) {}

bool InterfaceGUI::ouvrirFichier(const char* nom) {
	std::ifstream fichier(nom);
	if (fichier.is_open()) {
		std::string ligne;

		while (std::getline(fichier, ligne)) {

		}

		fichier.close();
	} 
	else {
		return false;
	}

	//int lenghtMax = 0;
	//int lastSlash = 0;

	//while (nom[lenghtMax] != '\0')
	//	lenghtMax++;

	//// Trouver où est la dernier /
	//const char* temp = nom;
	//for (int i = 0; i < lenghtMax; i++)
	//	if (temp[i] == '\\' || temp[i] == '/') 
	//		lastSlash = i + 1;

	//// Changer contenu de nom
	//nom = "";
	//for (int i = lastSlash; i < lenghtMax; i++)
	//	nom += temp[i];



	return true;
}

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
