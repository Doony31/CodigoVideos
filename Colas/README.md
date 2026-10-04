# Cómo Funcionan las Colas (Queue) en C++ | Estructura de Datos Explicada

Código del video de YouTube: **[Colas en C++ desde cero](URL_DEL_VIDEO)**

Una cola (queue) es una estructura de datos FIFO (First In, First Out):
el primer elemento en entrar es el primero en salir. Esta implementación
usa nodos enlazados y punteros (`frente` y `final`) en C++, permitiendo `encolar`
y `desencolar` en O(1). Está pensada para estudiantes de estructuras de datos
que ya conocen lo básico de C++.

## Qué incluye

- Clase genérica `Cola<T>` implementada con nodos
- `encolar` (enqueue): insertar un elemento al final (O(1))
- `desencolar` (dequeue): retirar el primer elemento (O(1))
- `consultarFrente` (front): ver el primer elemento sin retirarlo
- `estaVacia` y `obtenerTamano`
- Destructor que libera toda la memoria dinámica

## Complejidad

| Operación         | Complejidad |
|-------------------|-------------|
| encolar (push)    | O(1)        |
| desencolar (pop)  | O(1)        |
| consultarFrente   | O(1)        |
| estaVacia         | O(1)        |
| obtenerTamano     | O(1)        |

## Ejemplo de uso

```cpp
Cola<int> cola;
cola.encolar(10);
cola.encolar(20);
cola.consultarFrente(); // 10
cola.desencolar();
cola.consultarFrente(); // 20


## Videos relacionados

- [Punteros en C++](https://youtu.be/NBO3UXdccIs?si=QeE1gmvIoDgTNcw8)
- [Listas enlazadas simples en C++](https://youtu.be/-8WIBEmiMEY?si=1mrKc8AOIZ8afRTQ)
- [Pilas en C++](https://youtu.be/IyKOsSD6yCc)

## Contenido del video

Principio FIFO, partes de una cola, repaso de un nodo, implementación de
los métodos, Cola vs lista enlazada y pila (justificación con Big O), destructor
y ejemplo práctico.

Canal: [Donny32](https://www.youtube.com/@Donny32)