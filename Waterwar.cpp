#include <stdlib.h>
#include <string>
#include "TXLib.h"

using namespace std;
void paintField(int x, int y);
void paintHeart(int x, int y);


int main()
{
    setlocale(LC_ALL, "RUSSIAN");//TODO: вся программа выходит на ломанном языке, хотя этот оператор стоит

    int xHeart = 3;
    int yHeart = 60;
    txCreateWindow(800, 600);
    txSetFillColour(RGB(144, 238, 144));
    txRectangle(0, 0, 800, 600);
    txSetColour(TX_BLACK);
    txLine(400, 170, 400, 600);
    txLine(0, 170, 800, 170);
    txRectangle(600, 100, 790, 150);
    paintField(50, 250);
    paintField(450, 250);
    txTextOut(150, 200, "МОЕ ПОЛЕ");
    txTextOut(530, 200, "ПОЛЕ ПРОТИВНИКА");
    txTextOut(3, 10, "Перед тобою два поля: твоё и противника. На поле противника некоторые клетки с кораблями");
    txTextOut(3, 25, "Твоя задача найти все корабли. Если угадываешь местонахождение корабля, то получаешь");
    txTextOut(3, 40, "3 сердечка, если нет, то отнимается одно. Удачи!");
    txTextOut(3, 55, "P.S. Рядом могут стоять 2 корабля");
    paintHeart(xHeart, yHeart);

    struct Ship
    {
        int condition;
        RECT place;
    };

    Ship array[10][10];
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
        {
            int a = rand()%2;//состояние
            int pointX = 450;
            int pointY = 250;
            array[i][j].place = {pointX+30*j, pointY+30*i, pointX+30*j+30, pointY+30*i+30};
            array[i][j].condition = a;
        }
//TODO: здесь выдаёт ошибку warning: extended initializer lists only available with -std=c++11 or -std=gnu++11|
int life = 5;
   do
    {

        if (txMouseButtons() & 1)
        {
            for (int i=0; i<10; i++)
                for (int j=0; j<10; j++)
                {
                    if (In(txMousePos(), array[i][j].place))
                    {
                        if (array[i][j].condition == 1)
                        {
                            txRectangle(600, 100, 790, 150);
                            txTextOut(610, 125, "Ты убил корабль!");
                            array[i][j].condition = 2;
                            for(int i=0; i<3; i++)
                            {
                                paintHeart(xHeart+55, yHeart);
                                xHeart = xHeart+55;
                                life++;
                            }
                        }
                        else if (array[i][j].condition == 0)
                        {
                            txRectangle(600, 100, 790, 150);
                            txTextOut(610, 125, "Ты промазал!");
                            life = life - 1;//TODO: есть ли life--, если есть life++?

                        }
                        else if (array[i][j].condition == 2)
                        {
                            txRectangle(600, 100, 790, 150);
                            txTextOut(610, 125, "Ты уже сюда стрелял!");
                        }

                    }
                }
        }
    }
        while(life>0);
    //TODO: выходит ошибка error: expected primary-expression before '}' token|
}
    void paintField(int x, int y)
    {
        txSetColour(TX_BLACK);
        txSetFillColour(TX_LIGHTBLUE);
        txRectangle(x, y, x+300, y+300);
        for(int i=1; i<10; i++)
        {
            txLine(x+30*i, y, x+30*i, y+300);
        }
        for(int i=1; i<11; i++)
        {
            txLine(x, y+30*i, x+300, y+30*i);
        }

    }
    void paintHeart (int x, int y)
    {
        txSetColour(TX_RED);
        txSetFillColour(TX_RED);
        POINT heart[16] = {{x, y}, {x+20, y}, {x+20, y+10}, {x+30, y+10}, {x+30, y}, {x+50, y}, {x+50, y+20}, {x+40, y+20}, {x+40, y+30}, {x+30, y+30}, {x+30, y+40}, {x+20, y+40}, {x+20, y+30}, {x+10, y+30}, {x+10, y+20}, {x, y+20}};
        txPolygon(heart, 16);
    }



