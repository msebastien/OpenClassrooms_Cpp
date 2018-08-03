#ifndef DEF_DUREE
#define DEF_DUREE

#include <iostream>
#include <cmath>

class Duree
{
    private:
    int m_heures;
    int m_minutes;
    int m_secondes;

    public:
    Duree(int heures = 0, int minutes = 0, int secondes = 0);

    bool estEgal(Duree const& b) const;
    void afficher() const;

};

bool operator==(Duree const& a, Duree const& b);



#endif