#pragma once
#include "Tamagotchi.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>


class TamagotchiPollito : public Tamagotchi
{
 public:

    TamagotchiPollito();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    void jugar();


private:



};
