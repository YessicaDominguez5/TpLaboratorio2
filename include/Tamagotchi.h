#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <cstring>
#include <string>
#include "rlutil.h"


class Tamagotchi : public sf::Drawable
{
public:
    Tamagotchi();
    void setTipoDeMascota(int tipo);
    void setNombre(std::string nombre);
    void setSalud(int salud);
    void setHigiene(bool higiene);
    void setHambriento(bool hambriento);
    void setEntretenimiento(bool entretenido);

    std::string getTipoDeMascota();
    std::string getNombre()const;
    std::string getSalud(int tipoSalud);
    bool getHigiene()const;
    bool getHambriento()const;
    bool getEntretenimiento()const;

    void petCreator(int tipoDeMascota);


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    virtual void jugar();
    void update();
    void limpiar();



    // virtual void Saludar();
    // virtual void Alimentarse();


protected:

    int _tipoDeMascota; //Perro, Gato o pollito
    char _mascota[6];
    char _nombre[15];
    int _salud; //0 Muerto, 15< grave, 50< && >15 Enfermo, >50 && <70 regular, >70 saludable, 100 espectacular
    char _descripcionSalud[13];
    bool _higiene; //1 limpio o 0 sucio
    bool _hambriento;//1 satisfecho o 0 hambriento
    bool _entretenimiento;//1 entretenido o 0 aburrido
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;



};


