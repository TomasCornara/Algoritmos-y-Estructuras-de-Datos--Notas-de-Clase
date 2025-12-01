#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_simple.h"
#define MIN(A,B) (((A)>(B))? (B):(A))

void crearLista(tLista* lista){
    *lista = NULL;
}

int ponerAlComienzo(tLista* lista, const void* dato, unsigned tam){
    tNodo* entrante;

    //Chequeo memoria
    if(!(entrante = malloc(sizeof(tNodo)))|| !(entrante->dato = malloc(tam))){
        free(entrante);
        return 0;
    }

    //Carga del nodo
    memcpy(entrante->dato,dato,tam);
    entrante->tam = tam;
    entrante->siguiente = NULL;

    //Enganche
    entrante->siguiente = *lista;
    *lista = entrante;

    return 1;
}

int verPrimero(const tLista* lista, void* dato, unsigned tam){
    if(*lista == NULL) return 0;

    memcpy(dato,(*lista)->dato,MIN(tam,(*lista)->tam));

    return 1;
}

int sacarPrimero(tLista* lista, void* dato, unsigned tam){
    tNodo* eliminar;

    //Chequeo que haya algo
    if(*lista == NULL) return 0;

    //Cargo eliminar y devuelvo el dato
    eliminar = *lista;
    memcpy(dato,eliminar->dato,MIN(tam,eliminar->tam));

    //Re enlazo
    *lista = eliminar->siguiente;

    //Devuelvo memoria
    free(eliminar->dato);
    free(eliminar);

    return 1;
}

int ponerAlFinal(tLista* lista, const void* dato, unsigned tam){
    tNodo* entrante;

    //Chequeo memoria
    if(!(entrante = malloc(sizeof(tNodo)))|| !(entrante->dato = malloc(tam))){
        free(entrante);
        return 0;
    }

    //Recorro
    while(*lista){
        lista = &(*lista)->siguiente;
    }

    //Cargo
    memcpy(entrante->dato, dato,tam);
    entrante->tam = tam;
    entrante->siguiente = NULL;

    //Enlazo
    *lista = entrante;

    return 1;
}

int listaLlena(const tLista* lista, unsigned tam){
    tNodo* aux;
    void* info;

    aux = (tNodo*)malloc(sizeof(tNodo));
    if(!aux || !(info = malloc(tam))){
        free(aux);
        return 0;
    }

    free(aux);
    free(info);

    return 1;
}

void vaciarLista(tLista* lista){
    tNodo* aux;

    while(*lista){
        aux = *lista;
        *lista = aux->siguiente;
        free(aux->dato);
        free(aux);
    }
}

int sacarUltimoLista(tLista* lista, void* dato, unsigned tam){
    //Chequeo que haya algo
    if(*lista == NULL) return 0;

    while((*lista)->siguiente){
        lista = &(*lista)->siguiente;
    }
    memcpy(dato,(*lista)->dato,MIN(tam,(*lista)->tam));
    free((*lista)->dato);
    free(*lista);
    *lista = NULL;
    return 1;
}

int verUltimoLista(const tLista* lista, void* dato, unsigned cantBytes){
    if(*lista == NULL) return 0;

    while((*lista)->siguiente){
        lista = &(*lista)->siguiente;
    }
    memcpy(dato,(*lista)->dato,MIN(cantBytes,(*lista)->tam));
    return 1;
}

int eliminar(tLista* lista, const void* clave, accion cmp){
    tNodo* eliminar;

    while((*lista)){
        if(cmp((*lista)->dato, clave) == 0){
            eliminar = *lista;
            *lista = eliminar->siguiente;
            free(eliminar->dato);
            free(eliminar);
            return 1;
        }

        lista = &((*lista)->siguiente);
    }
    return 0;
}

int insertarOrdenado(tLista* lista, const void* dato, unsigned cantBytes, accion cmp){
    tNodo* entrante;

    //Pido el espacio para el nodo
    entrante = (tNodo*)malloc(sizeof(tNodo));
    if(!entrante || !(entrante->dato = malloc(cantBytes))){
        free(entrante);
        return 0;
    }

    //Lo cargo
    memcpy(entrante->dato,dato,cantBytes);
    entrante->tam = cantBytes;

    //Si esta vacia
    if(*lista == NULL){
        entrante->siguiente = NULL;
        *lista = entrante;
        return 1;
    }


    //Busco la posicion
    while(*lista && (cmp(dato,(*lista)->dato) > 0)){
        lista = &(*lista)->siguiente;
    }

    //Enlazo
    entrante->siguiente = *lista;
    *lista = entrante;

    return 1;
}

int insertanEnPosicion(tLista* lista, unsigned pos, const void* dato, unsigned cantBytes){
    int i;
    tNodo* entrante;

    //Pido memoria para el nodo
    entrante = (tNodo*)malloc(sizeof(tNodo));
    if(!entrante || !(entrante->dato = malloc(cantBytes))){
        free(entrante);
        return 0;
    }

    //Cargo el nodo
    memcpy(entrante->dato,dato,cantBytes);
    entrante->tam = cantBytes;

    //Busco su posicion
    for(i = 0; i != pos && (*lista) != NULL; i++, lista = &(*lista)->siguiente);

    printf("///%d",i);
    if(i == pos){
        entrante->siguiente = *lista;
        *lista = entrante;
        return 1;
    } else {
        return 0;
    }
}

int cmp_int(const void* elemA,const void* elemB){
    int a = *(int*)elemA;
    int b = *(int*)elemB;

    return a-b;
}

void mostrarLista(const tLista* lista) {
    const tLista* pl = lista;
    int valor;

    printf("Lista: ");
    while (*pl) {
        memcpy(&valor, (*pl)->dato, sizeof(int));
        printf("%d -> ", valor);
        pl = &(*pl)->siguiente;
    }
    printf("NULL\n");
}

int eliminarPrimera(tLista* lista, const void* key, accion cmp){
    tNodo* eliminar;
    int res;

    //Comprueblo que no haya NULL y busco el siguiente
    while(*lista != NULL && (res = cmp(key,(*lista)->dato)) != 0){
        lista = &(*lista)->siguiente;
    }

    if(!res){
        eliminar = (*lista)->siguiente;
        *lista = eliminar->siguiente;
        free(eliminar->dato);
        free(eliminar);

        return 1;
    }

    return 0;
}

int eliminarTodas(tLista* lista, const void* key, accion cmp){
    int eliminados = 0;
    tNodo* eliminar;

    while(*lista) {
        if(cmp(key, (*lista)->dato) == 0) {
            eliminar = *lista;
            *lista = eliminar->siguiente;
            free(eliminar->dato);
            free(eliminar);
            eliminados++;
        } else {
            lista = &(*lista)->siguiente;
        }
    }

    return eliminados;
}

int eliminarPosicion(tLista* lista, unsigned pos){
    int i;
    tNodo* eliminar;

    for(i = 0; (i != pos) && ((*lista) != NULL); i++, lista=&(*lista)->siguiente);

    if((*lista) == NULL) return 0;

    eliminar = *lista;
    *lista = eliminar->siguiente;
    free(eliminar->dato);
    free(eliminar);

    return 1;
}

void eliminarRepetidos(tLista* lista,accion cmp){
    while(*lista){
        eliminarTodas(&(*lista)->siguiente,(*lista)->dato,cmp);
        lista = &(*lista)->siguiente;
    }
}
