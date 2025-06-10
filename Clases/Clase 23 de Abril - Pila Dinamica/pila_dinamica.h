#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED
#define ERROR_MEMORIA -1
#define TODO_OK 1

///Definicion de una estructura recursiva
typedef struct sNodo{ // <<-- Nombre temporal (Normalmente el nombre va con S)
    void* dato;
    unsigned tam_dato;
    struct sNodo* sig; // <<-- Lo uso para poder declarar este puntero
} tNodo; // <<---- Redifino con el nombre que quiero

typedef tNodo* tPila; // <<-- Esto oculta la implementacion de la pila dinamica y mantiene la compatibilidad
                      //      Con otras implementaciones

void crearPila(tPila *pila);
int apilar(tPila *pila, const void *dato, unsigned tamDato);
int desapilar(tPila *pila, void *dato, unsigned tamDato);
int pilaLlena(const tPila *pila, unsigned tamDato);
int pilaVacia(const tPila *pila);
void vaciarPila(tPila *pila);
int verTope(const tPila *pila, void *dato, unsigned tamDato);

#endif // PILA_DINAMICA_H_INCLUDED
