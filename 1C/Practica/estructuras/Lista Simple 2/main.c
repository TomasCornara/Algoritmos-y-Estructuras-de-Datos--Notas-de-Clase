#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// ListaSimple.h
typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;
typedef int(*Accion)(const void*, const void*);


void crearLista(tLista* lista);
int listaLlena(const tLista* lista);
int listaVacia(const tLista* lista);
int ponerPrimero(tLista* lista, const void* dato, unsigned cantBytes);
void mapInt(const tLista* lista);
void vaciarLista(tLista* lista);
int ponerEnOrden(tLista* lista, const void* dato,unsigned cantBytes, Accion cmp);
int cmpIntMen(const void* elemA, const void* elemB);
int cmpIntMay(const void* elemA, const void* elemB);

///MAIN
int main()
{
    int vec[] = {1,2,3,4,5,6,7,8};
    int vec2[] = {2,4,5,0,1,3,9,8};
    tLista mio;

    crearLista(&mio);

    for(int i = 0; i < sizeof(vec)/sizeof(vec[0]); i++){
        ponerPrimero(&mio,&vec[i],sizeof(vec[0]));
    }



    mapInt(&mio);
    vaciarLista(&mio);


    if(listaVacia(&mio)){
        printf("todo ok\n");
    }

    for(int i = 0; i < sizeof(vec2)/sizeof(vec2[0]); i++){
        ponerEnOrden(&mio,&vec2[i],sizeof(vec2[0]),cmpIntMen);
    }

    mapInt(&mio);
    vaciarLista(&mio);
    if(listaVacia(&mio)){
        printf("todo ok\n");
    }

    for(int i = 0; i < sizeof(vec2)/sizeof(vec2[0]); i++){
        ponerEnOrden(&mio,&vec2[i],sizeof(vec2[0]),cmpIntMay);
    }

    mapInt(&mio);
    vaciarLista(&mio);
    if(listaVacia(&mio)){
        printf("todo ok\n");
    }

    qsort(vec2,sizeof(vec2)/sizeof(vec2[0]),sizeof(vec2[0]),cmpIntMen);
    for(int i = 0; i < sizeof(vec)/sizeof(vec[0]); i++){
        ponerPrimero(&mio,&vec[i],sizeof(vec[0]));
    }
    mapInt(&mio);
    vaciarLista(&mio);
    if(listaVacia(&mio)){
        printf("todo ok\n");
    }

    return 0;
}

/// ListaSimple.c

void crearLista(tLista* lista){
    *lista = NULL;
}

int listaVacia(const tLista* lista){
    return !(*lista);
}

int listaLlena(const tLista* lista){
    return 0;
}

int ponerPrimero(tLista* lista, const void* dato, unsigned cantBytes){
    tNodo* nue;

    //Pido memoria
    nue = malloc(sizeof(tNodo));
    if(!nue || !(nue->dato = malloc(cantBytes))){
        free(nue);
        return 0;
    }

    //Enlazo
    if(*lista == NULL){
        *lista = nue;
        nue->sig = NULL;
    } else {
        nue->sig = *lista;
        *lista = nue;
    }

    //Paso la info
    memcpy(nue->dato,dato,cantBytes);
    nue->tam = cantBytes;

    return 1;
}

void mapInt(const tLista* lista){
    while(*lista != NULL){
        printf("%d\n",*((int*)((*lista)->dato)));
        lista = &((*lista)->sig);
    }
}

void vaciarLista(tLista* lista){
    tNodo* elim;

    while(*lista != NULL){
        elim = *lista;
        *lista = (*lista)->sig;
        free(elim->dato);
        free(elim);
    }
}

int ponerEnOrden(tLista* lista, const void* dato,unsigned cantBytes, Accion cmp){
    tNodo* nue;
    int res;

    nue = malloc(sizeof(tNodo));
    if(!nue || !(nue->dato = malloc(cantBytes))){
        free(nue);
        return 0;
    }

    if(*lista == NULL){
        *lista = nue;
        nue->sig = NULL;
    } else {
        while(*lista != NULL && (res = cmp(dato,(*lista)->dato)) > 0){
            lista = &((*lista)->sig);
        }

        if(res == 0){
            free(nue->dato);
            free(nue);
            return 0;
        }

        nue->sig = *lista;
        *lista = nue;
    }

    memcpy(nue->dato,dato,cantBytes);
    nue->tam = cantBytes;

    return 1;
}


int cmpIntMen(const void* elemA, const void* elemB){
    int A = *((int*)elemA);
    int B = *((int*) elemB);
    return A - B;
}

int cmpIntMay(const void* elemA, const void* elemB){
    int A = *((int*)elemA);
    int B = *((int*) elemB);
    return B - A;
}
