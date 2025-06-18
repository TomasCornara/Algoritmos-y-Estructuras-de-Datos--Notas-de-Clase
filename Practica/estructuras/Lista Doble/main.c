#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de estructuras
typedef struct sNodo {
    void* dato;
    unsigned tam;
    struct sNodo* sig;
    struct sNodo* ant;
} tNodo;

typedef tNodo* tLista;
typedef int (*comparacion)(const void* a, const void* b);

// Función de comparación para enteros
int compararEnteros(const void* a, const void* b) {
    int valorA = *(int*)a;
    int valorB = *(int*)b;
    return valorA - valorB;
}

void imprimirLista(tLista lista) {
    if(!lista) {
        printf("Lista vacía\n");
        return;
    }

    tNodo* aux;

    // RECORRIDO HACIA ADELANTE (desde el primer nodo)
    // Primero encontrar el primer nodo
    aux = lista;
    while(aux->ant) {
        aux = aux->ant;
    }

    printf("Adelante: ");
    while(aux) {
        printf("%d", *(int*)aux->dato);
        aux = aux->sig;
        if(aux) printf(" -> ");
    }
    printf("\n");

    // RECORRIDO HACIA ATRÁS (desde el último nodo)
    // Primero encontrar el último nodo
    aux = lista;
    while(aux->sig) {
        aux = aux->sig;
    }

    printf("Atrás:    ");
    while(aux) {
        printf("%d", *(int*)aux->dato);
        aux = aux->ant;
        if(aux) printf(" -> ");
    }
    printf("\n");
}

// Función alternativa más compacta
void mostrarLista(tLista lista) {
    if(!lista) return;

    tNodo* primero = lista;
    tNodo* ultimo = lista;

    // Encontrar extremos
    while(primero->ant) primero = primero->ant;
    while(ultimo->sig) ultimo = ultimo->sig;

    // Adelante
    printf("->");
    for(tNodo* aux = primero; aux; aux = aux->sig) {
        printf("%d ", *(int*)aux->dato);
    }
    printf("\n");

    // Atrás
    printf("<-");
    for(tNodo* aux = ultimo; aux; aux = aux->ant) {
        printf("%d ", *(int*)aux->dato);
    }
    printf("\n");
}

int ponerEnLista(tLista* lista, const void* dato, unsigned cantBytes, comparacion cmp) {
    if (!lista)
        return 0;

    // Lista vacía: crear primer nodo
    if (*lista == NULL) {
        tNodo* entrante = malloc(sizeof(tNodo));
        if (!entrante)
            return 0;
        entrante->dato = malloc(cantBytes);
        if (!entrante->dato) {
            free(entrante);
            return 0;
        }
        memcpy(entrante->dato, dato, cantBytes);
        entrante->tam = cantBytes;
        entrante->ant = NULL;
        entrante->sig = NULL;
        *lista = entrante;
        return 1;
    }

    // Buscar la posición correcta (modificando *lista)
    int comp;
    while ((*lista)->ant && (comp = cmp(dato, (*lista)->dato)) < 0)
        *lista = (*lista)->ant;
    while ((*lista)->sig && (comp = cmp(dato, (*lista)->dato)) > 0)
        *lista = (*lista)->sig;

    comp = cmp(dato, (*lista)->dato);
    if (comp == 0)
        return 0; // Ya existe, no se inserta

    // Ahora sí: crear nodo entrante
    tNodo* entrante = malloc(sizeof(tNodo));
    if (!entrante)
        return 0;
    entrante->dato = malloc(cantBytes);
    if (!entrante->dato) {
        free(entrante);
        return 0;
    }
    memcpy(entrante->dato, dato, cantBytes);
    entrante->tam = cantBytes;

    if (comp < 0) {
        // Insertar antes de *lista
        entrante->sig = *lista;
        entrante->ant = (*lista)->ant;
        if ((*lista)->ant)
            (*lista)->ant->sig = entrante;
        (*lista)->ant = entrante;
    } else {
        // Insertar después de *lista
        entrante->ant = *lista;
        entrante->sig = (*lista)->sig;
        if ((*lista)->sig)
            (*lista)->sig->ant = entrante;
        (*lista)->sig = entrante;
    }

    return 1;
}




int main() {
    tLista lista = NULL;

    printf("=== CARGA DE DATOS EN LISTA DOBLE ENLAZADA ===\n\n");

    // Datos para insertar
    int valores[] = {50, 25, 75, 10, 60, 30, 80};
    int cantValores = sizeof(valores) / sizeof(valores[0]);

    // Cargar datos uno por uno
    for(int i = 0; i < cantValores; i++) {
        printf("Insertando: %d\n", valores[i]);

        if(ponerEnLista(&lista, &valores[i], sizeof(int), compararEnteros)) {
            printf("Insertado correctamente\n");
        } else {
            printf(" Error al insertar\n");
        }

        mostrarLista(lista);
        printf("\n");
    }
    return 0;
}
