/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Modifie par : Vincent Simard-Schmidt (simv2104) & Kevin Gauvin (gauk1703)
 * Date : 10 janvier 2024
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"

Forme* creer_forme() {
    int x = 3;
    int y = 2;
    int l = 5;
    int h = 8;

    return new Rectangle(x, y, l, h);
}

void Tests::tests_unitaires_formes()
{
    cout << "Debut - tests_unitaires_formes" << endl;
    // Tests sur les formes geometriques
    Coordonnee c;
    c.x = 2;
    c.y = 3;

    // Formes utilisees pour les tests
    int x = 3;
    int y = 2;
    int l = 5;
    int h = 8;
    Forme *forme = creer_forme(); // Rectangle
    Forme *formeCercle = new Cercle(x, y, l);
    Forme *fromeCarre = new Carre(x, y, l);

    if(forme->aire() != l * h)
        cout << "Erreur: L'aire du rectangle devrait être de 40" << endl;

    if(formeCercle->aire() != PI * l * l)
        cout << "Erreur: L'aire du cercle devrait être de 40" << endl;

    if(fromeCarre->aire() != l * l)
        cout << "Erreur: L'aire du carre devrait être de 25" << endl;  

    // Forme::getAncrage()
    if (forme->getAncrage().x != x || forme->getAncrage().y != y)
        cout << "Erreur: Rectangle::getAncrage() - Mauvaise valeur retournee apres instantiation" << endl;

    // Forme::translater()
    int deltaX = 2;
    int deltaY = -3;
    forme->translater(deltaX, deltaY);
    if (forme->getAncrage().x != x + deltaX || forme->getAncrage().y != y + deltaY)
        cout << "Erreur: Rectangle::translater() - Mauvaise valeur retournee apres translation" << endl;

    forme->setAncrage(c);
    if(forme->getAncrage().x != c.x && forme->getAncrage().y != c.y)
        cout << "Erreur: getAncrage devrait retourner 2 pour x et 3 pour y" << endl;

    cout << "Fin - tests_unitaires_formes" << endl;
}

void Tests::tests_unitaires_vecteur()
{
    cout << "Debut - tests_unitaires_vecteur" << endl;

    // Tests sur la classe Vecteur
    Vecteur *vecteur = new Vecteur();
    Forme *forme = creer_forme();

    if(vecteur->taille() != 0)
        cout << "Erreur: La taille par defaut devrait être de 0" << endl;

    if(vecteur->ajouterForme(nullptr) != false)
        cout << "Erreur: Lorsque l'on passe nullprt en argument ajouterForme devrait retourner false" << endl;

    if(vecteur->ajouterForme(forme) != true)
        cout << "Erreur: Lorsque l'on passe un Forme en argument ajouterForme devrait retourner true" << endl;

    if(vecteur->estVide() != false)
        cout << "Erreur: Après avoir ajoute une forme la taille devrait être de 1 alors estVide() devrait retourner false" << endl;   

    if(vecteur->taille() != 1)
        cout << "Erreur: Après avoir ajoute une forme la taille devrait être de 1" << endl;

     if(vecteur->obtenirForme(-2) != nullptr) 
        cout << "Erreur: Lorsque l'on passe un nombre plus petit que 0 en argument obtenirForme devrait retourner nullptr" << endl;

    if(vecteur->obtenirForme(1) != nullptr) 
        cout << "Erreur: Lorsque l'on passe un nombre plus grand ou egale à la taille en argument obtenirForme devrait retourner nullptr" << endl;
    
    if(vecteur->obtenirForme(0) != forme) 
        cout << "Erreur: Lorsque l'on passe un nombre plus grand ou egale à 0 et plus petit que la taille en argument obtenirForme devrait retourner la forme" << endl;

    if(vecteur->retirerForme(-2) != nullptr) 
        cout << "Erreur: Lorsque l'on passe un nombre plus petit que 0 en argument retirerForme devrait retourner nullptr" << endl;

    if(vecteur->retirerForme(1) != nullptr) 
        cout << "Erreur: Lorsque l'on passe un nombre plus grand ou egale à la taille en argument retirerForme devrait retourner nullptr" << endl;
    
    if(vecteur->retirerForme(0) != forme) 
        cout << "Erreur: Lorsque l'on passe un nombre plus grand ou egale à 0 et plus petit que la taille en argument retirerForme devrait retourner la forme" << endl;

    if(vecteur->taille() != 0)
        cout << "Erreur: Après avoir retire une forme la taille devrait être de 0" << endl;

     if(vecteur->estVide() != true)
        cout << "Erreur: Après avoir retire une forme la taille devrait être de 0" << endl;    

    vecteur->ajouterForme(creer_forme());
    vecteur->ajouterForme(creer_forme());
    vecteur->ajouterForme(creer_forme());
    vecteur->vider();
    if(vecteur->estVide() != true)
        cout << "Erreur: Après avoir appele vider() il reste des elements dans le tablau de forme" << endl;    

    if(vecteur->capacite() != 2)
        cout << "Erreur: La capacite par defaut devrait être de 1" << endl;    

    vecteur->doublerCapacite();
    if(vecteur->capacite() != 4)
        cout << "Erreur: La capacite devrait être de 2 puisqu'elle a ete double 1 fois" << endl;

    vecteur->doublerCapacite();
    if(vecteur->capacite() != 8)
        cout << "Erreur: La capacite devrait être de 4 puisqu'elle a ete double 2 fois" << endl;      

    cout << "Fin - tests_unitaires_vecteur" << endl;
    
}

