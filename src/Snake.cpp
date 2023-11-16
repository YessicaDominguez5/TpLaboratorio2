#include "Snake.h"

Snake::Snake()
{
    _x = 350;
    _y = 350;
}
void Snake::setx(int x)
{
    _x = x;
}
void Snake::sety(int y)
{
    _y = y;
}
int Snake::getx()
{
    return _x;
}
int Snake::gety()
{
    return _y;
}


