#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <cstring>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include "rlutil.h"
#include "Salud.h"
#include "horario.h"
#include "Higiene.h"
#include "Hambre.h"
#include "Entretenimiento.h"
#include "Suenio.h"
#include "BotonRojo.h"
#include "BotonAzul.h"
#include "BotonVerde.h"
#include "BotonNegro.h"
#include "BotonGris.h"
#include "Collisionable.h"
#include "Pizza.h"
#include "Vacuna.h"
#include "Jabon.h"
#include "CabezaSnake.h"
#include "CuerpoSnake.h"
#include "Manzana.h"



class Tamagotchi : public sf::Drawable, public Collisionable
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
    void dibujarAcciones(sf::RenderWindow&);
    sf::FloatRect getBounds()const override; //para colisiones


    virtual void jugar();
    void update(int valorTop);


    bool Limpiar(sf::RenderWindow& window);
    bool Alimentar(sf::RenderWindow& window);
    bool Dormir(sf::RenderWindow& window);
    int Curar(sf::RenderWindow& window);
    void Negarse(sf::RenderWindow& window, std::string negacion);
    void Morir(sf::RenderWindow& window);
    bool JugarSnake(sf::RenderWindow& window);

    void llenarVecCuerpo(CuerpoSnake *vecCuerpo, int tam, CuerpoSnake agregarParte);





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


