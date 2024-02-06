/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 05 fevrier 2024
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche() {
    etat = Etat::Initialisee;
    _indexFormeActive = -1;
}

Couche::~Couche() {}

bool Couche::ajouterForme(Forme *forme) {
    if (etat != Etat::Active)
        return false;

    _indexFormeActive = formes.taille();

    return formes.ajouter(forme);
}

bool Couche::translater(int deltaX, int deltaY) {
    if (etat != Etat::Active)
        return false;

    for (int i = 0; i < formes.taille(); i++)
        formes.obtenir(i)->translater(deltaX, deltaY);

    return true;
}

bool Couche::reinitialiser() {
    etat = Etat::Initialisee;

    formes.vider();

    if(formes.taille() != 0)
        return false;
    return true;
}

bool Couche::changerEtat(Etat e) {
    if(e != Etat::Active && e != Etat::Inactive)
        return false;
    etat = e;
    return true;
}

Couche::Etat Couche::getEtat() {
    return etat;
}

const char* Couche::getEtatCStr() {
    switch (etat) {
        case Etat::Initialisee: return "i";        break;
        case Etat::Active:      return "a";        break;
        case Etat::Inactive:    return "x";        break;
    }
    return "erreur";
}

bool Couche::prochaineForme() {
    if (formes.taille() == 0)
        return false;

    if (++_indexFormeActive >= formes.taille())
        _indexFormeActive = 0;

    return true;
}

bool Couche::precedenteForme() {
    if (formes.taille() == 0)
        return false;

    if (--_indexFormeActive < 0)
        _indexFormeActive = formes.taille() - 1;

    return true;
}

bool Couche::premiereForme() {
    if (formes.taille() == 0)
        return false;

    _indexFormeActive = 0;

    return true;
}

bool Couche::derniereForme() {
    if (formes.taille() == 0)
        return false;

    _indexFormeActive = formes.taille() - 1;

    return true;
}

Forme* Couche::obtenirFormeActive() {
    return &formes[_indexFormeActive];
}

int Couche::obtenirIndexFormeActive() {
    return _indexFormeActive;
}

int Couche::nbFormes() {
    return formes.taille();
}

double Couche::aireTotal() {
    if (etat == Etat::Initialisee)
        return 0;

    double somme = 0;

    for (int i = 0; i < formes.taille(); i++)
        somme += formes.obtenir(i)->aire();

    return somme;
}

void Couche::afficher(ostream &flot) {
    flot << "L " << getEtatCStr() << endl;
    formes.afficher(flot);
}

Forme *Couche::retirerForme(int index) {
    if (etat != Etat::Active)
        return nullptr;

    return formes.retirer(index);
}

Forme *Couche::obtenirForme(int index) {
    return formes.obtenir(index);
}
