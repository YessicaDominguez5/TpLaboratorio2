#include "Tamagotchi.h"
#include "Salud.h"
#include "Higiene.h"
#include "Hambre.h"
#include "Entretenimiento.h"
#include "suenio.h"


Tamagotchi::Tamagotchi()
{
    _tipoDeMascota = 0;
    strcpy(_mascota,"");
    strcpy(_nombre,"");
    _salud = 100;
    _higiene = true;
    _hambriento = true;
    _entretenimiento = true;
    _suenio = true;
    _velocity = {4,4};
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height); //Para dar vuelta la imagen seleccionando el punto en donde va a agarrar para invertirla
    //getGlobalBounds trae los bordes del sprite, ancho del la imagen dividido 2 para que tome como punto la mitad de la imagen
    _sprite.setPosition(300,200);
    _horario = Horario();
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
    if(salud <= 100 && salud >= 0)
    {
        _salud = salud;

    }
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
void Tamagotchi::setSuenio(bool suenio)
{
    _suenio = suenio;
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
int Tamagotchi::getSaludNumerica()
{
    return _salud;
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
bool Tamagotchi::getSuenio()const
{
    return _suenio;
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

    rlutil::cls();

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
        window.draw(_sprite); //dibuja al personaje

        Horario horario;


        if(horario.getMinuto() % 3 == 0) //cambia el estado
        {
            _salud = 16; //enfermo
        }

        Higiene h;

        if(horario.getMinuto() % 3 == 0) //cambia el estado
        {
            _higiene = false;

        }

        h.TipoHigiene(_higiene); //si esta limpio o sucio


        Hambre ha;

        if(horario.getMinuto() % 3 == 0)
        {
            _hambriento = false;

        }

        ha.TipoHambre(_hambriento); //si tiene hambre o esta satisfecho

        Entretenimiento e;

        if(horario.getMinuto() % 3 == 0)
        {
            _entretenimiento = false;

        }

        e.TipoEntretenimiento(_entretenimiento);

        Suenio s;
        s.TipoSuenio(_suenio);


        dibujarSalud(window); //dibuja los corazones
        window.draw(h); //dibuja perfume si esta limpio o emogie si esta sucio
        window.draw(ha); //dibuja plato lleno si esta satisfecho y plato vacio si tiene hambre
        window.draw(e);
        window.draw(s);

        dibujarAcciones(window);

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
        _sprite.setPosition(_sprite.getGlobalBounds().width,_sprite.getPosition().y);
    }

    if(_sprite.getGlobalBounds().top < 120)
    {
        _sprite.setPosition(_sprite.getPosition().x, 120); //que no se vaya para arriba
    }

    if(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800)
    {
        _sprite.setPosition(800 -(_sprite.getGlobalBounds().width - _sprite.getOrigin().x),_sprite.getPosition().y);//que no se vaya para la derecha
    }

    if(_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600)
    {
        _sprite.setPosition(_sprite.getPosition().x, 600 - (_sprite.getGlobalBounds().height));//que no se vaya para abajo
    }


}
void Tamagotchi::dibujarSalud(sf::RenderWindow& window)
{

    if(_salud == 100)//espetacular

    {
        int cant = 5;
        cantidadCorazoness(window,cant);

    }
    else if(_salud < 100 && _salud >= 70)//saludable
    {
       int cant = 4;
        cantidadCorazoness(window,cant);
    }
    else if(_salud >= 50 && _salud < 70)//regular
    {
        int cant = 3;
        cantidadCorazoness(window,cant);
    }
    else if(_salud >= 15 && _salud < 50)//enfermo
    {
        int cant = 2;
        cantidadCorazoness(window,cant);
    }
    else if(_salud > 0 && _salud < 15) //grave
    {
        int cant = 1;
        cantidadCorazoness(window,cant);
    }


    }
    void Tamagotchi::cantidadCorazoness(sf::RenderWindow& window ,int cant)
    {
         int posX = 25; /// Posicion X inicial (para el primer corazon)

            for(int i = 0; i < cant; i++)  /// Como tenes la vida completa, tenemos que dibujar 5 corazones
        {
            _estadoSalud[i].SetearImagen();
            _estadoSalud[i].setearPosicion(posX);/// Posicion del corazon
            window.draw(_estadoSalud[i].getSprite());
            posX+=30;
        }
    }

    void Tamagotchi::dibujarAcciones(sf::RenderWindow& window)
    {

     sf::Font font;
    font.loadFromFile("Valoon.ttf");

    sf::Text textAlimentar,textJugarSnake,textDormir, textLimpiar, textCurar;
    std::string Alimentar = "Alimentar", JugarSnake = "Jugar", Dormir = "Dormir", Limpiar = "Limpiar", Curar = "Curar";

    textAlimentar.setFont(font);
    textJugarSnake.setFont(font);
    textDormir.setFont(font);
    textLimpiar.setFont(font);
    textCurar.setFont(font);

    textAlimentar.setColor(sf::Color::Yellow);
    textJugarSnake.setColor(sf::Color::Magenta);
    textDormir.setColor(sf::Color::Red);
    textLimpiar.setColor(sf::Color::Blue);
    textCurar.setColor(sf::Color::Green);

    textAlimentar.setPosition(1,550);
    textJugarSnake.setPosition(200,550);
    textDormir.setPosition(350,550);
    textLimpiar.setPosition(500,550);
    textCurar.setPosition(680,550);

    textAlimentar.setString(Alimentar);
    textJugarSnake.setString(JugarSnake);
    textDormir.setString(Dormir);
    textLimpiar.setString(Limpiar);
    textCurar.setString(Curar);

    window.draw(textAlimentar);
    window.draw(textJugarSnake);
    window.draw(textDormir);
    window.draw(textLimpiar);
    window.draw(textCurar);




    }
