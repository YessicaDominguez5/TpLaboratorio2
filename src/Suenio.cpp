#include "Suenio.h"

Suenio::Suenio()
{
    _spriteSuenio.setPosition(450,55);
}
void Suenio::TipoSuenio(bool suenio)
{
    if(suenio == true)
    {
        _textureSuenio.loadFromFile("despierto.png");
        _spriteSuenio.setTexture(_textureSuenio);

    }
    else
    {

        _textureSuenio.loadFromFile("suenio.png");
        _spriteSuenio.setTexture(_textureSuenio);



    }


}

void Suenio::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteSuenio, states);
}

