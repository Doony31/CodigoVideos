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

    int x = 40;
    int y = 20;

    int x2 = 40;
    int y2 = 39;

    while (true) {

        // Borrar
        Console::SetCursorPosition(x, y);
        cout << " ";

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

        // Colisiones
        if (x == x2 && y == y2) break;


        // Dibujar

        Console::SetCursorPosition(x, y);
        cout << "*";

        Console::SetCursorPosition(x2, y2);
        cout << "*";

        _sleep(40);

    }

    Console::SetCursorPosition(40, 20);
    cout << "Perdiste";

    system("pause>0");
    return 0;
}