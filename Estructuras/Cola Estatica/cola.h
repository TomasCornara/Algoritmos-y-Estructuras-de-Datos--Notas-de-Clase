#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#define TAM_COLA 16

typedef struct tCola{
    char cola[TAM_COLA];
    unsigned primero;
    unsigned ultimo;
    unsigned tam_disp;
}tCola;

void crearCola(tCola *cola);
int enColar(tCola *cola, const void *dato, unsigned cantBytes);
int desEnColar(tCola *cola, void *dato, unsigned cantBytes);
int verPrimero(const tCola *cola, void *dato, unsigned cantBytes);
void vaciarCola(tCola *cola);
int colaVacia(const tCola *cola);
int colaLlena(const tCola *cola, unsigned cantBytes);

#endif // COLA_H_INCLUDED
