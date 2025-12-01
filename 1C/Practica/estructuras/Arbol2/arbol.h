#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* izq;
    struct sNodo* der;
}tNodo;

typedef tNodo* tArbol;
typedef int(*Comparar)(const void* elem1, const void* elem2);
typedef void(*Print)(const void* elem);

void crearArbol(tArbol* arbol);
int arbolVacio(const tArbol* arbol);
int ponerEnArbol(tArbol* arbol, const void* dato, unsigned cantBytes, Comparar cmp);
void mostrarArbol(const tArbol* arbol, Print prt);
void printInt(const void* elem);
void mostrarArbolConForma(const tArbol* arbol, Print prt, unsigned nivel);
void guardarArbol(tArbol* arbol, FILE* arch);
void liberarArbol(tArbol* arbol);

int cmpIntMen(const void* elemA, const void* elemB);

#endif // ARBOL_H_INCLUDED
