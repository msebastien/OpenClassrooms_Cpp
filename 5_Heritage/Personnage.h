#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>

class Personnage
{
  protected: //Privé, mais accessible aux éléments enfants (Guerrier, Magicien)
    std::string m_nom;
    int m_vie;

  public:         // Méthodes publiques
    Personnage(); //Constructeur par défaut
    Personnage(std::string nom);
    void recevoirDegats(int nb_degats);
    void coupDePoing(Personnage &cible) const;

    void sePresenter() const;
};

#endif