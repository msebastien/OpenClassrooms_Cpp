#ifndef DEF_MAGICIEN
#define DEF_MAGICIEN

#include <iostream>
#include <string>
#include <Personnage.h>

class Magicien : public Personnage //Signifie : créer une classe Guerrier qui hérite de la classe Personnage
{
  public:
    Magicien(std::string nom);
    void bouleDeFeu() const;
    void bouleDeGlace() const;

  private:
    int m_mana;
};

#endif