#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class BotonRojo : public sf::Drawable, public Collisionable
{
public:
    BotonRojo();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override;
    sf::Sprite getSpriteBtnRojo();

private:
    sf::Sprite _spriteBotonRojo;
    sf::Texture _textureBotonRojo;

};
