/********
 * Fichier: cercle.h
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 janvier 2024 (creation)
 * Description: Declaration de la classe Cercle. La classe
 *    hérite de la classe Forme et représente un cercle par son
 *    rayon. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "forme.h"

#ifndef CERCLE_H
#define CERCLE_H

const double PI = 3.14159265359;

class Cercle : public Forme {
public:
    Cercle(int x = 0, int y = 0, int r = 1);
    ~Cercle();
    double aire() override;
    void afficher(ostream &flot) override;
private:
    int _rayon;
};

#endif
