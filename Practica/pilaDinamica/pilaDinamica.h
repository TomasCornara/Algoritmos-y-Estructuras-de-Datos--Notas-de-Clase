#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo* siguiente;
}tNodo;

typedef tNodo* tPila;

void crearPila(tPila* pila);
int desApilar(tPila* pila, void* buffer, unsigned cantBytes);
int apilar(tPila* pila, const void* dato, unsigned cantByte);
int pilaVacia(const tPila* pila);
int pilaLlena(const tPila* pila);
int verTope(const tPila* pila, void* buffer, unsigned cantBytes);

#endif // PILADINAMICA_H_INCLUDED
