#ifndef __ZFRACTION__
#define __ZFRACTION__

#include <iostream>


class ZFraction
{
    private:
    int m_numerateur;
    int m_denominateur;  

    public:
    ZFraction(); // Constructeur par défaut
    Zfraction(int numerateur, int denominateur = 1);

    int getNumerateur() const;
    int getDenominateur() const;
    void setNumerateur(int a);
    void setDenominateur(int a);
    bool isEqual(const ZFraction &a) const;
    void display(std::ostream &flux) const;

    ZFraction& operator+=(const ZFraction& a);
    ZFraction& operator*=(const ZFraction& a);
};

ZFraction operator*(const ZFraction &a, const ZFraction &b);
ZFraction operator+(const ZFraction &a, const ZFraction &b);
bool operator==(const ZFraction a, const ZFraction b);
bool operator>(const ZFraction a, const ZFraction b);
std::ostream& operator<<( std::ostream &flux, ZFraction const& a );

int getPGCD(int a, int b);


#endif // __ZFRACTION__