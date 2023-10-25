#include "CabezaSnake.h"

CabezaSnake::CabezaSnake()
{
    _textureCabezaSnake.loadFromFile("cabezasnake.png");
    _spriteCabezaSnake.setTexture(_textureCabezaSnake);
    _spriteCabezaSnake.setOrigin(_spriteCabezaSnake.getGlobalBounds().width/2, _spriteCabezaSnake.getGlobalBounds().height/2);
    _velocityCabeza = {4,4};
    _spriteCabezaSnake.setPosition(350,350);
}

CabezaSnake::~CabezaSnake()
{
    //dtor
}


void CabezaSnake::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteCabezaSnake, states);
}

sf::FloatRect CabezaSnake::getBounds()const
{
    return _spriteCabezaSnake.getGlobalBounds();
}

