/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 05 fevrier 2024
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas()
{
	Couche* c = new Couche;
	c->changerEtat(Couche::Etat::Active);
	_couches.ajouter(c);

	_couches.setActif(0);
	activerCouche(_couches.actif());
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
	for (int i = 0; i < _couches.taille(); i++)
		if (reinitialiserCouche(i) == false)
			return false;

	_couches.setActif(0);

	return activerCouche(_couches.actif());
}

bool Canevas::reinitialiserCouche(int index)
{
	if (index < 0 || index >= _couches.taille())
		return false;

	bool etaitActive = (_couches[index].getEtat() == Couche::Etat::Active);

	bool succes = _couches[index].reinitialiser();
	if (etaitActive == true)
		_couches[index].changerEtat(Couche::Etat::Active);
	return succes;
}

bool Canevas::ajouterCouche() {
	return _couches.ajouter(new Couche)
		   && derniereCouche();
}

bool Canevas::retirerCouche(int index) {
	if (_couches.taille() <= 1)
		return false;

	Couche* c = _couches.retirer(index);

	if (c == nullptr)
		return false;

	delete c;
	return true;
}

bool Canevas::activerCouche(int index)
{
	if (index < 0 || index >= _couches.taille())
		return false;

	if (_couches.actif() != -1)
		_couches[_couches.actif()].changerEtat(Couche::Etat::Inactive);

	_couches.setActif(index);

	return _couches[index].changerEtat(Couche::Etat::Active);
}

bool Canevas::desactiverCouche(int index)
{
	if (index < 0 || index >= _couches.taille())
		return false;

	if (index == _couches.actif())
		_couches.setActifAucun();

	return _couches[index].changerEtat(Couche::Etat::Inactive);
}

bool Canevas::prochaineCouche() {
	int newIndex = _couches.actif();

	if (++newIndex >= _couches.taille())
		newIndex = _couches.taille() - 1;

	return activerCouche(newIndex);
}

bool Canevas::precedenteCouche() {
	int newIndex = _couches.actif();

	if (--newIndex < 0)
		newIndex = 0;

	return activerCouche(newIndex);
}

bool Canevas::premiereCouche() {
	return activerCouche(0);
}

int Canevas::derniereCouche() {
	int derniereCouche = _couches.taille() - 1;
	activerCouche(derniereCouche);
	return derniereCouche;
}

Couche* Canevas::obtenirCoucheActive() {
	return &_couches[_couches.actif()];
}

int Canevas::indexCoucheActive() {
	return _couches.actif();
}

int Canevas::nbCouches() {
	return _couches.taille();
}

bool Canevas::ajouterForme(Forme* p_forme)
{
	if (_couches.actif() < 0 || _couches.actif() >= _couches.taille())
		return false;

	return _couches[_couches.actif()].ajouterForme(p_forme);
}

bool Canevas::retirerForme(int index)
{
	if (_couches.actif() < 0 || _couches.actif() >= _couches.taille())
		return false;

	return _couches[_couches.actif()].retirerForme(index);
}

int Canevas::nbFormes() {
	int somme = 0;

	for (int i = 0; i < _couches.taille(); i++)
		somme += _couches[i].nbFormes();

	return somme;
}

double Canevas::aire()
{
	double somme = 0;

	for (int i = 0; i < _couches.taille(); i++)
		somme += _couches[i].aireTotal();

	return somme;
}

bool Canevas::translater(int deltaX, int deltaY)
{
	if (_couches.actif() < 0 || _couches.actif() >= _couches.taille())
		return false;

	return _couches[_couches.actif()].translater(deltaX, deltaY);
}

void Canevas::afficher(ostream& s)
{
    s << _couches;
}

ostream& operator<<(ostream& s, Canevas& canevas) {
    canevas.afficher(s);
    return s;
}

istream& operator>>(istream& s, Canevas& canevas) {
	canevas.reinitialiser();

	bool premiereCouche = true;
	char ligne[256];
	char params[4][256];

	while (s >> ligne) {
		switch (ligne[0]) {
			case 'L':
				if (premiereCouche)	premiereCouche = false;
				else				canevas.ajouterCouche();

				switch (ligne[2]) {
					case 'a':	canevas.activerCouche(canevas.derniereCouche());	break;
					case 'x':	canevas.desactiverCouche(canevas.derniereCouche());	break;
				}
				break;
			case 'R':
				for (int i = 0; i < 4; i++)
					s >> params[i];
				canevas.ajouterForme(new Rectangle(stoi(params[0]), stoi(params[1]), stoi(params[2]), stoi(params[3])));
				break;
			case 'K':
				for (int i = 0; i < 3; i++)
					s >> params[i];
				canevas.ajouterForme(new Carre(stoi(params[0]), stoi(params[1]), stoi(params[2])));
				break;
			case 'C':
				for (int i = 0; i < 3; i++)
					s >> params[i];
				canevas.ajouterForme(new Cercle(stoi(params[0]), stoi(params[1]), stoi(params[2])));
				break;
		}
	}

	return s;
}

void Canevas::modePile() {
	_couches.modePile();
}