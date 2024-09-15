#include <iostream>
#include "Cola/Cola.h"  // Incluye la clase de la cola

// Función para eliminar todas las ocurrencias de un número, excepto la primera
void eliminarOcurrencias(Cola<int>& cola, int numero) {
    Cola<int> colaDepurada;  // Cola auxiliar para guardar los elementos filtrados
    bool primeraOcurrencia = false;  // Para rastrear si ya hemos encontrado la primera ocurrencia del número

    // Recorrer la cola original
    while (!cola.esVacia()) {
        int elemento = cola.desencolar();

        // Si encontramos el número y es la primera vez que lo vemos
        if (elemento == numero && !primeraOcurrencia) {
            colaDepurada.encolar(elemento);  // Mantenemos la primera ocurrencia
            primeraOcurrencia = true;  // Marcamos que ya hemos encontrado la primera ocurrencia
        }
        // Si encontramos el número, pero ya hemos guardado la primera ocurrencia, lo ignoramos
        else if (elemento == numero && primeraOcurrencia) {
            // No lo encolamos, eliminamos las ocurrencias posteriores
        }
        // Encolamos cualquier otro elemento que no sea el número
        else {
            colaDepurada.encolar(elemento);
        }
    }

    // Restaurar la cola original con la cola depurada
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
    int numero;

    // Leer la cola desde la entrada del usuario
    std::cout << "Introduce los números para la cola (termina con -1):" << std::endl;
    leerCola(cola);

    // Leer el número a eliminar (excepto la primera ocurrencia)
    std::cout << "Ingresa el número que deseas eliminar (excepto la primera ocurrencia): ";
    std::cin >> numero;

    // Eliminar todas las ocurrencias menos la primera
    eliminarOcurrencias(cola, numero);

    // Imprimir la cola final para verificar las modificaciones
    std::cout << "Cola final: ";
    imprimirCola(cola);

    return 0;
}