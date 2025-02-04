#include <iostream>
using namespace std;

// Definimos la estructura del nodo
struct Nodo {
    int dato;
    int siguiente;
    int anterior; // Índice del nodo anterior en la lista (Solo dobles enlazada)
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
            nodos[i].anterior = -1; // Inicializamos la lista de nodos libres (Solo dobles enlazada)
        }
        nodos[9].siguiente = -1; // El último nodo libre no tiene siguiente
        nodos[9].anterior = -1; // El último nodo libre no tiene anterior (Solo dobles enlazada)
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
        nodos[nuevo].siguiente = cabeza;
        nodos[nuevo].anterior = -1; // El nuevo nodo no tiene anterior (Solo dobles enlazada)
        if (cabeza != -1) {
            nodos[cabeza].anterior = nuevo; // Actualizamos el anterior del primer nodo (Solo dobles enlazada)
        }
        cabeza = nuevo;
    }

    // Función para imprimir la lista
    void imprimir() {
        int actual = cabeza;
        while (actual != -1) {
            cout << nodos[actual].dato << " ";
            actual = nodos[actual].siguiente;
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