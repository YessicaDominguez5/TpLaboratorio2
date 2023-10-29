#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Collisionable.h"

class CabezaSnake: public sf::Drawable, public Collisionable
{
public:
    CabezaSnake();
    ~CabezaSnake();

    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override; //para colisiones
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    bool choqueConBordes();
    int getPositionX();
    int getPositionY();




private:

    sf::Sprite _spriteCabezaSnake;
    sf::Texture _textureCabezaSnake;
    float _velocityCabeza;

};


