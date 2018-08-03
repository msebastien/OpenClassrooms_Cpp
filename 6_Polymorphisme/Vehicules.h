#ifndef DEF_VEHICULES
#define DEF_VEHICULES

#include <iostream>
#include <vector>

class Garage
{
    private:
    std::vector<Vehicule*> listeVehicules;

    public:
    Garage();
    void ajouterVehicule(Vehicule const& v);
    void supprimerVehicule(Vehicule const& v);
    void afficher();
};

// Classe abstraite (1 méthode virtuelle pure)
// On ne peut pas créer d'instance (ou d'objet) d'une classe abstraite. 
class Vehicule 
{
    protected:
    int m_prix; // Chaque véhicule a un prix
    int m_annee;

    public:
    Vehicule(int prix);
    virtual ~Vehicule(); // Destructeur virtuel

    virtual void affiche() const; // Affiche une description du véhicule
    virtual int nbrRoues() const = 0; // Méthode virtuelle pure
    void afficherAnnee() const;
};

class Voiture : public Vehicule 
{
    private:
    int m_portes; // Nombre de portes de la voiture

    public:
    Voiture(int prix, int portes);
    virtual ~Voiture();

    virtual void affiche() const;
    virtual int nbrRoues() const;
};

class Moto : public Vehicule 
{
    private:
    double m_vitesse; // Vitesse maximale de la moto

    public:
    Moto(int prix, double vitesseMax);
    virtual ~Moto();

    virtual void affiche() const;
    virtual int nbrRoues() const;
};

class Camion : public Vehicule 
{
    private:
    double m_poids; // Poids maximal 

    public:
    Camion(int prix, double poids);
    virtual ~Camion();

    virtual void affiche() const;
    virtual int nbrRoues() const;
};

#endif