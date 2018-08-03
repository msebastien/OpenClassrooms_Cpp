#include "Duree.h"


int main()
{
    Duree duree1(0, 10, 28), duree2(0, 15, 2);
    Duree chrono(0, 512, 1455);

    if(duree1 == duree2){
        std::cout << "OK" << std::endl;
    }else{
        std::cout << "PAS EGAL" << std::endl;
    }
    // Test de la conversion
    chrono.afficher();

    return 0;
}