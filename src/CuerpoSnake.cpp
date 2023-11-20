#include "CuerpoSnake.h"

CuerpoSnake::CuerpoSnake()
{
    _textureCuerpoSnake.loadFromFile("cuerposnake.png");
    _spriteCuerpoSnake.setTexture(_textureCuerpoSnake);
    _spriteCuerpoSnake.setOrigin(_spriteCuerpoSnake.getGlobalBounds().width/2, _spriteCuerpoSnake.getGlobalBounds().height/2);
    _velocityCuerpo = 15;

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
    //_spriteCuerpoSnake.move(-_velocityCuerpo,0);
    int x = getPositionX();
    int y = getPositionY();
    _spriteCuerpoSnake.setPosition(x-_velocityCuerpo,y);
}
void CuerpoSnake::moveRight()
{
    //_spriteCuerpoSnake.move(_velocityCuerpo,0);
    int x = getPositionX();
    int y = getPositionY();
    _spriteCuerpoSnake.setPosition(x+_velocityCuerpo,y);
}
void CuerpoSnake::moveUp()
{
    //_spriteCuerpoSnake.move(0,-_velocityCuerpo);
    int x = getPositionX();
    int y = getPositionY();
    _spriteCuerpoSnake.setPosition(x,y-_velocityCuerpo);

}
void CuerpoSnake::moveDown()
{
    //_spriteCuerpoSnake.move(0,_velocityCuerpo);
    int x = getPositionX();
    int y = getPositionY();
    _spriteCuerpoSnake.setPosition(x,y+_velocityCuerpo);

}

  int CuerpoSnake::getPositionX()
  {
      return _spriteCuerpoSnake.getPosition().x;
  }

int CuerpoSnake::getPositionY()
{
    return _spriteCuerpoSnake.getPosition().y;
}

bool CuerpoSnake::choqueConBordes()
{

    if(_spriteCuerpoSnake.getGlobalBounds().left < 0)
    {
        return true;
    }

    if(_spriteCuerpoSnake.getGlobalBounds().top < 0)
    {
        return true;
    }

    if(_spriteCuerpoSnake.getGlobalBounds().left + _spriteCuerpoSnake.getGlobalBounds().width > 800)
    {
        return true;
    }

    if(_spriteCuerpoSnake.getGlobalBounds().top + _spriteCuerpoSnake.getGlobalBounds().height > 600)
    {
        return true;

    }
}


