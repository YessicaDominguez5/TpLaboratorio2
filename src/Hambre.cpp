#include "Hambre.h"

Hambre::Hambre()
{
    _spriteHambre.setPosition(50,50);
}
void Hambre::TipoHambre(bool Hambre)
{
    if(Hambre == true)
    {
        _textureHambre.loadFromFile("satisfecho.png");
        _spriteHambre.setTexture(_textureHambre);

    }
    else
    {

        _textureHambre.loadFromFile("hambre.png");
        _spriteHambre.setTexture(_textureHambre);

    }

}

void Hambre::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteHambre, states);
}
