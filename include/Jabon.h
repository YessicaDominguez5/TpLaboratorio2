#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Collisionable.h"


class Jabon: public sf::Drawable, public Collisionable
{
public:
    Jabon();
    ~Jabon();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override; //para colisiones
    void respawn();

private:
    sf::Sprite _spriteJabon;
    sf::Texture _textureJabon;
};


