#ifndef LISTA_CIRCULAR_H_INCLUDED
#define LISTA_CIRCULAR_H_INCLUDED

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tPila;
typedef tNodo* tCola;

///FUNCIONES PILA
int vaciarPila(tPila* pila);
int verTope(const tPila* pila, void* dato, unsigned cantBytes);
int desApilar(tPila* pila, void* dato, unsigned cantBytes);
int apilar(tPila* pila, const void* dato, unsigned cantBytes);
int pilaLlena(const tPila* pila);
int pilaVacia(const tPila* pila);
void crearPila(tPila* pila);

///FUNCIONES COLA
void crearCola(tCola* cola);
int colaVacia(const tCola* cola);
int ponerEnCola(tCola* cola, const void* dato, unsigned cantBytes);
int desEncolar(tCola* cola,void* dato,unsigned cantBytes);
int verPrimero(const tCola* cola, void* dato, unsigned cantBytes);

#endif // LISTA_CIRCULAR_H_INCLUDED
