#include "Personnage.h"

// Constructeur par défaut sous forme de liste d'initalialisation
Personnage::Personnage() : m_vie(100), m_mana(100), 
m_nomArme("Épée rouillée"), m_degatsArme(10){}

// Constructeur sous forme de liste d'initalialisation
Personnage::Personnage(std::string nomArme, int degatsArme) : m_vie(100), m_mana(100), 
m_arme(nomArme, degatsArme){}


void Personnage::recevoirDegats(int nb_degats)

    m_vie -= nb_dagats;

    if(m_vie < 0)
    {
        m_vie = 0;
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats( m_arme.getDegats() );
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if(m_vie > 100)
    {
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant() const
{
    return m_vie > 0;
}

void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();
}