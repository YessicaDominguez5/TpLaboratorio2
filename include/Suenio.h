#pragma once
#include <SFML/Graphics.hpp>

class Suenio: public sf::Drawable
{
    public:
        Suenio();
        void TipoSuenio(bool suenio);
        void draw(sf::RenderTarget& target, sf::RenderStates states)const override;


    private:

    sf::Sprite _spriteSuenio;
    sf::Texture _textureSuenio;

};
