#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"


void crearArbol(tArbol* arbol){
    *arbol = NULL;
}

int ponerNodo(tArbol* arbol, const void* key, const void* dato, unsigned cantBytes, Comparacion cmp){
    tNodo* nue;
    int res;

    while(*arbol != NULL){
        res = cmp(key,(*arbol)->info);

        if(!res){
            return 0;
        }

        if(res > 0){
            arbol = &((*arbol)->izq);
        }

        if(res < 0){
            arbol = &((*arbol)->der);
        }
    }

    nue = malloc(sizeof(tNodo));
    if(!nue || !(nue->info = malloc(cantBytes))){
        free(nue);
        return 0;
    }

    *arbol = nue;
    nue->der = NULL;
    nue->izq = NULL;
    memcpy(nue->info,dato,cantBytes);
    nue->tam = cantBytes;

    return 1;
}

void imprimirArbol(const tArbol* arbol, Mostrar print) {
    imprimirArbolFormateado(arbol,print,0);
}

void imprimirArbolFormateado(const tArbol* arbol, Mostrar print, int nivel) {
    if(!arbol || !(*arbol)) return;


    imprimirArbolFormateado(&(*arbol)->der,print,nivel + 1);

    for(int i = 0; i < nivel; i++){
        printf("      ");
    }
    print((*arbol)->info);

    imprimirArbolFormateado(&(*arbol)->izq, print,nivel + 1);

}



void mostrarEntero(const void* dato) {
    printf("%d\n", *(int*)dato);
}


void printInt(const void* elem){
    printf("%d",*(int*)elem);
}

int cmpIntMen(const void* elemA, const void* elemB){
    int A = *(int*)elemA;
    int B = *(int*)elemB;

    return A - B;
}
