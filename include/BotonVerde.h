#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class BotonVerde : public sf::Drawable, public Collisionable
{

public:
    BotonVerde();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override;

private:
    sf::Sprite _spriteBotonVerde;
    sf::Texture _textureBotonVerde;
};


