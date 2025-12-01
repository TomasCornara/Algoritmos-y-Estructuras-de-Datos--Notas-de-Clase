#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main() {
    tCola cola = NULL;
    int nums[] = {10, 20, 30, 40, 50};
    int extraido;

    // Encolar
    for (int i = 0; i < 5; i++) {
        encolar(&cola, &nums[i], sizeof(int));
    }

    printf("Cola ahora:\n");
    mapCola(&cola,imprimirInt);

    // Desencolar uno por uno
    while (desEncolar(&cola, &extraido, sizeof(int))) {
        printf("\nElemento desencolado: %d\n", extraido);
        printf("Cola ahora:\n");
        mostrarCola(cola);
    }

    return 0;
}

