/********
 * Fichier: interfaceGUI.h
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 fevrier 2024 (creation)
 * Description: Definition de la classe InterfaceGUI. Cette classe redefinie
 * 				des methodes virtuelles de la librairie GraphicusGUI.
********/

#ifndef INTERFACEGUI_H
#define INTERFACEGUI_H

#include "canevas.h"
#include "carre.h"
#include "cercle.h"
#include "graphicusGUI.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class InterfaceGUI : public GraphicusGUI
{
public:
	InterfaceGUI(const char* titre = nullptr);

	// Actions de fichiers
	bool ouvrirFichier(const char* nom);
	bool sauvegarderFichier(const char* nom);

	// Actions de canevas, de couches et de formes
	void reinitialiserCanevas();
	void coucheAjouter();
	void coucheRetirer();
	void coucheTranslater(int deltaX, int deltaY);
	void ajouterCercle(int x, int y, int rayon);
	void ajouterRectangle(int x, int y, int longueur, int largeur);
	void ajouterCarre(int x, int y, int cote);
	void retirerForme();
	void modePileChange(bool mode);

	// Actions de navigation
	void couchePremiere();
	void couchePrecedente();
	void coucheSuivante();
	void coucheDerniere();
	void formePremiere();
	void formePrecedente();
	void formeSuivante();
	void formeDerniere();

	// Helper pour l'envoi d'information
	void updateInformation();
private:
	Canevas _canevas;
};

#endif
