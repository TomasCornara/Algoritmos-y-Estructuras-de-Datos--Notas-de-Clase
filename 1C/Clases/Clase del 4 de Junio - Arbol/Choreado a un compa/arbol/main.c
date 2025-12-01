#include "arbol.h"

int main()
{
    int vec[] = {10, 20, 30, 40, 50}, i;
    tArbol raiz;
    crearArbol(&raiz);
    for(i=0;i<sizeof(vec)/sizeof(int);i++){
        insertarArbolRec(&raiz, vec+i, sizeof(int), compararInt);
    }
    return 0;
}
