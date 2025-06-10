#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    int i;
    int mi_vector[] = {1,4,5,-1,2,3};
    lista head;

    crearLista(&head);

    for(i = 0; i < sizeof(mi_vector)/sizeof(mi_vector[0]); i++){
        ponerPrimero(&head,&mi_vector[i],sizeof(mi_vector[0]));
    }

    mostrarLista(&head);

    return 0;
}

