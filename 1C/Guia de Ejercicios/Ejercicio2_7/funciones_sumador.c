#include "sumador.h"

char* sumarDigitosLargos(char* resultado,
                          const char* primer_sumando,
                          const char* segundo_sumando){

    /// 0 - Bloque declarativo
    tPila sumando_1, sumando_2, pila_resultado;
    unsigned acarreo, sum;
    char op1, op2, res;
    char* px_resultado;

    /// 1 - Estado Inicial
    crearPila(&sumando_1);
    crearPila(&sumando_2);
    crearPila(&pila_resultado);
    acarreo = 0;
    px_resultado = resultado;

    /// 2 - Apilamiento
    while(*primer_sumando){
        if(apilar(&sumando_1, primer_sumando, sizeof(char)) != EXITO_PILA_APILADA) return NULL;
        primer_sumando++;
    }

    while(*segundo_sumando){
        if(apilar(&sumando_2, segundo_sumando, sizeof(char)) != EXITO_PILA_APILADA) return NULL;
        segundo_sumando++;
    }

    /// 3 - Desapilamiento y Cálculo
    while(pilaVacia(&sumando_1) != PILA_VACIA && pilaVacia(&sumando_2) != PILA_VACIA){
        if(desapilar(&sumando_1, &op1, sizeof(char)) != EXITO_PILA_DESAPILADA) return NULL;
        if(desapilar(&sumando_2, &op2, sizeof(char)) != EXITO_PILA_DESAPILADA) return NULL;
        sum = (op1 - '0') + (op2 - '0') + acarreo;
        acarreo = sum / 10;
        res = (sum % 10) + '0';
        if(apilar(&pila_resultado, &res, sizeof(char)) != EXITO_PILA_APILADA) return NULL;
    }

    while(pilaVacia(&sumando_1) != PILA_VACIA){
        if(desapilar(&sumando_1, &op1, sizeof(char)) != EXITO_PILA_DESAPILADA) return NULL;
        sum = (op1 - '0') + acarreo;
        acarreo = sum / 10;
        res = (sum % 10) + '0';
        if(apilar(&pila_resultado, &res, sizeof(char)) != EXITO_PILA_APILADA) return NULL;
    }

    while(pilaVacia(&sumando_2) != PILA_VACIA){
        if(desapilar(&sumando_2, &op2, sizeof(char)) != EXITO_PILA_DESAPILADA) return NULL;
        sum = (op2 - '0') + acarreo;
        acarreo = sum / 10;
        res = (sum % 10) + '0';
        if(apilar(&pila_resultado, &res, sizeof(char)) != EXITO_PILA_APILADA) return NULL;
    }

    if(acarreo > 0){
        res = acarreo + '0';
        if(apilar(&pila_resultado, &res, sizeof(char)) != EXITO_PILA_APILADA) return NULL;
    }

    /// 5 - Reorganización a string
    while(pilaVacia(&pila_resultado) != PILA_VACIA){
        if(desapilar(&pila_resultado, px_resultado, sizeof(char)) != EXITO_PILA_DESAPILADA) return NULL;
        px_resultado++;
    }

    *px_resultado = '\0';
    return resultado;
}
