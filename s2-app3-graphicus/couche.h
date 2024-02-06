/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 05 fevrier 2024
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "vecteur.h"

#ifndef COUCHE_H
#define COUCHE_H

class Couche {
public:
    enum class Etat {
        Initialisee,
        Active,
        Inactive
    };
public:
    Couche();
    ~Couche();

    bool ajouterForme(Forme *forme);
    bool translater(int deltaX, int deltaY);
    bool reinitialiser();
    bool changerEtat(Etat e);
    Etat getEtat();
    const char* getEtatCStr();

    bool prochaineForme();
    bool precedenteForme();
    bool premiereForme();
    bool derniereForme();
    Forme* obtenirFormeActive();
    int obtenirIndexFormeActive();
    int nbFormes();

    double aireTotal();

    void afficher(ostream &flot);

    Forme *retirerForme(int index);
    Forme *obtenirForme(int index);

    friend ostream& operator<<(ostream& s, Couche& couche);
private:
    Vecteur<Forme> formes;
    Etat etat;
    int _indexFormeActive;
};

#endif
