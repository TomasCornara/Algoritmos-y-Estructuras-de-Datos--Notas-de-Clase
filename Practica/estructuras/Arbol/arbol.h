#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct sNodo{
    void* info;
    unsigned tam;
    struct sNodo* izq;
    struct sNodo* der;
}tNodo;

typedef tNodo* tArbol;

void crearArbol(tArbol* arbol);
typedef int(*Comparacion)(const void*, const void*);
typedef void(*Mostrar)(const void*);

void crearNodo(tArbol* arbol);
int ponerNodo(tArbol* arbol, const void* key, const void* dato, unsigned cantBytes, Comparacion cmp);
void imprimirArbol(const tArbol* arbol, Mostrar print);
void imprimirArbolFormateado(const tArbol* arbol, Mostrar print, int nivel);



void printInt(const void* elem);
void mostrarEntero(const void* dato);
int cmpIntMen(const void* elemA, const void* elemB);

#endif // ARBOL_H_INCLUDED
