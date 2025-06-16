#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main() {
    // ========== PRUEBA DE COLA ==========
    printf("========== PRUEBA DE COLA ==========\n");
    tCola c;
    crearCola(&c);
    int valores[] = {10, 20, 30};
    int i;

    // Encolar elementos
    printf("Encolando elementos:\n");
    for (i = 0; i < 3; i++) {
        if (!ponerEnCola(&c, &valores[i], sizeof(int))) {
            printf("Error al encolar %d\n", valores[i]);
        } else {
            printf("  Encolado: %d\n", valores[i]);
        }
    }

    // Desencolar elementos
    printf("Desencolando:\n");
    while (!colaVacia(&c)) {
        int x;
        if (desEncolar(&c, &x, sizeof(int)))
            printf("  %d\n", x);
        else
            printf("Error al desencolar\n");
    }

    if(colaVacia(&c)){
        printf("Cola vacia - Todo ok\n");
    }

    // ========== PRUEBA DE PILA ==========
    printf("\n========== PRUEBA DE PILA ==========\n");
    tPila p;
    crearPila(&p);

    // Verificar pila vacia
    if(pilaVacia(&p)) {
        printf("Pila creada correctamente (vacia)\n");
    }

    // Apilar elementos
    printf("Apilando elementos:\n");
    for (i = 0; i < 3; i++) {
        if (!apilar(&p, &valores[i], sizeof(int))) {
            printf("Error al apilar %d\n", valores[i]);
        } else {
            printf("  Apilado: %d\n", valores[i]);
        }
    }

    // Ver tope sin desapilar
    printf("Verificando tope:\n");
    int tope;
    if (verTope(&p, &tope, sizeof(int))) {
        printf("  Tope: %d\n", tope);
    } else {
        printf("Error al ver tope\n");
    }

    // Desapilar elementos (debería salir en orden LIFO: 30, 20, 10)
    printf("Desapilando:\n");
    while (!pilaVacia(&p)) {
        int x;
        if (desApilar(&p, &x, sizeof(int)))
            printf("  %d\n", x);
        else
            printf("Error al desapilar\n");
    }

    if(pilaVacia(&p)){
        printf("Pila vacia - Todo ok\n");
    }

    // Verificar pila llena (si esta implementada)
    printf("\nVerificando funcion pilaLlena:\n");
    if(pilaLlena(&p)) {
        printf("Pila llena\n");
    } else {
        printf("Pila no llena (normal para implementacion dinamica)\n");
    }

    printf("\n========== FIN DE PRUEBAS ==========\n");
    return 0;
}

