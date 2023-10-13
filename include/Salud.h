#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <cstring>

class Salud : public sf::Drawable
{
public:
    Salud();
    void setSalud(int salud);
    std::string getSalud(int tipoSalud);
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

private:
    int _salud;//0 Muerto, 15< grave, 50< && >15 Enfermo, >50 && <70 regular, >70 saludable, 100 espectacular
    char _descripcionSalud[13];
    sf::Sprite _spriteSalud;
    sf::Texture _textureSalud;
};


