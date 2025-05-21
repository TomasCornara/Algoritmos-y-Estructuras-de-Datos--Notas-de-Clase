#include "lista_circular.h"

#define MINIMO(X, Y) (( X ) <= ( Y ) ? ( X ) : ( Y ))

void crearPila(tPila *pila)
{
    *pila = NULL;
}

unsigned char pilaVacia(const tPila *pila)
{
    return *pila == NULL;
}

unsigned char pilaLLena(const tPila *pila, unsigned tamDato)
{
    return VERDADERO;
}

int apilar(tPila *pila, const void *dato, unsigned tamDato)
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

    if (!*pila)
    {
        insertar->siguiente = insertar;

        *pila = insertar;
    }
    else
    {
        insertar->siguiente = (*pila)->siguiente;

        (*pila)->siguiente = insertar;
    }

    return VERDADERO;
}

int desapilar(tPila *pila, void *dato, unsigned tamDato)
{
    tNodo *eliminar;

    if (!*pila)
        return PILA_VACIA;

    eliminar = (*pila)->siguiente;

    memcpy(dato, eliminar->info, MINIMO(tamDato, eliminar->tamInfo));

    if (eliminar == *pila)
        *pila = NULL;
    else
        (*pila)->siguiente = eliminar->siguiente;

    free(eliminar->info);
    free(eliminar);

    return VERDADERO;
}

int verTope(const tPila *pila, void *dato, unsigned tamDato)
{
    if (*pila)
        return PILA_VACIA;

    memcpy(dato, (*pila)->siguiente->info, MINIMO(tamDato,
            (*pila)->siguiente->tamInfo));

    return VERDADERO;
}

void vaciarPila(tPila *pila)
{
    tNodo *eliminar;

    if (!*pila)
        return;

    while (*pila)
    {
        eliminar = (*pila)->siguiente;

        if (eliminar == *pila)
            *pila = NULL;
        else
            (*pila)->siguiente = eliminar->siguiente;

        free(eliminar->info);
        free(eliminar);
    }
}
