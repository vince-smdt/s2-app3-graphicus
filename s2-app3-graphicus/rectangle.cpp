/********
 * Fichier: rectangle.cpp
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 janvier 2024 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 05 fevrier 2024
 * Description: Implementation des methodes des classes decrites dans
 *    rectangle.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int l, int h) : Forme(x, y) {
    _dimensions.x = (l <= 0) ? 0 : l;
    _dimensions.y = (h <= 0) ? 0 : h;
}

Rectangle::~Rectangle() {}

double Rectangle::aire() {
    return _dimensions.x * (double)_dimensions.y;
}

void Rectangle::afficher(ostream &flot) {
    flot << "R " << ancrage.x << " " << ancrage.y << " " << _dimensions.x << " " << _dimensions.y << endl;
}
