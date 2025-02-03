#include <iostream> // Incluye la biblioteca de entrada y salida
using namespace std; // Usa el espacio de nombres estándar
//Vacios por base (9,14,20,28,38,49,56,59)
// Definición de la estructura Nodo
struct Nodo {

    Nodo* siguiente; // Puntero al siguiente nodo
};

// Clase Lista para manejar la lista enlazada
class Lista {
private:
    Nodo* cabeza; // Puntero al primer nodo de la lista

public:
    // Constructor para inicializar la lista vacía
    Lista() {
        cabeza = nullptr; // Inicializa la cabeza como nula
    }

    // Método para insertar un nuevo nodo al inicio de la lista
    void insertarInicio(int valor) {
        Nodo* nuevoNodo = new Nodo(); // Crea un nuevo nodo

        nuevoNodo->siguiente = cabeza; // El siguiente del nuevo nodo es la cabeza actual
        cabeza = nuevoNodo; // La cabeza ahora es el nuevo nodo
    }

    // Método para mostrar los elementos de la lista
    void mostrarLista() {
        Nodo* actual = cabeza; // Comienza desde la cabeza
        while (actual != nullptr) { // Recorre hasta el final de la lista

            actual = actual->siguiente; // Avanza al siguiente nodo
        }
        cout << endl; // Imprime una nueva línea al final
    }

    // Destructor para liberar la memoria de los nodos
    ~Lista() {
        Nodo* actual = cabeza; // Comienza desde la cabeza
        while (actual != nullptr) { // Recorre toda la lista

            actual = actual->siguiente; // Avanza al siguiente nodo
            delete temp; // Libera la memoria del nodo temporal
        }
    }
};

// Función principal
int main() {
    Lista lista; // Crea una lista
    lista.insertarInicio(10); // Inserta el valor 10 al inicio

    lista.insertarInicio(30); // Inserta el valor 30 al inicio

    cout << "Elementos de la lista: "; // Imprime un mensaje
    lista.mostrarLista(); // Muestra los elementos de la lista

    return 0; // Termina el programa
}