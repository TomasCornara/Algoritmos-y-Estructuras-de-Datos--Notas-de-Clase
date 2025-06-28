#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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

int ponerOrdenado(tLista* lista, const void* dato, unsigned cantBytes,Comparar cmp)
{
    tNodo* nue;
    tNodo* aux;
    int res;

    nue = malloc(sizeof(tNodo));
    if(!nue || !(nue->dato = malloc(cantBytes)))
    {
        free(nue);
        return 0;
    }

    if(*lista == NULL)
    {
        nue->ant = NULL;
        nue->sig = NULL;
        *lista = nue;
    }
    else
    {
        while(res = cmp(dato,(*lista)->dato))
        {
            //Si ya estaba
            if(!res)
            {
                free(nue->dato);
                free(nue);
                return 0;
            }

            if(res > 0 && (*lista)->sig != NULL)
            {
                aux = *lista;
                lista = &(*lista)->ant;
            }

            if(res < 0 && (*lista)->ant != NULL)
                aux = *lista;
            lista = &(*lista)->sig;
        }
    }


    //Si esta en el medio entre ambos
    if(aux && *lista)
    {
        //Se corto por izquierda
        if(res > 0)
        {
            nue->ant = aux;
            nue->sig = *lista;
            (*lista)->ant = aux->sig = nue;
        }

        //Se corto por derecha
        if(res < 0)
        {
            nue->sig = aux;
            nue->ant = *lista;
            (*lista)->sig = aux->ant = nue;
        }
    }

    //Si llegue al final por derecha
    if(res > 0 && !(*lista))
    {
        (*lista)->sig = nue;
        nue->ant = *lista;
        nue->sig = NULL;
    }

    if(res < 0 && !(*lista))
    {
        (*lista)->ant = nue;
        nue->sig = *lista;
        nue->ant = NULL;
    }

    //Carga
    memcpy(nue->dato,dato,cantBytes);
    nue->tam = cantBytes;


    return 1;
}


int cmpIntMen(const void* elemA, const void* elemB)
{
    A = *(int*)elemA;
    B = *(int*)elemB;
    return A - B;
}
