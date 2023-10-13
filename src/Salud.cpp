#include "Salud.h"


Salud::Salud()
{
    _salud = 100;
    _textureSalud.loadFromFile("CorazonSalud.png");
    _spriteSalud.setTexture(_textureSalud);
    _spriteSalud.setOrigin(_spriteSalud.getGlobalBounds().width/2, _spriteSalud.getGlobalBounds().height/2);//sprite agarrado desde el centro
}

void Salud::setSalud(int salud)
{
    _salud = salud;

}

std::string Salud::getSalud(int tipoSalud)
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

void Salud::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteSalud, states);
}
