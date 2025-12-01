#include <string.h>
#include "pila.h"

void crearPila(tPila* pila){
   pila->ultimo = CAPACIDAD_PILA;
}

int pilaVacia(const tPila* pila){
    return pila->ultimo == CAPACIDAD_PILA;
}

int pilaLlena(const tPila* pila){
    return pila->ultimo == 0;
}

int desApilar(tPila* pila, void* dato, unsigned cantBytes){
    unsigned tam;

    //Si la pila esta vacia
    if(CAPACIDAD_PILA == pila->ultimo){
        return 0;
    }

    memcpy(&tam,pila->vec + pila->ultimo,sizeof(unsigned));
    pila->ultimo += sizeof(unsigned);

    memcpy(dato,pila->vec + pila->ultimo,MIN(tam,cantBytes));
    pila->ultimo += tam;

    return 1;
}

int pila_llena(const tPila* pila, unsigned tam){
    return pila->ultimo < tam + sizeof(unsigned);
}


int apilar(tPila* pila, const void* dato, unsigned cantBytes){

    //Controlo que hay espacio
    if(pila->ultimo < cantBytes + sizeof(unsigned)){
        return 0; //No hay espacio
    }

    pila->ultimo-= cantBytes;
    memcpy(pila->vec + pila->ultimo,dato,cantBytes);

    pila->ultimo -= sizeof(unsigned);
    memcpy(pila->vec + pila->ultimo,&cantBytes,sizeof(cantBytes));

    return 1;
}

int verTope(const tPila* pila, void* dato, unsigned cantBytes){
    unsigned tam;

    //Si la pila esta vacia
    if(pila->ultimo == CAPACIDAD_PILA){
        return 0;
    }

    //Leo el tam del archivo
    memcpy(&tam,pila->vec + pila->ultimo,sizeof(unsigned));

    //Leo el dato
    memcpy(dato,pila->vec + pila->ultimo + sizeof(unsigned),MIN(tam,cantBytes));

    return 1;
}

void vaciarPila(tPila* pila){
    pila->ultimo = CAPACIDAD_PILA;
}
