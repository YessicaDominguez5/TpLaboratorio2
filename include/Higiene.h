#pragma once
#include <SFML/Graphics.hpp>

class Higiene: public sf::Drawable
{
    public:
        Higiene();
        void TipoHigiene(bool higiene);
        void draw(sf::RenderTarget& target, sf::RenderStates states)const override;


    private:

    sf::Sprite _spriteHigiene;
    sf::Texture _textureHigiene;

};


