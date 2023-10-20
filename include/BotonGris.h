#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class BotonGris : public sf::Drawable, public Collisionable
{
public:
    BotonGris();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override;
    sf::Sprite getSpriteBtnGris();

private:
    sf::Sprite _spriteBotonGris;
    sf::Texture _textureBotonGris;
};

