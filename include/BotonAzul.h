#pragma once
#include <SFML/Graphics.hpp>

class BotonAzul : public sf::Drawable

{public:
    BotonAzul();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

private:
    sf::Sprite _spriteBotonAzul;
    sf::Texture _textureBotonAzul;
};

