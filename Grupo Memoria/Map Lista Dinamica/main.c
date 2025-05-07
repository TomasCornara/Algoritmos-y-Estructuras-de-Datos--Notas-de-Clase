#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dinamica.h"



int main() {
    tLista lista;
    crearLista(&lista);

    // Datos para insertar
    tPersona p1 = {1, "Juan"};
    tPersona p2 = {2, "Maria"};
    tPersona p3 = {3, "Carlos"};

    // Inserciones
    ponerAlComienzo(&lista, &p1, sizeof(tPersona));
    ponerAlComienzo(&lista, &p2, sizeof(tPersona));
    ponerAlComienzo(&lista, &p3, sizeof(tPersona));

    map(&lista,1,lista->tam,mapListas);

    return 0;
}

