/********
 * Fichier: carre.cpp
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 janvier 2024 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 05 fevrier 2024
 * Description: Implementation des methodes des classes decrites dans
 *    carre.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "carre.h"

Carre::Carre(int x, int y, int c) : Rectangle(x, y, c, c) {}

Carre::~Carre() {}

void Carre::afficher(ostream &flot) {
    flot << "K " << ancrage.x << " " << ancrage.y << " " << _dimensions.x << endl;
}
