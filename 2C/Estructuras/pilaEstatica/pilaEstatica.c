#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilaEstatica.h"

void crearPila(tPila* pila){
    pila->tope = MAX_PILA;
}

int pilaLlena(const tPila* pila){
    return !pila->tope;
}

int pilaVacia(const tPila* pila){
    return pila->tope == MAX_PILA;
}

void vaciarPila(tPila* pila){
    pila->tope = MAX_PILA;
}

int verTope(const tPila* pila, void* dato,unsigned cantBytes){
    unsigned auxTam;

    //Compruebo que la pila no este vacia
    if(pila->tope == MAX_PILA){
        return 0;
    }

    //Si hay algo, leo el tam dato
    memcpy(&auxTam,pila->pila,sizeof(unsigned));

    //Una vez hecho eso, leo el minimo entre ambos hacia dato
    memcpy(dato,pila->pila + pila->tope + sizeof(unsigned),MIN(auxTam,cantBytes));

    //Todo ok
    return 1;
}

int desapilar(tPila* pila, void* dato, unsigned cantBytes){
    unsigned auxTam;

    //Compruebo que no este vacia
    if(pila->tope == MAX_PILA){
        return 0;
    }

    //Si hay algo, leo el tam dato y avanzo el tope
    memcpy(&auxTam,pila->pila + pila->tope,sizeof(unsigned));
    pila->tope += sizeof(unsigned);

    //Leo el dato
    memcpy(dato,pila->pila + pila->tope,MIN(auxTam,cantBytes));
    pila->tope += auxTam;

    return 1;
}

int apilar(tPila* pila, const void* dato, unsigned cantBytes){
    //Compruebo que haya suficiente espacio
    if(pila->tope < sizeof(unsigned) + cantBytes){
        return 0;
    }

    //hago lugar y pongo el dato
    pila->tope -= cantBytes;
    memcpy(pila->pila + pila->tope,dato,cantBytes);

    //Hago lugar para el tamdato y escribo
    pila->tope -= sizeof(unsigned);
    memcpy(pila->pila + pila->tope,&cantBytes,sizeof(unsigned));

    return 1;
}
