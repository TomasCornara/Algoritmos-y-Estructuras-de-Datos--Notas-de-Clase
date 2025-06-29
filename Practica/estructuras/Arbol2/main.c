#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    int vec[] = {2,3,1,20,5,7,8,0};
    tArbol arbol;
    FILE* arch;

    arch = fopen("arbol.txt","wt");
    if(!arch){
        return 0;
    }

    crearArbol(&arbol);

    for(int i = 0; i < sizeof(vec)/sizeof(vec[0]); i++){
        ponerEnArbol(&arbol,&vec[i],sizeof(vec[0]),cmpIntMen);
    }

    mostrarArbolConForma(&arbol,printInt,0);

    guardarArbol(&arbol,arch);

    liberarArbol(&arbol);

    if(arbol == NULL){
        printf("Todo correcto.\n");
    }

    return 0;
}
