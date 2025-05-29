#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

int main() {
    tLista lista;
    crearLista(&lista);

    printf("=== PRUEBA DE LISTA DOBLEMENTE ENLAZADA ===\n\n");

    // Verificar lista vacía
    printf("1. Lista vacía: %s\n", listaVacia(&lista) ? "SÍ" : "NO");
    imprimirLista(lista);
    printf("\n");

    // Insertar al comienzo
    printf("2. Insertando al comienzo: 5, 3, 7\n");
    int val1 = 5, val2 = 3, val3 = 7;
    insertarAlComienzo(&lista, &val1, sizeof(int));
    insertarAlComienzo(&lista, &val2, sizeof(int));
    insertarAlComienzo(&lista, &val3, sizeof(int));
    imprimirLista(lista);
    imprimirListaReversa(lista);
    printf("\n");

    // Liberar y empezar de nuevo para probar insertarOrdenado
    liberarLista(&lista);
    crearLista(&lista);

    // Probar insertarOrdenado con lista vacía
    printf("3. Insertando ordenado en lista vacía: 5\n");
    int orden1 = 5;
    insertarOrdenado(&lista, &orden1, &orden1, sizeof(int), cmpInt);
    imprimirLista(lista);
    printf("\n");

    // Insertar más elementos ordenados
    printf("4. Insertando ordenado: 2, 8, 1, 7, 6, 5\n");
    int valores[] = {2, 8, 1, 7, 6, 5};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        printf("   Insertando %d...\n", valores[i]);
        insertarOrdenado(&lista, &valores[i], &valores[i], sizeof(int), cmpInt);
        imprimirLista(lista);
    }
    printf("\n");

    // Probar cuando el puntero no está al inicio
    printf("5. PRUEBA CRÍTICA: Insertando desde un nodo del medio\n");
    printf("   Lista actual: ");
    imprimirLista(lista);

    // Mover el puntero a un nodo del medio
    tLista punteroMedio = lista;
    while (punteroMedio && *(int*)(punteroMedio->info) != 5) {
        punteroMedio = punteroMedio->sig;
    }

    if (punteroMedio) {
        printf("   Puntero apunta al nodo con valor: %d\n", *(int*)(punteroMedio->info));

        // Insertar un nuevo valor
        int nuevoVal = 4;
        printf("   Insertando %d desde este punto...\n", nuevoVal);
        insertarOrdenado(&punteroMedio, &nuevoVal, &nuevoVal, sizeof(int), cmpInt);

        printf("   Resultado: ");
        imprimirLista(punteroMedio);
        imprimirListaReversa(punteroMedio);
    }
    printf("\n");

    // Probar con otro punto intermedio
    printf("6. Otra prueba: Insertando desde el final\n");
    tLista punteroFinal = lista;
    while (punteroFinal && punteroFinal->sig != NULL) {
        punteroFinal = punteroFinal->sig;
    }

    if (punteroFinal) {
        printf("   Puntero apunta al último nodo con valor: %d\n", *(int*)(punteroFinal->info));

        int otroVal = 3;
        printf("   Insertando %d desde este punto...\n", otroVal);
        insertarOrdenado(&punteroFinal, &otroVal, &otroVal, sizeof(int), cmpInt);

        printf("   Resultado: ");
        imprimirLista(punteroFinal);
    }
    printf("\n");

    // Verificar integridad de la lista
    printf("7. Verificación de integridad:\n");
    tNodo* inicio = encontrarInicio(lista);
    tNodo* actual = inicio;
    int count = 0;

    printf("   Hacia adelante: ");
    while (actual != NULL) {
        printf("%d ", *(int*)(actual->info));
        count++;
        actual = actual->sig;
    }
    printf("(total: %d nodos)\n", count);

    // Verificar enlaces hacia atrás
    actual = inicio;
    while (actual->sig != NULL) {
        actual = actual->sig;
    }

    printf("   Hacia atrás: ");
    while (actual != NULL) {
        printf("%d ", *(int*)(actual->info));
        actual = actual->ant;
    }
    printf("\n");

    // Limpiar memoria
    liberarLista(&lista);
    printf("\n=== PRUEBAS COMPLETADAS ===\n");

    return 0;
}
