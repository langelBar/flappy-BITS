#include <windows.h>
#include "basics.h"

basics::basics()
{

}

void basics::gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
void basics::changeColor(int k){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}

void basics::changeScreen()
{
    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 100, 30};
    /*
    SHORT Left;
    SHORT Top;
    SHORT Right;
    SHORT Bottom;
    */
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
}

void basics::disableCursor()
{
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    cci.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
