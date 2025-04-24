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
    unsigned tam,ini,fin,posDato;

    ///Lectura del tamaño de dato
    ini = MIN(sizeof(unsigned), TAM_COLA - cola->primero);
    fin = sizeof(unsigned) - ini;

    if(ini){ //Si hay algo que leer desde el inicio
        memcpy(&tam,(char*)cola->cola + cola->primero,ini);
    }
    if(fin){ //Si hay algo que leer desde el final
        memcpy((char*)&tam + ini, cola->cola,fin);
    }

    ///Lectura del dato
    posDato = fin? fin: cola->primero + ini;
    ini = MIN(TAM_COLA - posDato,MIN(cantBytes,tam));
    fin = MIN(cantBytes,tam) - ini;

    if(ini){
        memcpy(dato,(char*)cola->cola + posDato,ini);
    }
    if(fin){
        memcpy((char*)dato + ini,cola->cola,fin);
    }

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


int desEnColar(tCola *cola, void *dato, unsigned cantBytes){
    unsigned tam,ini,fin,posDato;

    ///Lectura del tamaño de dato
    ini = MIN(sizeof(unsigned), TAM_COLA - cola->primero);
    fin = sizeof(unsigned) - ini;

    if(ini){ //Si hay algo que leer desde el inicio
        memcpy(&tam,(char*)cola->cola + cola->primero,ini);
    }
    if(fin){ //Si hay algo que leer desde el final
        memcpy((char*)&tam + ini, cola->cola,fin);
    }

    //Devuelvo el espacio ocupado por el tamaño del dato
    cola->tam_disp += sizeof(unsigned);

    ///Lectura del dato
    posDato = fin? fin: cola->primero + ini;
    ini = MIN(TAM_COLA - posDato,MIN(cantBytes,tam));
    fin = MIN(cantBytes,tam) - ini;

    if(ini){
        memcpy(dato,(char*)cola->cola + posDato,ini);
    }
    if(fin){
        memcpy((char*)dato + ini,(char*)cola->cola,fin);
    }

    //Devuelvo el espacio ocupado por el dato y corrijo a la nueva posicion
    cola->tam_disp += tam;
    cola->primero = fin? fin: posDato + ini;


    return 1;
}




