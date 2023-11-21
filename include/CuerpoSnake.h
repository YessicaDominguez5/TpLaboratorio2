#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Collisionable.h"


class CuerpoSnake: public sf::Drawable, public Collisionable
{
public:
    CuerpoSnake();
    ~CuerpoSnake();

    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override; //para colisiones
    sf::Sprite getSprite();
    void setearPosicionInicial(int x, int y);
    void setearPosicion(int x, int y);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    int getPositionX();
    int getPositionY();
    bool choqueConBordes();
    void setVelocity(float sumarVelocity);



private:

    sf::Sprite _spriteCuerpoSnake;
    sf::Texture _textureCuerpoSnake;
    float _velocityCuerpo;

};

