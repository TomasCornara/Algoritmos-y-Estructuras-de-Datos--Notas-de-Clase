#include <stdio.h>
#include <stdlib.h>
#include "pila_dinamica.h"

int main() {
    tPila pila;
    int valor, extraido;

    crearPila(&pila);

    valor = 10;
    apilar(&pila, &valor, sizeof(valor));

    valor = 20;
    apilar(&pila, &valor, sizeof(valor));

    valor = 30;
    apilar(&pila, &valor, sizeof(valor));

    /*printf("Desapilando elementos:\n");
    while (!pilaVacia(&pila)) {
        if (desapilar(&pila, &extraido, sizeof(extraido)))
            printf("Valor desapilado: %d\n", extraido);
        else
            printf("Error al desapilar.\n");
    }*/

    vaciarPila(&pila);

    if(pilaVacia(&pila)){
        printf("Todo bien");
    }

    return 0;
}

