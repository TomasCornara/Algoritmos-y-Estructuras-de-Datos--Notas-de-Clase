#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista_doble.h"

#define MIN(A,B) (((A) > (B))? (B):(A))

void crearLista(tLista* lista){
    *lista = NULL;
}

/*int ponerEnLista(tLista* lista, const void* origen, unned cantBytes, accion cmp){
    tNodo* auxAnt;
    tNodo* aux;
    tNodo* actual;
    tNodo* entrante;

    actual = *lista;

    //Caso lista vacia
    if(!actual){
        aux = auxAnt = NULL;
    }
    else {
        aux = actual->uiente;
        auxAnt = actual->ant;

        //Derecha
        while(aux && cmp(origen,actual->dato) > 0){
            actual = actual->uiente;
        }

        //Izquierda
        while(auxAnt && cmp(origen,actual->dato) > 0){
            actual = actual->ant;
        }

        //Duplicado
        if(!cmp(origen,actual->dato))
            return 0;


        if(cmp(origen,actual->dato)<0){
            auxAnt = actual->ant;
            aux = actual;
        }
        else{
            auxAnt = actual;
            aux = actual->uiente;
        }

    }


    //Pido memoria
    entrante = (tNodo*)malloc(sizeof(tNodo));
    if(!entrante || !(entrante->dato = malloc(cantBytes))){
        free(entrante);
        return 0;
    }
    //Cargo el nodo
    memcpy(entrante->dato,origen,cantBytes);
    entrante->tam = cantBytes;

    //Insercion
    entrante->ant = auxAnt;
    entrante->uiente = aux;
    if(aux) aux->ant = entrante;
    if(auxAnt) auxAnt->uiente = entrante;
    *lista = entrante;
    return 1;
}*/

int insertarNodo(tLista *lista, void * dato, unsigned tam, accion comparar)
{
    tNodo *aux, *auxAnt, *act,*nue;
    if(*lista==NULL)
    {
        auxAnt=NULL;
        aux=NULL;
    }
    else
    {
        act=*lista;
        while(act->sig && comparar(act->dato, dato)<0)
            act=act->sig;

        while(act->ant && comparar(act->dato, dato)>0)
            act=act->ant;

        if(comparar(act->dato, dato)==0)
            return DUPLICADO;//SINO PUEDO PONER ACCION

        else if(comparar(act->dato, dato)<0)
        {
            auxAnt=act;
            aux=act->sig;
        }
        else
        {
            auxAnt=act->ant;
            aux=act;
        }
    }
    nue=(tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEM;
    nue->dato=malloc(tam);
    if(!nue->dato)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->dato, dato, tam);
    nue->tam=tam;
    nue->sig=aux;
    nue->ant=auxAnt;

    if(auxAnt!=NULL)
        auxAnt->sig=nue;
    if(aux!=NULL)
        aux->ant=nue;

    *lista=nue;

    return REALIZADO;
}

void mostrarInt(const void*a){
    printf("%d ",*(int*)a);
}

int cmpInt(const void* elemA, const void* elemB){
    int A;
    int B;

    A = *(int*)elemA;
    B = *(int*)elemB;

    return A - B;
}

void mapearIzq(tLista*pl,void acc(const void*)){

    if(*pl == NULL)
        return;

    while( (*pl)->ant != NULL)
        pl = &(*pl)->ant;

    while(*pl){
        acc((*pl)->dato);
        pl = &(*pl)->sig;
    }
}

void mapearDer(tLista*pl,void acc(const void*)){

    while( (*pl)->sig != NULL)
        pl = &(*pl)->sig;
    while(*pl){
        acc((*pl)->dato);
        pl = &(*pl)->ant;
    }
}
