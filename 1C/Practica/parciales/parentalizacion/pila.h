#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED


#define MIN(A,B) (((A)>(B))? (B):(A))
#define CAPACIDAD_PILA 256

typedef struct{
    char vec[CAPACIDAD_PILA];
    unsigned ultimo;
}tPila;


void crearPila(tPila* pila);
int pilaVacia(const tPila* pila);
int pilaLlena(const tPila* pila);
int apilar(tPila* pila, const void* dato, unsigned cantBytes);
int verTope(const tPila* pila, void* dato, unsigned cantBytes);
int desApilar(tPila* pila, void* dato, unsigned cantBytes);
void vaciarPila(tPila* pila);


#endif // PILA_H_INCLUDED
