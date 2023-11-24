#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class BotonSalir : public sf::Drawable, public Collisionable
{

public:
    BotonSalir();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override;
    sf::Sprite getSpriteBtnSalir();


private:
    sf::Sprite _spriteBotonSalir;
    sf::Texture _textureBotonSalir;

};





