#include <iostream>
#include "Cola/Cola.h"  // Incluye la clase de la cola

void leerCola(Cola<int>& cola) {
    char c;
    std::cout << "Ingrese caracteres para la cola (termine con un punto '.'): ";
    while (std::cin >> c && c != '.') {
        cola.encolar(c);
    }
}

bool sonIguales(Cola<int>& cola1, Cola<int>& cola2) {
    // Si ambas colas están vacías, son iguales
    if (cola1.esVacia() && cola2.esVacia()) {
        return true;
    }

    // Mientras ambas colas no estén vacías
    while (!cola1.esVacia() && !cola2.esVacia()) {
        // Desencolamos los elementos para comparar
        char elemento1 = cola1.desencolar();
        char elemento2 = cola2.desencolar();

        // Si algún elemento no coincide, las colas no son iguales
        if (elemento1 != elemento2) {
            return false;
        }
    }

    // Al final, si una cola es vacía y la otra no, tampoco son iguales
    if (!cola1.esVacia() || !cola2.esVacia()) {
        return false;
    }

    return true;
}

int main() {
    Cola<int> cola1;
    Cola<int> cola2;

    // Leer la primera cola
    std::cout << "Primera cola:" << std::endl;
    leerCola(cola1);

    // Leer la segunda cola
    std::cout << "Segunda cola:" << std::endl;
    leerCola(cola2);

    // Llamamos a la función que compara las colas
    if (sonIguales(cola1, cola2)) {
        std::cout << "Las colas son iguales." << std::endl;
    } else {
        std::cout << "Las colas no son iguales." << std::endl;
    }

    return 0;
}