#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilaDinamica.h"

#define NANA_VAR {int n = 10}

int main()
{
    int numeritos[] = {9,8,7,6,5,4,3,2,1};
    int aux;
    tPila pila;

    printf("n = %d\n", NANA_VAR);

    //Inicio pila
    crearPila(&pila);

    //Los pongo en pila
    for(int i = 0; i < sizeof(numeritos)/sizeof(numeritos[0]);i++){
        if(!apilar(&pila,&numeritos[i],sizeof(numeritos[0]))){
            printf("Error al apilar.\n");
        }
    }

    //Desapilo y muestro
    while(!pilaVacia(&pila)){
        if(!desApilar(&pila,&aux,sizeof(numeritos[0]))){
            printf("Error al desapilar.\n");
        }
        printf("%d\n",aux);
    }

    //Chequeo que haya quedado vacio
    printf("\n\n");
    if(pilaVacia(&pila)){
        printf("Todo Ok");
    } else {
        printf("Todo Mal");
    }

    return 0;
}

