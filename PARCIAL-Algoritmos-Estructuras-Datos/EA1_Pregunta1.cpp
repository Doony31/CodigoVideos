
#include <iostream>
#include <string>

using namespace std;

int contadorPalabras(string palabra) {
    if (palabra.empty()) return 0;

    if (palabra[0] == ' ') {
        palabra.erase(palabra.begin());
        return contadorPalabras(palabra);
    }

    palabra.erase(palabra.begin());
    if (palabra.empty() || palabra[0] == ' ')
        return 1 + contadorPalabras(palabra);
    return contadorPalabras(palabra);
}

int main() {

    string palabra; /*= "El esfuerzo de hoy es el éxito de mañana";*/

    cout << "Ingrese la palabra: ";
    getline(cin, palabra);

    cout << contadorPalabras(palabra) << endl;

    system("pause>0");
    return 0;
}
