#include "CuerpoSnake.h"

CuerpoSnake::CuerpoSnake()
{
    _textureCuerpoSnake.loadFromFile("cuerposnake.png");
    _spriteCuerpoSnake.setTexture(_textureCuerpoSnake);
    _spriteCuerpoSnake.setOrigin(_spriteCuerpoSnake.getGlobalBounds().width/2, _spriteCuerpoSnake.getGlobalBounds().height/2);
    _velocityCuerpo = {4,4};
   // _spriteCuerpoSnake.setPosition(350,350);
}

CuerpoSnake::~CuerpoSnake()
{
    //dtor
}

void CuerpoSnake::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteCuerpoSnake, states);
}

sf::FloatRect CuerpoSnake::getBounds()const
{
    return _spriteCuerpoSnake.getGlobalBounds();
}

sf::Sprite CuerpoSnake::getSprite(){
    return _spriteCuerpoSnake;
}