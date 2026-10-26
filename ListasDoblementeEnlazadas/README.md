# Listas Doblemente Enlazadas en C++ | Implementación, Big O y Caso Práctico

Código del video de YouTube: **[Listas Doblemente Enlazadas en C++ en 12 minutos](https://youtu.be/I4s2pmL4wig)**

Una **lista doblemente enlazada** es una estructura de datos lineal compuesta por nodos, donde cada nodo contiene un dato y dos punteros: uno hacia el nodo **siguiente** y otro hacia el nodo **anterior**. Al mantener punteros a la **cabeza** (`cabeza`) y a la **cola** (`cola`), permite una navegación bidireccional eficiente e inserciones/eliminaciones en ambos extremos en tiempo constante $O(1)$.

---

## Archivos incluidos

1. **`codigoListaDoblementeEnlazada.cpp`**:
   - Estructura `NodoDoble<T>` con punteros `siguiente` y `anterior`.
   - Clase genérica `ListaDoble<T>`.
   - Inserción al inicio, al final y en cualquier posición (base 0).
   - Eliminación al inicio, al final y en cualquier posición (base 0).
   - Recorrido e impresión hacia adelante (`imprimirAdelante`) y hacia atrás (`imprimirAtras`).
   - Algoritmo optimizado `obtenerNodo(int indice)`: recorre desde la cabeza o desde la cola dependiendo de si el índice está en la primera o segunda mitad de la lista ($O(n/2)$).
   - Destructor con liberación completa de memoria dinámica.

2. **`casoPracticoCodigo.cpp`**:
   - Implementación práctica de un **Reproductor de Música**.
   - Clase `Cancion` (título y artista) y lista de reproducción con puntero `cancionActual`.
   - Funcionalidades: reproducir actual, agregar canciones al final, avanzar (`siguiente`), retroceder (`anterior`) y eliminar la canción actual reorganizando punteros adecuadamente.

---

## Complejidad Algorítmica (Big O)

### Complejidad Temporal

| Operación | Complejidad | Detalle |
|-----------|-------------|---------|
| `agregarInicio` | $O(1)$ | Inserta directamente en la cabeza |
| `agregarFinal` | $O(1)$ | Inserta directamente en la cola |
| `agregarEnPosicion` | $O(n)$ | Requiere buscar la posición ($O(n/2)$ pasos) + reconexión $O(1)$ |
| `eliminarInicio` | $O(1)$ | Elimina y reasigna la cabeza |
| `eliminarFinal` | $O(1)$ | Elimina y reasigna la cola |
| `eliminarEnPosicion` | $O(n)$ | Búsqueda del nodo ($O(n/2)$ pasos) + reconexión $O(1)$ |
| `obtenerNodo` (por índice) | $O(n)$ | Optimizado a máx. $n/2$ iteraciones (cabeza o cola) |
| `imprimirAdelante` / `imprimirAtras` | $O(n)$ | Recorre todos los elementos |

### Complejidad Espacial
- **$O(n)$**: Cada nodo almacena el dato más dos punteros (`siguiente` y `anterior`).

---

## Ventajas y Desventajas

### Ventajas
- **Recorrido bidireccional:** Permite navegar hacia adelante y hacia atrás.
- **Inserción y eliminación rápida en ambos extremos:** $O(1)$ tanto en el inicio como en el final.
- **Eliminación eficiente conociendo el nodo:** Si se tiene el puntero directo al nodo, se puede eliminar en $O(1)$ sin necesidad de recorrer la lista para encontrar el nodo anterior.

### Desventajas
- **Mayor consumo de memoria:** Requiere dos punteros por nodo en lugar de uno.
- **Mayor sobrecarga de punteros:** Más operaciones de asignación al insertar y eliminar nodos para mantener la consistencia en ambas direcciones.

---

## Ejemplo de uso básico

```cpp
#include <iostream>
#include "codigoListaDoblementeEnlazada.cpp" // o incluir la definición

int main() {
    ListaDoble<int> lista;

    // Inserciones
    lista.agregarInicio(20);
    lista.agregarInicio(10);
    lista.agregarFinal(40);
    lista.agregarEnPosicion(2, 30);

    // Impresión bidireccional
    lista.imprimirAdelante(); // Cabeza -> 10 <-> 20 <-> 30 <-> 40 <-> nullptr
    lista.imprimirAtras();    // Cola -> 40 <-> 30 <-> 20 <-> 10 <-> nullptr

    // Eliminación
    lista.eliminarEnPosicion(2); // Elimina el 30
    lista.imprimirAdelante(); // Cabeza -> 10 <-> 20 <-> 40 <-> nullptr

    return 0;
}
```

---

## Contenido del Video

- **0:00** - Introducción
- **0:38** - Estructura de una Lista Doblemente Enlazada
- **1:25** - Algoritmo eficiente para obtener Nodos
- **2:34** - Agregar nodos
- **4:50** - Eliminar nodos
- **6:50** - Complejidad temporal (Big O)
- **7:32** - Complejidad espacial (Big O)
- **7:57** - Ventajas y Desventajas
- **9:02** - Caso Práctico de implementación (Reproductor de Música)
- **12:03** - Conclusión

---

## Videos relacionados

- [Listas simplemente enlazadas en C++](https://youtu.be/-8WIBEmiMEY)
- [Pilas en C++](https://youtu.be/lyKOsSD6yCc)
- [Colas en C++](https://youtu.be/WC1Deyo4vnk)
- [Punteros en C++](https://youtu.be/NBO3UXdccIs)

Canal: [Donny32](https://www.youtube.com/@Donny32)
