#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

void crearLista(tLista* lista)
{
    *lista = NULL;
}

int listaVacia(const tLista* lista)
{
    return !(*lista);
}

int listaLlena(const tLista* lista)
{
    return 0;
}

int ponerEnLista(tLista* lista, const void* dato, unsigned cantByte)
{
    tNodo* nue;
    tNodo* aux;

    //Pido info
    nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue || !(nue->info = malloc(cantByte)))
    {
        free(nue);
        return 0;
    }

    //Si esta vacio
    if(*lista == NULL)
    {
        nue->ant = NULL;
        nue->sig = NULL;
        *lista = nue;
    }
    else
    {
        if(!((*lista)->sig))
        {
            (*lista)->sig = nue;
            nue->sig = NULL;
        }
        else
        {
            aux = (*lista)->sig;
            nue->sig = aux;

            aux->ant = nue;
            (*lista)->sig = nue;
        }
        nue->ant = (*lista);
    }



    //Paso la data
    memcpy(nue->info,dato,cantByte);
    nue->tam = cantByte;

    return 1;
}

void printLista(const tLista* lista, Print prt)
{
    tNodo* aux;

    if(*lista == NULL)
    {
        return;
    }

    aux = *lista;

    // Ir al extremo izquierdo
    while(aux->ant)
        aux = aux->ant;

    // Imprimir de izquierda a derecha
    while(aux)
    {
        prt(aux->info);
        aux = aux->sig;
    }
}


void printInt(const void* elem)
{
    printf("%d",*((int*)elem));
}

int cmpInt(const void* dato1, const void* dato2)
{
    int A = *(int*)dato1;
    int B = *(int*)dato2;

    return A - B;
}

int ponerEnListaOrdenado(tLista* lista, const void* dato, unsigned cantBytes, Comparar cmp)
{
    int res;
    tNodo* nue,
           * ant,
           * sig;

    if(*lista == NULL)
    {
        ant = NULL;
        sig = NULL;
    }
    else
    {
        ant = sig = *lista;
        //Busco a derecha
        while(sig->sig && (res = cmp(dato,sig->info)) > 0){
            ant = sig;
            sig = sig->sig;
        }

        //Busco izquierda
        while(ant->ant && (res = cmp(dato,ant->info)) < 0){
            sig = ant;
            ant = ant->ant;
        }

        res = cmp(dato,sig->info);
        if(res == 0){
            return 0;
        }
    }

    nue = malloc(sizeof(tNodo));
    if(!nue || !(nue->info = malloc(cantBytes)))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,dato,cantBytes);
    nue->tam = cantBytes;

    //Si quedo a la derecha o al medio a la izquierda
    if(res < 0) {
        nue->ant = sig;
        nue->sig = sig->sig;
        if(sig->sig)
            sig->sig->ant = nue;
        sig->sig = nue;
    } else {
        nue->sig = sig;
        nue->ant = sig->ant;
        if(sig->ant)
            sig->ant->sig = nue;
        sig->ant = nue;
    }

    *lista = nue;

    return 1;
}
