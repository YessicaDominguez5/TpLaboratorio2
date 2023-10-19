#pragma once
#include <SFML/Graphics.hpp>

class BotonRojo : public sf::Drawable
{
public:
    BotonRojo();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

private:
    sf::Sprite _spriteBotonRojo;
    sf::Texture _textureBotonRojo;

};
