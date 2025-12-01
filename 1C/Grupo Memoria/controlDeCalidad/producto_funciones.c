#include "producto.h"
#include <string.h>

int buscarFallosLote(tCola* lote){
    return buscarFalloRecursivo(lote->primero);
}

int buscarFalloRecursivo(tNodo* nodo){
    if(!nodo)
        return LOTE_APROBADO;

    printf("%s %s %s\n", ((producto*)(nodo->dato))->lote, ((producto*)(nodo->dato))->producto, ((producto*)(nodo->dato))->control);

    int cmp = strcmp(((producto*)(nodo->dato))->control, "FALLA");
    if(!cmp)
        return LOTE_FALLIDO;

    return buscarFalloRecursivo(nodo->siguiente);
}

void procesarLote(tCola* lote, FILE* aprobados, FILE* observados){
    producto prod_aux;
    int fallos = buscarFallosLote(lote);

    FILE* destino = (fallos == LOTE_FALLIDO) ? observados : aprobados;

    while(desEncolar(lote, &prod_aux, sizeof(prod_aux)) == EXITO){
        fprintf(destino, "%s,%s,%s\n", prod_aux.lote, prod_aux.producto, prod_aux.control);
    }
}

void parseToProd(char buffer[MAX_BUFFER], producto* prod) {
    char* px_aux;
    unsigned cant_caracteres;

    //Busco el Salto de Linea
    px_aux = strrchr(buffer,'\n');
    *px_aux = '\0';

    // Parseo el estado de control
    px_aux = strrchr(buffer, ',');
    *px_aux = '\0';
    px_aux++;
    cant_caracteres = strlen(px_aux);
    memcpy(prod->control, px_aux, cant_caracteres);
    *(prod->control + cant_caracteres) = '\0';

    // Parseo el producto
    px_aux = strrchr(buffer, ',');
    *px_aux = '\0';
    px_aux++;
    cant_caracteres = strlen(px_aux);
    memcpy(prod->producto, px_aux, cant_caracteres);
    *(prod->producto + 4) = '\0';

    // Parseo el lote - AQUÍ ESTÁ EL ERROR
    // Debería ser:
    px_aux = buffer; // Usar lo que queda del buffer original
    cant_caracteres = strlen(px_aux);
    memcpy(prod->lote, px_aux, cant_caracteres);
    *(prod->lote + 4) = '\0';
}
