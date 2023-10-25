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

private:

    sf::Sprite _spriteCuerpoSnake;
    sf::Texture _textureCuerpoSnake;
    sf::Vector2f _velocityCuerpo;

};

