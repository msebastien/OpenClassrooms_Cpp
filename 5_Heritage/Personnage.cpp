#include "Personnage.h"

// Constructeur par défaut sous forme de liste d'initalialisation
Personnage::Personnage() : m_nom("Jack"), m_vie(100) {}

Personnage::Personnage(std::string nom) : m_nom(nom), m_vie(100) {}

void Personnage::recevoirDegats(int nb_degats)

    m_vie -= nb_dagats;

    if(m_vie < 0)
    {
        m_vie = 0;
    }
}

void Personnage::coupDePoing(Personnage &cible)
{
    cible.recevoirDegats(10);
}

void Personnage::sePresenter() const
{
    cout << "Bonjour, je m'appelle " << m_nom << "." << endl;
    cout << "J'ai encore " << m_vie << " points de vie." << endl;
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if(m_vie > 100)
    {
        m_vie = 100;
    }
}
