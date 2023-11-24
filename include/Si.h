#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Si : public sf::Drawable, public Collisionable
{

public:
    Si();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override;
    sf::Sprite getSpriteBtnSalir();


private:
    sf::Sprite _spriteSi;
    sf::Texture _textureSi;

};

