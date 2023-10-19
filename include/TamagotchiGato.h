#pragma once
#include "Tamagotchi.h"
#include <SFML/Graphics.hpp>


class TamagotchiGato : public Tamagotchi
{
 public:

    TamagotchiGato();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    void jugar();



private:



};

