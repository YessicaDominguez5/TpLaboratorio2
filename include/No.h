#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class No : public sf::Drawable, public Collisionable
{

public:
    No();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override;
    sf::Sprite getSpriteBtnSalir();


private:
    sf::Sprite _spriteNo;
    sf::Texture _textureNo;

};

