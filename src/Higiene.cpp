#include "Higiene.h"

Higiene::Higiene()
{
    _spriteHigiene.setPosition(700,30);
}
void Higiene::TipoHigiene(bool higiene)
{
    if(higiene == true)
    {
        _textureHigiene.loadFromFile("limpio.png");
        _spriteHigiene.setTexture(_textureHigiene);

    }
    else
    {

        _textureHigiene.loadFromFile("sucio.png");
        _spriteHigiene.setTexture(_textureHigiene);



    }


}

void Higiene::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteHigiene, states);
}

