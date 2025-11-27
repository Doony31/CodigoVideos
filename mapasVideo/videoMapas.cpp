#include "pch.h"
#include "iostream"
#include "conio.h"
#include "string"

#define arriba 72
#define abajo 80
#define derecha 77
#define izquierda 75

using namespace System;
using namespace std;

// funcion que cambia del fondo de los caracteres
void colorFondo(int opc) {
    switch (opc) {
    case 0: Console::BackgroundColor = ConsoleColor::Black; break;
    case 1: Console::BackgroundColor = ConsoleColor::DarkBlue; break;
    case 2: Console::BackgroundColor = ConsoleColor::DarkGreen; break;
    case 3: Console::BackgroundColor = ConsoleColor::DarkRed; break;
    case 4: Console::BackgroundColor = ConsoleColor::White; break;
    case 5: Console::BackgroundColor = ConsoleColor::DarkYellow; break;
    case 6: Console::BackgroundColor = ConsoleColor::Gray; break;
    case 7: Console::BackgroundColor = ConsoleColor::DarkGray; break;
    case 8: Console::BackgroundColor = ConsoleColor::Blue; break;
    case 9:  Console::BackgroundColor = ConsoleColor::Green; break;
    case 10: Console::BackgroundColor = ConsoleColor::Cyan; break;
    case 11: Console::BackgroundColor = ConsoleColor::Red; break;
    case 12: Console::BackgroundColor = ConsoleColor::Magenta; break;
    case 13: Console::BackgroundColor = ConsoleColor::Yellow; break;
    case 14: Console::BackgroundColor = ConsoleColor::DarkMagenta; break;
    default: Console::BackgroundColor = ConsoleColor::Black; break;
    }
}

// funcion que cambia el color de los caracteres
void color(int opc) {
    switch (opc) {
    case 0: Console::ForegroundColor = ConsoleColor::Black; break;
    case 1: Console::ForegroundColor = ConsoleColor::DarkBlue; break;
    case 2: Console::ForegroundColor = ConsoleColor::DarkGreen; break;
    case 3: Console::ForegroundColor = ConsoleColor::DarkRed; break;
    case 4: Console::ForegroundColor = ConsoleColor::White; break;
    case 5: Console::ForegroundColor = ConsoleColor::DarkYellow; break;
    case 6: Console::ForegroundColor = ConsoleColor::Gray; break;
    case 7: Console::ForegroundColor = ConsoleColor::DarkGray; break;
    case 8: Console::ForegroundColor = ConsoleColor::Blue; break;
    case 9: Console::ForegroundColor = ConsoleColor::Green; break;
    case 10: Console::ForegroundColor = ConsoleColor::Cyan; break;
    case 11: Console::ForegroundColor = ConsoleColor::Red; break;
    case 12: Console::ForegroundColor = ConsoleColor::Magenta; break;
    case 13: Console::ForegroundColor = ConsoleColor::Yellow; break;
    case 14: Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
    default: Console::BackgroundColor = ConsoleColor::Black; break;
    }
}

