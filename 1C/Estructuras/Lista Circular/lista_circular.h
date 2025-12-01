#ifndef LISTA_CIRCULAR_H_INCLUDED
#define LISTA_CIRCULAR_H_INCLUDED

typedef struct sNodo
{
    void* info;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tCola;

void crearCola(tCola* cola);
int colaVacia(const tCola* cola);
int colaLlena(const tCola* cola, unsigned tamDato);
int encolar(tCola* cola, void* dato, unsigned tamDato);
int desEncolar(tCola* cola, void* destino, unsigned cantBytes);
int verTopeCola(tCola* cola, void* destino, unsigned cantBytes);
void mostrarCola(const tCola cola);
void mapCola(const tCola* cola, void (*accion)(const void*));
void imprimirInt(const void* dato);

#endif // LISTA_CIRCULAR_H_INCLUDED
