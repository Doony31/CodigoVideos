#include <iostream>

using namespace std;

template <typename T>
struct NodoDoble {
    T dato;
    NodoDoble<T>* siguiente;
    NodoDoble<T>* anterior;

    NodoDoble(T valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
class ListaDoble {
private:
    NodoDoble<T>* cabeza;
    NodoDoble<T>* cola;
    int longitud;

public:
    ListaDoble() : longitud(0), cabeza(nullptr), cola(nullptr) {}

    ~ListaDoble() {
        vaciar();
    }

    bool estaVacia() { return longitud == 0; }

    int obtenerLongitud() { return longitud; }

    void imprimirAdelante() {
        NodoDoble<T>* aux = cabeza;
        cout << "Cabeza -> ";
        while (aux != nullptr) {
            cout << aux->dato << " <-> ";
            aux = aux->siguiente;
        }
        cout << "nullptr\n";
    }

    void imprimirAtras() {
        NodoDoble<T>* aux = cola;
        cout << "Cola -> ";
        while (aux != nullptr) {
            cout << aux->dato << " <-> ";
            aux = aux->anterior;
        }
        cout << "nullptr\n";
    }

    NodoDoble<T>* obtenerNodo(int indice) {
        if (indice < 0 || indice >= longitud) { return nullptr; }

        NodoDoble<T>* aux = nullptr;
        if (indice < longitud / 2) {
            aux = cabeza;
            for (int i = 0; i < indice; i++) {
                aux = aux->siguiente;
            }
        }
        else {
            aux = cola;
            for (int i = longitud - 1; i > indice; i--) {
                aux = aux->anterior;
            }
        }
        return aux;
    }

    // 1. Insercion al inicio
    void agregarInicio(T valor) {
        NodoDoble<T>* nuevoNodo = new NodoDoble<T>(valor);
        if (estaVacia()) {
            cabeza = cola = nuevoNodo;
        }
        else {
            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
        longitud++;
    }

    // 2. Insercion al final
    void agregarFinal(T valor) {
        NodoDoble<T>* nuevoNodo = new NodoDoble<T>(valor);
        if (estaVacia()) {
            cabeza = cola = nuevoNodo;
        }
        else {
            nuevoNodo->anterior = cola;
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
        longitud++;
    }

    // 3. Insercion en cualquier posicion (base 0)
    void agregarEnPosicion(int indice, T valor) {
        if (indice < 0 || indice > longitud) {
            cout << "Error: Indice fuera de rango.\n";
            return;
        }

        if (indice == 0) {
            agregarInicio(valor);
            return;
        }
        if (indice == longitud) {
            agregarFinal(valor);
            return;
        }

        NodoDoble<T>* aux = obtenerNodo(indice);
        NodoDoble<T>* nuevoNodo = new NodoDoble<T>(valor);

        nuevoNodo->anterior = aux->anterior;
        nuevoNodo->siguiente = aux;
        aux->anterior->siguiente = nuevoNodo;
        aux->anterior = nuevoNodo;

        longitud++;
    }

    // 4. Eliminacion al inicio
    void eliminarInicio() {
        if (estaVacia()) {
            cout << "La lista ya esta vacia.\n";
            return;
        }

        NodoDoble<T>* nodoAEliminar = cabeza;
        if (cabeza == cola) {
            cabeza = cola = nullptr;
        }
        else {
            cabeza = cabeza->siguiente;
            cabeza->anterior = nullptr;
        }
        delete nodoAEliminar;
        longitud--;
    }

    // 5. Eliminacion al final
    void eliminarFinal() {
        if (estaVacia()) {
            cout << "La lista ya esta vacia.\n";
            return;
        }

        NodoDoble<T>* nodoAEliminar = cola;
        if (cabeza == cola) {
            cabeza = cola = nullptr;
        }
        else {
            cola = cola->anterior;
            cola->siguiente = nullptr;
        }
        delete nodoAEliminar;
        longitud--;
    }

    // 6. Eliminacion en cualquier posicion (base 0)
    void eliminarEnPosicion(int indice) {
        if (indice < 0 || indice >= longitud) {
            cout << "Error: Indice fuera de rango.\n";
            return;
        }

        if (indice == 0) {
            eliminarInicio();
            return;
        }
        if (indice == longitud - 1) {
            eliminarFinal();
            return;
        }

        NodoDoble<T>* nodoAEliminar = obtenerNodo(indice);

        nodoAEliminar->anterior->siguiente = nodoAEliminar->siguiente;
        nodoAEliminar->siguiente->anterior = nodoAEliminar->anterior;

        delete nodoAEliminar;
        longitud--;
    }

    void vaciar() {
        while (!estaVacia()) {
            eliminarInicio();
        }
    }
};

int main() {
    ListaDoble<int>* list = new ListaDoble<int>();

    cout << "--- 1. Pruebas de Insercion ---\n";
    list->agregarInicio(20);
    list->agregarInicio(10);
    list->agregarFinal(40);
    list->agregarFinal(50);
    list->imprimirAdelante();

    cout << "\nInsertando 30 en la posicion 2:\n";
    list->agregarEnPosicion(2, 30);
    list->imprimirAdelante();

    cout << "\n--- 2. Prueba de obtenerNodo ---\n";
    NodoDoble<int>* nodoRecuperado = list->obtenerNodo(2);
    if (nodoRecuperado != nullptr) {
        cout << "Dato en el nodo del indice 2: " << nodoRecuperado->dato << "\n";
    }

    cout << "\n--- 3. Pruebas de Eliminacion ---\n";
    cout << "Eliminando al inicio:\n";
    list->eliminarInicio();
    list->imprimirAdelante();

    cout << "Eliminando al final:\n";
    list->eliminarFinal();
    list->imprimirAdelante();

    cout << "Eliminando en la posicion 1 (elemento central: 30):\n";
    list->eliminarEnPosicion(1);
    list->imprimirAdelante();

    cout << "\n--- 4. Verificacion de enlaces inversos ---\n";
    list->imprimirAtras();

    delete list;

    system("pause>0");
    return 0;
}