#include <iostream>
#include "Tamagotchi.h"
#include "Funciones.h"
#include "TamagotchiPerro.h"
#include "TamagotchiGato.h"
#include "TamagotchiPollito.h"


using namespace std;

int main()
{
    presentacion();

    int tipoElegidoDeMascota = eleccionDeMascota();

    switch(tipoElegidoDeMascota)
    {
        case 1:
            {
            TamagotchiPerro tamagotchi;

            }
            break;

        case 2:
            {

            TamagotchiGato tamagotchi;
            }
            break;

        default:
            {
            TamagotchiPollito tamagotchi;
            }
            break;


    }





    return 0;
}
