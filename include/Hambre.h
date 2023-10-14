#pragma once
#include <SFML/Graphics.hpp>

class Hambre: public sf::Drawable
{
    public:
        Hambre();
        void TipoHambre(bool hambre);
        void draw(sf::RenderTarget& target, sf::RenderStates states)const override;


    private:

    sf::Sprite _spriteHambre;
    sf::Texture _textureHambre;

};
