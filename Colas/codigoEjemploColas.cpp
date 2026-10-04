/*
Realiza un programa con las siguientes características:

1. Implementar una Cola que almacena un objeto Tarea.
2. Cada Tarea debe tener un atributo esfuerzo.
3. El programa debe procesar al menos 3 Tareas y verificar el esfuerzo de cada una.
4. Si el esfuerzo es menor o igual a 0, la Tarea se elimina de la Cola y se muestra el mensaje "Tarea completada".
5. Caso contrario, se vuelve a encolar restando 2 al esfuerzo.

*/

#include <iostream>

using namespace std;

struct Tarea {
    string nombre;
    int esfuerzo;

    Tarea() : nombre(""), esfuerzo(0) {}
    Tarea(string n, int e) : nombre(n), esfuerzo(e) {}
};

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

    Cola<Tarea>* queue = new Cola<Tarea>();

    int contador;
    string nombre;
    int esfuerzo;

    do {
        cout << "Cuantas tareas deseas procesar?: ";
        cin >> contador;
    } while (contador < 3);

    for (int i = 0; i < contador; i++) {
        cout << "Tarea " << (i + 1) << ": " << endl;
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Nivel de esfuerzo: ";
        cin >> esfuerzo;

        queue->Enqueue(Tarea(nombre, esfuerzo));
    }

    cout << "Procesamiento de tareas: " << endl;

    while (!queue->estaVacia()) {
        Tarea tareaActual = queue->consultarFrente();

        queue->Dequeue();

        if (tareaActual.esfuerzo <= 0) {
            cout << "Tarea " << tareaActual.nombre << " completada" << endl;
        }
        else {
            tareaActual.esfuerzo -= 2;
            queue->Enqueue(tareaActual);
        }
    }

    delete queue;
    system("pause>0");
    return 0;
}

