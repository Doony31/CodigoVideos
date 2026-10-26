/*
 * ============================================================================
 * ENUNCIADO:
 *
 * Implementar un sistema de reproductor de música utilizando una estructura
 * de datos lineal (Lista Doblemente Enlazada) que cumpla con los siguientes
 * requerimientos:
 *
 * 1. Visualización:
 *    - Permitir consultar en todo momento qué canción se está escuchando actualmente
 *
 * 2. Inserción:
 *    - Agregar nuevas canciones al final de la lista de reproducción.
 *
 * 3. Navegación:
 *    - Avanzar a la siguiente canción de la lista.
 *    - Retroceder a la canción anterior de la lista.
 *
 * 4. Eliminación:
 *    - Eliminar de la lista de reproducción la canción que se está escuchando actualmente
 * 
 * ============================================================================
 */

#include <iostream>
#include <string>

using namespace std;

class Cancion {
private:
    string titulo;
    string artista;

public:
    Cancion(string t = "", string a = "") : titulo(t), artista(a) {}

    void mostrar() { cout << titulo << " (" << artista << ")"; }
};

template <typename T>
struct Nodo {
    T dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(T valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
class ListaDoble {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    Nodo<T>* cancionActual;

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr), cancionActual(nullptr) {}

    ~ListaDoble() {
        Nodo<T>* aux = cabeza;
        while (aux != nullptr) {
            Nodo<T>* nodoAEliminar = aux;
            aux = aux->siguiente;
            delete nodoAEliminar;
        }
        cabeza = cola = cancionActual = nullptr;
    }

    void mostrarActual() {
        if (cancionActual != nullptr) {
            cout << ">> En reproduccion: ";
            cancionActual->dato.mostrar();
            cout << "\n";
        }
    }

    void agregarFinal(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (estaVacio()) {
            cabeza = cola = cancionActual = nuevoNodo;
        }
        else {
            cola->siguiente = nuevoNodo;
            nuevoNodo->anterior = cola;
            cola = nuevoNodo;
        }
    }

    void siguiente() {
        if (cancionActual && cancionActual->siguiente != nullptr) {
            cancionActual = cancionActual->siguiente;
            mostrarActual();
        }
        else {
            cout << "[Fin de la lista] No hay elemento siguiente.\n";
        }
    }

    void anterior() {
        if (cancionActual && cancionActual->anterior != nullptr) {
            cancionActual = cancionActual->anterior;
            mostrarActual();
        }
        else {
            cout << "[Inicio de la lista] No hay elemento anterior.\n";
        }
    }

    void eliminarActual() {
        if (cancionActual == nullptr) return;

        Nodo<T>* nodoAEliminar = cancionActual;
        cout << "Eliminando elemento actual: ";
        nodoAEliminar->dato.mostrar();
        cout << "\n";

        // Caso 1: Único elemento en la lista
        if (cabeza == cola) {
            cabeza = cola = cancionActual = nullptr;
        }
        // Caso 2: El elemento es la cabeza
        else if (nodoAEliminar == cabeza) {
            cabeza = cabeza->siguiente;
            cabeza->anterior = nullptr;
            cancionActual = cabeza;
        }
        // Caso 3: El elemento es la cola
        else if (nodoAEliminar == cola) {
            cola = cola->anterior;
            cola->siguiente = nullptr;
            cancionActual = cola;
        }
        // Caso 4: Elemento intermedio
        else {
            nodoAEliminar->anterior->siguiente = nodoAEliminar->siguiente;
            nodoAEliminar->siguiente->anterior = nodoAEliminar->anterior;
            cancionActual = nodoAEliminar->siguiente;
        }

        delete nodoAEliminar;
    }

    bool estaVacio() { return cabeza == nullptr; }

};

void limpiarPantalla() {
    system("pause>0");
    system("cls");
}

int main() {
    ListaDoble<Cancion>* miPlaylist = new ListaDoble<Cancion>();

    cout << "--- Agregando pistas a la lista ---\n";
    miPlaylist->agregarFinal(Cancion("Cancion 1", "Artista 1"));
    miPlaylist->agregarFinal(Cancion("Cancion 2", "Artista 2"));
    miPlaylist->agregarFinal(Cancion("Cancion 3", "Artista 3"));
    miPlaylist->agregarFinal(Cancion("Cancion 4", "Artista 4"));
    limpiarPantalla();


    int opcion = 0;
    string titulo, artista;

    do {
        cout << "==============================\n";
        cout << "    REPRODUCTOR DE MUSICA     \n";
        cout << "==============================\n";
        miPlaylist->mostrarActual();
        cout << "------------------------------\n";
        cout << "1. Mostrar cancion actual\n";
        cout << "2. Agregar nueva cancion \n";
        cout << "3. Ir a la cancion siguiente\n";
        cout << "4. Ir a la cancion anterior\n";
        cout << "5. Eliminar cancion actual\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: 
            miPlaylist->mostrarActual();
            limpiarPantalla();
            break;
        case 2:
            cin.ignore();
            cout << "Ingresa el titulo de la cancion: ";
            getline(cin, titulo);
            cout << "Ingresa el artista: ";
            getline(cin, artista);
            miPlaylist->agregarFinal(Cancion(titulo, artista));
            cout << "Cancion agregada exitosamente.\n";
            limpiarPantalla();
            break;
        case 3:
            miPlaylist->siguiente();
            limpiarPantalla();
            break;
        case 4:
            miPlaylist->anterior();
            limpiarPantalla();
            break;
        case 5:
            miPlaylist->eliminarActual();
            limpiarPantalla();
            break;
        case 0:
            cout << "Saliendo del reproductor...\n";
            break;
        default:
            cout << "Opcion no valida. Intenta de nuevo.\n";
            limpiarPantalla();
            break;
        }
    } while (opcion != 0);

    system("pause>0");
    return 0;
}