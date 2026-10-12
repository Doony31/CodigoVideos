#include <iostream>
#include <string>

using namespace std;
typedef unsigned int uint;

int sumaDigitos(int num) {
    if (num < 10) return num;
    else {
        return (num % 10) + sumaDigitos(num / 10);
    }
}

bool esPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

template<typename T>
struct Nodo {
    T elemento;
    Nodo<T>* siguiente;
    Nodo(T e) : elemento(e), siguiente(nullptr) {}
};

template<typename T>
class Lista {
private:
    Nodo<T>* cabeza;
    uint lon;

public:
    Lista() : cabeza(nullptr), lon(0) {}

    void agregar(T elemento) {
        Nodo<T>* nuevoNodo = new Nodo<T>(elemento);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        }
        else {
            Nodo<T>* aux = cabeza;
            while (aux->siguiente != nullptr) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevoNodo;
        }
        lon++;
    }

    uint longitud() { return lon; }

    T obtener(uint pos) {
        if (pos >= lon) return T();
        Nodo<T>* aux = cabeza;
        for (uint i = 0; i < pos; i++) {
            aux = aux->siguiente;
        }
        return aux->elemento;
    }
};

class Prestamo {
public:
    int codigoPrestamo;
    int codigoAsociado;
    int montoPrestamo;
    string fechaRegistro;

    Prestamo(int cP, int cA, int mP, string f)
        : codigoPrestamo(cP), codigoAsociado(cA), montoPrestamo(mP), fechaRegistro(f) {
    }
};

class Cliente {
public:
    int codigo;
    string nombre;
    string apellido;
    char sexo;
    char estadoCivil;
    char tipoCliente;

    Lista<Prestamo*> misPrestamos;

    Cliente(int c, string n, string a, char s, char e, char t) {
        codigo = c;
        nombre = n;
        apellido = a;
        sexo = s;
        estadoCivil = e;
        tipoCliente = t;
    }
};

class Sistema {
private:
    Lista<Cliente*> clientes;

public:
    void agregarCliente(int codigo, string nombre, string apellido,
        char sexo, char estadoCivil, char tipoCliente) {

        if (sexo != 'M' && sexo != 'F') {
            cout << "Ingrese un sexo valido" << endl;
            return;
        }
        if (estadoCivil != 'S' && estadoCivil != 'C' && estadoCivil != 'V' && estadoCivil != 'D') {
            cout << "Ingrese un estado civil valido" << endl;
            return;
        }
        if (tipoCliente != 'N' && tipoCliente != 'V' && tipoCliente != 'P' && tipoCliente != 'O') {
            cout << "Ingrese un tipo de cliente valido" << endl;
            return;
        }
        clientes.agregar(new Cliente(codigo, nombre, apellido, sexo, estadoCivil, tipoCliente));
        cout << "Cliente registrado con exito." << endl;

    }

    void contarClientesPorTipo() {
        int clientesNormal = 0;
        int clientesVip = 0;
        int clientesPlatinium = 0;
        int clientesOro = 0;

        for (uint i = 0; i < clientes.longitud(); i++) {
            if (clientes.obtener(i)->tipoCliente == 'N') {
                clientesNormal += 1;
            }
            if (clientes.obtener(i)->tipoCliente == 'V') {
                clientesVip += 1;
            }
            if (clientes.obtener(i)->tipoCliente == 'P') {
                clientesPlatinium += 1;
            }
            if (clientes.obtener(i)->tipoCliente == 'O') {
                clientesOro += 1;
            }
        }

        cout << "Resultados: " << endl;
        cout << "Clientes Normales: " << clientesNormal << endl;
        cout << "Clientes Vip: " << clientesVip << endl;
        cout << "Clientes Platinium: " << clientesPlatinium << endl;
        cout << "Clientes Oro: " << clientesOro << endl;

    }

    void mayorMontoPrimo() {
        Prestamo* mayorPrestamo = nullptr;

        for (uint i = 0; i < clientes.longitud(); i++) {
            Cliente* client = clientes.obtener(i);
            for (uint j = 0; j < client->misPrestamos.longitud(); j++) {
                Prestamo* pr = client->misPrestamos.obtener(j);
                if (mayorPrestamo == nullptr || pr->montoPrestamo > mayorPrestamo->montoPrestamo) {
                    mayorPrestamo = pr;
                }
            }
        }

        if (mayorPrestamo == nullptr) {
            cout << "No hay prestamos registrados." << endl;
            return;
        }

        cout << "Mayor monto: " << mayorPrestamo->montoPrestamo << endl;

        if (esPrimo(mayorPrestamo->montoPrestamo))
            cout << "Es primo. Suma de digitos del codigo " << mayorPrestamo->codigoPrestamo
            << ": " << sumaDigitos(mayorPrestamo->codigoPrestamo) << endl;
        else
            cout << "El monto no es primo." << endl;
    }

    // METODO AUXILIAR PARA PRUEBAS
    void agregarPrestamoCliente(Prestamo* prestamo) {
        for (uint i = 0; i < clientes.longitud(); i++) {
            if (clientes.obtener(i)->codigo == prestamo->codigoAsociado) {
                clientes.obtener(i)->misPrestamos.agregar(prestamo);
                return;
            }
        }
    }
};

void mostrarMenu() {
    cout << "\n--- MENU CAJA LIMA ---" << endl;
    cout << "1. Agregar cliente nuevo" << endl;
    cout << "2. Contar clientes por tipo de usuario" << endl;
    cout << "3. Cliente con el mayor monton primo" << endl;
    cout << "4. Salir" << endl;
    cout << "Opcion: ";
}

int main() {
    Sistema gestor;

    // DATOS DE PRUEBA 
    gestor.agregarCliente(1001, "Cliente", "01", 'M', 'C', 'N');
    gestor.agregarCliente(1002, "Cliente", "02", 'F', 'C', 'V');

    gestor.agregarPrestamoCliente(new Prestamo(101, 1001, 33, "21/05/2026"));
    gestor.agregarPrestamoCliente(new Prestamo(102, 1002, 45, "21/05/2026"));
    gestor.agregarPrestamoCliente(new Prestamo(103, 1002, 4, "21/05/2026"));

    int opc;

    // CLIENTE
    int codigo;
    string nombre;
    string apellido;
    char sexo;
    char estadoCivil;
    char tipoCliente;

    do {
        mostrarMenu();
        cin >> opc;
        cin.ignore();

        switch (opc) {
        case 1:
            cout << "Ingrese su codigo: ";
            cin >> codigo;
            cin.ignore();

            cout << "Nombre: ";
            cin >> nombre;

            cout << "Apellido: ";
            cin >> apellido;

            cout << "Sexo: ";
            cin >> sexo;

            cout << "Estado Civil: ";
            cin >> estadoCivil;

            cout << "Tipo de Cliente: ";
            cin >> tipoCliente;

            gestor.agregarCliente(codigo, nombre, apellido, sexo, estadoCivil, tipoCliente);
            system("pause>0");
            system("cls");
            break;
        case 2:
            gestor.contarClientesPorTipo();
            system("pause>0");
            system("cls");
            break;

        case 3:
            gestor.mayorMontoPrimo();
            system("pause>0");
            system("cls");
            break;

        case 4:
            cout << "Saliendo del sistema..." << endl;
            break;

        default:
            cout << "Opcion incorrecta. Intente de nuevo." << endl;
            system("pause>0");
            system("cls");
            break;
        }
    } while (opc != 4);

    return 0;
}
