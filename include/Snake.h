#pragma once
class Snake
{
    public:
        Snake();
        void setx(int x);
        void sety(int y);
        int getx();
        int gety();

    private:
        int _x;
        int _y;
};

