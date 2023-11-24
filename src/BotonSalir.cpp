#include "BotonSalir.h"

BotonSalir::BotonSalir()
{
    _textureBotonSalir.loadFromFile("botonSalir.png");
    _spriteBotonSalir.setTexture(_textureBotonSalir);
    _spriteBotonSalir.setPosition(810,490);
}

void BotonSalir::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteBotonSalir, states);
}

sf::FloatRect BotonSalir::getBounds()const
{
return _spriteBotonSalir.getGlobalBounds();
}

sf::Sprite BotonSalir::getSpriteBtnSalir(){
    return _spriteBotonSalir;
}

