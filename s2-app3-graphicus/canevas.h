/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 05 janvier 2024
 * Description: Declaration de la classe Canevas. La classe gere un
 *    tableau de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include <iostream>
#include "couche.h"

#ifndef CANEVAS_H
#define CANEVAS_H

const int MAX_COUCHES = 5;

using namespace std;

class Canevas
{
public:
    Canevas();
    ~Canevas();

    bool reinitialiser();
    bool reinitialiserCouche(int index);

    bool activerCouche(int index);
    bool desactiverCouche(int index);

    bool ajouterForme(Forme *p_forme);
    bool retirerForme(int index);

    double aire();
    bool translater(int deltaX, int deltaY);
    void afficher(ostream &s);

private:
    Couche _couches[MAX_COUCHES];
    int _indexCoucheActive;
};


#endif
