#include <stdlib.h>
#include <string>
#include "TXLib.h"
#include <ctime>

using namespace std;
void paintField(int x, int y);
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    txCreateWindow(800, 600);
    txSetFillColour(RGB(144, 238, 144));
    txRectangle(0, 0, 800, 600);
    txSetColour(TX_BLACK);
    txLine(400, 170, 400, 600);
    txLine(0, 170, 800, 170);
    txRectangle(600, 100, 790, 150);
    paintField(50, 250);
    paintField(450, 250);
    txTextOut(150, 200, "MY FIELD");
    txTextOut(530, 200, "OPPONENT'S FIELD");
    txTextOut(3, 10, "You can see two fields: your and computer's. On the second field located a lot of ship.");
    txTextOut(3, 25, "You must find all ship. If you found ship, you will see an article <You found it!!!> ");
    txTextOut(3, 40, "If you didn't find ship, you will see <You lose(> and you lose one your life");
    txTextOut(3, 55, "You have only one life at the beginning! There are can be more than two ship near.");

    struct Ship
    {
        int condition;
        RECT place;
    };

    int life = 1;
    Ship array[10][10];
    srand(time(NULL));
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
        {
            int a = rand()%2;//состояние
            int pointX = 450;
            int pointY = 250;
            array[i][j].place = {pointX+30*i, pointY+30*j, pointX+30*i+30, pointY+30*j+30};
            array[i][j].condition = a;
        }

    while(txMouseButtons() !=3 || life>0)
    {
        if (txMouseButtons() & 1 && life>0)
        {
            for (int i=0; i<10; i++)
                for (int j=0; j<10; j++)
                {
                    if (In(txMousePos(), array[i][j].place))
                    {
                        if (array[i][j].condition == 1)
                        {
                            txSetFillColour(RGB(144, 238, 144));
                            txSetColour(TX_BLACK);
                            txRectangle(600, 100, 790, 150);
                            txTextOut(610, 125, "You found it!!!");
                            txSetColour(TX_RED);
                            txTextOut(txMouseX()-400, txMouseY()-3, "X");
                            life = life+1;
                        }
                        else if (array[i][j].condition == 0)
                        {
                            txSetFillColour(RGB(144, 238, 144));
                            txSetColour(TX_BLACK);
                            txRectangle(600, 100, 790, 150);
                            txTextOut(610, 125, "You lose( ");
                            txSetColour(TX_WHITE);
                            txTextOut(txMouseX()-400, txMouseY()-3, "X");
                            life = life-1;
                        }
                    }
                }
        }
        if (txMouseButtons() & 1 && life<=0)
        {
            txSetColour(TX_BLACK);
            txRectangle(600, 100, 790, 150);
            txTextOut(610, 125, "You lose! GAME OVER!");
        }

    }
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




