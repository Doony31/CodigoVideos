
// Pide como parametro el mapa que hiciste.
// Si se te complica solo copia lo de adentro y realiza tal cual como el video
void imprimirEscenarios(int sprite[32][105]) {
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 105; j++) {
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
}