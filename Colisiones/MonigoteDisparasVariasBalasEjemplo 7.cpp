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

    const int balas = 5;
    int posX[balas];
    int posY[balas];
    bool activo[balas];

    int x = 40;
    int y = 20;

    string personaje[3];

    personaje[0] = " o ";
    personaje[1] = "/|\\";
    personaje[2] = "/ \\";

    string enemigo[3];

    enemigo[0] = " @ ";
    enemigo[1] = "/|\\";
    enemigo[2] = "/ \\";

    for (int i = 0; i < balas; i++) {
        activo[i] = false;
    }


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

        for (int i = 0; i < balas; i++) {
            if (activo[i] == true) {
                Console::SetCursorPosition(posX[i], posY[i]);
                cout << " ";
            }
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
                for (int i = 0; i < balas; i++) {
                    if (activo[i] == false) {
                        posX[i] = x + 3;
                        posY[i] = y + 1;
                        activo[i] = true;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < balas; i++) {
            if (activo[i] == true) {
                posX[i]++;
                if (posX[i] == 80) {
                    activo[i] = false;
                }
            }
        }

        //// Colisiones
        for (int i = 0; i < balas; i++) {
            if (activo[i] == true) {
                if ((posX[i] >= 76 && posX[i] <= 76 + 2) && (posY[i] >= 19 && posY[i] <= 19 + 2)) {
                    Console::Clear();
                    Console::SetCursorPosition(40, 20);
                    cout << "Ganaste";
                    system("pause>0");
                    return 0;
                };
            }
        }


        // Dibujar

        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(x, y + i);
            cout << personaje[i];
        }

        for (int i = 0; i < balas; i++) {
            if (activo[i] == true) {
                Console::SetCursorPosition(posX[i], posY[i]);
                cout << "*";
            }
        }

        for (int i = 0; i < 3; i++) {
            Console::SetCursorPosition(76, 19 + i);
            cout << enemigo[i];
        }

        _sleep(40);

    }

    system("pause>0");
    return 0;
}