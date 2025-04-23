#include "pila.h"
#include "funciones_auxiliares.h"

#define MINIMO(A, B) ((A) <= (B) ? (A) : (B))

void crearPila(tPila *pila)
{
    pila->tope = TAM_PILA;
}

int apilar(tPila *pila, const void *dato, unsigned tamDato)
{
    if (pila->tope == 0)
        return 0;

    tInformacion *aux = (tInformacion *)malloc(sizeof(tInformacion));
    if (!aux)
        return 0;

    aux->dato = malloc(tamDato);
    if (!aux->dato)
    {
        free(aux);
        return 0;
    }

    mMemcpy(aux->dato, dato, tamDato);
    aux->tamDato = tamDato;

    pila->tope--;
    pila->pila[pila->tope] = aux;

    return 1;
}

int desapilar(tPila *pila, void *dato, unsigned tamDato)
{
    if (pila->tope == TAM_PILA)
        return 0;

    tInformacion *aux = pila->pila[pila->tope];
    if (!aux)
        return 0;

    mMemcpy(dato, aux->dato, MINIMO(tamDato, aux->tamDato));

    free(aux->dato);
    free(aux);
    pila->pila[pila->tope] = NULL;
    pila->tope++;

    return 1;
}

int pilaLlena(const tPila *pila)
{
    return pila->tope == 0;
}

int pilaVacia(const tPila *pila)
{
    return pila->tope == TAM_PILA;
}

void vaciarPila(tPila *pila)
{
    while (pila->tope < TAM_PILA)
    {
        tInformacion *aux = pila->pila[pila->tope];
        if (aux)
        {
            free(aux->dato);
            free(aux);
            pila->pila[pila->tope] = NULL;
        }
        pila->tope++;
    }
}

int verTope(const tPila *pila, void *dato, unsigned tamDato)
{
    if (pila->tope == TAM_PILA)
        return 0;

    tInformacion *aux = pila->pila[pila->tope];
    if (!aux)
        return 0;

    mMemcpy(dato, aux->dato, MINIMO(tamDato, aux->tamDato));
    return 1;
}
