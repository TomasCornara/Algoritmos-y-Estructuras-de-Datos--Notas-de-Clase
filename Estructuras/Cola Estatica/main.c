#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    tCola cola;
    char texto[] = "Hello Word";
    char vacio[14];

    crearCola(&cola);

    if(enColar(&cola,texto,sizeof(texto))){
        printf("Todo Ok\n");
    } else {
        printf("Todo Mal\n");
    }

    verPrimero(&cola,vacio,11);
    printf("%s",vacio);

    return 0;
}
