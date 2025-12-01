#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct sNodo{
    void* dato;
    unsigned cantBytes;
    struct sNodo* der;
    struct sNodo* izq;
}tNodo;

typedef tNodo* tArbol;
typedef int(*cmp_fun)(const void*,const void*);

void crearArbol(tArbol* arbol);
int insertarArbol(tArbol* arbol, const void* dato, unsigned cantBytes,cmp_fun cmp);
tNodo* buscarArbol(const tArbol* arbol, const void* key, cmp_fun cmp);
void vaciarArbol(tArbol* arbol);

#endif // ARBOL_H_INCLUDED
