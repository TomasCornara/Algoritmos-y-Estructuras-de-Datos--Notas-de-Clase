#include <stdlib.h>
#include <string.h>
#include "cola.h"

void crearCola(tCola* p){
    p->pri = 0;
    p->ult = 0;
    p->tam_rest = MAX_CAPACIDAD;
}

int colaVacia(const tCola* p){
    return p->tam_rest == MAX_CAPACIDAD;
}

int colaLlena(const tCola* p, unsigned cantBytes){
    return p->tam_rest < cantBytes + sizeof(unsigned);
}

void vaciarCola(tCola* p){
    p->tam_rest = MAX_CAPACIDAD;
    p->pri = p->ult;
}

int encolar(tCola* p, const void* dato, unsigned cantBytes){
    unsigned ini, fin;

    if(p->tam_rest < cantBytes + sizeof(unsigned)){
        return 0;
    }

    /// Encolar tamaño
    ini = MIN(sizeof(unsigned), MAX_CAPACIDAD - p->ult);
    fin = sizeof(unsigned) - ini;

    memcpy(&p->datos[p->ult], (char*)&cantBytes, ini);
    memcpy(&p->datos[0], ((char*)&cantBytes) + ini, fin);
    p->ult = (fin) ? fin : p->ult + ini;

    /// Encolar dato
    ini = MIN(cantBytes, MAX_CAPACIDAD - p->ult);
    fin = cantBytes - ini;

    memcpy(&p->datos[p->ult], (char*)dato, ini);
    memcpy(&p->datos[0], ((char*)dato) + ini, fin);
    p->ult = (fin) ? fin : p->ult + ini;

    p->tam_rest -= cantBytes + sizeof(unsigned);
    return 1;
}

int desencolar(tCola* p, void* dato, unsigned cantBytes) {
    unsigned aux_tam;
    unsigned ini, fin;
    unsigned bytesACopiar;

    if(p->tam_rest == MAX_CAPACIDAD) {
        return 0; // cola vacía
    }

    /// Leer tamaño
    ini = MIN(sizeof(unsigned), MAX_CAPACIDAD - p->pri);
    fin = sizeof(unsigned) - ini;

    memcpy(&aux_tam, &p->datos[p->pri], ini);
    memcpy(((char*)&aux_tam) + ini, &p->datos[0], fin);
    p->pri = (fin) ? fin : p->pri + ini;

    /// Leer datos
    bytesACopiar = MIN(aux_tam, cantBytes);
    ini = MIN(bytesACopiar, MAX_CAPACIDAD - p->pri);
    fin = bytesACopiar - ini;

    memcpy(dato, &p->datos[p->pri], ini);
    memcpy(((char*)dato) + ini, p->datos, fin);

    // Saltar los bytes restantes que no copiamos
    p->pri = (p->pri + aux_tam) % MAX_CAPACIDAD;

    p->tam_rest += aux_tam + sizeof(unsigned);
    return 1;
}
