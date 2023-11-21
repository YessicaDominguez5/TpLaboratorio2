#include "Tamagotchi.h"

Tamagotchi::Tamagotchi()
{
    _tipoDeMascota = 0;
    strcpy(_mascota,"");
    strcpy(_nombre,"");
    _salud = 5;
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
    if(salud <= 5 && salud >= 0)
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

    std::string petName;
    rlutil::locate(60,16);

    std::cin >> petName;


    strcpy(_nombre,petName.c_str());

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
    bool alimentado = false;
    bool curado = false;
    bool baniado = false;
    bool descansado = false;
    bool banderaHorario = false;
    bool entretenido  = false;

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


        if(horario.getMinuto() % 3 == 0 && banderaHorario == false) //cambia el estado //que entre una sola vez por minuto %3
        {
            if(_salud == 1)
            {
                Morir(window);
            }
            _salud = 1; //grave
            dibujarSalud(window);
            banderaHorario = true;
            alimentado = false;
            curado = false;
            baniado = false;
            descansado = false;

        }
        else if(horario.getMinuto() % 3 == 0 && curado == true)
        {
            _salud = 5;
            dibujarSalud(window);
            curado = false;
        }
        else if(!(horario.getMinuto() % 3 == 0)&& curado == true)
        {
            _salud = 5;
            dibujarSalud(window);
        }
        else if(!(horario.getMinuto() % 3 == 0))
        {
            dibujarSalud(window);
            banderaHorario = false;
        }
        else
        {
            dibujarSalud(window);
        }


        Higiene h;

        if(horario.getMinuto() % 3 == 0 && baniado == false)
        {
            _higiene = false;


        }
        else if(horario.getMinuto() % 3 == 0 && baniado == true)
        {
            _higiene = true;

        }
        else if(!(horario.getMinuto() % 3 == 0)&& baniado == true)
        {
            _higiene = true;


        }

        h.TipoHigiene(_higiene); //si esta limpio o sucio


        Hambre ha;

        if(horario.getMinuto() % 3 == 0 && alimentado == false)
        {
            _hambriento = false;


        }
        else if(horario.getMinuto() % 3 == 0 && alimentado == true)
        {
            _hambriento = true;


        }
        else if(!(horario.getMinuto() % 3 == 0)&& alimentado == true)
        {
            _hambriento = true;

        }

        ha.TipoHambre(_hambriento); //si tiene hambre o esta satisfecho

        Entretenimiento e;

        if(horario.getMinuto() % 3 == 0 && entretenido == false)
        {
            _entretenimiento = false;

        }
        else if(horario.getMinuto() % 3 == 0 && entretenido == true)
        {
            _entretenimiento = true;


        }
        else if(!(horario.getMinuto() % 3 == 0)&& entretenido == true)
        {
            _entretenimiento = true;

        }

        e.TipoEntretenimiento(_entretenimiento);

        Suenio s;

        if(horario.getMinuto() % 3 == 0 && descansado == false)
        {
            _suenio = false;


        }
        else if(horario.getMinuto() % 3 == 0 && descansado == true)
        {
            _suenio = true;
            //_salud++;

        }
        else if(!(horario.getMinuto() % 3 == 0)&& descansado == true)
        {
            _suenio = true;
            // _salud++;

        }
        s.TipoSuenio(_suenio);


        dibujarSalud(window); //dibuja los corazones
        window.draw(h); //dibuja perfume si esta limpio o emogie si esta sucio
        window.draw(ha); //dibuja plato lleno si esta satisfecho y plato vacio si tiene hambre
        window.draw(e);
        window.draw(s);

        BotonRojo br;
        BotonAzul ba;
        BotonVerde bv;
        BotonGris bg;
        BotonNegro bn;

        window.draw(br);
        window.draw(ba);
        window.draw(bv);
        window.draw(bg);
        window.draw(bn);

        dibujarAcciones(window);

        if(isCollision(br))
        {
            if(_hambriento == false)
            {
                _hambriento = Alimentar(window);
                alimentado = true;

                if(_salud < 5)
                {
                    _salud++;

                }
                _sprite.setPosition(300,200);

            }
            else
            {
                std::string text = "NO TENGO HAMBRE, GRACIAS";

                Negarse(window,text);
            }
        }


        if(isCollision(ba))
        {
            if(_entretenimiento == false)
            {
                _entretenimiento = JugarSnake(window);
               // entretenido = true;
               if(_entretenimiento == true)
               {
                if(_salud < 5)
                {
                    _salud++;

                }

               }

                _sprite.setPosition(300,200);
            }



            else
            {
                std::string text = "NO ESTOY ABURRIDO";

               Negarse(window,text);

             // JugarSnake(window);
             // _sprite.setPosition(300,200);




            }
        }
        if(isCollision(bv))
        {
            if(_higiene == false)
            {
                _higiene = Limpiar(window);
                baniado = true;
                if(_salud < 5)
                {
                    _salud++;

                }
                _sprite.setPosition(300,200);

            }
            else
            {
                std::string text = "NO ME TOCA BAÑARME!";

                Negarse(window,text);
            }
        }
        if(isCollision(bn))
        {
            if(_suenio == false)
            {
                _suenio = Dormir(window);
                descansado = true;
                if(_salud < 5)
                {
                    _salud++;
                }
                _sprite.setPosition(300,200);

            }
            else
            {
                std::string text = "NO TENGO GANAS DE DORMIR";

                Negarse(window,text);
            }
        }
        if(isCollision(bg))
        {
            if(_salud < 4)
            {
                _salud = Curar(window);
                curado = true;
                _sprite.setPosition(300,200);

            }
            else
            {
                std::string text = "ME SIENTO BIEN POR AHORA";

                Negarse(window,text);
            }
        }



        update(120);


        window.display();
    }

}

