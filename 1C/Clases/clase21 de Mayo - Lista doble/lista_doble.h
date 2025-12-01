#ifndef LISTA_DOBLE_H_INCLUDED
#define LISTA_DOBLE_H_INCLUDED

#define DUPLICADO 1
#define SIN_MEM -1
#define REALIZADO -2

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
    struct sNodo* ant;
} tNodo;

typedef tNodo* tLista;
typedef int(*accion)(const void*,const void*);

void crearLista(tLista* lista);
int insertarNodo(tLista *lista, void * dato, unsigned tam, accion comparar);
int cmpInt(const void* elemA, const void* elemB);

void mostrarInt(const void*a);
void mapearIzq(tLista*pl,void acc(const void*));
void mapearDer(tLista*pl,void acc(const void*));

#endif // LISTA_DOBLE_H_INCLUDED
