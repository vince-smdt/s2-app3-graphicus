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
}

Couche::~Couche() {}

bool Couche::ajouterForme(Forme *forme) {
    if (etat != Etat::Active)
        return false;

    bool succes = formes.ajouter(forme);
    formes.setActif(formes.taille() - 1);
    return succes;
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
    if (formes.taille() > 0 && formes.actif() < formes.taille() - 1)
        formes++;

    return true;
}

bool Couche::precedenteForme() {
    if (formes.taille() > 0 && formes.actif() > 0)
        formes--;

    return true;
}

bool Couche::premiereForme() {
    if (formes.taille() > 0)
        formes.setActif(0);

    return true;
}

bool Couche::derniereForme() {
    if (formes.taille() > 0)
        formes.setActif(formes.taille() - 1);

    return true;
}

Forme* Couche::obtenirFormeActive() {
    return &formes[formes.actif()];
}

int Couche::obtenirIndexFormeActive() {
    return formes.actif();
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
    flot << "L " << getEtatCStr() << endl << formes;
}

Forme *Couche::retirerForme(int index) {
    if (etat != Etat::Active)
        return nullptr;

    return formes.retirer(index);
}

Forme *Couche::obtenirForme(int index) {
    return formes.obtenir(index);
}

ostream& operator<<(ostream& s, Couche& couche) {
    couche.afficher(s);
    return s;
}
