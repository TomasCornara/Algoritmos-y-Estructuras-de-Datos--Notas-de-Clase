#include <stdio.h>
#include <stdlib.h>

#include "pilaEstatica.h"

int main() {
    tPila pila;
    int num, tope;

    crearPila(&pila);
    printf("Pila creada. Esta vacia? %s\n", pilaVacia(&pila) ? "Si" : "No");

    // Cargar elementos
    for (int i = 1; i <= 5; i++) {
        if (!ponerEnPila(&pila, &i, sizeof(i))) {
            printf("Error al poner %d en pila (posible pila llena)\n", i);
            break;
        }
        printf("Puesto %d en pila.\n", i);
    }

    printf("Pila llena? %s\n", pilaLlena(&pila) ? "Si" : "No");

    // Ver el tope sin sacar
    if (verTope(&pila, &tope, sizeof(tope)))
        printf("Tope actual: %d\n", tope);

    // Sacar elementos
    printf("Desapilando elementos:\n");
    while (!pilaVacia(&pila)) {
        if (sacarPila(&pila, &num, sizeof(num)))
            printf("  %d\n", num);
        else
            printf("Error al desapilar.\n");
    }

    printf("Pila vacia? %s\n", pilaVacia(&pila) ? "Si" : "No");

    // Poner y vaciar
    int x = 99;
    ponerEnPila(&pila, &x, sizeof(x));
    printf("Puesto %d y luego vaciando pila...\n", x);
    vaciarPila(&pila);
    printf("Pila vacia tras vaciarPila()? %s\n", pilaVacia(&pila) ? "Si" : "No");

    return 0;
}
