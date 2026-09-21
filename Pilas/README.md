# Pilas en C++ desde cero: Stack, LIFO, push y pop explicados fácil

Código del video de YouTube: **[Pilas en C++ desde cero](https://youtu.be/IyKOsSD6yCc)**

Una pila (stack) es una estructura de datos LIFO (Last In, First Out):
el último elemento en entrar es el primero en salir. Esta implementación
usa nodos enlazados y punteros en C++, con `push` y `pop` en O(1)
porque solo modifican el tope. Está pensada para estudiantes de
estructuras de datos que ya conocen lo básico de C++.

## Qué incluye

- Clase genérica `Pila<T>` implementada con nodos
- `push`: apilar un elemento (O(1))
- `pop`: desapilar el elemento del tope (O(1))
- `consultarTop`: ver el elemento del tope sin quitarlo
- `estaVacia` y `obtenerTamano`
- Destructor que libera toda la memoria dinámica

## Complejidad

| Operación      | Complejidad |
|----------------|-------------|
| push           | O(1)        |
| pop            | O(1)        |
| consultarTop   | O(1)        |
| estaVacia      | O(1)        |
| obtenerTamano  | O(1)        |

## Ejemplo de uso

```cpp
Pila<int> pila;
pila.push(10);
pila.push(20);
pila.consultarTop();   // 20
pila.pop();
pila.consultarTop();   // 10
```

## Videos relacionados

- [Punteros en C++](https://youtu.be/NBO3UXdccIs?si=QeE1gmvIoDgTNcw8)
- [Listas enlazadas simples en C++](https://youtu.be/-8WIBEmiMEY?si=1mrKc8AOIZ8afRTQ)

## Contenido del video

Principio LIFO, partes de una pila, repaso de un nodo, implementación de
los métodos, lista enlazada vs pila (justificación con Big O) y destructor.

Canal: [Donny32](https://www.youtube.com/@Donny32)
