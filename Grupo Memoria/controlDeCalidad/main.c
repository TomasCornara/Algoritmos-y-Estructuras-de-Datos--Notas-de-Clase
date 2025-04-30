#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"

int main()
{
    FILE* px_entrada;
    FILE* px_aprobados;
    FILE* px_observados;
    char buffer[MAX_BUFFER];
    tCola cola;
    producto prod_aux;
    int cmp;

    ///Apertura de archivos
    px_entrada = fopen("entrada.txt", "r");
    if(!px_entrada) return 1;

    px_aprobados = fopen("lotesAprobados.txt", "w");
    if(!px_aprobados){
        fclose(px_entrada);
        return 1;
    }

    px_observados = fopen("lotesObservados.txt", "w");
    if(!px_observados){
        fclose(px_entrada);
        fclose(px_aprobados);
        return 1;
    }

    //Creacion de la cola
    crearCola(&cola);

    ///Carga de la cola
    while(fgets(buffer, MAX_BUFFER, px_entrada)){
        //Parseo lo leido
        parseToProd(buffer, &prod_aux);

        //Si no hay nada, hay que encolar directamente
        if(!cola.primero){
            enColar(&cola, &prod_aux, sizeof(prod_aux));
            continue;
        }

        //Chequeo si no hubo un cambio de lote
        cmp = strcmp(((producto*)(cola.ultimo->dato))->lote, prod_aux.lote);
        if(cmp){
            procesarLote(&cola, px_aprobados, px_observados);
        }

        enColar(&cola, &prod_aux, sizeof(prod_aux));
    }

    /// Procesar el último lote
    if(!colaVacia(&cola))
        procesarLote(&cola, px_aprobados, px_observados);

    /// Cierre de punteros
    vaciarCola(&cola); // opcional porque procesarLote ya vacía
    fclose(px_entrada);
    fclose(px_aprobados);
    fclose(px_observados);

    return 0;
}
