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

    string personaje[3];

    personaje[0] = " o ";
    personaje[1] = "/|\\";
    personaje[2] = "/ \\";


    while (true) {


        // Borrar
        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(x, y + i);
            cout << "   ";
        }


        // Mover

        if (_kbhit()) {
            char tecla = getch();
            if (tecla == arriba) y--;
            if (tecla == abajo) y++;
            if (tecla == izquierda) x--;
            if (tecla == derecha) x++;
        }


        //// Colisiones
        if ((x == 77) && (y == 37)) {
            x = 1;
            y = 1;
        }



        // Dibujar

        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(x, y + i);
            cout << personaje[i];
        }


        _sleep(40);

    }


    system("pause>0");
    return 0;
}