void Tamagotchi::update(int valorTop)
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

    if(_sprite.getGlobalBounds().top < valorTop)
    {
        _sprite.setPosition(_sprite.getPosition().x, valorTop); //que no se vaya para arriba
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

    if(_salud == 5)//espetacular

    {
        int cant = 5;
        cantidadCorazoness(window,cant);

    }
    else if(_salud == 4)//saludable
    {
        int cant = 4;
        cantidadCorazoness(window,cant);
    }
    else if(_salud == 3)//regular
    {
        int cant = 3;
        cantidadCorazoness(window,cant);
    }
    else if(_salud == 2)//enfermo
    {
        int cant = 2;
        cantidadCorazoness(window,cant);
    }
    else if(_salud == 1) //grave
    {
        int cant = 1;
        cantidadCorazoness(window,cant);
    }


}
void Tamagotchi::cantidadCorazoness(sf::RenderWindow& window,int cant)
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

    textAlimentar.setFillColor(sf::Color::Yellow);
    textJugarSnake.setFillColor(sf::Color::Magenta);
    textDormir.setFillColor(sf::Color::Red);
    textLimpiar.setFillColor(sf::Color::Blue);
    textCurar.setFillColor(sf::Color::Green);

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

sf::FloatRect Tamagotchi::getBounds()const
{
    return _sprite.getGlobalBounds();
}

void Tamagotchi::Negarse(sf::RenderWindow& window, std::string negacion)
{
    sf::Font font;
    font.loadFromFile("Valoon.ttf");

    sf::Text texto;

    texto.setFont(font);
    texto.setFillColor(sf::Color::White);
    texto.setPosition(350,200);
    texto.setString(negacion);
    window.draw(texto);
}


bool Tamagotchi::Alimentar(sf::RenderWindow& window)
{

    Pizza pizza;
    int pizzasRecolectadas = 0;

    /// while pizzasReconectadas < 6 => Este codigo se va a ejecutar todo el tiempo hasta
    /// que recolectes 5 pizzas para alimentar el tamagotchi.

    _sprite.setPosition(300,1);


    sf::Font font;
    font.loadFromFile("Valoon.ttf");

    sf::Text texto;

    texto.setFont(font);
    texto.setFillColor(sf::Color::White);
    texto.setPosition(350,10);

    pizza.respawn();


    while(pizzasRecolectadas < 5)
    {


        window.clear();

        if(isCollision(pizza))
        {
            pizzasRecolectadas++;
            pizza.respawn();

            if(pizzasRecolectadas == 5)
            {

                return true;
            }
        }

        update(0);

        texto.setString(std::to_string(pizzasRecolectadas));
        window.draw(_sprite);
        window.draw(pizza);
        window.draw(texto);

        window.display();

    }

    pizza.~Pizza();

    return false;
}

int Tamagotchi::Curar(sf::RenderWindow& window)
{

    Vacuna vacuna;
    int vacunasRecolectadas = 0;

    _sprite.setPosition(300,1);


    sf::Font font;
    font.loadFromFile("Valoon.ttf");

    sf::Text texto;

    texto.setFont(font);
    texto.setFillColor(sf::Color::White);
    texto.setPosition(350,10);

    vacuna.respawn();


    while(vacunasRecolectadas < 5)
    {


        window.clear();

        if(isCollision(vacuna))
        {
            vacunasRecolectadas++;
            vacuna.respawn();

            if(vacunasRecolectadas == 5)
            {

                return 5;
            }
        }

        update(0);

        texto.setString(std::to_string(vacunasRecolectadas));
        window.draw(_sprite);
        window.draw(vacuna);
        window.draw(texto);

        window.display();

    }

    vacuna.~Vacuna();

    return 1;

}

bool Tamagotchi::Limpiar(sf::RenderWindow& window)
{

    Jabon jabon;
    int jabonesRecolectados = 0;

    _sprite.setPosition(300,1);


    sf::Font font;
    font.loadFromFile("Valoon.ttf");

    sf::Text texto;

    texto.setFont(font);
    texto.setFillColor(sf::Color::White);
    texto.setPosition(350,10);

    jabon.respawn();


    while(jabonesRecolectados < 5)
    {


        window.clear();

        if(isCollision(jabon))
        {
            jabonesRecolectados++;
            jabon.respawn();

            if(jabonesRecolectados == 5)
            {

                return true;
            }
        }

        update(0);

        texto.setString(std::to_string(jabonesRecolectados));
        window.draw(_sprite);
        window.draw(jabon);
        window.draw(texto);

        window.display();

    }

    jabon.~Jabon();

    return false;

}

