/********
 * Fichier: rectangle.h
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 janvier 2024 (creation)
 * Description: Declaration de la classe Rectangle. La classe
 *    herite de la classe Forme et represente un rectangle par sa
 *    largeur et sa hauteur. Ce fichier fait partie de la distribution
 *    de Graphicus.
********/

#include "forme.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Forme {
public:
    Rectangle(int x = 0, int y = 0, int l = 1, int h = 1);
    virtual ~Rectangle();
    double aire() override;
    void afficher(ostream &flot) override;
protected:
    Coordonnee _dimensions;
};

#endif
