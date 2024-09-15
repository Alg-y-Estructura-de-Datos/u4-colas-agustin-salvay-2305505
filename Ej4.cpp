#include <iostream>
#include "Cola/Cola.h"  // Incluye la clase de la cola

// Función para sumar los elementos de la cola hasta encontrar "n" (sin incluirlo)
// Si "n" no está en la cola, devuelve la suma de todos los elementos
int sumarHastaN(Cola<int>& cola, int n) {
    Cola<int> colaAux;  // Cola auxiliar para restaurar la cola original
    int suma = 0;
    bool encontrado = false;

    // Recorrer la cola original
    while (!cola.esVacia()) {
        int elemento = cola.desencolar();

        // Si encontramos "n", dejamos de sumar
        if (elemento == n) {
            encontrado = true;
            // No lo encolamos en la suma, pero lo encolamos en la auxiliar
        } else {
            suma += elemento;  // Sumar los elementos que no sean "n"
        }

        // Encolamos todos los elementos en la cola auxiliar para restaurarla luego
        colaAux.encolar(elemento);

        // Si encontramos "n", salimos del bucle
        if (encontrado) {
            break;
        }
    }

    // Transferimos los elementos de vuelta a la cola original
    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }

    // Si no se encontró "n", sumar el resto de los elementos que estaban en la cola
    if (!encontrado) {
        while (!cola.esVacia()) {
            int elemento = cola.desencolar();
            suma += elemento;
            colaAux.encolar(elemento);
        }

        // Restauramos la cola original nuevamente
        while (!colaAux.esVacia()) {
            cola.encolar(colaAux.desencolar());
        }
    }

    return suma;
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
    int numero;

    // Leer la cola desde la entrada del usuario
    std::cout << "Introduce los números para la cola (termina con -1):" << std::endl;
    leerCola(cola);

    // Leer el número n
    std::cout << "Introduce el número 'n': ";
    std::cin >> numero;

    // Imprimir la cola antes de la suma
    std::cout << "Cola original: ";
    imprimirCola(cola);

    // Llamar a la función para sumar hasta "n" y obtener el resultado
    int suma = sumarHastaN(cola, numero);

    // Imprimir el resultado
    std::cout << "La suma de los elementos hasta " << numero << " es: " << suma << std::endl;

    return 0;
}

