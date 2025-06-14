#ifndef COLAESTATICA_H_INCLUDED
#define COLAESTATICA_H_INCLUDED
#define CAPACIDAD_COLA 120

typedef struct {
    char vec[CAPACIDAD_COLA];
    unsigned primero;
    unsigned ultimo;
    unsigned bytesDisponibles;
}tCola;

void crearCola(tCola* cola);
int colaLlena(const tCola* cola);
int colaVacia(const tCola* cola);
int encolar(tCola* cola, const void* dato, unsigned cantBytes);
void escribirEnCola(tCola* cola, const void* origen, unsigned cant);
int desEncolar(tCola* cola, void* buffer, unsigned cantBytes);
void leerDeCola(tCola* cola,void* buffer, unsigned cantBytes);
int verPrimero(const tCola* cola, void* buffer, unsigned cantBytes);
void leerDeColaConst(const tCola* cola,void* buffer, unsigned cantBytes);

#endif // COLAESTATICA_H_INCLUDED
