#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dinamica.h"

#define MIN(A,B) (((A) > (B))? (B):(A))

void crearLista(tLista* lista){
    *lista = NULL;
}

int listaVacia(const tLista* lista){
    return *lista == NULL;
}

int listaLlena(const tLista* lista, unsigned cantBytes){
    return 1;
}

void vaciarLista(tLista* lista){
    tNodo* elim;
    while(*lista){
        elim = *lista;
        *lista = elim->siguiente;
        free(elim->dato);
        free(elim);
    }
}

int ponerAlComienzo(tLista* lista, const void* dato, unsigned cantBytes){
    tNodo* entrante;

    //Creacion del nodo
    if(!(entrante = (tNodo*)malloc(sizeof(tNodo))) ||
       !(entrante->dato = malloc(cantBytes)))
    {
        free(entrante);
        return 0;
    }


    //Carga
    entrante->tam = cantBytes;
    memcpy(entrante->dato,dato,cantBytes);

    //Conexion
    entrante->siguiente = *lista;
    *lista = entrante;

    return 1;
}

int sacarPrimeroLista(tLista* lista, void* dato, unsigned cantBytes){
    tNodo* elim;

    //Chequeo inicial
    if(*lista == NULL) return 0;

    //Pase de memoria main
    memcpy(dato,(*lista)->dato,MIN(cantBytes,(*lista)->tam));

    //Desenlace
    elim = *lista;
    *lista = elim->siguiente;
    free(elim->dato);
    free(elim);
    return 1;
}

int verPrimeroLista(const tLista* lista, void* dato, unsigned cantBytes){
    if(*lista == NULL) return 0;

    memcpy(dato,(*lista)->dato,MIN(cantBytes,(*lista)->tam));
    return 1;
}

void map(void* vec, unsigned ce, unsigned tam, void accion(void*)) {
    int i;

    for (i = 0; i < ce; i++) {
        accion(vec);
        vec += tam;
    }
}

void mapListas(void* lis){
    tLista* lista = (tLista*)lis;
    printListaRecursivo(*lista, printNodo);
}

void printListaRecursivo(const tNodo* nodo, void (*prnt)(const void*)) {
    if (nodo == NULL) return;

    printListaRecursivo(nodo->siguiente, prnt);
    prnt(nodo->dato);
}

void printNodo(const void* dato) {
    const tPersona* persona = (const tPersona*)dato;
    printf("%d %s\n", persona->id, persona->nombre);
}

int insertar_ordenado(tLista* lista,const void* dato, unsigned tamDato, int (cmp*)(const void*, const void*)){
    lista* miLista; //Auxliar para recorrer
    tNodo* entrante;

    //Pido memoria
    entrante = (tNodo*)malloc(sizeof(tNodo));
    if(!entrante || entrante->dato = malloc(tamDato)){
        return 0;
    }

    //Traigo el inicio de la lista
    **miLista = *tLista;

    //Recorro hasta que encuentre su lugar
    while(!(*tNodo) && (cmp((*lista)->dato,miLista->dato) > 0)){
        miLista = *(&miLista)->siguiente;
    }

    entrante->siguiente = *miLista;

}

int comparar(const void* elemento1, const void* elemento2){


}
