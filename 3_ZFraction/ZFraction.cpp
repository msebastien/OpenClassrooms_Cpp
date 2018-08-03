#include "ZFraction.h"

// Constructeurs
ZFraction::ZFraction() : m_numerateur(0), m_denominateur(0) {}

//ZFraction::ZFraction(int numerateur) : m_numerateur(numerateur), m_denominateur(1) {}

ZFraction::ZFraction(int numerateur, int denominateur) : m_numerateur(numerateur), m_denominateur(denominateur) {}

int ZFraction::getNumerateur() const
{
    return m_numerateur;
}

int ZFraction::getDenominateur() const
{
    return m_denominateur;
}

void ZFraction::setNumerateur(int a)
{
    m_numerateur = a;
}

void ZFraction::setDenominateur(int a)
{
    m_denominateur = a;
}

bool ZFraction::isEqual(const ZFraction &a) const
{
    return m_numerateur == a.m_numerateur && m_denominateur == a.m_denominateur;
}

void ZFraction::display(std::ostream &flux) const
{
    flux << m_numerateur << "/" << m_denominateur;
}

ZFraction& ZFraction::operator+=(const ZFraction& a)
{
    if(m_denominateur == a.m_denominateur)
    {
        m_numerateur += a.m_numerateur;
    }
    else
    {
        m_denominateur = m_denominateur * a.m_denominateur;
        m_numerateur = m_numerateur * a.m_denominateur + m_denominateur * a.m_numerateur;
        // TODO: Simplifier fraction
    }
    return *this;
}

ZFraction& ZFraction::operator*=(const ZFraction& a)
{
    m_numerateur *= a.m_numerateur;
    m_denominateur *= a.m_denominateur;
    return *this;
}

ZFraction operator*(const ZFraction &a, const ZFraction &b)
{
    ZFraction copie(a);
    copie *= b;

    return copie;
}

ZFraction operator+(const ZFraction &a, const ZFraction &b)
{
    ZFraction copie(a);
    copie += b;

    return copie;
}

bool operator==(const ZFraction a, const ZFraction b)
{
    return a.isEqual(b);
}

bool operator>(const ZFraction a, const ZFraction &b)
{
    return a.getDenominateur() < b.getDenominateur() && a.getNumerateur() > b.getNumerateur();
}

std::ostream& operator<<( std::ostream &flux, ZFraction const& a )
{
    //Affichage des attributs
    a.display(flux);
    return flux;
}

int getPGCD(int a, int b)
{
    while (b != 0) // Tant que l'on a un reste
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}