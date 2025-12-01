#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#define MIN(A,B) (((A) > (B))? (B):(A))

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
} tNodo;

typedef tNodo* tPila;

void crearPila(tPila* pila);
int pilaVacia(const tPila* pila);
int pilaLlena(const tPila* pila, unsigned cantBytes);
void vaciarPila(tPila* pila);
int apilar(tPila* pila, const void* dato, unsigned cantBytes);
int desApilar(tPila* pila, void* dato, unsigned cantBytes);
int verTope(const tPila* pila, void* dato, unsigned cantBytes);

#endif // PILADINAMICA_H_INCLUDED
