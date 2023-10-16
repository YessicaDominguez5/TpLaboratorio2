#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <cstring>
#include <string>
#include "rlutil.h"
#include "Salud.h"
#include "horario.h"


class Tamagotchi : public sf::Drawable
{
public:
    Tamagotchi();
    void setTipoDeMascota(int tipo);
    void setNombre(std::string nombre);
    void setSaludDeSalud(int salud);
    void setHigiene(bool higiene);
    void setHambriento(bool hambriento);
    void setEntretenimiento(bool entretenido);
    void setSalud(int tipoSalud);
    void setSuenio(bool suenio);

    std::string getSalud(int posVector);
    int getSaludNumerica();
    std::string getTipoDeMascota();
    std::string getNombre()const;
    bool getHigiene()const;
    bool getHambriento()const;
    bool getEntretenimiento()const;
    bool getSuenio()const;

    void petCreator(int tipoDeMascota);


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    void dibujarSalud(sf::RenderWindow& window);
    void cantidadCorazoness(sf::RenderWindow&,int cant);


    virtual void jugar();
    void update();
    void limpiar();


    // virtual void Alimentarse();


protected:

    int _tipoDeMascota; //Perro, Gato o pollito
    char _mascota[8];
    char _nombre[15];
    int _salud;
    Salud _estadoSalud[6];
    char _descripcionSalud[13];
    bool _higiene; //1 limpio o 0 sucio
    bool _hambriento;//1 satisfecho o 0 hambriento
    bool _entretenimiento;//1 entretenido o 0 aburrido
    bool _suenio; //1 despierto o 0 con sueño
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
    Horario _horario;





};


