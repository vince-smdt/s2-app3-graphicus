/********
 * Fichier: vecteur.cpp
 * Auteurs: Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date: 05 janvier 2024 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    vecteur.h. Ce fichier fait partie de la distribution de Graphicus.
********/

//#include "vecteur.h"

//template <class T>
//Vecteur<T>::Vecteur() {
//    T* elements
//    _taille = 0;
//    _capacite = CAPACITE_DEPART;
//    _elements = new T * [_capacite];
//}
//
//template <class T>
//Vecteur<T>::~Vecteur() {
//    vider();
//}
//
//template <class T>
//int Vecteur<T>::capacite() {
//    return _capacite;
//}
//
//template <class T>
//void Vecteur<T>::doublerCapacite() {
//    _capacite *= 2;
//
//    T **tempElements = _elements;
//    _elements = new T * [_capacite];
//
//    for (int i = 0; i < _taille; i++)
//        _elements[i] = tempElements[i];
//
//    delete[] tempElements;
//}
//
//template <class T>
//void Vecteur<T>::vider() {
//    for (int i = 0; i < _taille; i++)
//        delete _elements[i];
//    
//    _taille = 0;
//    _capacite = CAPACITE_DEPART;
//    _elements = new T * [_capacite];
//}
//
//template <class T>
//void Vecteur<T>::afficher(ostream &flot) {
//    for (int i = 0; i < _taille; i++)
//        _elements[i]->afficher(flot);
//}
//
//template <class T>
//int Vecteur<T>::taille() {
//    return _taille;
//}
//
//template <class T>
//bool Vecteur<T>::estVide() {
//    return _taille == 0;
//}
//
//template <class T>
//bool Vecteur<T>::ajouter(T *element) {
//    if (element == nullptr)
//        return false;
//
//    if (_taille + 1 > _capacite)
//        doublerCapacite();
//
//    _elements[_taille] = element;
//
//    _taille++;
//
//    return true;
//}
//
//template <class T>
//T *Vecteur<T>::retirer(int index) {
//    if (index < 0 || index >= _taille)
//        return nullptr;
//
//    T * elementRetiree = _elements[index];
//
//    for (int i = index; i < _taille - 1; i++)
//        _elements[i] = _elements[i + 1];
//
//    _taille--;
//
//    return elementRetiree;
//}
//
//template <class T>
//T *Vecteur<T>::obtenir(int index) {
//    if (index < 0 || index >= _taille)
//        return nullptr;
//
//    return _elements[index];
//}
