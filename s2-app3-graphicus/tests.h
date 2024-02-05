/********
 * Fichier: tests.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 10 janvier 2024
 * Description: Declaration de la classe pour les tests de Graphicus.
 *    Ce fichier peut etre adapte a vos besoins de tests. Ce fichier
 *    fait partie de la distribution de Graphicus.
********/

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <string>
#include "canevas.h"
#include "cercle.h"
#include "carre.h"
#include "vecteur.h"

using namespace std;

class Tests
{
public:
    // Methodes pour les tests unitaires des classes
    void tests_unitaires_formes();
    void tests_unitaires_vecteur();
    void tests_unitaires_couche();
    void tests_unitaires_canevas();
    void tests_unitaires(); // Appel de tous les tests unitaires

    void tests_validation();
};

#endif
