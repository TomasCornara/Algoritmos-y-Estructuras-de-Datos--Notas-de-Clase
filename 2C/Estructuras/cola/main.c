#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main(void)
{
    tCola cola;
    int x, i;

    crearCola(&cola);

    printf("Encolando números del 1 al 5...\n");
    for(i = 1; i <= 5; i++) {
        if(encolar(&cola, &i, sizeof(i)))
            printf("Encolado: %d\n", i);
        else
            printf("Error: cola llena al intentar encolar %d\n", i);
    }

    printf("\nDesencolando números...\n");
    while(!colaVacia(&cola)) {
        if(desencolar(&cola, &x, sizeof(x)))
            printf("Desencolado: %d\n", x);
        else
            printf("Error al desencolar\n");
    }

    printf("\nProbando vaciar la cola...\n");
    for(i = 10; i < 15; i++)
        encolar(&cola, &i, sizeof(i));

    vaciarCola(&cola);
    if(colaVacia(&cola))
        printf("Cola vaciada correctamente\n");
    else
        printf("Error: la cola no está vacía\n");

    return 0;
}
