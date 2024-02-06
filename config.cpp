#include <windows.h>

void changeScreen(){
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

void disableCursor(){
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    cci.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
