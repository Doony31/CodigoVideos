#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
    T valor;
    Nodo<T>* siguiente;

    Nodo(T val) : valor(val), siguiente(nullptr) {}
};

template <typename T>
class Cola {
private:
    Nodo<T>* frente;
    Nodo<T>* fin;
    unsigned int longitud;

public:
    Cola() : frente(nullptr), fin(nullptr), longitud(0) {}

    ~Cola() {
        while (!estaVacia()) {
            Dequeue();
        }
    }

    bool estaVacia() {
        return frente == nullptr;
    }

    T consultarFrente() {
        if (estaVacia()) {
            cout << "Error: Cola vacia.\n";
            return T();
        }
        return frente->valor;
    }

    unsigned int obtenerTamano() {
        return longitud;
    }

    void Enqueue(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (estaVacia()) {
            frente = nuevoNodo;
            fin = nuevoNodo;
        }
        else {
            fin->siguiente = nuevoNodo;
            fin = nuevoNodo;
        }
        longitud++;
    }

    void Dequeue() {
        if (estaVacia()) {
            cout << "Error: Cola vacia, no se puede hacer pop.\n";
            return;
        }
        Nodo<T>* nodoAEliminar = frente;
        frente = frente->siguiente;
        delete nodoAEliminar;
        longitud--;

        if (frente == nullptr) {
            fin = nullptr;
        }
    }

};

int main() {

    Cola<int>* queue = new Cola<int>();

    queue->consultarFrente();

    queue->Enqueue(10);
    cout << queue->consultarFrente() << endl;

    queue->Enqueue(20);
    cout << queue->consultarFrente() << endl;

    queue->Dequeue();
    cout << queue->consultarFrente() << endl;

    queue->Enqueue(30);
    cout << queue->consultarFrente() << endl;

    delete queue;

    system("pause>0");
    return 0;
}

