#include "Collisionable.h"

Collisionable::Collisionable()
{
}


bool Collisionable::isCollision(Collisionable& obj)const
{
    return getBounds().intersects(obj.getBounds());
}
