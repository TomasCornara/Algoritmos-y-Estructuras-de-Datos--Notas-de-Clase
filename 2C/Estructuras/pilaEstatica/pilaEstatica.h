#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED

#define MIN(X,Y) (((X)>(Y))? (Y):(X))
#define MAX_PILA 512

typedef struct{
    char* pila[MAX_PILA];
    unsigned tope;
} tPila;

void crearPila(tPila* pila);
int pilaLlena(const tPila* pila);
int pilaVacia(const tPila* pila);
void vaciarPila(tPila* pila);
int verTope(const tPila* pila, void* dato,unsigned cantBytes);
int desapilar(tPila* pila, void* dato, unsigned cantBytes);
int apilar(tPila* pila, const void* dato, unsigned cantBytes);

#endif // PILAESTATICA_H_INCLUDED
