
#include <iostream>

using namespace std;

typedef unsigned int uint;

template <typename T>
struct Nodo {
    T valor;
    Nodo<T>* siguiente;

    Nodo(T val) : valor(val), siguiente(nullptr) {}
};

template <typename T>
class Pila {
private:
    Nodo<T>* tope;
    uint longitud;

public:
    Pila() : tope(nullptr), longitud(0) {}

    ~Pila() {
        while (!estaVacia()) {
            pop();
        }
    }

    bool estaVacia() {
        return tope == nullptr;
    }

    T consultarTop() {
        if (estaVacia()) {
            cout << "La pila esta vacia" << endl;
            return T();
        }
        else {
            return tope->valor;
        }
    }

    unsigned int obtenerTamano() {
        return longitud;
    }

    void push(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        nuevoNodo->siguiente = tope;
        tope = nuevoNodo;
        longitud++;
    }
    
    void pop() {
        if (estaVacia()) {
            cout << "Error: Pila vacia, no se puede hacer pop\n";
            return;
        }
        Nodo<T>* nodoAEliminar = tope;
        tope = tope->siguiente;
        delete nodoAEliminar;
        longitud--;
    }
};

int main() {

    Pila<int>* stack = new Pila<int>();

    cout << "Longitud de la Lista: " << stack->obtenerTamano() << endl;

    stack->pop();

    stack->push(10);
    cout << stack->consultarTop() << endl;

    stack->push(20);
    cout << stack->consultarTop() << endl;

    stack->push(30);
    cout << stack->consultarTop() << endl;

    stack->pop();
    cout << stack->consultarTop() << endl;

    cout << "Longitud de la Lista: " << stack->obtenerTamano() << endl;

    delete stack;
    system("pause>0");
    return 0;
}