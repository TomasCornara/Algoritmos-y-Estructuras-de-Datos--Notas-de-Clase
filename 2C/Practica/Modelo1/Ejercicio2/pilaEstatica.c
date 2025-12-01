#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilaEstatica.h"

void crearPila(tPila* pila){
    pila->tope = MAX_PILA;
}

int pilaLlena(const tPila* pila){
    return !(pila->tope);
}

int pilaVacia(const tPila* pila){
    return pila->tope == MAX_PILA;
}

void vaciarPila(tPila* pila){
    pila->tope = MAX_PILA;
}

int ponerEnPila(tPila* pila, const void* dato, unsigned cantBytes){
    //Chequear que haya espacio
    if(cantBytes + sizeof(unsigned) > pila->tope){
        return 0;
    }

    //Muevo el tope y pongo el dato
    pila->tope -= cantBytes;
    memcpy(pila->base + pila->tope,dato,cantBytes);

    //Muevo el tope y pongo el tam
    pila->tope -= sizeof(unsigned);
    memcpy(pila->base + pila->tope,&cantBytes,sizeof(unsigned));

    return 1;
}

int sacarPila(tPila* pila, void* buffer, unsigned cantBytes){
    unsigned tamDato;

    //Chequear que haya algo en la pila
    if(pila->tope == MAX_PILA){
        return 0;
    }

    //Saco el tam dato
    memcpy(&tamDato,pila->base + pila->tope,sizeof(unsigned));
    pila->tope += sizeof(unsigned);

    //Saco el dato
    memcpy(buffer,pila->base + pila->tope,MIN(tamDato,cantBytes));
    pila->tope += tamDato;

    return 1;
}

int verTope(const tPila* pila, void* buffer, unsigned cantBytes){
    unsigned tamDato;

    if(pila->tope == MAX_PILA){
        return 0;
    }

    memcpy(&tamDato,pila->base + pila->tope,sizeof(unsigned));
    memcpy(buffer,pila->base + pila->tope + sizeof(tamDato),MIN(tamDato,cantBytes));

    return 1;
}
