#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct sNodo{
    void* info;
    unsigned tam;
    struct sNodo* mayor;
    struct sNodo* menor;
}tNodo;


typedef tNodo* arbol;

void crearArbol(arbol* head);
int insertarNodo(arbol* head, const void* dato, unsigned cantBytes, int comparar(const void*,const void*));
void imprimirArbolGen(const arbol raiz, int nivel, void (*imprimir)(const void*));
int calcularNodos(const arbol raiz);
unsigned calcularAltura(const arbol raiz);
void imprimirArbolInt(const arbol raiz, int espacio);
int guardarArbol(const arbol raiz, char* nombre);
void guardarArbol_aux(const arbol raiz, FILE* arch);
arbol cargarArbol_aux(FILE* arch);
arbol cargarArbol(const char* nombre);
void contarHojas_aux(const arbol raiz, unsigned* hojas);
unsigned contarHojas(const arbol raiz);
void contarRamas_aux(const arbol raiz,unsigned* ramas);
unsigned contarRamas(const arbol raiz);
int eliminarNodo(arbol* raiz, const void* clave,int comparar(const void*, const void*));

int cmp_int(const void* elemA, const void* elemB);
void imprimirEntero(const void* dato);


#endif // ARBOL_H_INCLUDED
