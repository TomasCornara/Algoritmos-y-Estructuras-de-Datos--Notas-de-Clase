#ifndef LISTA_CIRCULAR_H_INCLUDED
#define LISTA_CIRCULAR_H_INCLUDED

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
} tNodo;

typedef tNodo* tLista;

void crearLista(tLista* lista);
int listaVacia(const tLista* lista);
int listaLlena(const tLista* lista);
int encolar(tLista* lista, const void* dato, unsigned cantBytes);
int verPrimero(const tLista* lista,void* dato, unsigned cantBytes);
int girarUno(tLista* lista);
int quitarPrimero(const tLista* lista);
int quedaUnoEnLista(const tLista* lista);
int vaciarCola(tLista* lista);

#endif // LISTA_CIRCULAR_H_INCLUDED
