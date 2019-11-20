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
    txTextOut(150, 200, "��� ����");
    txTextOut(530, 200, "���� ����������");
    txTextOut(3, 10, "����� ����� ��� ����: ��� � ����������. �� ���� ���������� ��������� ������ � ���������");
    txTextOut(3, 25, "���� ������ ����� ��� 10 ��������. ���� ���������� ��������������� �������, �� ���������");
    txTextOut(3, 40, "3 ��������, ���� ���, �� ���������� ����. �����!");

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
            if (txMousePos() == field[0][0])//TODO: ����������, ����� ����� ������������ ������� ������ ����, ���������� ������� ������������ � ������������ ������. ��� ���������� ������������ ������ � ������� �������?
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
/*void paintShip  //TODO: ����� ��������� ����� ���� ����������? ������� ����������� 1(������ �������), ���� � ������ 0(�� ����� �������)
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
