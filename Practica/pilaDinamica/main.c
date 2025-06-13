#include <stdio.h>
#include <stdlib.h>
#include "pilaDinamica.h"

int main()
{
    tPila mi_pila;
    int mi_vec[] = {1,2,3,4,5,6,7,8};
    int auxiliar;

    crearPila(&mi_pila);

    for(int i = 0; i < sizeof(mi_vec)/sizeof(mi_vec[0]);i++){
        apilar(&mi_pila,&mi_vec[i],sizeof(mi_vec[0]));
    }

    verTope(&mi_pila,&auxiliar,sizeof(unsigned));
    printf("%d\n",auxiliar);

    while(desApilar(&mi_pila,&auxiliar,sizeof(unsigned))){
        printf("%d\n",auxiliar);
    }

    return 0;
}
