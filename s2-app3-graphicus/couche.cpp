/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 05 janvier 2024
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche() {
    etat = Initialisee;
}

Couche::~Couche() {}

bool Couche::ajouterForme(Forme *forme) {
    if (etat != Active)
        return false;

    return formes.ajouterForme(forme);
}

bool Couche::translater(int deltaX, int deltaY) {
    if (etat != Active)
        return false;

    for (int i = 0; i < formes.taille(); i++)
        formes.obtenirForme(i)->translater(deltaX, deltaY);

    return true;
}

bool Couche::reinitialiser() {
    etat = Initialisee;

    formes.vider();

    if(formes.taille() != 0)
        return false;
    return true;
}

bool Couche::changerEtat(Etat e) {
    if(e != Couche::Active && e != Couche::Inactive)
        return false;
    etat = e;
    return true;
}

Couche::Etat Couche::getEtat() {
    return etat;
}

double Couche::aireTotal() {
    if (etat == Initialisee)
        return 0;

    double somme = 0;

    for (int i = 0; i < formes.taille(); i++)
        somme += formes.obtenirForme(i)->aire();

    return somme;
}

void Couche::afficher(ostream &flot) {
    flot << "Etat: ";
    switch (etat) {
        case Initialisee:   flot << "initialisee";  break;
        case Active:        flot << "active";       break;
        case Inactive:      flot << "inactive";     break;
        default:            flot << "erreur";       break;
    }
    flot << endl;

    if (formes.taille() == 0) {
        flot << "Couche: vide" << endl;
        return;
    }

    formes.afficher(flot);
}

Forme *Couche::retirerForme(int index) {
    if (etat != Active)
        return nullptr;

    return formes.retirerForme(index);
}

Forme *Couche::obtenirForme(int index) {
    return formes.obtenirForme(index);
}
