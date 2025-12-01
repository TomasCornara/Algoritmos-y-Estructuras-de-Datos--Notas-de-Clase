#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED

#define MAX_PILA 256
#define MIN(A,B) (((A)>(B))? (B):(A))


typedef struct {
    char base[MAX_PILA];
    unsigned tope;
}tPila;

void crearPila(tPila* pila);
int pilaLlena(const tPila* pila);
int pilaVacia(const tPila* pila);
void vaciarPila(tPila* pila);
int ponerEnPila(tPila* pila, const void* dato, unsigned cantBytes);
int sacarPila(tPila* pila, void* buffer, unsigned cantBytes);
int verTope(const tPila* pila, void* buffer, unsigned cantBytes);

#endif // PILAESTATICA_H_INCLUDED
