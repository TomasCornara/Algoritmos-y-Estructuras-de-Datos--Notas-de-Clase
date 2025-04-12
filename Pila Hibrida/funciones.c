#include "pila_hibrida.h"
#include <string.h>
#define TAM_DATO sizeof(unsigned)

void crear_pila(t_pila* pila){
    pila->tope = 0;
}

int apilar(t_pila* pila, const void* dato, unsigned tam){
    char* px_aux;
    unsigned tam_dato = tam;

    ///Chequeo que haya espacio en la pila
    if(pila-> tope >= CAPACIDAD_PILA) return 0;

    ///Chequeo que puedo pedir el lugar para el bloque que tengo que guardar
    px_aux = malloc(TAM_DATO + tam);
    if(!px_aux) return 0;

    ///Si todo sale bien, muevo el tope, guardo la direccion del bloque y asigno la data al espacio que pedi
    pila->pila[pila->tope] = px_aux;
    pila->tope++;
    //Paso el tam
    memcpy(px_aux,&tam_dato,TAM_DATO);
    px_aux += TAM_DATO;
    //Paso el dato
    memcpy(px_aux,dato,tam);
    return 1;
}

int desapilar(t_pila* pila, void* dato, unsigned tam){
    unsigned tam_dato;
    char* px_bloque = pila->pila[pila->tope - 1];

    ///Chequeo que haya algo que desapilar
    if(!px_bloque) return 0;

    ///Recupero el tam del dato
    memcpy(&tam_dato,px_bloque,TAM_DATO);
    px_bloque += TAM_DATO;

    ///Recupero el dato
    memcpy(dato,px_bloque,(tam > tam_dato)? tam_dato:tam);
    free(pila->pila[pila->tope]); //Devuelvo memoria
    pila->tope--;

    return 1;
}

void vaciar_pila(t_pila* pila){
    while(pila->tope > 0){
        pila->tope--;
        free(pila->pila[pila->tope]);
    }
}
