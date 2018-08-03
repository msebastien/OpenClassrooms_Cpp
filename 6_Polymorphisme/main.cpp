#include <iostream>

#include "Vehicules.h"

using namespace std;

//--------------------------------------------------
// Résolution dynamique des liens
// Il faut : 
//      * Un pointeur ou une référence vers l'objet
//      * Utiliser des méthodes virtuelles
//--------------------------------------------------

//---------------------------------------------------------
// *Le polymorphisme permet de manipuler des objets d'une classe fille 
// via des pointeurs ou des références sur une classe mère.
//
// *Deux ingrédients sont nécessaires : 
// des fonctions virtuelles et des pointeurs ou références sur l'objet.
//
// *Si l'on ne sait pas quoi mettre dans le corps d'une méthode de la classe mère,
// on peut la déclarer virtuelle pure.
//
// *Une classe avec des méthodes virtuelles pures est dite abstraite.
// On ne peut pas créer d'objet à partir d'une telle classe.
//----------------------------------------------------

void presenter(Vehicule const& v)  //Présente le véhicule passé en argument
{
    v.affiche();
}

/*
int main()
{
    Vehicule v;
    presenter(v);    

    Moto m;
    presenter(m);

    return 0;
}*/

/*int main()
{
    Vehicule *v(0);
    v = new Voiture;
    //On crée une Voiture et on met son adresse dans un pointeur de Vehicule

    v->affiche();  //On affiche "Ceci est une voiture."

    delete v;      //Et on détruit la voiture

    return 0;
}*/

/*int main()
{
    vector<Vehicule*> listeVehicules;

    listeVehicules.push_back(new Voiture(15000, 5));
    //J'ajoute à ma collection de véhicules une voiture
    //Valant 15000 euros et ayant 5 portes
    listeVehicules.push_back(new Voiture(12000, 3));  //…
    listeVehicules.push_back(new Moto(2000, 212.5));
    //Une moto à 2000 euros allant à 212.5 km/h

    //On utilise les voitures et les motos
    listeVehicules[0]->affiche();
    //On affiche les informations de la première voiture
    
    listeVehicules[2]->affiche();
    //Et celles de la moto

    for(int i(0); i<listeVehicules.size(); ++i)
    {
        delete listeVehicules[i];  //On libère la i-ème case mémoire allouée
        listeVehicules[i] = 0;  //On met le pointeur à 0 pour éviter les soucis
    }

    return 0;
}*/

int main()
{
    Vehicule* ptr(0);  //Un pointeur sur un véhicule
    
    Voiture caisse(20000,5);
    //On crée une voiture
    //Ceci est autorisé puisque toutes les fonctions ont un corps
    
    ptr = &caisse;  //On fait pointer le pointeur sur la voiture

    cout << ptr->nbrRoues() << endl;
    //Dans la classe fille, nbrRoues() existe, ceci est donc autorisé

    return 0;
}