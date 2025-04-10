#include <stdio.h>
#include <string.h>
#include "pila.h"

int main(void) {
    t_pila pila;
    char mensaje1[] = "hola";
    char mensaje2[] = "chau";
    char buffer[20];

    crear_pila(&pila);

    /// Apilo "hola"
    if (apilar(&pila, mensaje1, strlen(mensaje1) + 1)) {
        printf("Se apiló: \"%s\"\n", mensaje1);
    } else {
        printf("ERROR al apilar \"%s\"\n", mensaje1);
    }

    /// Apilo "chau"
    if (apilar(&pila, mensaje2, strlen(mensaje2) + 1)) {
        printf("Se apiló: \"%s\"\n", mensaje2);
    } else {
        printf("ERROR al apilar \"%s\"\n", mensaje2);
    }

    /// Veo el tope (debería ser "chau")
    if (ver_tope(&pila, buffer, sizeof(buffer))) {
        printf("Elemento en el tope (sin desapilar): \"%s\"\n", buffer);
    } else {
        printf("No hay nada en el tope.\n");
    }

    /// Desapilo (debería salir "chau")
    if (desapilar(&pila, buffer, sizeof(buffer))) {
        printf("Se desapiló: \"%s\"\n", buffer);
    } else {
        printf("No se pudo desapilar.\n");
    }

    /// Desapilo de nuevo (debería salir "hola")
    if (desapilar(&pila, buffer, sizeof(buffer))) {
        printf("Se desapiló: \"%s\"\n", buffer);
    } else {
        printf("No se pudo desapilar.\n");
    }

    /// Desapilo una tercera vez (ya está vacía)
    if (desapilar(&pila, buffer, sizeof(buffer))) {
        printf("Se desapiló: \"%s\"\n", buffer);
    } else {
        printf("La pila ya estaba vacía.\n");
    }

    return 0;
}
