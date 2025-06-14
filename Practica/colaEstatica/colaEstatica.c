#include <string.h>
#include "colaEstatica.h"
#define MIN(A,B) (((A) > (B))? (B):(A))

void crearCola(tCola* cola){
    cola->bytesDisponibles = CAPACIDAD_COLA;
    cola->primero = 0;
    cola->ultimo = 0;
}

int colaLlena(const tCola* cola){
    return !cola->bytesDisponibles;
}

int colaVacia(const tCola* cola){
    return cola->bytesDisponibles == CAPACIDAD_COLA;
}

int encolar(tCola* cola, const void* dato, unsigned cantBytes){
    //Verifico que haya lugar
    if(cantBytes + sizeof(unsigned) > cola->bytesDisponibles) return 0;

    //Reservo el espacio
    cola->bytesDisponibles -= cantBytes + sizeof(unsigned);

    ///Pongo el tam del dato
    escribirEnCola(cola,&cantBytes,sizeof(unsigned));

    ///Pongo el dato
    escribirEnCola(cola,dato,cantBytes);

    return 1;
}

void escribirEnCola(tCola* cola, const void* origen, unsigned cant) {
    unsigned fin = MIN(CAPACIDAD_COLA - cola->ultimo, cant);
    unsigned ini = cant - fin;

    memcpy(cola->vec + cola->ultimo, origen, fin);
    memcpy(cola->vec, ((char*)origen) + fin, ini);

    cola->ultimo = (cola->ultimo + cant) % CAPACIDAD_COLA;
}

int desEncolar(tCola* cola, void* buffer, unsigned cantBytes){
    unsigned auxTam;

    //Verifico que haya algo en la cola
    if(cola->bytesDisponibles == CAPACIDAD_COLA) return 0;

    //Leo el tam
    leerDeCola(cola,&auxTam,sizeof(unsigned));

    //Leer el dato
    leerDeCola(cola,buffer,MIN(auxTam,cantBytes));

    //Devuelvo el espacio a la cola
    cola->bytesDisponibles += auxTam + sizeof(unsigned);

    return 1;
}

void leerDeCola(tCola* cola,void* buffer, unsigned cantBytes){
    unsigned ini;
    unsigned fin;

    fin = MIN(cantBytes,CAPACIDAD_COLA - cola->primero);
    ini = cantBytes - fin;

    memcpy(buffer,cola->vec + cola->primero,fin);
    memcpy(buffer + fin,cola->vec,ini);

    cola->primero = (cola->primero + cantBytes) % CAPACIDAD_COLA;
}

void vaciarCola(tCola* cola){
    cola->primero = cola->ultimo = CAPACIDAD_COLA;
}

