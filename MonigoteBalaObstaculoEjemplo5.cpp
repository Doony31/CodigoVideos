#include "pch.h"
#include "iostream"
#include "conio.h"

using namespace std;
using namespace System;

#define arriba 72
#define abajo 80
#define derecha 77
#define izquierda 75

int main() {

    Console::SetWindowSize(80, 40);
    Console::CursorVisible = false;
    Console::Clear();

    int x = 70;
    int y = 19;

    string personaje[3];

    personaje[0] = " o ";
    personaje[1] = "/|\\";
    personaje[2] = "/ \\";

    int x2 = 40;
    int y2 = 39;


    while (true) {


        // Borrar
        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(x, y + i);
            cout << "   ";
        }

        Console::SetCursorPosition(x2, y2);
        cout << " ";

        // Mover

        if (_kbhit()) {
            char tecla = getch();
            if (tecla == arriba) y--;
            if (tecla == abajo) y++;
            if (tecla == izquierda) x--;
            if (tecla == derecha) x++;
        }

        if (y2 >= 1) y2--;
        if (y2 == 1) {
            y2 = 39;
        }

        // colisiones
        if ((x2 >= x && x2 <= x + 2) && (y2 >= y && y2 <= y + 2)) {
            x = 70;
            y = 19;
        };



        // Dibujar

        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(x, y + i);
            cout << personaje[i];
        }

        Console::SetCursorPosition(x2, y2);
        cout << "*";
       
        _sleep(60);

    }


    system("pause>0");
    return 0;
}