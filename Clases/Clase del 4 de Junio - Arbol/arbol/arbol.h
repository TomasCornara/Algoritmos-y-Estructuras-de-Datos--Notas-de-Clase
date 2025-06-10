#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct sNodo{
    void* info;
    unsigned tam;
    void* mayor;
    void* menor;
}tNodo;


typedef tNodo* arbol;

void crearArbol(arbol* head);
int insertarNodo(arbol* head, const void* dato, unsigned cantBytes, int comparar(const void*,const void*));
void imprimirArbolGen(const arbol raiz, int nivel, void (*imprimir)(const void*));


int cmp_int(const void* elemA, const void* elemB);
void imprimirEntero(const void* dato);


#endif // ARBOL_H_INCLUDED
