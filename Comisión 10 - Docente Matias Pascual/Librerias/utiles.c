#include <windows.h>

void gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(int _color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
}

void getColors()
{
    for(int i = 0; i < 255; i++)
    {
        color(i);
        printf("%i :  ABCDE abcde 1234 |@#&          \n", i);
    }

    color(7);
}
