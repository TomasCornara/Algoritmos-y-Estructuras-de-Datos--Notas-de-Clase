#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#define MIN(A,B) (((A) > (B))? (B):(A))

#define MAX_CAPACIDAD 320

typedef struct{
    char datos[MAX_CAPACIDAD];
    unsigned pri;
    unsigned ult;
    unsigned tam_rest;
}tCola;

void crearCola(tCola* p);
int colaVacia(const tCola* p);
int colaLlena(const tCola* p, unsigned cantBytes);
void vaciarCola(tCola* p);
int encolar(tCola* p, const void* dato, unsigned cantBytes);
int desencolar(tCola* p, void* dato, unsigned cantBytes);


#endif // COLA_H_INCLUDED
