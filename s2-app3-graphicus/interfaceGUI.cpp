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

void InterfaceGUI::ajouterCercle(int x, int y, int rayon) {
	if (_canevas.ajouterForme(new Cercle(x, y, rayon)) == false) {
		messageErreur("Erreur lors de la creation d'un cercle!");
		return;
	}

	Forme* forme = _canevas.obtenirCoucheActive()->obtenirFormeActive();
	if (forme == nullptr) {
		messageErreur("Le cercle cree n'a pas pu etre recupere!");
		return;
	}

	ostringstream ss;
	_canevas.afficher(ss);
	dessiner(ss.str().c_str());

	updateInformation();
}

void InterfaceGUI::ajouterRectangle(int x, int y, int longueur, int largeur) {
	if (_canevas.ajouterForme(new Rectangle(x, y, longueur, largeur)) == false)
		messageErreur("Erreur lors de la creation d'un rectangle!");

	Forme* forme = _canevas.obtenirCoucheActive()->obtenirFormeActive();
	if (forme == nullptr) {
		messageErreur("Le rectangle cree n'a pas pu etre recupere!");
		return;
	}

	ostringstream ss;
	_canevas.afficher(ss);
	dessiner(ss.str().c_str());

	updateInformation();
}

void InterfaceGUI::ajouterCarre(int x, int y, int cote) {
	if (_canevas.ajouterForme(new Carre(x, y, cote)) == false)
		messageErreur("Erreur lors de la creation d'un carre!");

	Forme* forme = _canevas.obtenirCoucheActive()->obtenirFormeActive();
	if (forme == nullptr) {
		messageErreur("Le carre cree n'a pas pu etre recupere!");
		return;
	}

	ostringstream ss;
	_canevas.afficher(ss);
	dessiner(ss.str().c_str());

	updateInformation();
}

void InterfaceGUI::retirerForme() {}

void InterfaceGUI::modePileChange(bool mode) {}

void InterfaceGUI::couchePremiere() { 
	if (_canevas.premiereCouche() == false)
		messageErreur("Erreur lors de la selection de la premiere couche!");
	updateInformation();
}

void InterfaceGUI::couchePrecedente() {
	if (_canevas.precedenteCouche() == false)
		messageErreur("Erreur lors de la selection de la couche precedente!");
	updateInformation();
}

void InterfaceGUI::coucheSuivante() {
	if (_canevas.prochaineCouche() == false)
		messageErreur("Erreur lors de la selection de la couche suivante!");
	updateInformation();
}

void InterfaceGUI::coucheDerniere() { 
	if (_canevas.derniereCouche() == false)
		messageErreur("Erreur lors de la selection de la derniere couche!");
	updateInformation();
}

void InterfaceGUI::formePremiere() {
	if (_canevas.obtenirCoucheActive()->premiereForme() == false)
		messageErreur("Erreur lors de la selection de la premiere forme de la couche!");
	updateInformation();
}

void InterfaceGUI::formePrecedente() {
	if (_canevas.obtenirCoucheActive()->precedenteForme() == false)
		messageErreur("Erreur lors de la selection de la forme precedente de la couche!");
	updateInformation();
}

void InterfaceGUI::formeSuivante() {
	if (_canevas.obtenirCoucheActive()->prochaineForme() == false)
		messageErreur("Erreur lors de la selection de la forme suivante de la couche!");
	updateInformation();
}

void InterfaceGUI::formeDerniere() {
	if (_canevas.obtenirCoucheActive()->derniereForme() == false)
		messageErreur("Erreur lors de la selection de la derniere forem de la couche!");
	updateInformation();
}

void InterfaceGUI::updateInformation() {
	Informations info;

	// Canevas
	info.nbCouches = _canevas.nbCouches();
	info.nbFormesCanevas = _canevas.nbFormes();
	info.coucheActive = _canevas.indexCoucheActive();
	info.aireCanevas = _canevas.aire();

	// Couche active
	Couche* couche = _canevas.obtenirCoucheActive();
	info.nbFormesCouche = couche->nbFormes();
	strcpy(info.etatCouche, couche->getEtatCStr());
	info.aireCouche = couche->aireTotal();
	info.formeActive = couche->obtenirIndexFormeActive();

	// Forme active
	Forme* forme = couche->obtenirFormeActive();
	info.coordX = forme->getAncrage().x;
	info.coordY = forme->getAncrage().y;
	info.aireForme = forme->aire();
	ostringstream infoForme;
	forme->afficher(infoForme);
	strcpy(info.informationForme, infoForme.str().c_str());

	setInformations(info);
}
