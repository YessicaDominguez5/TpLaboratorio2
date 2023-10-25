#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Collisionable.h"


class Manzana: public sf::Drawable, public Collisionable
{
public:
    Manzana();
    ~Manzana();

    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override; //para colisiones
    void respawn();

private:
    sf::Sprite _spriteManzana;
    sf::Texture _textureManzana;
};


