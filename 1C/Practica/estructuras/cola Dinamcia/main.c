#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola_dinamica.h"

typedef struct {
    int id;
    char nombre[20];
} Persona;

int main() {
    tCola cola;
    Persona p1 = {1, "Ana"};
    Persona p2 = {2, "Luis"};
    Persona extraido;

    crearCola(&cola);

    // Comprobar si está vacía
    if (colaVacia(&cola))
        printf("Cola vacía al inicio.\n");

    // ponerEnCola elementos
    if (!colaLlena(&cola, sizeof(Persona))) {
        if (ponerEnCola(&cola, &p1, sizeof(Persona)))
            printf("Encolado: %s\n", p1.nombre);
        else
            printf("Fallo al ponerEnCola p1\n");
    }

    if (!colaLlena(&cola, sizeof(Persona))) {
        if (ponerEnCola(&cola, &p2, sizeof(Persona)))
            printf("Encolado: %s\n", p2.nombre);
        else
            printf("Fallo al ponerEnCola p2\n");
    }

    // Ver el primero
    if (verPrimero(&cola, &extraido, sizeof(Persona)))
        printf("Primero en la cola: %s\n", extraido.nombre);
    else
        printf("Error al ver el primero.\n");

    // DesponerEnCola
    if (desEncolar(&cola, &extraido, sizeof(Persona)))
        printf("Desencolado: %s\n", extraido.nombre);
    else
        printf("Error al desponerEnCola.\n");

    // Vaciar cola
    if (vaciarCola(&cola, sizeof(Persona)))
        printf("Cola vaciada.\n");
    else
        printf("Error al vaciar la cola.\n");

    // Comprobar estado final
    if (colaVacia(&cola))
        printf("Cola vacía al final.\n");

    return 0;
}

