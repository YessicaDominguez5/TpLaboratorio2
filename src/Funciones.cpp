#include "Funciones.h"

void presentacion()
{
    rlutil::hidecursor();
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::locate(30,10);

    std::cout << "********************************************************************" << std::endl << std::endl;
    rlutil::locate(30,12);
    std::cout << "                             TAMAGOTCHI                             "<< std::endl << std::endl;
    rlutil::locate(30,14);
    std::cout << "********************************************************************"<< std::endl << std::endl;

    rlutil::locate(30,16);
    std::cout << "                          TU MASCOTA VIRTUAL                        "<< std::endl << std::endl;

    rlutil::locate(30,18);
    std::cout << "********************************************************************"<< std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;



    system("pause>>null");
    rlutil::cls();
}

int eleccionDeMascota()
{
    int opcion = -1, y = 0;

    do
    {
        rlutil::hidecursor();
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);


        rlutil::locate(30,10); //posiciona el cursor en coordenada
        std::cout << "********************************************************************" << std::endl <<std::endl;
        rlutil::locate(50,12);
        std::cout << "QUE TIPO DE MASCOTA DESEAS TENER?" << std::endl;
        rlutil::locate(30,14);
        std::cout << "********************************************************************" << std::endl <<std::endl;

        showItem(" PERRO ", 60, 16, y == 0);//y == 0 manda el selected en true si esta en la posicion seleccionada
        showItem(" GATO ", 60, 17, y == 1);
        showItem(" POLLITO ", 60, 18, y == 2);
        showItem(" SALIR ", 60, 19, y == 3);

        rlutil::locate(30,21);
        std::cout << "********************************************************************" << std::endl <<std::endl;

        int key = rlutil::getkey();//tecla presionada(espera a que se presione una tecla).

        switch(key)
        {
        case 14://up

            rlutil::locate(58,16 + y);//»
            std::cout << " " << std::endl<< std::endl;
            y--;

            if(y < 0)
            {
                y = 0;
            }
            break;

        case 15: //down
            rlutil::locate(58,16 + y);//»
            std::cout << " " << std::endl<< std::endl;
            y++;

            if(y > 3)
            {
                y = 3;
            }
            break;

        case 1://enter

            switch(y)
            {
            case 0:
                //PERRO
                opcion = 1;
                break;

            case 1:
                //GATO
                opcion = 2;
                break;

            case 2:
                //POLLITO
                opcion = 3;
                break;


            case 3:
                opcion = 0;
                break;
            }
            break;

        default:
            break;

        }

    }
    while(opcion == -1);
    return opcion;
    rlutil::cls();
}
void showItem(const char* text, int posx, int posy, bool selected) //vector de caracteres con el nombre de la opcion, posicion de x, posicion de y, si esta seleccionado
{

    if(selected)
    {
        rlutil::setBackgroundColor(rlutil::COLOR::GREEN);

    }
    else
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }
    rlutil::locate(posx,posy);
    std::cout << text << std::endl<< std::endl;

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);

}
void principalMenu () // Muestra las opciones para crear o cargar una partida y una opcion que para el programa
{
    int y = 1;
    bool opc = false;
    do
    {
        rlutil::hidecursor();
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::locate(30,10);
        std::cout << "********************************************************************" << std::endl << std::endl;
        rlutil::locate(30,12);
        std::cout << "                             TAMAGOTCHI                             "<< std::endl << std::endl;
        rlutil::locate(30,14);
        std::cout << "********************************************************************"<< std::endl << std::endl;
        showItem(" NUEVA PARTIDA ", 58, 16, y == 1);
        showItem (" CARGAR PARTIDA ", 58,18, y==2);
        showItem (" SALIR ", 58,20, y==3);
        rlutil::locate(30,22);
        std::cout << "********************************************************************"<< std::endl << std::endl;

        int key = rlutil::getkey();

        switch(key)
        {
        case 14://up

            rlutil::locate(58,16 + y);//»
            std::cout << " " << std::endl<< std::endl;
            y--;

            if(y < 1)
            {
                y = 1;
            }
            break;

        case 15: //down
            rlutil::locate(58,16 + y);//»
            std::cout << " " << std::endl<< std::endl;
            y++;

            if(y > 3)
            {
                y = 3;
            }
            break;

        case 1://enter
            opc = true;
            rlutil::cls();
            switch(y)
            {
            case 1:
            {
                FILE *p = fopen("partidanueva.dat", "wb");

                 if(p == NULL)
                 {
                     std::cout << "No hay memoria para iniciar una partida nueva" << std::endl;
                     //return ;
                 }
                 else
                 {
                 fclose(p);

                int tipo = eleccionDeMascota();
                if(tipo == 1) //si la mascota es tipo 1 crea un objeto TamagotchiPerro
                {

                    TamagotchiPerro tp;
                    Tamagotchi tchi;
                    tp.petCreator(tipo);
                    tp.jugar();

                    FILE *p = fopen("partidanueva.dat", "ab");
                     fwrite(&tp, sizeof(TamagotchiPerro), 1, p);
                     fclose(p);

                }
                else if(tipo == 2)//si la mascota es tipo 2 crea un objeto TamagotchiGato
                {
                    TamagotchiGato tg;
                    tg.petCreator(tipo);
                    tg.jugar();

                    FILE *p = fopen("partidanueva.dat", "ab");
                    fwrite(&tg, sizeof(TamagotchiGato), 1, p);
                     fclose(p);

                }
                else if(tipo == 3)//si la mascota es tipo 3 crea un objeto TamagotchiPollito
                {
                    TamagotchiPollito tpo;
                    tpo.petCreator(tipo);
                    tpo.jugar();

                    FILE *p = fopen("partidanueva.dat", "ab");
                    fwrite(&tpo, sizeof(TamagotchiPollito), 1, p);
                     fclose(p);



                }
                else
                {
                    opc = false; //Si en la eleccion de mascota se elige salir vuelve al menu anterior
                }
            }


            break;
                 }
            case 2:
                //Opcion "CARGAR PARTIDA"
                 FILE *p = fopen("partidanueva.dat", "rb");

                 if(p == NULL)
                 {
                     std::cout << "No hay memoria para continuar la partida" << std::endl;

                 }
                 else
                 {
                     TamagotchiPerro auxPerro;

                     fread(&auxPerro, sizeof(TamagotchiPerro),1,p);
                     if(auxPerro.getTipoDeMascota() == "perro")
                     {
                    auxPerro.jugar();
                     fclose(p);
                         return;
                     }

                    TamagotchiGato auxGato;

                     fread(&auxGato, sizeof(TamagotchiGato),1,p);
                     if(auxGato.getTipoDeMascota() == "gato")
                     {

                    auxGato.jugar();
                     fclose(p);
                     return;

                     }
                     TamagotchiPollito auxPollito;

                      fread(&auxPollito, sizeof(TamagotchiPollito),1,p);
                     if(auxPollito.getTipoDeMascota() == "pollito")
                     {
                    auxPollito.jugar();
                     fclose(p);
                         return;
                     }

                    std::cout << "No se encontro ninguna partida" << std::endl;

                    system("pause");

                    fclose(p);

                    return;


                 }
                break;
            }

            break;

        default:
            break;

        }

    }
    while (!opc);
}


