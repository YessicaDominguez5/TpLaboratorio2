#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class BotonAzul : public sf::Drawable, public Collisionable

{public:
    BotonAzul();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds()const override;
    sf::Sprite getSpriteBtnAzul();

private:
    sf::Sprite _spriteBotonAzul;
    sf::Texture _textureBotonAzul;
};

