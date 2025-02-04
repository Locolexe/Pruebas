#include <iostream>
using namespace std;

// Definimos la estructura del nodo
struct Nodo {
    int dato; // Dato que almacena el nodo
    int siguiente; // Índice del siguiente nodo en la lista
};

// Definimos la clase para la lista enlazada estática circular
class ListaEnlazadaEstatica {
private:
    Nodo nodos[10]; // Arreglo de nodos con tamaño fijo de 10
    int cabeza; // Índice del primer nodo de la lista
    int libre; // Índice del primer nodo libre en la lista

public:
    // Constructor para inicializar la lista
    ListaEnlazadaEstatica() {
        cabeza = -1; // Inicialmente, la lista está vacía
        libre = 0; // El primer nodo libre es el índice 0
        for (int i = 0; i < 9; ++i) {
            nodos[i].siguiente = i + 1; // Cada nodo apunta al siguiente
        }
        nodos[9].siguiente = -1; // El último nodo apunta a -1 indicando el final de la lista libre
    }

    // Función para insertar un dato en la lista
    void insertar(int dato) {
        if (libre == -1) { // Si no hay nodos libres
            cout << "Lista llena" << endl; // Imprimimos un mensaje de error
            return; // Salimos de la función
        }
        int nuevo = libre; // Tomamos el primer nodo libre
        libre = nodos[libre].siguiente; // Actualizamos el índice del primer nodo libre
        nodos[nuevo].dato = dato; // Asignamos el dato al nuevo nodo
        if (cabeza == -1) { // Si la lista está vacía
            nodos[nuevo].siguiente = nuevo; // El nuevo nodo se apunta a sí mismo
            cabeza = nuevo; // El nuevo nodo es ahora la cabeza de la lista
        } else {
            int temp = cabeza; // Empezamos desde la cabeza de la lista
            while (nodos[temp].siguiente != cabeza) { // Buscamos el último nodo
                temp = nodos[temp].siguiente; // Avanzamos al siguiente nodo
            }
            nodos[nuevo].siguiente = cabeza; // El nuevo nodo apunta a la cabeza
            nodos[temp].siguiente = nuevo; // El último nodo apunta al nuevo nodo
        }
        cabeza = nuevo; // Actualizamos la cabeza de la lista
    }

    // Función para imprimir la lista
    void imprimir() {
        if (cabeza == -1) return; // Si la lista está vacía, no imprimimos nada
        int actual = cabeza; // Empezamos desde la cabeza de la lista
        do {
            cout << nodos[actual].dato << " "; // Imprimimos el dato del nodo actual
            actual = nodos[actual].siguiente; // Pasamos al siguiente nodo
        } while (actual != cabeza); // Repetimos hasta volver a la cabeza
        cout << endl; // Imprimimos un salto de línea al final
    }
};

int main() {
    ListaEnlazadaEstatica lista; // Creamos una lista enlazada estática
    lista.insertar(10); // Insertamos el dato 10
    lista.insertar(20); // Insertamos el dato 20
    lista.insertar(30); // Insertamos el dato 30
    lista.imprimir(); // Imprimimos la lista
    return 0;
}