void Tests::tests_unitaires_couche()
{
    cout << "Debut - tests_unitaires_couche" << endl;

    // Tests sur la classe Couche
    Couche *couche = new Couche();
    Forme *forme = creer_forme();

    if(couche->getEtat() != Couche::Initialisee)
        cout << "Erreur: L'etat de base devrait être 'Initialisee'" << endl;

    if(couche->aireTotal() != 0)
        cout << "Erreur: Lorsque l'etat est Initialisee airTotal devrait retourner 0" << endl;  

    couche->changerEtat(Couche::Active);
    if(couche->getEtat() != Couche::Active)
            cout << "Erreur: L'etat devrait être 'Active'" << endl;

    couche->changerEtat(Couche::Inactive);
    if(couche->getEtat() != Couche::Inactive)
            cout << "Erreur: L'etat devrait être 'Inactive'" << endl; 

    if(couche->changerEtat(Couche::Initialisee) != false)
            cout << "Erreur: L'etat 'Initialisee' ne peut pas être changer avec changerEtat" << endl;

    couche->changerEtat(Couche::Active);
    if(couche->translater(4, 4) != true)
        cout << "Erreur: Lorsque la couche est Active et que l'on appel translater() le methode devrait retourner true" << endl;
        
    if(couche->ajouterForme(forme) != true)
        cout << "Erreur: Lorsque la couche est Active et que l'on ajoute une forme ajouterForme devrait retourner true" << endl;
    
    if(couche->obtenirForme(0) != forme)
         cout << "Erreur: Lorsque l'on appel obtenirForme() cela devrait retourner la forme de l'index" << endl;

    if(couche->aireTotal() == 0)
        cout << "Erreur: Lorsque l'etat est Active airTotal devrait retourner l'air et non 0" << endl;

    couche->changerEtat(Couche::Inactive);
    if(couche->ajouterForme(forme) != false)
        cout << "Erreur: Lorsque la couche est Inactive et que l'on appel ajouterForme() le methode devrait retourner false" << endl;

    if(couche->translater(4, 4) != false)
        cout << "Erreur: Lorsque la couche est Inactive et que l'on appel translater() le methode devrait retourner false" << endl;

    if(couche->retirerForme(0) != nullptr)
         cout << "Erreur: Lorsque l'on retire une forme d'une couche et que l'etat est different de Active retirerForme() devrait retourner nullptr" << endl;

    couche->changerEtat(Couche::Active);
    if(couche->retirerForme(0) != forme)
         cout << "Erreur: Lorsque l'on retire une forme d'une couche et que l'etat est Active retirerForme() devrait retourner la forme retirer" << endl;

    couche->ajouterForme(forme);
    if(couche->reinitialiser() != true)
         cout << "Erreur: reinitialiser() à ete appele et la taille dans forme est differente de 0 " << endl;
    
    cout << "Fin - tests_unitaires_couche" << endl;

}

