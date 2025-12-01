#include <stdio.h>
#include <stdlib.h>
#include "ordenar_seleccion.h"

int main()
{
    int vec[] = {3,4,1,10,20,30};

    printf("Vector sin ordenar:\n");
    for(int i = 0; i < sizeof(vec)/sizeof(vec[0]);i++){
        printf("%d\t",vec[i]);
    }
    printf("\n");

    ordenarSeleccion(vec,sizeof(vec[0]),sizeof(vec)/sizeof(vec[0]),intMenor);

    printf("Vector ordenado:\n");
    for(int i = 0; i < sizeof(vec)/sizeof(vec[0]);i++){
        printf("%d\t",vec[i]);
    }
    printf("\n");

    return 0;
}
