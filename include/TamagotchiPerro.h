#pragma once
#include "Tamagotchi.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>


class TamagotchiPerro : public Tamagotchi
{
 public:

    TamagotchiPerro();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    void jugar();



private:



};


