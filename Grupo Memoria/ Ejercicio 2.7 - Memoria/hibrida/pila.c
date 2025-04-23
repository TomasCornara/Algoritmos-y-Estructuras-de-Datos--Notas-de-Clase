#include "pila.h"
#include "funciones_auxiliares.h"

#define MINIMO( A, B ) ( ( A ) <= ( B ) ? ( A ) : ( B ) )

void crearPila(tPila *pila)
{
    pila->tope = TAM_PILA;
}

int apilar(tPila *pila, const void *dato, unsigned tamDato)
{
    tInformacion *aux;

    if (!pila->tope)
        return -1;

    aux = (tInformacion *)malloc(sizeof(tInformacion));

    if (!aux)
        return -2;

    aux->dato = malloc(tamDato);

    if (!aux->dato)
    {
        free(aux);
        return -2;
    }

    pila->tope--;

    mMemcpy(aux->dato, dato, tamDato);
    aux->tamDato = tamDato;

    *(pila->pila + pila->tope) = aux;

    return 0;
}

int desapilar(tPila *pila, void *dato, unsigned tamDato)
{
    if (pila->tope == TAM_PILA)
        return -1;

    mMemcpy(dato, ((*(pila->pila + pila->tope))->dato),
            MINIMO(tamDato, ((*(pila->pila + pila->tope))->tamDato)));

    free((*(pila->pila + pila->tope))->dato);
    free(*(pila->pila + pila->tope));

    *(pila->pila + pila->tope) = NULL;

    pila->tope++;

    return 0;
}

int pilaLlena(const tPila *pila, unsigned tamDato)
{
    return !pila->tope ? -1 : 0;
}

int pilaVacia(const tPila *pila)
{
    return pila->tope == TAM_PILA ? -1 : 0;
}

void vaciarPila(tPila *pila)
{
    while (pila->tope < TAM_PILA)
    {
        if (*(pila->pila + pila->tope))
        {
            free((*(pila->pila + pila->tope))->dato);
            free(*(pila->pila + pila->tope));

            *(pila->pila + pila->tope) = NULL;
        }

        pila->tope++;
    }
}

int verTope(const tPila *pila, void *dato, unsigned tamDato)
{
    if (pila->tope == TAM_PILA)
        return -1;

    mMemcpy(dato, ((*(pila->pila + pila->tope))->dato),
            MINIMO(tamDato, ((*(pila->pila + pila->tope))->tamDato)));

    return 0;
}
