#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED

#define ERROR_PILA_VACIA -3
#define ERROR_PILA_LLENA -2
#define ERROR_FALTA_MEMORIA -1


#define EXITO_APILADO 1
#define EXITO_LUGAR_EN_PILA 2
#define EXITO_VER_TOPE 3
#define EXITO_DESAPILAR 4

typedef struct sNodo{
    void* dato;
    unsigned tam_dato;
    struct sNodo* siguiente;
}tNodo;

typedef tNodo* tPila;

void crearPila(tPila* pila);
int pilaVacia(tPila* pila);
int pilaLlena(tPila* pila, unsigned cantBytes);
int apilar(tPila* pila, const void* dato, unsigned cantBytes);
int verTope(const tPila* pila, void* dato, unsigned cantBytes);
int desapilar(tPila* pila, void* dato, unsigned cantBytes);
void vaciarPila(tPila* pila);

#endif // PILA_DINAMICA_H_INCLUDED
