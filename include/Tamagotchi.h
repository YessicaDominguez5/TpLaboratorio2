#pragma once
#include <cstring>
#include "Fecha.h"
#include "Entretenimiento.h"



class Tamagotchi
{
    public:
        Tamagotchi();
        void Jugar();
        void Limpiar();

        void setTipoDeMascota(int tipo);
        void setNombre(std::string nombre);
        void setEdadEnDias(int dia);
        void setSalud(int salud);
        void setHigiene(bool higiene);
        void setHambriento(bool hambriento);
        void setEntretenimiento(bool entretenido);
        void setFechaDeNacimiento(const Fecha &fecha);

        std::string getTipoDeMascota(int tipoMascota);
        std::string getNombre()const;
        Fecha getFechaDeNacimiento()const;
        int getEdadEnDias()const;
        std::string getSalud()const;
        bool getHigiene()const;
        bool getHambriento()const;
        bool getEntretenimiento()const;

        void MostrarMenu();

       // virtual void Saludar();
       // virtual void Alimentarse();


    protected:

        int _tipoDeMascota; //Perro, Gato u Oso
        char _mascota[5];
        char _nombre[15];
        int _edadEnDias;
        Fecha _fechaDeNacimiento;
        int _salud; //0 Muerto,1 Enfermo, 2 Vivo
        bool _higiene; //limpio o sucio
        bool _hambriento;//hambriento o satisfecho
        bool _entretenimiento;


};


