#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    int i;
    int mi_vectorcito[] = {10,30,20,1,2,3,40,50};
    arbol mi_arbol;

    crearArbol(&mi_arbol);

    for(i = 0; i < sizeof(mi_vectorcito)/sizeof(mi_vectorcito[0]); i++){
        insertarNodo(&mi_arbol,&mi_vectorcito[i],sizeof(mi_vectorcito[0]),cmp_int);
    }

    imprimirArbolGen(mi_arbol,4,imprimirEntero);

    return 0;
}
