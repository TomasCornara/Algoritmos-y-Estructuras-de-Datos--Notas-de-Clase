#ifndef EMULADORDADOS_H_INCLUDED
#define EMULADORDADOS_H_INCLUDED
#define MAX_NOMBRE 25
#include <time.h>

typedef struct {
    int numero;
    char nombre[25];
} jugador;

jugador* cargarEstadoInicial(FILE* archivoJugadores, int* cantJugadores);
int tirarDado(void);

#endif // EMULADORDADOS_H_INCLUDED
