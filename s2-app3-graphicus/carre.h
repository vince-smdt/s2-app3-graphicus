/********
 * Fichier: carre.h
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 janvier 2024 (creation)
 * Description: Declaration de la classe Carre. La classe
 *    hérite de la classe Rectangle et représente un carre par sa
 *    longueur de cote. Ce fichier fait partie de la distribution
 *    de Graphicus.
********/

#include "rectangle.h"

#ifndef CARRE_H
#define CARRE_H

class Carre : public Rectangle {
public:
    Carre(int x = 0, int y = 0, int c = 1);
    ~Carre();
    void afficher(ostream &flot);
};

#endif
