#include "CuerpoSnake.h"

CuerpoSnake::CuerpoSnake()
{
    _textureCuerpoSnake.loadFromFile("cuerposnake.png");
    _spriteCuerpoSnake.setTexture(_textureCuerpoSnake);
    _spriteCuerpoSnake.setOrigin(_spriteCuerpoSnake.getGlobalBounds().width/2, _spriteCuerpoSnake.getGlobalBounds().height/2);
    _velocityCuerpo = 4;

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

void CuerpoSnake::setearPosicionInicial(int x, int y)
{
    _spriteCuerpoSnake.setPosition(x,y);
}
void CuerpoSnake::setearPosicion(int x, int y)
{
    _spriteCuerpoSnake.setPosition(x,y);
}
void CuerpoSnake::moveLeft()
{
    _spriteCuerpoSnake.move(-_velocityCuerpo,0);

}
void CuerpoSnake::moveRight()
{
    _spriteCuerpoSnake.move(_velocityCuerpo,0);


}
void CuerpoSnake::moveUp()
{
    _spriteCuerpoSnake.move(0,-_velocityCuerpo);


}
void CuerpoSnake::moveDown()
{
    _spriteCuerpoSnake.move(0,_velocityCuerpo);


}

  int CuerpoSnake::getPositionX()
  {
      return _spriteCuerpoSnake.getPosition().x;
  }

int CuerpoSnake::getPositionY()
{
    return _spriteCuerpoSnake.getPosition().y;
}
