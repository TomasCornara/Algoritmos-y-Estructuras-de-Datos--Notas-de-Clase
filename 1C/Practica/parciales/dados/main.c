#include <stdio.h>
#include <stdlib.h>
#include "emuladorDados.h"
#include "bache_incial.h"
#include "lista_circular.h"

int main()
{
    int i,
        cantidadJugadores,
        jugadoresEnRonda,
        tirada = 0,
        ronda = 0;
    FILE* archJugadores;
    tLista listaJugadores;
    jugador *vecJugadores,
            bufferJugador,
            ganador;


    ///Crear los archivos iniciales
    if(!crearEstadoInicial()){
        fprintf(stderr,"Error al crear los archivos iniciales");
        return 1;
    }

    ///Solucion del problema
    srand(time(NULL));
    crearLista(&listaJugadores);

    //Abro el archivo
    if(!(archJugadores = fopen("participantes.dat","rb"))){
        fprintf(stderr,"No se pudo leer el archivo de jugadores");
        return 2;
    }

    //Cargo los datos
    if(!(vecJugadores = cargarEstadoInicial(archJugadores,&cantidadJugadores))){
        fprintf(stderr,"No se pudo cargar el estado inicial del juego");
        return 3;
    }

    //Pasar los jugadores a una lista circular
    printf("JUGADORES:\n\n");
    printf("\tPos\tNombre\n\n");
    for(i = 0; i < cantidadJugadores; i++){
        encolar(&listaJugadores,&vecJugadores[i],sizeof(vecJugadores[0]));
        printf("\t%d\t%s\n",vecJugadores[i].numero,vecJugadores[i].nombre);
    }
    printf("\n\nIngrese \"ENTER\" para empezar.\n");
    getchar();

    //Bucle principal
    while(!quedaUnoEnLista(&listaJugadores)){
        printf("\nNUEVA RONDA: N-%d \n\n", ronda);

        jugadoresEnRonda = cantidadJugadores;

        //Hago una ronda pasando por todos los jugadores
        for(i = 0; i < jugadoresEnRonda; i++){
            tirada = tirarDado(); //Tiro el dado

            //Veo el primero para poder imprimirlo
            verPrimero(&listaJugadores, &bufferJugador, sizeof(jugador));
            printf("%d|%s|%d\n", bufferJugador.numero, bufferJugador.nombre, tirada);

            //Si saco 5, lo que tengo que sacar
            if(tirada == 5){
                quitarPrimero(&listaJugadores);
                cantidadJugadores--;

                //Si solo queda un jugador, lo "veo" para guardarlo en la variable ganador
                if(cantidadJugadores == 1){
                    verPrimero(&listaJugadores, &ganador, sizeof(jugador));
                }
            } else { //Si no se elimino a nadie en esta ronda, hay que girar la el circulo en una posicion para ver quien sigue
                    //Nota: Si elimine a alguien en la ronda anterior, no hay que girar. Ya "avance" al siguiente al eliminarlo
                girarUno(&listaJugadores);
            }
        }

        printf("\n//////// FIN RONDA //////// \n\n");
        ronda++;
    }


    printf("FIN DE PARTIDA.\n");
    printf("\aEl ganador fue %s.\n\n",ganador.nombre);


    //Devolucion de memoria
    vaciarCola(&listaJugadores);
    free(vecJugadores);

    return 0;
}
