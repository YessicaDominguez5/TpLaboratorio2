#pragma once
#include <SFML/Graphics.hpp>

class BotonVerde : public sf::Drawable
{

public:
    BotonVerde();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

private:
    sf::Sprite _spriteBotonVerde;
    sf::Texture _textureBotonVerde;
};


