#include <stdio.h>
#include <stdlib.h>

#include "pilaEstatica.h"
#include "parentesis.h"

int main()
{
    tPila mi_pila;
    char cadena[] = "[{}](){}[]{{{}}}";
    char *aux, ch;

    crearPila(&mi_pila);

    aux = cadena;
    while(*aux != '\0'){
        //Si es abierto, apilo
        if(esAbierto(*aux)){
            if(ponerEnPila(&mi_pila,aux,sizeof(char))){
               printf("Apilado: %c\n",*aux);
            } else {
                printf("Error al apilar: %c\n",*aux);
            }
        }

        //Si es cerrado, desapilo y comparo
        if(esCerrado(*aux)){
            if(sacarPila(&mi_pila,&ch,sizeof(char))){
               printf("Desapilado: %c\n",ch);
            } else {
                printf("Error al desapilar: %c\n",ch);
            }

            if(!cierran(*aux,ch)){
                vaciarPila(&mi_pila);
                printf("Cadena mal paranterisada\n");
                return 0;
            }
        }

        //Avanzo al siguiente
        aux++;
    }

    printf("Cadena bien paranterisada\n");

    return 0;
}
