#include <stdlib.h>
#include "stdio.h"
#include "emuladorDados.h"



jugador* cargarEstadoInicial(FILE* archivoJugadores, int* cantJugadores){
    jugador* vectorJugadores;

    //Verifico que el archivo sea correcto
    if(!archivoJugadores) return NULL;

    //Leo la cantidad de jugadores
    fread(cantJugadores,sizeof(int),1,archivoJugadores);

    //Pido memoria para esa cantidad de jugadores
    vectorJugadores = malloc((*cantJugadores) * sizeof(jugador));
    if(!vectorJugadores){
        fprintf(stderr,"Error memoria - jugadores");
        return NULL;
    }

    //Leo los jugadores
    fread(vectorJugadores,sizeof(jugador),*cantJugadores,archivoJugadores);

    //Devuelvo el vector de jugadores
    return vectorJugadores;
}

int tirarDado(void){
    return (rand()%6 + 1);
}
