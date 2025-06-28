#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

int main()
{
    tLista listaDoble;
    int vec[] = {1,2,3,4,5,6,7,8};

    crearLista(&listaDoble);

    for(int i = 0; i < sizeof(vec)/sizeof(vec[0]); i++){
        ponerEnListaOrdenado(&listaDoble,&vec[i],sizeof(vec[0]),cmpInt);
    }

    printLista(&listaDoble,printInt);

    return 0;
}
