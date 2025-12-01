#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    int vec[] = {1,2,3,4,5,6,7,8,9};
    tArbol miArbol;

    crearArbol(&miArbol);

    for(int i = 0; i < sizeof(vec)/sizeof(vec[0]); i++){
        ponerNodo(&miArbol,&vec[i],&vec[i],sizeof(vec[0]),cmpIntMen);
    }

    imprimirArbol(&miArbol,mostrarEntero);
    printf("\n");

    return 0;
}
