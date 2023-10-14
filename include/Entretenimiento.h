#pragma once
#include <SFML/Graphics.hpp>

class Entretenimiento: public sf::Drawable
{
    public:
        Entretenimiento();
        void TipoEntretenimiento(bool entretenimiento);
        void draw(sf::RenderTarget& target, sf::RenderStates states)const override;


    private:

    sf::Sprite _spriteEntretenimiento;
    sf::Texture _textureEntretenimiento;

};
