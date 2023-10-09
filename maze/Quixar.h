#include <iostream>
#include <ctime> // time
#include <conio.h> 
#include <windows.h>
using namespace std;
enum Directions { LEFT = 75, RIGHT = 77, DOWN = 80, UP = 72 };
enum Colors { RED = 12, BLACK = 0, DARKBLUE = 3, YELLOW = 14, PINK = 13, BLUE = 1 };
enum Objects { HALL = 0, WALL = 1, COIN = 2, ENEMY = 3, AID = 4 };

// 1) определение (создание) функции

// ОПИСАНИЕ ФУНКЦИИ:
    // установка курсора в определённую позицию
    // + окрашивание текста в определённый цвет
    // + вывод строки текста
void SetCursor(int x, int y, int color, string text) // пример функции с 4 параметрами
{
    // дескриптор окна консоли (уникальный номер окна в консоли, нужен для того чтобы найти конкретное окно и выполнить именно над ним определённые действия)
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    // специальный структурный тип для работы с координатами (для перестановки курсора)
    COORD position;
    position.X = x; // настройка конкретных координат
    position.Y = y;
    SetConsoleCursorPosition(h, position); // установка курсора в заданную точку
    SetConsoleTextAttribute(h, color); // смена цвета
    cout << text; // вывод строки текста
    cout << "\n";
}

void takingCoin()
{
    int coins = 0;
    const int width = 60; // ширина лабиринта
    const int height = 15; // высота лабиринта
    int maze[height][width] = {};
    COORD position;
    position.X = 0;
    position.Y = 0;
    coins++; // на одну монетку подобрано больше
    maze[position.Y][position.X] = HALL; // убираем монетку из массива
    SetCursor(width + 1, 1, YELLOW, "COINS: ");
}

void hideCursor()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.bVisible = false;
    info.dwSize = 100; // 1...100
    SetConsoleCursorInfo(h, &info);
}


void chechExit()
{
    const int width = 60;
    const int height = 15;
    COORD position;
    position.X = 0;
    position.Y = 0;
    if (position.X == width - 1 and
        position.Y == height - 3)
    {
        MessageBoxA(0, "A way out of the maze has been found", "YOU WIN!!!", MB_OK);
    }
}