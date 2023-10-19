#pragma once
#include <SFML/Graphics.hpp>

class Collisionable
{
    public:
        Collisionable();
        virtual sf::FloatRect getBounds()const = 0;//Espera que quien herede de esta clase utilice su propio método getBounds()
        bool isCollision(Collisionable& col)const;

    protected:

    private:
};

