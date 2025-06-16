#include <string.h>
#include "pila_estatica.h"
#define MIN(A,B) (((A) > (B))? (B):(A))


void crearPila(tPila* pila){
    pila->tope = CAPACIDAD_PILA;
}

int apilar(tPila* pila, const void* dato, unsigned cantBytes){

    //Si no hay espacio
    if(sizeof(unsigned) + cantBytes > pila->tope){
        return 0;
    }

    //Si hay espacio, primero hago lugar para el dato y copio
    pila->tope -= cantBytes;
    memcpy(pila->vec + pila->tope,dato,cantBytes);

    //Luego hago lugar para el tam y copio
    pila->tope -= sizeof(unsigned);
    memcpy(pila->vec + pila->tope,&cantBytes,sizeof(unsigned));

    return 1;
}

int desApilar(tPila* pila, void* buffer, unsigned cantBytes){
    unsigned auxTam;

    //Chequeo que no este vacio
    if(pila->tope == CAPACIDAD_PILA) return 0;

    //Leo el tamaño
    memcpy(&auxTam,pila->vec + pila->tope,sizeof(unsigned));
    pila->tope += sizeof(unsigned);

    //Leo el dato
    memcpy(buffer,pila->vec + pila->tope,auxTam);
    pila->tope += auxTam;

    return 1;
}

int pilaVacia(const tPila* pila){
    return pila->tope == CAPACIDAD_PILA;
}

int pilaLlena(const tPila* pila){
    return pila->tope == 0;
}

int verTope(const tPila* pila, void* buffer, unsigned cantBytes){
    unsigned auxTam;

    //Verifico que haya algo que leer
    if(pila->tope == cantBytes) return 0;

    //Leo el tamaño
    memcpy(&auxTam,pila->vec + pila->tope,sizeof(unsigned));

    //Leo el tado
    memcpy(buffer,pila->vec + pila->tope + sizeof(unsigned),MIN(auxTam,cantBytes));

    return 1;
}
