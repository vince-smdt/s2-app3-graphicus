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
    etat = Initialisee;
}

Couche::~Couche() {}

bool Couche::ajouterForme(Forme *forme) {
    if (etat != Active)
        return false;

    return formes.ajouter(forme);
}

bool Couche::translater(int deltaX, int deltaY) {
    if (etat != Active)
        return false;

    for (int i = 0; i < formes.taille(); i++)
        formes.obtenir(i)->translater(deltaX, deltaY);

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
        somme += formes.obtenir(i)->aire();

    return somme;
}

void Couche::afficher(ostream &flot) {
    flot << "L ";
    switch (etat) {
        case Initialisee:   flot << "i";        break;
        case Active:        flot << "a";        break;
        case Inactive:      flot << "x";        break;
        default:            flot << "erreur";   break;
    }
    flot << endl;

    formes.afficher(flot);
}

Forme *Couche::retirerForme(int index) {
    if (etat != Active)
        return nullptr;

    return formes.retirer(index);
}

Forme *Couche::obtenirForme(int index) {
    return formes.obtenir(index);
}
