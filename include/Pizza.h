#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Collisionable.h"


class Pizza: public sf::Drawable, public Collisionable
{
public:
    Pizza();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override; //para colisiones
    void respawn();

private:
    sf::Sprite _spritePizza;
    sf::Texture _texturePizza;
};


