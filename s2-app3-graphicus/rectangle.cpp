/********
 * Fichier: rectangle.cpp
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 janvier 2024 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    rectangle.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int l, int h) : Forme(x, y) {
    _dimensions.x = l;
    _dimensions.y = h;
}

Rectangle::~Rectangle() {}

double Rectangle::aire() {
    return _dimensions.x * _dimensions.y;
}

void Rectangle::afficher(ostream &flot) {
    flot << "Rectangle (x=" << ancrage.x << ", y=" << ancrage.y
        << ", l=" << _dimensions.x << ", h=" << _dimensions.y 
        << ", aire=" << aire() << ")" << endl;
}
