#include <stdlib.h>
#include <string>
#include "TXLib.h"

using namespace std;
void paintField(int x, int y);
void paintHeart(int x, int y);
//void paintShip;

int main()
{
    txCreateWindow(800, 600);
    txSetFillColour(RGB(144, 238, 144));
    txRectangle(0, 0, 800, 600);
    txSetColour(TX_BLACK);
    txLine(400, 170, 400, 600);
    txLine(0, 170, 800, 170);
    paintField(50, 250);
    paintField(450, 250);
    txTextOut(150, 200, "МОЕ ПОЛЕ");
    txTextOut(530, 200, "ПОЛЕ ПРОТИВНИКА");
    txTextOut(3, 10, "Перед тобою два поля: твоё и противника. На поле противника некоторые клетки с кораблями");
    txTextOut(3, 25, "Твоя задача найти все 10 кораблей. Если угадываешь местонахождение корабля, то получаешь");
    txTextOut(3, 40, "3 сердечка, если нет, то отнимается одно. Удачи!");

    const int numRows = 10;
    const int numCols = 10;
    int field[numRows][numCols] = {0};

    for (int row = 0; row < numRows; ++row)
        for (int col = 0; col < numCols; ++col)
            field[row][col] = row * col;

    do
    {
        if (txMouseButtons() & 1)
        {
            if (txMousePos() == field[0][0])//TODO: необходимо, чтобы когда пользователь нажимал кнопку мыши, координаты нажатия сравнивались с координатами ячейки. Как совместить нарисованную ячейку с ячейкой массива?
            {


            }
        }
    }
    while(life>0)


}
void paintField(int x, int y)
{
    txSetColour(TX_BLACK);
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
/*void paintShip  //TODO: какие аргументы нужно сюда подставить? Функция присваивает 1(ставит корабль), если в клетке 0(не стоит корабль)
{
    for(int i=0; i<10; i++)
    {
        int a = rand()%10 + 1;
        int b = rand()%10 + 1;
        if (field[a][b] == 0)
            field[a][b] = 1;
        else
        {
            do
            {
                a = rand()%10 + 1;
                b = rand()%10 + 1;
            }
            while (field[a][b] == 0)
            }
    }

}*/
