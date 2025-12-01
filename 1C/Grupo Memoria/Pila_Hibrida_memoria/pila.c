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
        return PILA_LLENA;

    aux = (tInformacion *)malloc(sizeof(tInformacion));

    if (!aux)
        return FALLO_MEMORIA;

    aux->dato = malloc(tamDato);

    if (!aux->dato)
    {
        free(aux);

        return FALLO_MEMORIA;
    }

    pila->tope--;

    mMemcpy(aux->dato, dato, tamDato);
    aux->tamDato = tamDato;

    *(pila->pila + pila->tope) = aux;

    return EXITO_PILA_APILADA;
}

int desapilar(tPila *pila, void *dato, unsigned tamDato)
{
    if (pila->tope == TAM_PILA)
        return PILA_VACIA;

    mMemcpy(dato, ((*(pila->pila + pila->tope))->dato),
            MINIMO(tamDato, ((*(pila->pila + pila->tope))->tamDato)));

    free((*(pila->pila + pila->tope))->dato);
    free(*(pila->pila + pila->tope));

    *(pila->pila + pila->tope) = NULL;

    pila->tope++;

    return EXITO_PILA_DESAPILADA;
}

int pilaLlena(const tPila *pila, unsigned tamDato)
{
    return !pila->tope ? PILA_LLENA : PILA_NO_LLENA;
}

int pilaVacia(const tPila *pila)
{
    return pila->tope == TAM_PILA ? PILA_VACIA : PILA_NO_VACIA;
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
        return PILA_VACIA;

    mMemcpy(dato, ((*(pila->pila + pila->tope))->dato),
            MINIMO(tamDato, ((*(pila->pila + pila->tope))->tamDato)));

    return EXITO_VER_TOPE;
}
