/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 05 janvier 2024
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas()
{
    _indexCoucheActive = 0;
    activerCouche(_indexCoucheActive);
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
    for (int i = 0; i < MAX_COUCHES; i++)
        if(reinitialiserCouche(i) == false)
            return false;

    _indexCoucheActive = 0;

    return activerCouche(_indexCoucheActive);
}

bool Canevas::reinitialiserCouche(int index)
{
    if (index < 0 || index >= MAX_COUCHES)
        return false;
    
    bool etaitActive = _couches[index].getEtat() == Couche::Active;

    bool succes = _couches[index].reinitialiser();
    if(etaitActive == true)
        _couches[index].changerEtat(Couche::Active);
    return succes;
}

bool Canevas::activerCouche(int index)
{
    if (index < 0 || index >= MAX_COUCHES)
        return false;

    if (_indexCoucheActive != -1)
        _couches[_indexCoucheActive].changerEtat(Couche::Inactive);

    _indexCoucheActive = index;

    return _couches[index].changerEtat(Couche::Active);
}

bool Canevas::desactiverCouche(int index)
{
    if (index < 0 || index >= MAX_COUCHES)
        return false;

    if (index == _indexCoucheActive)
        _indexCoucheActive = -1;

    return _couches[index].changerEtat(Couche::Active);
}

bool Canevas::ajouterForme(Forme *p_forme)
{
    if (_indexCoucheActive < 0 || _indexCoucheActive >= MAX_COUCHES)
        return false;

    return _couches[_indexCoucheActive].ajouterForme(p_forme);
}

bool Canevas::retirerForme(int index)
{
    if (_indexCoucheActive < 0 || _indexCoucheActive >= MAX_COUCHES)
        return false;

    return _couches[_indexCoucheActive].retirerForme(index);
}

double Canevas::aire()
{
    double somme = 0;

    for (int i = 0; i < MAX_COUCHES; i++)
        somme += _couches[i].aireTotal();

    return somme;
}

bool Canevas::translater(int deltaX, int deltaY)
{
    if (_indexCoucheActive < 0 || _indexCoucheActive >= MAX_COUCHES)
        return false;

    return _couches[_indexCoucheActive].translater(deltaX, deltaY);
}

void Canevas::afficher(ostream &s)
{
    for (int i = 0; i < MAX_COUCHES; i++) {
        s << "----- Couche " << i << " -----" << endl;
        _couches[i].afficher(s);
    }
}
