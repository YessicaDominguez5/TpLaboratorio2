#include "Tamagotchi.h"


Tamagotchi::Tamagotchi()
{
    _tipoDeMascota = 1;
}

void Tamagotchi::setTipoDeMascota(int tipo)
{
    _tipoDeMascota = tipo;
}
void Tamagotchi::setNombre(std::string nombre)
{
    strcpy(_nombre,nombre.c_str()); //para pasar de string a vector de char

}
void Tamagotchi::setEdadEnDias(int dia)
{

    _edadEnDias = dia;
}
void Tamagotchi::setSalud(int salud)
{
    _salud = salud;

}
void Tamagotchi::setHigiene(bool higiene)
{
    _higiene = higiene;
}
void Tamagotchi::setHambriento(bool hambriento)
{
    _hambriento = hambriento;
}
void Tamagotchi::setEntretenimiento(Entretenimiento entretenido)
{
    _entretenimiento = entretenido;

}
void Tamagotchi::setFechaDeNacimiento(const Fecha &fecha)
{
    _fechaDeNacimiento = fecha;
}
std::string Tamagotchi::getTipoDeMascota(int tipoMascota)
{
    std::string tipoDeMascota1 = "perro";
    std::string tipoDeMascota2 = "gato";
    std::string tipoDeMascota3 = "oso";

    if(tipoMascota == 1)
    {
        strcpy(_mascota, tipoDeMascota1.c_str());
    }
    else if(tipoMascota == 2)
    {
        strcpy(_mascota, tipoDeMascota2.c_str());

    }
    else
    {
        strcpy(_mascota, tipoDeMascota3.c_str());
    }

    return _mascota;
}

std::string Tamagotchi::getNombre()const
{

return _nombre;

}

 Fecha Tamagotchi::getFechaDeNacimiento()const
 {
     return _fechaDeNacimiento;
 }



/*void Jugar();
void Limpiar();











int getEdadEnDias()const;
bool getSalud()const;
bool getHigiene()const;
bool getHambriento()const;
Entretenimiento getEntretenimiento()const;

void MostrarMenu();

virtual void Saludar();
virtual void Alimentarse();*/


