#pragma once
#include <SFML/Graphics.hpp>

class BotonGris : public sf::Drawable
{
public:
    BotonGris();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

private:
    sf::Sprite _spriteBotonGris;
    sf::Texture _textureBotonGris;
};

