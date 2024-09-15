#include <iostream>
#include "Cola/Cola.h"  // Clase de cola

// Función para separar elementos pares e impares
void separarCola(Cola<int>& cola, Cola<int>& colaImpares) {
    // Verificar si la cola está vacía
    if (cola.esVacia()) {
        std::cout << "Error: la cola está vacía." << std::endl;
        return;
    }

    Cola<int> colaAux;  // Cola auxiliar para almacenar los números pares

    // Recorrer la cola original
    while (!cola.esVacia()) {
        int elemento = cola.desencolar();

        if (elemento % 2 == 0) {
            // Si el número es par, lo encolamos en la cola auxiliar
            colaAux.encolar(elemento);
        } else {
            // Si el número es impar, lo encolamos en la cola de impares
            colaImpares.encolar(elemento);
        }
    }

    // Restaurar la cola original con los elementos pares de la cola auxiliar
    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
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

// Función para imprimir la cola en orden inverso
void imprimirColaInversa(Cola<int>& cola) {
    Cola<int> colaAux;  // Cola auxiliar para invertir el orden
    while (!cola.esVacia()) {
        colaAux.encolar(cola.desencolar());
    }

    // Imprimir en orden inverso
    while (!colaAux.esVacia()) {
        int elemento = colaAux.desencolar();
        std::cout << elemento << " ";
        cola.encolar(elemento);  // Restauramos el orden original
    }
    std::cout << std::endl;
}

int main() {
    Cola<int> cola;
    Cola<int> colaImpares;

    // Leer la cola desde la entrada del usuario
    std::cout << "Introduce los números para la cola (termina con -1):" << std::endl;
    leerCola(cola);

    // Separar los elementos de la cola en pares e impares
    separarCola(cola, colaImpares);

    // Imprimir la cola después de la separación
    std::cout << "Cola (solo pares): ";
    imprimirCola(cola);

    // Imprimir la cola de impares en orden inverso
    std::cout << "Cola (impares en orden inverso): ";
    imprimirColaInversa(colaImpares);

    return 0;
}