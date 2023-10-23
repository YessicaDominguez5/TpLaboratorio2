#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Collisionable.h"


class Vacuna: public sf::Drawable, public Collisionable
{
public:
    Vacuna();
    ~Vacuna();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override; //para colisiones
    void respawn();

private:
    sf::Sprite _spriteVacuna;
    sf::Texture _textureVacuna;
};


