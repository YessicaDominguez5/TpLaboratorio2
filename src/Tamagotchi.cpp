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
void Tamagotchi::setEntretenimiento(bool entretenido)
{
    _entretenimiento = entretenido;

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

  std::string Tamagotchi::getSalud(int tipoSalud)
  {

        std::string EstadoDeSalud1 = "Espectacular";
        std::string EstadoDeSalud2 = "Saludable";
        std::string EstadoDeSalud3 = "Regular";
        std::string EstadoDeSalud4 = "Enfermo";
        std::string EstadoDeSalud5 = "Grave";
        std::string EstadoDeSalud6 = "Muerto";

      if(tipoSalud == 100)
      {
        strcpy(_descripcionSalud, EstadoDeSalud1.c_str());
      }

      else if(tipoSalud >= 70)
      {
        strcpy(_descripcionSalud, EstadoDeSalud2.c_str());
      }
      else if(tipoSalud >= 50 && tipoSalud < 70)
      {
        strcpy(_descripcionSalud, EstadoDeSalud3.c_str());
      }
      else if(tipoSalud < 50 && tipoSalud >= 15)
      {
        strcpy(_descripcionSalud, EstadoDeSalud4.c_str());
      }
      else if(tipoSalud > 0 && tipoSalud < 15)
      {
        strcpy(_descripcionSalud, EstadoDeSalud5.c_str());
      }
      else
      {
        strcpy(_descripcionSalud, EstadoDeSalud6.c_str());
      }

      return _descripcionSalud;
  }

bool Tamagotchi::getHigiene()const
{
    return _higiene;
}
bool Tamagotchi::getHambriento()const
{
    return _hambriento;
}

bool Tamagotchi::getEntretenimiento()const
{
    return _entretenimiento;
}


/*void Jugar();
void Limpiar();
void MostrarMenu();

virtual void Saludar();
virtual void Alimentarse();*/


