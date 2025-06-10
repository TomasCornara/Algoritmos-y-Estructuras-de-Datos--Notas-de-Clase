#include "arbol.h"


void crearArbol(tArbol *p){
    *p = NULL;
}
int insertarArbolIte(tArbol *p, const void *dato, unsigned tam, tCMP cmp){
    int res;
    tNodo *nue;
    while(*p){
        res = cmp(dato, (*p)->dato);
        if(res<0){
            p = &(*p)->izq;
        }
        else{
            if(res>0){
                p = &(*p)->der;
            }
            else{
                return 0;
            }
        }
    }
    nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->izq = NULL;
    nue->der = NULL;
    *p = nue;
    return 1;
}

int insertarArbolRec(tArbol *p, const void *dato, unsigned tam, tCMP cmp){
    int res;
    tNodo *nue;
    if(*p){
        res = cmp(dato, (*p)->dato);
        if(res<0){
            return insertarArbolRec(&(*p)->izq, dato, tam, cmp);
        }
        else{
            if(res>0){
                return insertarArbolRec(&(*p)->der, dato, tam, cmp);
            }
            else{
                return 0;
            }
        }
    }
    nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tam);
    if(!nue->dato){
        free(nue);
        return 0;
    }
    memcpy(nue->dato, dato, tam);
    nue->tam = tam;
    nue->izq = NULL;
    nue->der = NULL;
    *p = nue;
    return 1;
}

int compararInt(const void* dato1, const void *dato2){
    return *(int*)dato1 - *(int*)dato2;
}



