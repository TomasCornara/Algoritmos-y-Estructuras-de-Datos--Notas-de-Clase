#ifndef LISTA_DOBLE_H_INCLUDED
#define LISTA_DOBLE_H_INCLUDED

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
    struct sNodo* ant;
}tNodo;

typedef tNodo* tLista;
typedef int(*Comparar)(const void*,const void*);

void crearLista(tLista* lista);
int listaVacia(const tLista* lista);
int listaLlena(const tLista* lista);
int ponerOrdenado(tLista* lista, const void* dato, unsigned cantBytes,Comparar cmp);


int cmpIntMen(const void* elemA, const void* elemB);
#endif // LISTA_DOBLE_H_INCLUDED
