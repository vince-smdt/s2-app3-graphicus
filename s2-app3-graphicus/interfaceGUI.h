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
#include "graphicusGUI.h"

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
	void ajouterCerclee(int x, int y, int rayon);
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
private:
	Canevas _canevas;
};

#endif
