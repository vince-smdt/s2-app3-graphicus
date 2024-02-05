/********
 * Fichier: cercle.cpp
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 janvier 2024 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    cercle.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "cercle.h"

Cercle::Cercle(int x, int y, int r) : Forme(x, y) {
    _rayon = r;
}

Cercle::~Cercle() {}

double Cercle::aire() {
    return PI * _rayon * _rayon;
}

void Cercle::afficher(ostream &flot) {
    flot << "Cercle (x=" << ancrage.x << ", y=" << ancrage.y
        << ", r=" << _rayon << ", aire=" << aire() << ")" << endl;
}
