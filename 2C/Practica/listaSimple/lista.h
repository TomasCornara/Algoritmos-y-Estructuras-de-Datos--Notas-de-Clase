#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;
typedef int(*f_cmp)(const void*,const void*);
typedef void(*f_ptr)(const void*);

void crearLista(tLista* lista);
int listaVacia(const tLista* lista);
int listaLlena(const tLista* lista, unsigned cantBytes);
int ponerEnLista(tLista* lista, const void* dato, unsigned cantBytes,f_cmp cmp);
void mapLista(const tLista* lista, f_ptr ptr);

#endif // LISTA_H_INCLUDED