void Tests::tests_unitaires_canevas()
{
    cout << "Debut - tests_unitaires_canevas" << endl;

    // Tests sur la classe Canevas
    Canevas *canevas = new Canevas();
    Forme *forme = creer_forme();

    // Par defaut la couche est suppose être active

    if(canevas->ajouterForme(forme) != true)
         cout << "Erreur: lorsque l'on ajoute une forme et que la couche est active cela devrait retourner true" << endl;

    if(canevas->translater(1, 1) != true)
        cout << "Erreur: il devrait être possible de translater une couche active" << endl;

    canevas->desactiverCouche(0);
    if(canevas->ajouterForme(forme) != false)
        cout << "Erreur: lorsque l'on ajoute une forme et que la couche est inactive cela devrait retourner false" << endl;

    if(canevas->translater(1, 1) != false)
        cout << "Erreur: il devrait être possible de translater une couche inactive" << endl;

    if(canevas->aire() < 0)
        cout << "Erreur: L'air devrait être superieur ou egale à 0" << endl;

    if(canevas->retirerForme(0) != false)
            cout << "Erreur: lorsque l'on retire une forme et que la couche est inactive cela devrait retourner false" << endl;

    forme = creer_forme();
    canevas->activerCouche(0);
    if(canevas->ajouterForme(forme) != true)
         cout << "Erreur: lorsque l'on retire une forme et que la couche est active cela devrait retourner true" << endl;

    if(canevas->reinitialiserCouche(5) != false)
         cout << "Erreur: lorsque l'on reinitialiserCouche() à un index superieur au nombre de couche cela doit retourner false" << endl;

    if(canevas->reinitialiserCouche(0) != true)
         cout << "Erreur: lorsque l'on reinitialiserCouche() à un index existant cela doit retourner true" << endl;

    if(canevas->reinitialiser() != true)
         cout << "Erreur: Reinitialiser doit retourner true" << endl;

    cout << "Fin - tests_unitaires_canevas" << endl;
}

void Tests::tests_unitaires()
{
    // Fait tous les tests unitaires
    tests_unitaires_formes();
    tests_unitaires_vecteur();
    tests_unitaires_couche();
    tests_unitaires_canevas();
}

