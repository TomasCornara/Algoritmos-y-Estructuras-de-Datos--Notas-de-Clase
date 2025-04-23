#include "cola.h"
#include <string.h>
#define MIN(A,B) (((A) > (B))? (B):(A))

void crearCola(tCola *cola){
    cola->tam_disp = TAM_COLA;
    cola->primero = 0;
    cola->ultimo = 0;
}

void vaciarCola(tCola *cola){
    cola->tam_disp = TAM_COLA;
    cola->primero = 0;
    cola->ultimo = 0;
}

int colaVacia(const tCola *cola){
    return cola->tam_disp == TAM_COLA;
}

int colaLlena(const tCola *cola, unsigned cantBytes){
    return cola->tam_disp < (cantBytes + sizeof(unsigned));
}

int verPrimero(const tCola* cola, void* dato, unsigned cantBytes)
{
    unsigned tam, ini, fin;

    // Verifico si hay algo en la cola
    if(cola->tam_disp == TAM_COLA)
        return 0;

    // Leo el tamaño del dato
    ini = MIN(TAM_COLA - cola->primero, sizeof(tam));
    if(ini)
        memcpy(&tam, cola->cola + cola->primero, ini);

    fin = sizeof(tam) - ini;
    if(fin)
        memcpy((char*)&tam + ini, cola->cola, fin);

    // Valido que el dato quepa en el destino
    if(tam > cantBytes)
        return 0;

    // Leo el dato sin modificar la cola
    unsigned posDato = (cola->primero + sizeof(tam)) % TAM_COLA;

    ini = MIN(TAM_COLA - posDato, tam);
    if(ini)
        memcpy(dato, cola->cola + posDato, ini);

    fin = tam - ini;
    if(fin)
        memcpy((char*)dato + ini, cola->cola, fin);

    return 1;
}

int enColar(tCola* cola, const void* dato, unsigned tam)
{
    unsigned ini, fin;

    // Verifico si hay espacio suficiente para el tamaño y los datos
    if(cola->tam_disp < tam + sizeof(tam))
        return 0;

    // Reservo el espacio necesario
    cola->tam_disp -= tam + sizeof(tam);

    // Copio el tamaño del dato en la cola (puede dividirse por el final del buffer)
    ini = MIN(TAM_COLA - cola->ultimo, sizeof(tam));
    if(ini)
        memcpy(cola->cola + cola->ultimo, &tam, ini);

    fin = sizeof(tam) - ini;
    if(fin)
        memcpy(cola->cola, (char*)&tam + ini, fin);

    // Actualizo la posición del último
    cola->ultimo = fin ? fin : cola->ultimo + ini;

    // Copio el dato (también puede dividirse por el final del buffer)
    ini = MIN(TAM_COLA - cola->ultimo, tam);
    if(ini)
        memcpy(cola->cola + cola->ultimo, dato, ini);

    fin = tam - ini;
    if(fin)
        memcpy(cola->cola, (char*)dato + ini, fin);
    // Actualizo la posición del último
    //cola->ultimo = fin ? fin : cola->ultimo + tam;
    cola->ultimo = fin ? fin : cola->ultimo + ini;

    return 1;
}




int desEnColar(tCola *cola, void *dato, unsigned cantBytes);




