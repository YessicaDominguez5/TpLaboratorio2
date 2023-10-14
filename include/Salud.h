#pragma once
#include <SFML/Graphics.hpp>


class Salud : public sf::Drawable
{
public:
    Salud();

    void SetearImagen();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    void setearPosicion(int x);
    sf::Sprite getSprite();

private:

    sf::Sprite _spriteSalud;
    sf::Texture _textureSalud;
};