void Tests::tests_validation() {
        Canevas *canevas = new Canevas();
    cout << "Etape 1" << endl;
    cout << "   Activer la couche 2" << endl;
    canevas->activerCouche(2);
    cout << endl;

    cout << "   Une cercle a été créé x=0, y=1, rayon=5" << endl;
    cout << "   Le cercle a été ajouté à la couche 2" << endl;
    canevas->ajouterForme(new Cercle(0, 1, 5));
    cout << endl;

    cout << "   Un carré a été créé x=1, y=2, côté=6" << endl;
    cout << "   Le carré a été ajouté à la couche 2" << endl;
    canevas->ajouterForme(new Carre(1, 2, 6));
    cout << endl;

    cout << "   Un rectangle a été créé x=2, y=3, largeur=4, hauteur=9" << endl;
    cout << "   Le rectangle a été ajouté à la couche 2" << endl;
    canevas->ajouterForme(new Rectangle(2, 3, 4, 9));
    cout << endl;
    
    cout << "Etape 2" << endl;
    cout << "   Activer la couche 1" << endl;
    canevas->activerCouche(1);
    cout << endl;

    cout << "   Un rectangle a été créé x=0, y=0, largeur=12, hauteur=3" << endl;
    cout << "   Le rectangle a été ajouté à la couche 1" << endl;
    canevas->ajouterForme(new Rectangle(0, 0, 12, 3));
    cout << endl;

    cout << "Etape 3" << endl;
    cout << "   Afficher le canevas" << endl;
    canevas->afficher(cout);
    cout << endl;

    cout << "Etape 4" << endl;
    cout << "   Afficher l’aire du canevas " << endl;
    cout << "   Aire du canevas: "  + to_string(canevas->aire()) << endl;
    cout << endl;

    cout << "Etape 5" << endl;
    cout << "   Activer la couche 0" << endl;
    canevas->activerCouche(0);
    cout << endl;

    cout << "   Un rectangle a été créé x=0, y=0, largeur=1, hauteur=1" << endl;
    cout << "   Le rectangle a été ajouté à la couche 0" << endl;
    canevas->ajouterForme(new Rectangle(0, 0, 1, 1));
    cout << endl;

    cout << "   Un carré a été créé x=0, y=0, côté=1" << endl;
    cout << "   Le carré a été ajouté à la couche 0" << endl;
    canevas->ajouterForme(new Carre(0, 0, 1));
    cout << endl;

    cout << "   Une cercle a été créé x=0, y=0, rayon=1" << endl;
    cout << "   Le cercle a été ajouté à la couche 0" << endl;
    canevas->ajouterForme(new Cercle(0, 0, 1));
    cout << endl;

    cout << "Etape 6" << endl;
    cout << "   Activer la couche 2" << endl;
    canevas->activerCouche(2);
    cout << endl;

    cout << "   Translater la couche 2 de x=2 et y=1" << endl;
    canevas->translater(2, 1);
    cout << endl;

    cout << "Etape 7" << endl;
    cout << "   Afficher le canevas" << endl;
    canevas->afficher(cout);
    cout << endl;

    cout << "Etape 8" << endl;
    cout << "   Afficher l’aire du canevas " << endl;
    cout << "   Aire du canevas: "  + to_string(canevas->aire()) << endl;
    cout << endl;

    cout << "Etape 9" << endl;
    cout << "   Activer la couche 0" << endl;
    canevas->activerCouche(0);
    cout << endl;

    cout << "Etape 10" << endl;
    cout << "   Réinitialiser la couche 1" << endl;
    canevas->reinitialiserCouche(1);
    cout << endl;
    
    cout << "Etape 11" << endl;
    cout << "   Activer la couche 4" << endl;
    canevas->activerCouche(4);
    cout << endl;


    cout << "Etape 12" << endl;
    cout << "   Afficher le canevas" << endl;
    canevas->afficher(cout);
    cout << endl;

    cout << "Etape 13" << endl;
    cout << "   Afficher l’aire du canevas " << endl;
    cout << "   Aire du canevas: "  + to_string(canevas->aire()) << endl;
    cout << endl;

    cout << "Etape 14" << endl;
    cout << "   Réinitialiser le canevas" << endl;
    canevas->reinitialiser();

    cout << "Etape 15" << endl;
    cout << "   Afficher le canevas" << endl;
    canevas->afficher(cout);
    cout << endl;

    cout << "Etape 16" << endl;
    cout << "   Afficher l’aire du canevas " << endl;
    cout << "   Aire du canevas: "  + to_string(canevas->aire()) << endl;
    cout << endl;

    cout << "Etape 17" << endl;
    cout << "   Activer la couche 3" << endl;
    canevas->activerCouche(3);
    cout << endl;

    cout << "   Un carré a été créé x=10, y=10, côté=10" << endl;
    cout << "   Le carré a été ajouté à la couche 3" << endl;
    canevas->ajouterForme(new Carre(10, 10, 10));
    cout << endl;

    cout << "   Ajout d'une forme null" << endl;
    Forme *forme = nullptr;
    canevas->ajouterForme(forme);
    cout << endl;

    cout << "Etape 18" << endl;
    cout << "   Activer la couche 6" << endl;
    canevas->activerCouche(6);
    cout << endl;

    cout << "Etape 19" << endl;
    cout << "   Afficher le canevas" << endl;
    canevas->afficher(cout);
    cout << endl;

    cout << "Etape 20" << endl;
    cout << "   Afficher l’aire du canevas " << endl;
    cout << "   Aire du canevas: "  + to_string(canevas->aire()) << endl;
    cout << endl;
}
