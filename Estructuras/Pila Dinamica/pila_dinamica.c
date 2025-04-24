#include <stdlib.h>
#include <string.h>
#include "pila_dinamica.h"
#define MIN(A,B) (((A)>(B))? (B):(A))

void vaciarPilaRecursivo(tNodo* nodo);

void crearPila(tPila* pila){
    *pila = NULL;
}

int pilaVacia(tPila* pila){
    return *pila == NULL;
}

int pilaLlena(tPila* pila, unsigned cantBytes){
    tNodo* aux;

    aux = (tNodo*)malloc(sizeof(tNodo));
    if(!aux){
        return ERROR_PILA_LLENA;
    }

    return EXITO_LUGAR_EN_PILA;
}

int apilar(tPila* pila, const void* dato, unsigned cantBytes){
    tNodo* entrante;
    tNodo* auxiliar;

    ///Creacion del nuevo nodo
    //Pido memoeria para el nodo
    entrante = (tNodo*)malloc(sizeof(tNodo));
    if(!entrante) return ERROR_FALTA_MEMORIA;

    //Pido memoria para su dato
    entrante->dato = malloc(cantBytes);
    if(!entrante->dato){
        free(entrante);
        return ERROR_FALTA_MEMORIA;
    }

    //Cargo el resto de los datos
    entrante->siguiente = NULL;
    entrante->tam_dato = cantBytes;
    memcpy(entrante->dato,dato,cantBytes);

    ///Apilamiento
    //Si se pudo pedir correctamente memoria, hay que enlazar el nuevo dato
    //Si es el primer nodo, se hace directo
    if(*pila == NULL){
        *pila = entrante;
        return EXITO_APILADO;
    }

    //Si no es el primero, hay que guardar el anterior y re-enlazar
    auxiliar = *pila;
    *pila = entrante;
    entrante->siguiente = auxiliar;
    return EXITO_APILADO;
}

int verTope(const tPila* pila, void* dato, unsigned cantBytes){
    if(*pila == NULL) return ERROR_PILA_VACIA;

    memcpy(dato,(*pila)->dato,MIN(cantBytes,(*pila)->tam_dato));

    return EXITO_VER_TOPE;
}

int desapilar(tPila* pila, void* dato, unsigned cantBytes){
    tNodo* eliminar;

    //Chequeo que haya algo que sacar
    if(!*pila) return ERROR_PILA_VACIA;

    eliminar = *pila;
    *pila = eliminar->siguiente;

    memcpy(dato,eliminar->dato,MIN(cantBytes,eliminar->tam_dato));
    free(eliminar->dato);
    free(eliminar);

    return EXITO_DESAPILAR;
}

void vaciarPila(tPila* pila){
   vaciarPilaRecursivo(*pila);
   *pila = NULL;
}

void vaciarPilaRecursivo(tNodo* nodo){
    //Chequeo si este no es el ultimo nodo
    if(!nodo->siguiente) return;

    //Si no es el caso, busco el siguiente
    vaciarPilaRecursivo(nodo->siguiente);

    //Cuando vuelvo, libero la memoria
    free(nodo->dato);
    free(nodo);
    return;
}
