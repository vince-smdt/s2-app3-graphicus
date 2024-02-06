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
	_indexCoucheActive = 0;
	activerCouche(_indexCoucheActive);

	Couche* c = new Couche;
	c->changerEtat(Couche::Etat::Active);
	_couches.ajouter(c);
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
	for (int i = 0; i < _couches.taille(); i++)
		if (reinitialiserCouche(i) == false)
			return false;

	_indexCoucheActive = 0;

	return activerCouche(_indexCoucheActive);
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
	return _couches.ajouter(new Couche);
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

	if (_indexCoucheActive != -1)
		_couches[_indexCoucheActive].changerEtat(Couche::Etat::Inactive);

	_indexCoucheActive = index;

	return _couches[index].changerEtat(Couche::Etat::Active);
}

bool Canevas::desactiverCouche(int index)
{
	if (index < 0 || index >= _couches.taille())
		return false;

	if (index == _indexCoucheActive)
		_indexCoucheActive = -1;

	return _couches[index].changerEtat(Couche::Etat::Inactive);
}

bool Canevas::prochaineCouche() {
	int newIndex = _indexCoucheActive;

	if (++newIndex >= _couches.taille())
		newIndex = _couches.taille() - 1;

	return activerCouche(newIndex);
}

bool Canevas::precedenteCouche() {
	int newIndex = _indexCoucheActive;

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
	return &_couches[_indexCoucheActive];
}

int Canevas::indexCoucheActive() {
	return _indexCoucheActive;
}

int Canevas::nbCouches() {
	return _couches.taille();
}

bool Canevas::ajouterForme(Forme* p_forme)
{
	if (_indexCoucheActive < 0 || _indexCoucheActive >= _couches.taille())
		return false;

	return _couches[_indexCoucheActive].ajouterForme(p_forme);
}

bool Canevas::retirerForme(int index)
{
	if (_indexCoucheActive < 0 || _indexCoucheActive >= _couches.taille())
		return false;

	return _couches[_indexCoucheActive].retirerForme(index);
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
	if (_indexCoucheActive < 0 || _indexCoucheActive >= _couches.taille())
		return false;

	return _couches[_indexCoucheActive].translater(deltaX, deltaY);
}

void Canevas::afficher(ostream& s)
{
<<<<<<< HEAD
    s << _couches;
}

ostream& operator<<(ostream& s, Canevas& canevas) {
    canevas.afficher(s);
    return s;
=======
	for (int i = 0; i < _couches.taille(); i++)
		_couches[i].afficher(s);
>>>>>>> 1dab784bba9f401aacb833509f3fcd71caca98ca
}

void Canevas::modePile() {
	_couches.modePile();
}