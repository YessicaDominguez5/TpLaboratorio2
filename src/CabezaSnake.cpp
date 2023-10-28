#include "CabezaSnake.h"

CabezaSnake::CabezaSnake()
{
    _textureCabezaSnake.loadFromFile("cabezasnake.png");
    _spriteCabezaSnake.setTexture(_textureCabezaSnake);
    _spriteCabezaSnake.setOrigin(_spriteCabezaSnake.getGlobalBounds().width/2, _spriteCabezaSnake.getGlobalBounds().height/2);
    _velocityCabeza = 4;
    _spriteCabezaSnake.setPosition(100,350);
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

void CabezaSnake::moveLeft()
{
    _spriteCabezaSnake.move(-_velocityCabeza,0);
}
void CabezaSnake::moveRight()
{
    _spriteCabezaSnake.move(_velocityCabeza,0);

}
void CabezaSnake::moveUp()
{
    _spriteCabezaSnake.move(0,-_velocityCabeza);

}
void CabezaSnake::moveDown()
{
    _spriteCabezaSnake.move(0,_velocityCabeza);

}

bool CabezaSnake::choqueConBordes()
{

    if(_spriteCabezaSnake.getGlobalBounds().left < 0)
    {
        return true;
    }

    if(_spriteCabezaSnake.getGlobalBounds().top < 0)
    {
        return true;
    }

    if(_spriteCabezaSnake.getGlobalBounds().left + _spriteCabezaSnake.getGlobalBounds().width > 800)
    {
        return true;
    }

    if(_spriteCabezaSnake.getGlobalBounds().top + _spriteCabezaSnake.getGlobalBounds().height > 600)
    {
        return true;

    }
}
