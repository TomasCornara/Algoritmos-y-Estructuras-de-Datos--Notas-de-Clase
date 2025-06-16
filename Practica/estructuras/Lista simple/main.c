#include <stdio.h>
#include "lista_simple.h"


int main() {
    tLista lista;
    crearLista(&lista);

    int R = 40;
    int Z = 25;
    int valores[] = {30, 10, 50, 20, 40};

    //INSERSIONES EN ORDEN
    printf("Insertando ordenadamente:\n");
    for (int i = 0; i < 5; i++) {
        insertarOrdenado(&lista, &valores[i], sizeof(int), cmp_int);
        mostrarLista(&lista);
    }

    //TEST INSERT Y ELIMINACION INTERMEDIO
    printf("\nInsertando intermedio (25):\n");
    insertarOrdenado(&lista,&Z,sizeof(int),cmp_int);
    mostrarLista(&lista);

    printf("\nElimino intermedio (25):\n");
    eliminarPrimera(&lista,&Z,cmp_int);
    mostrarLista(&lista);

    //TEST INSERTAR EN POSICION
    printf("\nInsertando 40 en posicion 2 y ultimo:\n");
    insertanEnPosicion(&lista,2,&R,sizeof(int));
    mostrarLista(&lista);

    //TEST INSERT Y ELIMINACION DE INTERMEDIO Y ULTIMO
    printf("\nInsertando intermedio (25) y ultimo:\n");
    insertarOrdenado(&lista,&Z,sizeof(int),cmp_int);
    ponerAlFinal(&lista,&Z,sizeof(int));
    mostrarLista(&lista);

    eliminarTodas(&lista,&Z,cmp_int);
    mostrarLista(&lista);

    //Eliminar repetidos
    //Meto varios 40s
    printf("\nBorrar repetidos y ultimo:\n");
    for(int n = 0; n < 3; n++){
        ponerAlFinal(&lista,&R,sizeof(int));
    }
    mostrarLista(&lista);
    eliminarRepetidos(&lista,cmp_int);
    mostrarLista(&lista);

    //TEST ELIMINAR PUNTUAL
    printf("\nEliminar posicion 0\n");
    mostrarLista(&lista);
    eliminarPosicion(&lista,0);
    mostrarLista(&lista);

    //TESTS SACAR Y PONER
    printf("\nVer primero y ultimo:\n");
    int primero, ultimo;
    if (verPrimero(&lista, &primero, sizeof(int)))
        printf("Primero: %d\n", primero);
    if (verUltimoLista(&lista, &ultimo, sizeof(int)))
        printf("Ultimo: %d\n", ultimo);

    printf("\nSacar primero:\n");
    while (sacarPrimero(&lista, &primero, sizeof(int))) {
        printf("Sacado: %d\n", primero);
        mostrarLista(&lista);
    }

    printf("\nInsertar al comienzo:\n");
    for (int i = 0; i < 3; i++) {
        ponerAlComienzo(&lista, &valores[i], sizeof(int));
        mostrarLista(&lista);
    }

    printf("\nInsertar al final:\n");
    for (int i = 3; i < 5; i++) {
        ponerAlFinal(&lista, &valores[i], sizeof(int));
        mostrarLista(&lista);
    }

    printf("\nSacar ultimo:\n");
    while (sacarUltimoLista(&lista, &ultimo, sizeof(int))) {
        printf("Sacado: %d\n", ultimo);
        mostrarLista(&lista);
    }

    printf("\nInsertar desordenado para eliminar:\n");
    for (int i = 0; i < 5; i++) {
        ponerAlFinal(&lista, &valores[i], sizeof(int));
    }
    mostrarLista(&lista);

    int clave = 30;
    printf("Eliminando %d...\n", clave);
    eliminar(&lista, &clave, cmp_int);
    mostrarLista(&lista);

    printf("\nVaciando lista...\n");
    vaciarLista(&lista);
    mostrarLista(&lista);

    return 0;
}