int main() {

    Console::SetWindowSize(80, 40);
    Console::CursorVisible = false;

    string personaje[3];

    personaje[0] = " o ";
    personaje[1] = "/|\\";
    personaje[2] = "/ \\";


    // cyan
    int c = 10;
    // red
    int r = 11;

    int m = 12;

    int y = 13;

    int d = 14;

    int x1 = 1;
    int y1 = 0;

    int mapa[20][20] = {
    {c,5,5,5,c,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {c,y,y,y,c,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {c,5,5,5,c,c,c,c,c,0,0,0,0,0,0,0,0,0,0,0},
    {c,y,y,y,y,y,y,y,c,0,0,0,0,0,0,0,0,0,0,0},
    {c,5,5,5,5,5,5,5,c,0,0,0,0,0,0,0,0,0,0,0},
    {c,y,y,y,y,y,y,y,c,0,0,0,0,0,0,0,0,0,0,0},
    {c,c,c,c,c,5,5,5,c,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,c,y,y,y,c,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,c,5,5,5,c,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,c,y,y,y,c,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,c,5,5,5,c,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,c,y,y,y,c,c,c,c,c,c,c,c,c,c,0,0},
    {0,0,0,0,c,5,5,5,5,5,5,5,5,5,5,5,5,c,0,0},
    {0,0,0,0,c,y,y,y,y,y,y,y,y,y,y,y,y,c,0,0},
    {0,0,0,0,c,5,5,5,5,5,5,5,5,5,5,5,5,c,0,0},
    {0,0,0,0,c,c,c,c,c,c,c,c,c,c,y,y,y,c,c,c},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,c,5,5,5,5,5,5},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,c,y,y,y,y,y,y},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,c,5,5,5,5,5,5},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,c,c,c,c,c,c,c},
    };


    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            Console::SetCursorPosition(j, i);

            if (sprite[i][j] == 0) color(0);
            if (sprite[i][j] == 1) color(1);
            if (sprite[i][j] == 2) color(2);
            if (sprite[i][j] == 3) color(3);
            if (sprite[i][j] == 4) color(4);
            if (sprite[i][j] == 5) color(5);
            if (sprite[i][j] == 6) color(6);
            if (sprite[i][j] == 7) color(7);
            if (sprite[i][j] == 8) color(8);
            if (sprite[i][j] == 9) color(9);
            if (sprite[i][j] == 10) color(10);
            if (sprite[i][j] == 11) color(11);
            if (sprite[i][j] == 12) color(12);
            if (sprite[i][j] == 13) color(13);
            if (sprite[i][j] == 14) color(14);
            if (sprite[i][j] == 15) color(15);
            cout << char(219);
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        color(0);

        colorFondo(mapa[y1 + i][x1 + i]);
        Console::SetCursorPosition(x1, y1 + i);
        cout << personaje[i];
    }

    while (true) {

        for (int i = 0; i < 3; i++) {
            color(0);
            colorFondo(mapa[y1 + i][x1 + i]);
            Console::SetCursorPosition(x1, y1 + i);
            cout << "   ";
        }

        if (_kbhit()) {
            char tecla = getch();
            if (tecla == derecha) {
                if ((mapa[y1][x1 + 3] == y || mapa[y1][x1 + 3] == 5) &&
                    (mapa[y1 + 1][x1 + 3] == y || mapa[y1 + 1][x1 + 3] == 5) &&
                    (mapa[y1 + 2][x1 + 3] == y || mapa[y1 + 2][x1 + 3] == 5))
                {
                    x1++;
                }
            }

            if (tecla == izquierda) {
                if ((mapa[y1][x1 - 1] == y || mapa[y1][x1 - 1] == 5) &&
                    (mapa[y1 + 1][x1 - 1] == y || mapa[y1 + 1][x1 - 1] == 5) &&
                    (mapa[y1 + 2][x1 - 1] == y || mapa[y1 + 2][x1 - 1] == 5))
                {
                    x1--;
                }
            }

            if (tecla == arriba) {
                if ((mapa[y1 - 1][x1] == y || mapa[y1 - 1][x1] == 5) &&
                    (mapa[y1 - 1][x1 + 1] == y || mapa[y1 - 1][x1 + 1] == 5) &&
                    (mapa[y1 - 1][x1 + 2] == y || mapa[y1 - 1][x1 + 2] == 5))
                {
                    y1--;
                }
            }

            if (tecla == abajo) {
                if ((mapa[y1 + 3][x1] == y || mapa[y1 + 3][x1] == 5) &&
                    (mapa[y1 + 3][x1 + 1] == y || mapa[y1 + 3][x1 + 1] == 5) &&
                    (mapa[y1 + 3][x1 + 2] == y || mapa[y1 + 3][x1 + 2] == 5))
                {
                    y1++;
                }
            }

        }

        for (int i = 0; i < 3; i++) {
            color(0);
            colorFondo(mapa[y1 + i][x1 + i]);
            Console::SetCursorPosition(x1, y1 + i);
            cout << personaje[i];
        }

        _sleep(60);

    }

    system("pause>0");
    return 0;
}
