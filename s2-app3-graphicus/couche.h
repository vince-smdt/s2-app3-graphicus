/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 05 janvier 2024
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "vecteur.h"

#ifndef COUCHE_H
#define COUCHE_H

class Couche {
public:
    enum Etat {
        Initialisee,
        Active,
        Inactive
    };
public:
    Couche();
    ~Couche();

    bool ajouterForme(Forme *forme);
    bool translater(int deltaX, int deltaY);
    bool reinitialiser();
    bool changerEtat(Etat e);
    Etat getEtat();

    double aireTotal();

    void afficher(ostream &flot);

    Forme *retirerForme(int index);
    Forme *obtenirForme(int index);
private:
    Vecteur formes;
    Etat etat;
};

#endif
