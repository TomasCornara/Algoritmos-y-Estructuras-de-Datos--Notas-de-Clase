#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "listaVideojuegos.h"


void crearTop(tTop* top){
    crearLista(&(top->lista_interna));
    top->cant = 0;
    top->tope = MAX_REGISTROS;
}

void randomizarRegistro(tRegistro* registro) {
    for (int i = 0; i < 3; i++){
        registro->tag[i] = 'A' + (rand() % 26);
    }


    registro->tag[3] = '\0';
    registro->puntos = rand() % 1000;
}

int ponerEnTop(tTop* top, tRegistro* nuevo_registro){
    int ret;
    ret = ponerEnOrden(&top->lista_interna,nuevo_registro,sizeof(tRegistro),comparar_tRegistro);

    //Si hubo exito, se incrementa
    if(ret){
        top->cant++;
    }

    //Si hay demas, se elimina el ultimo
    if(top->cant > top->tope){
        borrarUltimo(&top->lista_interna);
        top->cant--;
    }

    return ret;
}

int comparar_tRegistro(const void* elementoEntrante, const void* elementoPresente){
    tRegistro* elemEnt = (tRegistro*)elementoEntrante;
    tRegistro* elemPres = (tRegistro*)elementoPresente;

    //Si los puntos del entrante son peores que el presente
    if(elemEnt->puntos < elemPres->puntos){
        return 1;
    }

    if(elemEnt->puntos > elemPres->puntos){
        return -1;
    }

    //Si tenes los mismos puintos, el nuevo es mejor
    return -1;
}

void mostrarRegistro(const void* registro){
    tRegistro* reg = (tRegistro*)registro;
    printf("\t%s \t %d\n",reg->tag,reg->puntos);
}

void mostrarTop(tTop* top){
    mapLista(&top->lista_interna,mostrarRegistro);
}
