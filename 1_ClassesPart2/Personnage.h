#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>

#include "Arme.h"

class Personnage 
{
    private: // Tous les attributs sont toujours private (Encapsulation)

    int m_vie;
    int m_mana;
    Arme m_arme;

    public: // Méthodes publiques

    Personnage(); //Constructeur par défaut
    Personnage(std::string nomArme, int degatsArme);
    ~Personnage(); // Destructeur
    void recevoirDegats(int nb_degats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant() const;
    void Personnage::afficherEtat() const;
};


#endif