#include <stdio.h>
#include "cola_circular.h"

#define EXITO 0

int main(void)
{
    unsigned char i;
    int vector[] = {10, 20, 30}, extraido;
    tCola cola;

    crearCola(&cola);

    for (i = 0; i < sizeof(vector) / sizeof(vector[0]); i++)
        if (acolar(&cola, &vector[i], sizeof(vector[0])) != VERDADERO)
            fprintf(stderr, "Error al insertar en la cola.\n");

    puts("Desacolando elementos:");
    while (!colaVacia(&cola))
    {
        if (desacolar(&cola, &extraido, sizeof(extraido)))
            printf("Valor desacolado: %d\n", extraido);
        else
            puts("Error al desacolar.");
    }

    vaciarCola(&cola);

    return EXITO;
}
