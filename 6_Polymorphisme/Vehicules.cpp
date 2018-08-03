#include <Vehicules.h>

//---------------
// GARAGE
//---------------
Garage::Garage() {}

void Garage::ajouterVehicule(Vehicule const& v)
{
    listeVehicules.push_back(v);
}

void Garage::supprimerVehicule(Vehicule const& v)
{
    // TODO
}


//---------------
// VEHICULE
//---------------
Vehicule::Vehicule(int prix) : m_prix(prix) {}

void Vehicule::affiche() const
//J'en profite pour modifier un peu les fonctions d'affichage
{
    cout << "Ceci est un vehicule coutant " << m_prix << " euros." << endl;
}

Vehicule::~Vehicule() //Même si le destructeur ne fait rien, on doit le mettre !
{}


//---------------
// VOITURE
//---------------
Voiture::Voiture(int prix, int portes): Vehicule(prix), m_portes(portes) {}

void Voiture::affiche() const
{
    cout << "Ceci est une voiture avec " << m_portes << " portes et coutant " << m_prix << " euros." << endl;
}

Voiture::~Voiture() {}

int Voiture::nbrRoues() const
{
    return 4;
}


//---------------
// MOTO
//---------------
Moto::Moto(int prix, double vitesseMax) : Vehicule(prix), m_vitesse(vitesseMax) {}

void Moto::affiche() const
{
    cout << "Ceci est une moto allant a " << m_vitesse << " km/h et coutant " << m_prix << " euros." << endl;
}

Moto::~Moto() {}

int Moto::nbrRoues() const
{
    return 2;
}


//---------------
// CAMION
//---------------