bool Tamagotchi::Dormir(sf::RenderWindow& window)
{
    sf::Sprite _spriteDormilon;
    sf::Texture _textureDormilon;

    _textureDormilon.loadFromFile("dormilon.png");
    _spriteDormilon.setTexture(_textureDormilon);
    _spriteDormilon.setOrigin(_spriteDormilon.getGlobalBounds().width/2, _spriteDormilon.getGlobalBounds().height/2);
    _spriteDormilon.setPosition(350,350);



    window.clear();
    window.draw(_spriteDormilon);
    window.display();
    Sleep(5000);


    return true;
}
void Tamagotchi::Morir(sf::RenderWindow& window)
{
    sf::Sprite _spriteMuerte;
    sf::Texture _textureMuerte;

    sf::Sprite _spriteGameOver;
    sf::Texture _textureGameOver;

    _textureMuerte.loadFromFile("muerte.png");
    _spriteMuerte.setTexture(_textureMuerte);
    _spriteMuerte.setOrigin(_spriteMuerte.getGlobalBounds().width/2, _spriteMuerte.getGlobalBounds().height/2);
    _spriteMuerte.setPosition(370,150);


    _textureGameOver.loadFromFile("gameover.png");
    _spriteGameOver.setTexture(_textureGameOver);
    _spriteGameOver.setOrigin(_spriteGameOver.getGlobalBounds().width/2, _spriteGameOver.getGlobalBounds().height/2);
    _spriteGameOver.setPosition(370,350);


    window.clear();
    window.draw(_spriteMuerte);
    window.draw(_spriteGameOver);
    window.display();
    Sleep(5000);

    window.close();

}

bool Tamagotchi::JugarSnake(sf::RenderWindow& window)
{
    //CabezaSnake cabeza;
    int manzanasRecolectadas = 0, tamVecCuerpo = 5;
    Manzana m;
    CuerpoSnake cuerpo[30];
    CuerpoSnake c;
    //cuerpo = new CuerpoSnake[tamVecCuerpo];
    bool primerVuelta = true;


    bool gameOver = false, left = false, right = false, down = false, up = false;


    sf::Font font;
    font.loadFromFile("Valoon.ttf");

    sf::Text texto;

    texto.setFont(font);
    texto.setFillColor(sf::Color::White);
    texto.setPosition(350,10);


    m.respawn();

    for(int i = 0; i < tamVecCuerpo; i++) //guarda el objeto c en cada una de las posiciones del vector
    {
        cuerpo[i] = c;

    }

    int x = 80, y = 350;

    for(int j = 0; j < tamVecCuerpo; j++)
    {

        cuerpo[j].setearPosicionInicial(x, y);

        x-=35;

    }



    while(gameOver == false)
    {
        window.clear();



        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && right == false) //despues de ir a la izquierda tiene que ir si o si para arriba o para abajo, no a la derecha
        {
            left = true;
            right = false;
            down = false;
            up = false;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && left == false)
        {
            left = false;
            right = true;
            down = false;
            up = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && up == false)
        {
            left = false;
            right = false;
            down = true;
            up = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && down == false)
        {
            left = false;
            right = false;
            down = false;
            up = true;
        }

        if(left)
        {
            cuerpo[0].moveLeft();
        }
        else if(right)
        {
            cuerpo[0].moveRight();

        }
        else if(down)
        {
            cuerpo[0].moveDown();

        }
        else if(up)
        {
           cuerpo[0].moveUp();

        }

       for(int j=tamVecCuerpo;j>0;j--){

            int x = cuerpo[j-1].getPositionX();
            int y = cuerpo[j-1].getPositionY();
            cuerpo[j].setearPosicion(x,y);
       }

       if(cuerpo[0].isCollision(m))
        {
            manzanasRecolectadas++;

            cuerpo[0].setVelocity(0.5);

            if(manzanasRecolectadas == 20)
            {
                return true;
            }

                tamVecCuerpo++;


            m.respawn();

        }

        for(int b = 5; b < tamVecCuerpo; b++){

            if(cuerpo[0].getPositionX() == cuerpo[b].getPositionX() && cuerpo[0].getPositionY() == cuerpo[b].getPositionY()){ // Choque consigo mismo
                return false;
            }

        }


        gameOver = cuerpo[0].choqueConBordes();

        texto.setString(std::to_string(manzanasRecolectadas));
        window.draw(m);
        window.draw(texto);


        for(int i = 0; i < tamVecCuerpo; i ++)
        {
            window.draw(cuerpo[i]);

        }


        window.display();

         Sleep(100);

         primerVuelta = false;


    }


        return false;


   // delete cuerpo;
}

void Tamagotchi::llenarVecCuerpo(CuerpoSnake *vecCuerpo, int tam, CuerpoSnake agregarParte)
{
    for(int i = 0; i < tam; i++)
    {
        vecCuerpo[i] = agregarParte;
    }
}










