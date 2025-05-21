#include "cola_circular.h"

#define MINIMO(X, Y) (( X ) <= ( Y ) ? ( X ) : ( Y ))

void crearCola(tCola *cola)
{
    *cola = NULL;
}

unsigned char colaVacia(const tCola *cola)
{
    return *cola == NULL;
}

unsigned char colaLlena(const tCola *cola, unsigned tamDato)
{
    return VERDADERO;
}

int acolar(tCola *cola, const void *dato, unsigned tamDato)
{
    tNodo *insertar = (tNodo *)malloc(sizeof(tNodo));

    if (!insertar)
        return FALLO_MEMORIA;

    insertar->info = malloc(tamDato);

    if (!insertar->info)
    {
        free(insertar);

        return FALLO_MEMORIA;
    }

    memcpy(insertar->info, dato, tamDato);
    insertar->tamInfo = tamDato;

    if (!*cola)
        insertar->siguiente = insertar;
    else
    {
        insertar->siguiente = (*cola)->siguiente;

        (*cola)->siguiente = insertar;
    }

    *cola = insertar;

    return VERDADERO;
}

int desacolar(tCola *cola, void *dato, unsigned tamDato)
{
    tNodo *eliminar;

    if (!*cola)
        return COLA_VACIA;

    eliminar = (*cola)->siguiente;

    memcpy(dato, eliminar->info, MINIMO(tamDato, eliminar->tamInfo));

    if (eliminar == *cola)
        *cola = NULL;
    else
        (*cola)->siguiente = eliminar->siguiente;

    free(eliminar->info);
    free(eliminar);

    return VERDADERO;
}

int verTopeCola(const tCola *cola, void *dato, unsigned tamDato)
{
    if (!*cola)
        return COLA_VACIA;

    memcpy(dato, (*cola)->siguiente->info, MINIMO(tamDato,
            (*cola)->siguiente->tamInfo));

    return VERDADERO;
}

void vaciarCola(tCola *cola)
{
    tNodo *eliminar;

    if (!*cola)
        return;

    while (*cola)
    {
        eliminar = (*cola)->siguiente;

        if (eliminar == *cola)
            *cola = NULL;
        else
            (*cola)->siguiente = eliminar->siguiente;

        free(eliminar->info);
        free(eliminar);
    }
}
