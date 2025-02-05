#include <iostream>
using namespace std;
// Lineas ya vacias (9,15,25,38,49)
// Definimos la estructura del nodo
struct Nodo {
    int dato; // Dato que almacena el nodo
    int siguiente; // Índice del siguiente nodo en la lista
};

// Definimos la lista enlazada estática
struct ListaEnlazadaEstatica {
    Nodo nodos[10]; // Arreglo de nodos con un tamaño máximo de 10
    int cabeza;//El indice del primer nodo de la lista 
    int libre; // Índice del primer nodo libre en la lista

    // Constructor para inicializar la lista
    ListaEnlazadaEstatica() {
        cabeza = -1; // Inicialmente, la lista está vacía
        libre=0;// Inicialmente, el primer nodo es el indice 0
        for (int i = 0; i < 9; ++i) {
            nodos[i].siguiente = i + 1; // Inicializamos la lista de nodos libres
        }
        nodos[9].siguiente = -1; // El último nodo libre no tiene siguiente
    }

    // Función para insertar un dato en la lista
    void insertar(int dato) {
        if (libre == -1) {
            cout << "Lista llena" << endl; // Si no hay nodos libres, la lista está llena
            return;
        }
        int nuevo = libre; // Tomamos el primer nodo libre
        libre = nodos[libre].siguiente; // Actualizamos el índice del primer nodo libre
        nodos[nuevo].dato = dato; // Asignamos el dato al nuevo nodo
        nodos[nuevo].siguiente=cabeza;//El siguiente del nuevo nodo es la cabeza actual
        cabeza = nuevo; // Actualizamos la cabeza de la lista
    }

    // Función para imprimir la lista
    void imprimir() {
        int actual=cabeza;//Empezamos desde la cabeza de la lista
        while (actual != -1) {
            cout << nodos[actual].dato << " "; // Imprimimos el dato del nodo actual
            actual = nodos[actual].siguiente; // Pasamos al siguiente nodo
        }
        cout << endl;
    }
};

int main() {
    ListaEnlazadaEstatica lista; // Creamos una lista enlazada estática
    lista.insertar(10); // Insertamos el dato 10
    lista.insertar(20); //Insertamos el dato 20
    lista.insertar(30); // Insertamos el dato 30
    lista.imprimir(); // Imprimimos la lista
    return 0;
}
