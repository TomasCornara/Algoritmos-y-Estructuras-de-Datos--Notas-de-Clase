#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"

//INICIALIZACION DE UN ARBOL BINARIO
void crearArbol(arbol* head)
{
    *head = NULL;
    return;
}

//INSERSION DE UN NODO
int insertarNodo(arbol* head, const void* dato, unsigned cantBytes, int comparar(const void*,const void*))
{
    tNodo* nue;
    int cmp;

    //Busco que posicion le corresponde
    while(*head)
    {
        if((cmp = comparar(dato,(*head)->info)) < 0)  //Caso izquierda
        {
            head = &(*head)->menor;
        }
        else if(cmp > 0)   //Caso derecha
        {
            head = &(*head)->mayor;
        }
        else   //Caso repetido
        {
            return 0;
        }
    }

    //Pido memoria
    nue = malloc(sizeof(tNodo));
    if(!nue || !(nue->info = malloc(cantBytes)))
    {
        free(nue);
        return 0;
    }

    //Cargo el nodo
    memcpy(nue->info,dato,cantBytes);
    nue->tam = cantBytes;
    nue->mayor = nue->menor = NULL;

    //Enlzo el nuevo nodo
    *head = nue;

    //Todo Ok
    return 1;
}

void imprimirArbolGen(const arbol raiz, int nivel, void (*imprimir)(const void*)) {
    if (!raiz) return;

    // Imprime el subárbol derecho (mayor)
    imprimirArbolGen(raiz->mayor, nivel + 1, imprimir);

    // Imprime la sangría correspondiente al nivel
    for (int i = 0; i < nivel; i++)
        printf("\t");

    imprimir(raiz->info);
    printf("\n");

    // Imprime el subárbol izquierdo (menor)
    imprimirArbolGen(raiz->menor, nivel + 1, imprimir);
}

void imprimirEntero(const void* dato) {
    printf("%d", *(int*)dato);
}


int cmp_int(const void* elemA, const void* elemB){
    int A;
    int B;

    A = *(int*)elemA;
    B = *(int*)elemB;

    return A - B;
}
