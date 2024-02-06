/********
 * Fichier: interfaceGUI.cpp
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 fevrier 2024 (creation)
 * Description: Implementation des methodes de la classe InterfaceGUI.h.
********/

#include "interfaceGUI.h"
#include <vector>

InterfaceGUI::InterfaceGUI(const char* titre) : GraphicusGUI(titre) { rafraichir(); }

std::string* const InterfaceGUI::separer(string entrer) {
	std::istringstream flux(entrer);
	std::string mesure;
	int i = 0;
	while (flux >> mesure) {
		_mesMesures[i] = mesure;
		i++;
	}
	return _mesMesures;
}

void InterfaceGUI::rafraichir() {
	ostringstream ss;
	ss << _canevas;
	dessiner(ss.str().c_str());
	updateInformation();
}

bool InterfaceGUI::ouvrirFichier(const char* nom) {
	bool premiereCouche = false;
	_canevas.reinitialiser();

	std::ifstream fichier(nom);
	if (fichier.is_open()) {
		std::string* mesMesures;
		std::string ligne;

		while (std::getline(fichier, ligne)) {
			switch (ligne[0])
			{
			case *"L":
				if (premiereCouche == false)
					premiereCouche = true;
				else
					_canevas.ajouterCouche();

				switch (ligne[2])
				{
				case * "a":
					_canevas.activerCouche(_canevas.derniereCouche());
					break;
				case * "x":
					_canevas.desactiverCouche(_canevas.derniereCouche());
					break;
				}
				break;
			case *"R":
				mesMesures = separer(ligne);
				_canevas.ajouterForme(new Rectangle(std::stoi(mesMesures[1]), std::stoi(mesMesures[2]), std::stoi(mesMesures[3]), std::stoi(mesMesures[4])));
				break;
			case * "K":
				mesMesures = separer(ligne);
				_canevas.ajouterForme(new Carre(std::stoi(mesMesures[1]), std::stoi(mesMesures[2]), std::stoi(mesMesures[3])));
				break;
			case * "C":
				mesMesures = separer(ligne);
				_canevas.ajouterForme(new Cercle(std::stoi(mesMesures[1]), std::stoi(mesMesures[2]), std::stoi(mesMesures[3])));
				break;
			default:
				return false;
			}
		}
		fichier.close();
	} 
	else {
		return false;
	}

	rafraichir();
	return true;
}

bool InterfaceGUI::sauvegarderFichier(const char* nom) { 
	std::ofstream fichier(nom);
	if (fichier.is_open()) {
		afficher(fichier);
		return true;
	}
	return false;	
}

void InterfaceGUI::reinitialiserCanevas() { 
	_canevas.reinitialiser();
	rafraichir();
}

void InterfaceGUI::coucheAjouter() { 
	_canevas.ajouterCouche(); 
	rafraichir(); 
}

void InterfaceGUI::coucheRetirer() { 
	_canevas.retirerCouche(_canevas.indexCoucheActive());
	rafraichir();
}

void InterfaceGUI::coucheTranslater(int deltaX, int deltaY) {
	if (_canevas.translater(deltaX, deltaY) == false)
		messageErreur("Erreur lors de la translation de la couche!");

	rafraichir();
}

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

	rafraichir();
}

void InterfaceGUI::ajouterRectangle(int x, int y, int longueur, int largeur) {
	if (_canevas.ajouterForme(new Rectangle(x, y, longueur, largeur)) == false)
		messageErreur("Erreur lors de la creation d'un rectangle!");

	Forme* forme = _canevas.obtenirCoucheActive()->obtenirFormeActive();
	if (forme == nullptr) {
		messageErreur("Le rectangle cree n'a pas pu etre recupere!");
		return;
	}

	rafraichir();
}

void InterfaceGUI::ajouterCarre(int x, int y, int cote) {
	if (_canevas.ajouterForme(new Carre(x, y, cote)) == false)
		messageErreur("Erreur lors de la creation d'un carre!");

	Forme* forme = _canevas.obtenirCoucheActive()->obtenirFormeActive();
	if (forme == nullptr) {
		messageErreur("Le carre cree n'a pas pu etre recupere!");
		return;
	}

	rafraichir();
}

void InterfaceGUI::retirerForme() {
	_canevas.retirerForme(_canevas.obtenirCoucheActive()->obtenirIndexFormeActive());
	rafraichir();
}

void InterfaceGUI::modePileChange(bool mode) {
	_canevas.modePile();
	rafraichir();
}

void InterfaceGUI::couchePremiere() { 
	if (_canevas.premiereCouche() == false)
		messageErreur("Erreur lors de la selection de la premiere couche!");
	rafraichir();
}

void InterfaceGUI::couchePrecedente() {
	if (_canevas.precedenteCouche() == false)
		messageErreur("Erreur lors de la selection de la couche precedente!");
	rafraichir();
}

void InterfaceGUI::coucheSuivante() {
	if (_canevas.prochaineCouche() == false)
		messageErreur("Erreur lors de la selection de la couche suivante!");
	rafraichir();
}

void InterfaceGUI::coucheDerniere() { 
	if (_canevas.derniereCouche() == false)
		messageErreur("Erreur lors de la selection de la derniere couche!");
	rafraichir();
}

void InterfaceGUI::formePremiere() {
	if (_canevas.obtenirCoucheActive()->premiereForme() == false)
		messageErreur("Erreur lors de la selection de la premiere forme de la couche!");
	rafraichir();
}

void InterfaceGUI::formePrecedente() {
	if (_canevas.obtenirCoucheActive()->precedenteForme() == false)
		messageErreur("Erreur lors de la selection de la forme precedente de la couche!");
	rafraichir();
}

void InterfaceGUI::formeSuivante() {
	if (_canevas.obtenirCoucheActive()->prochaineForme() == false)
		messageErreur("Erreur lors de la selection de la forme suivante de la couche!");
	rafraichir();
}

void InterfaceGUI::formeDerniere() {
	if (_canevas.obtenirCoucheActive()->derniereForme() == false)
		messageErreur("Erreur lors de la selection de la derniere forem de la couche!");
	rafraichir();
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
	if (couche != nullptr) {
		info.nbFormesCouche = couche->nbFormes();
		strcpy(info.etatCouche, couche->getEtatCStr());
		info.aireCouche = couche->aireTotal();
		info.formeActive = couche->obtenirIndexFormeActive();

		// Forme active
		Forme* forme = couche->obtenirFormeActive();
		if (forme != nullptr) {
			info.coordX = forme->getAncrage().x;
			info.coordY = forme->getAncrage().y;
			info.aireForme = forme->aire();
			ostringstream infoForme;
			infoForme << *forme;
			strcpy(info.informationForme, infoForme.str().c_str());
		}
	}

	

	setInformations(info);
}
