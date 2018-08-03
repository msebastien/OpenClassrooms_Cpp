#ifndef DEF_GUERRIER
#define DEF_GUERRIER

#include <iostream>
#include <string>
#include <Personnage.h>

class Guerrier : public Personnage //Signifie : créer une classe Guerrier qui hérite de la classe Personnage
{
  public:
    void sePresenter() const;
    void frapperCommeUnSourdAvecUnMarteau() const;
    //Méthode qui ne concerne que les guerriers
};

#endif