#ifndef DEF_ARME
#define DEF_ARME

#include <iostream>
#include <string>

class Arme
{
    private:
    std::string m_nom;
    int m_degats;

    public:
    Arme(); // Constructeur par defaut
    Arme(std::string nom, int degats);
    void changer(std::string nom, int degats);
    void afficher() const;
    
    //Accesseur
    int getDegats() const; 

};

#endif