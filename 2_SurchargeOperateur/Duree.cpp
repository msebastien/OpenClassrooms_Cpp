#include "Duree.h"



Duree::Duree(int heures, int minutes, int secondes)
{
    if(secondes > 59)
    {
        minutes += (int)(secondes / 60);
        secondes = secondes % 60; // Nombre de secondes qui n'ont pas complétés une minute
    }
    
    if(minutes > 59)
    {
        heures += minutes / 60;
        minutes = minutes % 60; // Nombre de minutes qui n'ont pas complétés une heure
    }

    // Initialisation des attributs de la classe Duree
    m_heures = heures;
    m_minutes = minutes;
    m_secondes = secondes;
}

bool Duree::estEgal(Duree const& b) const
{
    return (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes);     //Teste si a.m_heure == b.m_heure etc.  
}

void Duree::afficher() const
{
    std::cout << m_heures << "h " << m_minutes << "m " << m_secondes << "s " << std::endl;
}

bool operator==(Duree const& a, Duree const& b)
{
    return a.estEgal(b);
}

