#include <stdio.h>
#include <stdlib.h>
#include "pilaEstatica.h"

int main()
{
    int numeritos[] = {9,8,7,6,5,4,3,2,1};
    int aux;
    tPila pila;

    //Inicio pila
    crearPila(&pila);

    //Los pongo en pila
    for(int i = 0; i < sizeof(numeritos)/sizeof(numeritos[0]);i++){
        apilar(&pila,&numeritos[i],sizeof(numeritos[0]));
    }

    //Desapilo y muestro
    while(!pilaVacia(&pila)){
        desapilar(&pila,&aux,sizeof(numeritos[0]));
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
