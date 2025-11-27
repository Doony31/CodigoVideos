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

    int x2;
    int y2;

    string personaje[3];

    personaje[0] = " o ";
    personaje[1] = "/|\\";
    personaje[2] = "/ \\";

    string enemigo[3];

    enemigo[0] = " o ";
    enemigo[1] = "/|\\";
    enemigo[2] = "/ \\";

    bool activo = false;

    while (true) {

        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(76, 19 + i);
            cout << "   ";
        }


        // Borrar
        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(x, y + i);
            cout << "   ";
        }

        if (activo == true) {
            Console::SetCursorPosition(x2, y2);
            cout << " ";
        }


        // Mover

        if (_kbhit()) {
            char tecla = getch();
            if (tecla == arriba) y--;
            if (tecla == abajo) y++;
            if (tecla == izquierda) x--;
            if (tecla == derecha) x++;
            // D mayuscula
            if (tecla == 'D') {
                if (activo == false){
                    x2 = x + 3;
                    y2 = y + 1;
                    activo = true;
                }
            }
        }

        if (activo == true) {
            x2++;
            if (x2 == 80) {
                activo = false;
            }
        }

        //// Colisiones
        if (activo == true) {
            if ((x2 >= 76 && x2 <= 76 + 2) && (y2 >= 19 && y2 <= 19 + 2)) break;
        }


        // Dibujar

        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(x, y + i);
            cout << personaje[i];
        }

        if (activo == true) {
            Console::SetCursorPosition(x2, y2);
            cout << "*";
        }

        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(76, 19 + i);
            cout << enemigo[i];
        }

        _sleep(40);

    }

    Console::SetCursorPosition(40, 20);
    cout << "Ganaste";

    system("pause>0");
    return 0;
}