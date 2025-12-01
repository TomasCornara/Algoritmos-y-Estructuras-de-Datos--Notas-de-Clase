#ifndef LISTA_DOBLE_H_INCLUDED
#define LISTA_DOBLE_H_INCLUDED

typedef struct sNodo{
    void* info;
    unsigned tam;
    struct sNodo* sig;
    struct sNodo* ant;
}tNodo;

typedef tNodo* tLista;
typedef int(*Comparar)(const void*,const void*);
typedef void(*Print)(const void*);

void crearLista(tLista* lista);
int listaVacia(const tLista* lista);
int listaLlena(const tLista* lista);
int ponerEnLista(tLista* lista, const void* dato, unsigned cantByte);
int ponerEnListaOrdenado(tLista* lista, const void* dato, unsigned cantBytes, Comparar cmp);
void printLista(const tLista* lista, Print prt);


void printInt(const void* elem);
int cmpInt(const void* dato1, const void* dato2);

#endif // LISTA_DOBLE_H_INCLUDED
