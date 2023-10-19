#pragma once
#include <SFML/Graphics.hpp>

class BotonNegro : public sf::Drawable
{
public:
    BotonNegro();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;


private:
    sf::Sprite _spriteBotonNegro;
    sf::Texture _textureBotonNegro;

};


