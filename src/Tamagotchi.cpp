#include "Tamagotchi.h"
#include "Salud.h"


Tamagotchi::Tamagotchi()
{
    _tipoDeMascota = 0;
    strcpy(_mascota,"");
    strcpy(_nombre,"");
    _salud = 100;

    for(int i = 0; i < 6; i++)
    {
        _estadoSalud[i] = Salud();

    }
    _higiene = 1;
    _hambriento = 1;
    _entretenimiento = 1;
    //_texture.loadFromFile("Huevo.png");
    //_sprite.setTexture(_texture);
    _velocity = {4,4};
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height); //Para dar vuelta la imagen seleccionando el punto en donde va a agarrar para invertirla
    //getGlobalBounds trae los bordes del sprite, ancho del la imagen dividido 2 para que tome como punto la mitad de la imagen
    _sprite.setPosition(1,300);
}

void Tamagotchi::setTipoDeMascota(int tipo)
{
    _tipoDeMascota = tipo;
}
void Tamagotchi::setNombre(std::string nombre)
{
    strcpy(_nombre,nombre.c_str()); //para pasar de string a vector de char

}

void Tamagotchi::setSalud(int salud)
{
  _salud = salud;
}

std::string Tamagotchi::getSalud(int posVector)
{

    std::string EstadoDeSalud0 = "Muerto";
    std::string EstadoDeSalud1 = "Grave";
    std::string EstadoDeSalud2 = "Enfermo";
    std::string EstadoDeSalud3 = "Regular";
    std::string EstadoDeSalud4 = "Saludable";
    std::string EstadoDeSalud5 = "Espectacular";

    if(posVector == 0)
    {
        strcpy(_descripcionSalud, EstadoDeSalud0.c_str());
    }

    else if(posVector == 1)
    {
        strcpy(_descripcionSalud, EstadoDeSalud1.c_str());
    }
    else if(posVector == 2)
    {
        strcpy(_descripcionSalud, EstadoDeSalud2.c_str());
    }
    else if(posVector == 3)
    {
        strcpy(_descripcionSalud, EstadoDeSalud3.c_str());
    }
    else if(posVector == 4)
    {
        strcpy(_descripcionSalud, EstadoDeSalud4.c_str());
    }
    else
    {
        strcpy(_descripcionSalud, EstadoDeSalud5.c_str());
    }

    return _descripcionSalud;
}



void Tamagotchi::setHigiene(bool higiene)
{
    _higiene = higiene;
}
void Tamagotchi::setHambriento(bool hambriento)
{
    _hambriento = hambriento;
}
void Tamagotchi::setEntretenimiento(bool entretenido)
{
    _entretenimiento = entretenido;

}

std::string Tamagotchi::getTipoDeMascota()
{
    std::string tipoDeMascota1 = "perro";
    std::string tipoDeMascota2 = "gato";
    std::string tipoDeMascota3 = "pollito";

    if(_tipoDeMascota == 1)
    {
        strcpy(_mascota, tipoDeMascota1.c_str());
    }
    else if(_tipoDeMascota == 2)
    {
        strcpy(_mascota, tipoDeMascota2.c_str());

    }
    else
    {
        strcpy(_mascota, tipoDeMascota3.c_str());
    }

    return _mascota;
}

std::string Tamagotchi::getNombre()const
{

    return _nombre;

}

bool Tamagotchi::getHigiene()const
{
    return _higiene;
}
bool Tamagotchi::getHambriento()const
{
    return _hambriento;
}

bool Tamagotchi::getEntretenimiento()const
{
    return _entretenimiento;
}
void Tamagotchi::petCreator(int tipoDeMascota) //Recibe el tipo de mascota desde eleccionDeMascota(), setea el tipo y el nombre de la mascota.
{

    rlutil::cls();
    _tipoDeMascota = tipoDeMascota;

    rlutil::hidecursor();
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);


    rlutil::locate(30,10);
    std::cout << "********************************************************************" << std::endl <<std::endl;
    rlutil::locate(50,12);
    std::cout << "ELIGE EL NOMBRE DE TU MASCOTA: " << std::endl;
    rlutil::locate(30,14);
    std::cout << "********************************************************************" << std::endl <<std::endl;

    char petName[15];
    rlutil::locate(60,16);

    std::cin >> petName;

    strcpy(_nombre,petName);
}

void Tamagotchi::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_sprite, states);
}


void Tamagotchi::jugar()
{

    system("cls");

    sf::RenderWindow window(sf::VideoMode(800, 600), "TAMAGOTCHI");
    window.setFramerateLimit(60); //Limita los fps por segundo(velocidad de movimiento del sprite)


    while (window.isOpen()) //Game Loop
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        window.draw(_sprite);
         int posX = 25; /// Posicion X inicial (para el primer corazon)
            for(int i = 0; i < 6; i++){ /// Como tenes la vida completa, tenemos que dibujar 5/6 corazones
                _estadoSalud[i].SetearImagen();
                _estadoSalud[i].setearPosicion(posX);/// Posicion del corazon
                window.draw(_estadoSalud[i].getSprite());
                posX+=30;
            }
        update();
        window.display();
    }

}

void Tamagotchi::update()
{

    _velocity = {0,0};
    //para que se mueva el sprite
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // _velocity{0,-4};
    {
        _velocity.y = -4;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))// _velocity{-4,0};
    {
        _velocity.x = -4;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))// _velocity{0,4};
    {
        _velocity.y = 4;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))// _velocity{4,0};
    {
        _velocity.x = 4;
    }

    _sprite.move(_velocity);

    //para que mire hacia el lado que camina

    if(_velocity.x < 0)
    {
        _sprite.setScale(-1,1);
    }
    else if(_velocity.x > 0)
    {
        _sprite.setScale(1,1);
    }

    //para que no salga de pantalla

    if(_sprite.getGlobalBounds().left < 0)
    {
        _sprite.setPosition(_sprite.getOrigin().x,_sprite.getPosition().y); //Para que no se vaya para la izquierda, en vez de setPosition() ponemos getOrigin() para que no aparezca solo la mitad del sprite, ya que el origin lo establecimos en la mitad del sprite.
    }

    if(_sprite.getGlobalBounds().top < 0)
    {
        _sprite.setPosition(_sprite.getPosition().x,_sprite.getOrigin().y); //que no se vaya para arriba
    }

    if(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800)
    {
        _sprite.setPosition(800 -(_sprite.getGlobalBounds().width - _sprite.getOrigin().x),_sprite.getPosition().y);//que no se vaya para la derecha
    }

    if(_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600)
    {
        _sprite.setPosition(_sprite.getPosition().x, 600 + _sprite.getGlobalBounds().height - _sprite.getOrigin().y);//que no se vaya para abajo
    }


}








//void limpiar();


//virtual void saludar();
//virtual void alimentarse();*/


