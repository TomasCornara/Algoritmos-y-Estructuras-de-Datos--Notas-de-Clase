#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED
#define CAPACIDAD_PILA 255

typedef struct {
    char vec[CAPACIDAD_PILA];
    unsigned tope;
}tPila;

void crearPila(tPila* pila);
int apilar(tPila* pila, const void* dato, unsigned cantBytes);
int desApilar(tPila* pila, void* buffer, unsigned cantBytes);
int pilaVacia(const tPila* pila);
int verTope(const tPila* pila, void* buffer, unsigned cantBytes);

#endif // PILA_ESTATICA_H_INCLUDED
