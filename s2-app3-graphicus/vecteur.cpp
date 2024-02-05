/********
 * Fichier: vecteur.cpp
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 janvier 2024 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    vecteur.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "vecteur.h"

Vecteur::Vecteur() {
    _taille = 0;
    _capacite = CAPACITE_DEPART;
    _formes = new Forme * [_capacite];
}

Vecteur::~Vecteur() {
    vider();
}

int Vecteur::capacite() {
    return _capacite;
}

void Vecteur::doublerCapacite() {
    _capacite *= 2;

    Forme **tempFormes = _formes;
    _formes = new Forme * [_capacite];

    for (int i = 0; i < _taille; i++)
        _formes[i] = tempFormes[i];

    delete[] tempFormes;
}

void Vecteur::vider() {
    for (int i = 0; i < _taille; i++)
        delete _formes[i];
    
    _taille = 0;
    _capacite = CAPACITE_DEPART;
    _formes = new Forme * [_capacite];
}

void Vecteur::afficher(ostream &flot) {
    for (int i = 0; i < _taille; i++)
        _formes[i]->afficher(flot);
}

int Vecteur::taille() {
    return _taille;
}

bool Vecteur::estVide() {
    return _taille == 0;
}

bool Vecteur::ajouterForme(Forme *forme) {
    if (forme == nullptr)
        return false;

    if (_taille + 1 > _capacite)
        doublerCapacite();

    _formes[_taille] = forme;

    _taille++;

    return true;
}

Forme *Vecteur::retirerForme(int index) {
    if (index < 0 || index >= _taille)
        return nullptr;

    Forme *formeRetiree = _formes[index];

    for (int i = index; i < _taille - 1; i++)
        _formes[i] = _formes[i + 1];

    _taille--;

    return formeRetiree;
}

Forme *Vecteur::obtenirForme(int index) {
    if (index < 0 || index >= _taille)
        return nullptr;

    return _formes[index];
}
