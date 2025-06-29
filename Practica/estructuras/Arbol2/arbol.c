#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arbol.h"

void crearArbol(tArbol* arbol)
{
    *arbol = NULL;
}

int arbolVacio(const tArbol* arbol)
{
    return *arbol == NULL;
}

int ponerEnArbol(tArbol* arbol, const void* dato, unsigned cantBytes, Comparar cmp)
{
    tNodo* nue;
    int res;

    while(*arbol)
    {
        res = cmp(dato,(*arbol)->dato);

        if(!res)
        {
            return 0;
        }

        if(res > 0)
        {
            arbol = &(*arbol)->der;
        }
        else
        {
            arbol = &(*arbol)->izq;
        }
    }

    nue = malloc(sizeof(tNodo));
    if(!nue || !(nue->dato = malloc(cantBytes)))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato,dato,cantBytes);
    nue->tam = cantBytes;
    nue->der = NULL;
    nue->izq = NULL;

    *arbol = nue;

    return 1;
}

void mostrarArbol(const tArbol* arbol, Print prt)
{
    if(!arbol || !(*arbol)) return;

    mostrarArbol(&(*arbol)->der,prt);

    prt((*arbol)->dato);

    mostrarArbol(&(*arbol)->izq,prt);
}

void mostrarArbolConForma(const tArbol* arbol, Print prt, unsigned nivel)
{
    if(!arbol || !(*arbol)) return;

    mostrarArbolConForma(&(*arbol)->der,prt,nivel+1);


    for(int i = 0; i < nivel; i++)
    {
        printf("    ");
    }
    prt((*arbol)->dato);

    mostrarArbolConForma(&(*arbol)->izq,prt,nivel + 1);
}

void printInt(const void* elem)
{
    printf("%d\n",*(int*)elem);
}

int cmpIntMen(const void* elemA, const void* elemB)
{
    int A = *(int*)elemA;
    int B = *(int*)elemB;
    return A - B;
}

void guardarArbol(tArbol* arbol, FILE* arch){
    if(*arbol == NULL){
        fprintf(arch,"# ");
        return;
    }

    fprintf(arch, "%d ", *(int*)(*arbol)->dato);
    guardarArbol(&(*arbol)->izq, arch);
    guardarArbol(&(*arbol)->der, arch);
}

void liberarArbol(tArbol* arbol){
    if(arbol == NULL || *arbol == NULL){
        return;
    }

    liberarArbol(&(*arbol)->der);
    liberarArbol(&(*arbol)->izq);

    free((*arbol)->dato);
    free(*arbol);

    *arbol = NULL;
}
