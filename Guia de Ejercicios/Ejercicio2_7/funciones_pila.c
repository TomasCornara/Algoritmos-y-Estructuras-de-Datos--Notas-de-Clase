#include <string.h>
#include "pila.h"


void crearPila(tPila *pila){
    pila->tope = CAPACIDAD_PILA;
}

int apilar(tPila *pila, const void *dato, unsigned tamDato){
    unsigned tam_unsigned = sizeof(unsigned);

    //Chequear si hay lugar
    if(tamDato+tam_unsigned > pila->tope){
        return PILA_SIN_LUGAR;
    }

    //Bajo al lugar para el dato y copio
    pila->tope -= tamDato;
    memcpy(pila->pila + pila->tope,dato,tamDato);

    //Bajo al lugar para el tam dato y copio
    pila->tope -= tam_unsigned;
    memcpy(pila->pila + pila->tope,&tamDato,tam_unsigned);

    return EXITO_PILA_APILADA;
}

int desapilar(tPila *pila, void *dato, unsigned tamDato){
    unsigned aux_tam_dato;
    unsigned tam_unsigned = sizeof(unsigned);

    //Verifico que haya algo que leer
    if(pila->tope == CAPACIDAD_PILA){
        return PILA_VACIA;
    }

    //Leo el tam del dato
    memcpy(&aux_tam_dato,pila->pila + pila->tope,tam_unsigned);
    pila->tope += tam_unsigned;

    //Leo el dato
    memcpy(dato,pila->pila + pila->tope,MIN(tamDato,aux_tam_dato));
    pila->tope += aux_tam_dato;

    return EXITO_PILA_DESAPILADA;
}

int pilaLlena(const tPila *pila, unsigned tamDato){
    return ((pila->tope - tamDato) < 0)? PILA_LLENA: PILA_NO_LLENA;
}

int pilaVacia(const tPila *pila){
    return (pila->tope == CAPACIDAD_PILA)? PILA_VACIA: PILA_NO_VACIA;
}

void vaciarPila(tPila *pila){
    pila->tope = CAPACIDAD_PILA;
}

int verTope(const tPila *pila, void *dato, unsigned tamDato){
    unsigned tam_unsigned = sizeof(unsigned);
    unsigned aux_tam_dato;
    const char* px_auxiliar;

    //Verifico que haya algo que sacar
    if(pila->tope == CAPACIDAD_PILA){
        return PILA_VACIA;
    }

    //Busco la ultima posicion, leo el dato y avanzo
    px_auxiliar = pila->pila + pila->tope;
    memcpy(&aux_tam_dato,px_auxiliar,tam_unsigned);
    px_auxiliar += tam_unsigned;

    //Devuelvo el dato
    memcpy(dato,px_auxiliar,aux_tam_dato);

    return EXITO_VER_TOPE;
}
