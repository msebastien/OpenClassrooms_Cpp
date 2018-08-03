#include <Guerrier.h>


// Masquage / Démasquage de sePresenter (fonction normalement héritée de Personnage)
void Guerrier::sePresenter() const
{
    Personnage::sePresenter(); // Démasquage
    cout << "Je suis un Guerrier redoutable." << endl;
}