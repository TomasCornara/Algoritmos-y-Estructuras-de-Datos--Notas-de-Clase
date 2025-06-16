#include <stdio.h>
#include <stdlib.h>
#include "colaEstatica.h"

int main()
{
    int aux;
    tCola mi_cola;
    int vec[] = {1,2,3,4,5,6,7,8};

    crearCola(&mi_cola);

    for(int i = 0; i < sizeof(vec)/sizeof(vec[0]);i++){
        encolar(&mi_cola, &vec[i], sizeof(int));
    }

    verPrimero(&mi_cola,&aux,sizeof(int));
    printf("Primero: %d\n",aux);

    while(desEncolar(&mi_cola,&aux,sizeof(int))){
        printf("%d",aux);
    }

    return 0;
}
