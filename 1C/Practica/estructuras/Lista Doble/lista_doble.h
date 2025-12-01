#ifndef LISTA_DOBLE_H_INCLUDED
#define LISTA_DOBLE_H_INCLUDED

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* ant;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;
typedef int(*comparacion)(const void* elem1, const void* elem2);


void crearLista(tLista* lista);
int colaVacia(const tLista* lista);
int listaLlena(const tLista* lista);


#endif // LISTA_DOBLE_H_INCLUDED
