#include "CabezaSnake.h"
#include "time.h"

CabezaSnake::CabezaSnake()
{
    _textureCabezaSnake.loadFromFile("cabezasnake.png");
    _spriteCabezaSnake.setTexture(_textureCabezaSnake);
    _spriteCabezaSnake.setOrigin(_spriteCabezaSnake.getGlobalBounds().width/2, _spriteCabezaSnake.getGlobalBounds().height/2);
    _velocityCabeza = 4;
    _spriteCabezaSnake.setPosition(100,350);
}

CabezaSnake::~CabezaSnake()
{
    //dtor
}


void CabezaSnake::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteCabezaSnake, states);
}

sf::FloatRect CabezaSnake::getBounds()const
{
    return _spriteCabezaSnake.getGlobalBounds();
}

void CabezaSnake::moveLeft()
{
    _spriteCabezaSnake.move(-_velocityCabeza,0);
    _spriteCabezaSnake.setScale(-1,1);
}
void CabezaSnake::moveRight()
{
    _spriteCabezaSnake.move(_velocityCabeza,0);
    _spriteCabezaSnake.setScale(1,1);

}
void CabezaSnake::moveUp()
{
    _spriteCabezaSnake.move(0,-_velocityCabeza);
    _spriteCabezaSnake.setScale(1,1);

}
void CabezaSnake::moveDown()
{
    _spriteCabezaSnake.move(0,_velocityCabeza);
    _spriteCabezaSnake.setScale(-1,-1);

}

bool CabezaSnake::choqueConBordes()
{

    if(_spriteCabezaSnake.getGlobalBounds().left < 0)
    {
        return true;
    }

    if(_spriteCabezaSnake.getGlobalBounds().top < 0)
    {
        return true;
    }

    if(_spriteCabezaSnake.getGlobalBounds().left + _spriteCabezaSnake.getGlobalBounds().width > 800)
    {
        return true;
    }

    if(_spriteCabezaSnake.getGlobalBounds().top + _spriteCabezaSnake.getGlobalBounds().height > 600)
    {
        return true;

    }
}

int CabezaSnake::getPositionX()
{
    return _spriteCabezaSnake.getPosition().x;
}

int CabezaSnake::getPositionY()
{
    return _spriteCabezaSnake.getPosition().y;
}

int N=30,M=20;
int size=16;
int w = size*N;
int h = size*M;
int fru = 0;

int dir,num=4;

struct Snake
{ int x,y;}  s[100];

struct Fruit
{ int x,y;} f;

void Tick()
{
    for (int i=num; i>0; --i)
    {
        s[i].x=s[i-1].x;
        s[i].y=s[i-1].y;
    }

    if (dir==0) s[0].y+=1;
    if (dir==1) s[0].x-=1;
    if (dir==2) s[0].x+=1;
    if (dir==3) s[0].y-=1;

    if ((s[0].x==f.x) && (s[0].y==f.y))
    {
        num++;
        fru++;
        f.x=rand()%N;
        f.y=rand()%M;
    }

    /// aca son las colisiones
    if (s[0].x>N) s[0].x=0;
    if (s[0].x<0) s[0].x=N;
    if (s[0].y>M) s[0].y=0;
    if (s[0].y<0) s[0].y=M;

    for (int i=1; i<num; i++)
        if (s[0].x==s[i].x && s[0].y==s[i].y)  num=i;
}

bool CabezaSnake::jugar(sf::RenderWindow& snakeWindow){

    snakeWindow.clear();
    srand(time(0));


    sf::Texture t1,t2;
    t1.loadFromFile("pepe/images/white.png");
    t2.loadFromFile("pepe/images/red.png");

    sf::Sprite sprite1(t1);
    sf::Sprite sprite2(t2);

    sf::Clock clock;
    float timer=0, delay=0.1;

    f.x=10;
    f.y=10;

    bool gameOver = false;

    while (!gameOver)
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        sf::Event e;
        while (snakeWindow.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                snakeWindow.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) dir=1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) dir=2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) dir=3;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) dir=0;

        if (timer>delay) {timer=0; Tick();}

   ////// draw  ///////
    snakeWindow.clear();

    for (int i=0; i<N; i++)
      for (int j=0; j<M; j++)
        { sprite1.setPosition(i*size, j*size);  snakeWindow.draw(sprite1); }

    for (int i=0;i<num;i++)
        { sprite2.setPosition(s[i].x*size, s[i].y*size);  snakeWindow.draw(sprite2); }

    sprite2.setPosition(f.x*size, f.y*size);  snakeWindow.draw(sprite2);

    snakeWindow.display();
    }

    return true;

}
