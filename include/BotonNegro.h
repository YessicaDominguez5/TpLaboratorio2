#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class BotonNegro : public sf::Drawable, public Collisionable
{
public:
    BotonNegro();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override;
    sf::Sprite getSpriteBtnNegro();


private:
    sf::Sprite _spriteBotonNegro;
    sf::Texture _textureBotonNegro;

};


