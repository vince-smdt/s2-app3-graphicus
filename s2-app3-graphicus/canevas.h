/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 05 fevrier 2024
 * Description: Declaration de la classe Canevas. La classe gere un
 *    tableau de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include <iostream>
#include <string>
#include "carre.h"
#include "cercle.h"
#include "couche.h"
#include "rectangle.h"

#ifndef CANEVAS_H
#define CANEVAS_H

using namespace std;

class Canevas
{
public:
    Canevas();
    ~Canevas();

    bool reinitialiser();
    bool reinitialiserCouche(int index);

    bool ajouterCouche();
    bool retirerCouche(int index);
    bool activerCouche(int index);
    bool desactiverCouche(int index);
    bool prochaineCouche();
    bool precedenteCouche();
    bool premiereCouche();
    int derniereCouche();
    Couche* obtenirCoucheActive();
    int indexCoucheActive();
    int nbCouches();
    void modePile();

    bool ajouterForme(Forme *p_forme);
    bool retirerForme(int index);
    int nbFormes();

    double aire();
    bool translater(int deltaX, int deltaY);
    void afficher(ostream &s);

    friend ostream& operator<<(ostream& s, Canevas& canevas);
    friend istream& operator>>(istream& s, Canevas& canevas);

private:
    Vecteur<Couche> _couches;
    int _indexCoucheActive;
};


#endif
