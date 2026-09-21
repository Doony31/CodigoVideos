// LONGITUD EQUIVALE A ÍNDICE DE NODOS
// Para estructura de datos no es necesario crear el proyecto que incluye "pch.h"

#include <iostream>
#include <string>

using namespace std;

typedef unsigned int uint;

template<typename T>
struct Nodo { 
	T valor;
	Nodo<T>* siguiente;

	Nodo(T v) : valor(v), siguiente(nullptr) {} 
};

template<typename T>
class ListaSimple {
private:
	Nodo<T>* cabeza;
	// Representa el �ndice m�ximo de la lista (0 para 1 nodo, 1 para 2, etc)
	unsigned int longitud;
public:
	ListaSimple() : cabeza(nullptr), longitud(0) {}

	// No incluido en el video:
	// Destructor para liberar memoria autom�ticamente
	~ListaSimple() {
		// Simplemente recorrer la Lista eliminando cada Nodo
		while (cabeza != nullptr) {
			eliminarInicio();
		}
	}

	void agregarInicio(T valor) {
		Nodo<T>* nuevoNodo = new Nodo<T>(valor);
		if (cabeza == nullptr) cabeza = nuevoNodo;
		else {
			nuevoNodo->siguiente = cabeza;
			cabeza = nuevoNodo;
			longitud++;
		}
	}

	void recorrerLista() {
		Nodo<T>* NodoAux = cabeza;
		while (NodoAux != nullptr) {
			cout << NodoAux->valor << "->";
			NodoAux = NodoAux->siguiente;
		}
		cout << "NULL\n";
	}

	void devolverNodo(uint pos) {
		if (cabeza == nullptr || pos > longitud) {
			cout << "Posicion invalida\n";
			return;
		}

		Nodo<T>* NodoAux = cabeza;
		for (uint i = 0; i < pos; i++) {
			NodoAux = NodoAux->siguiente;
		}
		cout << NodoAux->valor << "\n";
	}

	// FUNCION ADICIONAL
	// Una funci�n que modifica el valor de un Nodo especifico.
	// La logica es exactamente la misma que la funcion devolverNodo
	void modificarNodoPos(T valor, uint pos) {
		if (cabeza == nullptr || pos > longitud) return;

		Nodo<T>* NodoAux = cabeza;
		for (uint i = 0; i < pos; i++) {
			NodoAux = NodoAux->siguiente;
		}
		NodoAux->valor = valor;
	}

	void agregarNodoPos(T valor, uint pos) {
		if (cabeza == nullptr) return;
		if (pos > longitud) return;
		if (pos == 0) {
			agregarNodo(valor);
			return;
		}
		Nodo<T>* nuevoNodo = new Nodo<T>(valor);
		Nodo<T>* NodoAux = cabeza;

		for (int i = 0; i < pos - 1; i++) {
			NodoAux = NodoAux->siguiente;
		}

		nuevoNodo->siguiente = NodoAux->siguiente;
		NodoAux->siguiente = nuevoNodo;
		longitud++;
	}

	void agregarFinal(T valor) {
		Nodo<T>* nuevoNodo = new Nodo<T>(valor);
		if (cabeza == nullptr) {
			cabeza = nuevoNodo;
		}
		else {
			Nodo<T>* aux = cabeza;
			while (aux->siguiente != nullptr) {
				aux = aux->siguiente;
			}
			aux->siguiente = nuevoNodo;
			longitud++;
		}
	}

	void EliminarNodoPos(uint pos) {
		if (cabeza == nullptr || pos > longitud) return;

		if (pos == 0) {
			eliminarInicio();
			return;
		}

		Nodo<T>* NodoAux = cabeza;
		for (int i = 0; i < pos - 1; i++) {
			NodoAux = NodoAux->siguiente;
		}
		Nodo<T>* nodoAEliminar = NodoAux->siguiente;
		NodoAux->siguiente = nodoAEliminar->siguiente;
		delete nodoAEliminar;
		longitud--;
	}

	void eliminarInicio() {
		if (cabeza == nullptr) return;

		Nodo<T>* nodoAEliminar = cabeza;
		cabeza = cabeza->siguiente;
		delete nodoAEliminar;

		if (cabeza != nullptr) {
			longitud--;
		}
	}

	void eliminarFinal() {
		if (cabeza == nullptr || cabeza->siguiente == nullptr) {
			eliminarInicio();
			return;
		}
		Nodo<T>* aux = cabeza;
		for (uint i = 0; i < longitud - 1; i++) {
			aux = aux->siguiente;
		}
		Nodo<T>* nodoAEliminar = aux->siguiente;
		aux->siguiente = nullptr;
		delete nodoAEliminar;
		longitud--;
	}

	// Funcion para que devuelva la cantidad de Nodos 
	// Especialmente util teniendo en cuenta que longitud representa el �ndice
	uint obtenerTamano() {
		return (cabeza == nullptr) ? 0 : longitud + 1;
	}

};

int main() {

	ListaSimple<float>* list = new ListaSimple<float>();
	ListaSimple<string>* list2 = new ListaSimple<string>();
	ListaSimple<int>* list3 = new ListaSimple<int>();

	list->agregarInicio(1.1);
	list->agregarInicio(1.2);
	list->agregarInicio(1.3);

	list2->agregarInicio("hola");
	list2->agregarFinal("mundo");

	cout << "Lista de flotantes: ";
	list->recorrerLista();

	cout << "Lista de strings: ";
	list2->recorrerLista();

	cout << "\nAgregando al final y eliminando en el medio...\n";
	list->agregarFinal(1.0);
	list->EliminarNodoPos(1);
	list->recorrerLista();

	// De esta manera llamamos al destructor de la Lista.
	delete list;
	delete list2;
	delete list3;

	system("pause>0");
	return 0;
}