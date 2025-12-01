#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

int main()
{
    int i;
    tLista mi_lista;
    int mi_vector[] = {1,4,5,3,2,0,1};

    //Creo lista
    crearLista(&mi_lista);

    //Cargo de cosas
    for(i = 0; i < sizeof(mi_vector)/sizeof(mi_vector[0]); i++){
        printf("%d\n",insertarNodo(&mi_lista,&mi_vector[i],sizeof(mi_vector[0]),cmpInt));
    }

    mapearIzq(&mi_lista,mostrarInt);
    mapearDer(&mi_lista,mostrarInt);

    return 0;
}
