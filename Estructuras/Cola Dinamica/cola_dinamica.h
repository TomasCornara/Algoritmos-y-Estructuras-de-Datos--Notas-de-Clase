#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED


#define ERROR_MEMORIA -1

#define EXITO 1
#define COLA_VACIA 2
#define COLA_LLENA 3
#define COLA_OCUPADA 4

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* siguiente;
}tNodo;

typedef struct {
    tNodo* primero;
    tNodo* ultimo;
} tCola;

void crearCola(tCola* cola);
int enColar(tCola *cola, const void *dato, unsigned cantBytes);
int desEncolar(tCola* cola, void *dato, unsigned cantBytes);
int verPrimero(const tCola *cola, void *dato, unsigned cantBytes);
void vaciarCola(tCola *cola);
void vaciarColaRecursivo(tNodo* nodo);
int colaVacia(const tCola *cola);
int colaLlena(const tCola *cola, unsigned cantBytes);

#endif // COLA_DINAMICA_H_INCLUDED
