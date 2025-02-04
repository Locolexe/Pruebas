#include <iostream>
using namespace std;

// Definimos la estructura del nodo
struct Nodo {
    int dato;
    int siguiente;
};

// Definimos la lista enlazada estática
struct ListaEnlazadaEstatica {
    Nodo nodos[10];
    int cabeza;
    int libre;

    // Constructor para inicializar la lista
    ListaEnlazadaEstatica() {
        cabeza = -1; 
        libre = 0; 
        for (int i = 0; i < 9; ++i) {
            nodos[i].siguiente = i + 1;
        }
        nodos[9].siguiente = -1;
    }

    // Función para insertar un dato en la lista
    void insertar(int dato) {
        if (libre == -1) {
            cout << "Lista llena" << endl;
            return;
        }
        int nuevo = libre;
        libre = nodos[libre].siguiente;
        nodos[nuevo].dato = dato;
        //Circular
        if (cabeza == -1) {
            nodos[nuevo].siguiente = nuevo;
            cabeza = nuevo;
        } else {
            int temp = cabeza;
            while (nodos[temp].siguiente != cabeza) {
                temp = nodos[temp].siguiente;
            }
            nodos[nuevo].siguiente = cabeza;
            nodos[temp].siguiente = nuevo;
        }
        nodos[nuevo].siguiente = cabeza; // El nuevo nodo apunta al antiguo primer nodo
        cabeza = nuevo; // Actualizamos la cabeza de la lista
    }

    // Función para imprimir la lista
    void imprimir() {
        if (cabeza == -1) return; // Si la lista está vacía, no imprimimos nada (Circular)
        int actual = cabeza; // Empezamos desde la cabeza de la lista
        while (actual != cabeza) {
            cout << nodos[actual].dato << " "; // Imprimimos el dato del nodo actual
            actual = nodos[actual].siguiente; // Pasamos al siguiente nodo
        }
        cout << endl;
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