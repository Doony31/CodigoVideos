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

    string NPC[3];

    NPC[0] = " o ";
    NPC[1] = "/|\\";
    NPC[2] = "/ \\";


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
            if (tecla == 'E') {
                if ((x >= 36 && x <= 44) && (y >= 16 && y <= 21)) {
                    Console::SetCursorPosition(34, 22);
                    cout << "Hola soy un NPC";
                    // Agrega lo que quieras
                }
            }
        }




        // Dibujar

        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(x, y + i);
            cout << personaje[i];
        }

        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(39, 19 + i);
            cout << NPC[i];
        }
        _sleep(40);

    }


    system("pause>0");
    return 0;
}