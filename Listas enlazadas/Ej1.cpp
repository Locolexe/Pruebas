#include <iostream>
using namespace std;

struct Nodo {
    int infor; // Dato que almacena el nodo
    int Isiguiente; // Indice del siguiente nodo en la lista
};

struct ListaEnlazadaEstatica {
    Nodo nodos[10]; //Maximo 10 nodos
    int Icabeza; // Indice del primer nodo de la lista
    int Ilibre; // Indice del primer nodo libre en la lista

    ListaEnlazadaEstatica() {
        Icabeza = -1; // Inicialmente, la lista estára vacía
        Ilibre = 0; // El primer nodo libre siempre sera el indice 0
        for (int i = 0; i < 9; ++i) {
            nodos[i].Isiguiente = i + 1; // Cada nodo conocera su siguiente nodo
        }
        nodos[9].Isiguiente = -1; // El último nodo libre sera NULL (-1)
    }

    void insertar(int dato) {
        if (Ilibre == -1) {
            cout << "Lista llena" << endl; // Si no hay nodos libres, la lista ya se lleno
            return;
        }
        int actu = Ilibre; // Tomamos el primer nodo libre
        Ilibre = nodos[Ilibre].Isiguiente; // Ahora el siguiente nodo libre sera el siguiente del nodo que acabamos de tomar
        nodos[actu].infor = dato; // Asignamos el dato al nuevo nodo
        nodos[actu].Isiguiente = Icabeza; // El nuevo nodo ahora sera la cabeza de la lista
        Icabeza = actu;
    }

    void imprimir() {
        int actual = Icabeza; // El primer nodo sera la cabeza de la lista
        while (actual != -1) {
            cout << nodos[actual].infor << " "; // Imprimimos el dato del nodo actual
            actual = nodos[actual].Isiguiente; // Cambiamos de nodo al siguiente
            cout << actual << "Actual" << endl;
        }
        cout << endl;
    }
};

int main() {
    ListaEnlazadaEstatica lista; // Creamos una lista enlazada estatica
    int dato;
    cin >> dato;
    lista.insertar(dato); // Insertamos el dato
    cin >> dato;
    lista.insertar(dato); // Insertamos el dato 2
    cin >> dato;
    lista.insertar(dato); // Insertamos el dato 3
    lista.imprimir(); // Imprimimos la lista
    return 0;
}