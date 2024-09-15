#include <iostream>
#include "Cola/Cola.h"  // Incluye la clase de la cola

// Función para eliminar los elementos mayores a 'n'
void suprimirMayores(Cola<int>& cola, int limite) {
    Cola<int> colaDepurada;  // Cola para almacenar los elementos que no superan el límite

    // Mientras la cola original no esté vacía
    while (!cola.esVacia()) {
        int elemento = cola.desencolar();  // Desencolamos cada elemento

        // Si el elemento es menor o igual al límite, lo encolamos en la cola depurada
        if (elemento <= limite) {
            colaDepurada.encolar(elemento);
        }
    }

    // Ahora transferimos los elementos de la cola depurada de vuelta a la original
    while (!colaDepurada.esVacia()) {
        cola.encolar(colaDepurada.desencolar());
    }
}

// Función para leer una cola de enteros desde la entrada del usuario
void leerCola(Cola<int>& cola) {
    int numero;
    std::cout << "Ingresa números para la cola (termina con -1): ";

    // El usuario ingresa números hasta que ingresa un -1
    while (true) {
        std::cin >> numero;
        if (numero == -1) {
            break;
        }
        cola.encolar(numero);  // Encolamos cada número ingresado
    }
}

// Función para imprimir la cola
void imprimirCola(Cola<int>& cola) {
    Cola<int> colaAux;  // Cola auxiliar para imprimir sin perder los elementos
    while (!cola.esVacia()) {
        int elemento = cola.desencolar();
        std::cout << elemento << " ";
        colaAux.encolar(elemento);  // Transferimos los elementos a la cola auxiliar
    }
    std::cout << std::endl;

    // Regresamos los elementos a la cola original desde la auxiliar
    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }
}

int main() {
    Cola<int> cola;
    int limite;

    // Leer la cola desde la entrada del usuario
    std::cout << "Introduce los números para la cola (termina con -1):" << std::endl;
    leerCola(cola);

    // Leer el límite n desde la entrada
    std::cout << "Ingresa el límite (n): ";
    std::cin >> limite;

    // Suprimir los elementos mayores que 'n'
    suprimirMayores(cola, limite);

    // Imprimir la cola depurada
    std::cout << "Cola depurada: ";
    imprimirCola(cola);

    return 0;
}

