#include <stdio.h>
#include <stdlib.h>
#include "expresion_regular.h"

int main()
{
    //char expresion[] = "{[()]}";
    //char expresion[] = "{}[]()";
    char expresion[] = "{([])";
    //char expresion[] = "[{{{()}}}]";
    tPila pila;
    int i;
    char aux;

    crearPila(&pila);

    i = 0;

    while(expresion[i] != '\0')
    {
        //Mientras sea abierto, apilo
        if(esAbierto(expresion[i]))
        {
            if(!apilar(&pila,&expresion[i],sizeof(expresion[0]))){
                printf("Error al apilar\n");
            }

        }
        else     //Si es cerrado, desapilo
        {
            if(!pilaVacia(&pila))
            {
                desApilar(&pila,&aux,sizeof(aux));
            }
            //Si no coinciden, esta mal formado
            if(!coinciden(aux,expresion[i]))
            {
                printf("Expresion mal formada.\n");
                vaciarPila(&pila);
                return 0;
            }
        }
        i++;
    }

    if(!pilaVacia(&pila)){
        printf("Expresion mal formada.\n");
        vaciarPila(&pila);
        return 0;
    }
    printf("Cadena bien formada.\n");

    return 0;
}
