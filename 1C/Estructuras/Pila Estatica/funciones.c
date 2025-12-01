#include "pila.h"
#include <string.h>

//Esta funcion carga una pila de capacidad
void crear_pila(t_pila* pila){
    pila->tope = CAPACIDAD_PILA;
}

//Pila Vacia
int pila_vacia(const t_pila* pila){
    return pila->tope == CAPACIDAD_PILA;
}

//Pila Llena (Esta funcion en realidad chequea si hay lugar para lo que se quiere poner)
int pila_llena(const t_pila* pila, unsigned tam){
    return pila->tope < tam + sizeof(unsigned);
}

//Pone un nuevo elemento dentro de la pila
int apilar(t_pila* pila, const void* dato, unsigned tam){
    void* px;

    ///Chequeo que haya lugar en la pila
    //Si el tamaño del dato + los 4 bytes para su espacio son mas que
    //El espacio que me queda en la pila, entonces no hay espacio
    if(tam + sizeof(unsigned) > pila->tope){
        return 0; //Devuelvo 0 porque tiene valor "falso" en C
    }

    ///Calculo las posiciones para escribir en la pila
    //Me muevo hasta la posicion que le corresponde al dato
    px = pila->pila + (pila->tope - tam);
    memcpy(px,dato,tam); //Escribo el dato
    px -= sizeof(unsigned); //Hago espacio para el tipo de dato
    memcpy(px,&tam,sizeof(unsigned)); //Guardo el tamaño

    ///Actualizo el espacio disponible y me vuelvo
    pila->tope -= sizeof(unsigned) + tam; //Retrocedo el tope
    return 1; //Devuelvo todo bien
}

//Desapila el elemento superior de la pila
int desapilar(t_pila* pila, void* dato, unsigned tam){
    unsigned tam_info;
    void* px;

    ///Chequeo que no se quiera sacar mas de lo que hay en el stack
    if(pila_vacia(pila)){
        return 0;
    }

    ///Recupero de la pila el tamaño del elemento
    px = pila->pila + pila->tope; //Calculo la direccion donde empieza el elemento
    memcpy(&tam_info,px,sizeof(unsigned)); //Muevo el tamaño guardado a mi variable auxiliar

    ///Devuelvo el dato
    px+= sizeof(unsigned); //Me paro donde inicia el dato
    memcpy(dato,px,(tam > tam_info)? tam_info : tam); //Escribo el dato.
    /*NOTA: No puedo devolver mas que lo que ocupa el dato, asi que
    Se tiene que devolver el minimo entre lo que pidio el usuario y el tam maximo*/
    pila->tope += sizeof(unsigned) + tam_info; //Avanzo sobre la pila
    return 1;
}

//Muestra que es lo que hay en el tope, pero sin avanzar sobre la pila
//NOTA: Todo esto es igual que en des_apilar, pero sin avanzar la pila.
int ver_tope(const t_pila* pila, void* dato, unsigned tam){
    unsigned tam_info;
    const void* px;

    ///Chequeo que haya algo que leer
    if(pila_vacia(pila)){
        return 0;
    }

    ///Recupero el espacio a leer
    px = pila->pila + pila->tope;
    memcpy(&tam_info,px,sizeof(unsigned));

    ///Devuelvo el dato
    px+= sizeof(unsigned);
    memcpy(dato,px,(tam > tam_info)? tam_info:tam);
    return 1;
}















