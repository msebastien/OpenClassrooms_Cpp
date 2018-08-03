#include "Personnage.h"

// Constructeur par défaut sous forme de liste d'initalialisation
Personnage::Personnage() : m_vie(100), m_mana(100), m_arme(0)
{
    m_arme = new Arme();
}

// Constructeur sous forme de liste d'initalialisation
Personnage::Personnage(std::string nomArme, int degatsArme) : m_vie(100), m_mana(100), m_arme(0)
{
    m_arme = new Arme(nomArme, degatsArme);
}

// Constructeur de copie
Personnage::Personnage(Personnage const& personnageACopier) : m_vie(personnageACopier.m_vie), m_mana(personnageACopier.m_mana), m_arme(0)
{
    m_arme = new Arme(*(personnageACopier.m_arme)); // Constructeur de copie générique de Arme
}

Personnage::~Personnage()
{
    delete m_arme;
}

void Personnage::recevoirDegats(int nb_degats)

    m_vie -= nb_dagats;

    if(m_vie < 0)
    {
        m_vie = 0;
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats( m_arme->getDegats() );
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
    m_arme->changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant() const
{
    return m_vie > 0;
}

void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme->afficher();
}

Personnage* Personnage::getAdresse() const
{
    return this;
}

Personnage& Personnage::operator=(Personnage const& personnageACopier) 
{
    if(this != &personnageACopier) //On vérifie que l'objet n'est pas le même que celui reçu en argument
    {
        m_vie = personnageACopier.m_vie; //On copie tous les champs
        m_mana = personnageACopier.m_mana;
	    delete m_arme; // On supprime l'ancienne Arme existante
        m_arme = new Arme(*(personnageACopier.m_arme));
    }
    return *this; //On renvoie l'objet lui-même
}