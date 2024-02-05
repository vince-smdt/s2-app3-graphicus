/********
 * Fichier: cercle.cpp
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 janvier 2024 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 05 fevrier 2024
 * Description: Implementation des methodes des classes decrites dans
 *    cercle.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "cercle.h"

Cercle::Cercle(int x, int y, int r) : Forme(x, y) {
    _rayon = (r <= 0) ? 0 : r;
}

Cercle::~Cercle() {}

double Cercle::aire() {
    return PI * _rayon * _rayon;
}

void Cercle::afficher(ostream &flot) {
    flot << "C " << ancrage.x << " " << ancrage.y << " " << _rayon << endl;
}
