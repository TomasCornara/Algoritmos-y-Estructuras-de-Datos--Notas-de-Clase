#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


//CREAR LISTA
void crearLista(lista* lista)
{
    *lista = NULL;
}

//PONER PRIMERO
int ponerPrimero(lista* lista,const void* dato,unsigned cantBytes)
{
    tNodo* nue;


    //Creacion del nodo entrante
    nue = malloc(sizeof(tNodo));
    if(!nue || !(nue->info = malloc(cantBytes)) )
    {
        free(nue);
        return 0;
    }

    //Si no habia nada
    if(*lista == NULL)
    {
        nue->sig = NULL;
    }
    else     //Si habia algo
    {
        while((*lista)->ant != NULL)
        {
            *lista = (*lista)->ant;
        }
        (*lista)->ant = nue;
        nue->sig = *lista;
    }

    *lista = nue;

    //Carga entrante
    nue->ant = NULL;
    nue->tam = cantBytes;
    memcpy(nue->info,dato,cantBytes);
    return 1;
}

void mostrarLista(const lista* head) {
    const tNodo* nodo = *head;
    while(nodo && nodo->ant) // ir al primero
        nodo = nodo->ant;

    while(nodo) {
        printf("%d ", *(int*)(nodo->info));
        nodo = nodo->sig;
    }
    puts("");
}
