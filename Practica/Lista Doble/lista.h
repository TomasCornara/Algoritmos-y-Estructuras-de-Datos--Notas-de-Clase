#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct sNodo{
    void* info;
    unsigned tam;
    struct sNodo* sig;
    struct sNodo* ant;
}tNodo;

typedef tNodo* lista;

void crearLista(lista* lista);
int ponerPrimero(lista* lista,const void* dato,unsigned cantBytes);
void mostrarLista(const lista* head);

#endif // LISTA_H_INCLUDED
