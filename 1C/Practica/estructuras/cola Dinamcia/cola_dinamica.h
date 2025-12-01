#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* siguiente;
}tNodo;

typedef struct{
    tNodo* primero;
    tNodo* ultimo;
}tCola;

void crearCola(tCola* cola);
int colaVacia(const tCola* cola);
int colaLlena(const tCola* cola, unsigned cantBytes);
int ponerEnCola(tCola* cola, const void* dato, unsigned cantBytes);
int colaLlena(const tCola* cola, unsigned cantBytes);
int desEncolar(tCola* cola, void* dato, unsigned cantBytes);
int verPrimero(const tCola* cola, void* dato, unsigned cantBytes);
int vaciarCola(tCola* cola, unsigned cantBytes);


#endif // COLA_DINAMICA_H_INCLUDED
