#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    int i;
    int mi_vectorcito[] = {40, 10, 2, 1, 3, 20, 30, 50, 42, 41, 43, 52};
    arbol mi_arbol;
    arbol mi_otro_arbol;

    //Crea arbol
    crearArbol(&mi_arbol);

    //Inserta nodos
    for(i = 0; i < sizeof(mi_vectorcito)/sizeof(mi_vectorcito[0]); i++){
        insertarNodo(&mi_arbol,&mi_vectorcito[i],sizeof(mi_vectorcito[0]),cmp_int);
    }

    imprimirArbolGen(mi_arbol,sizeof(int),imprimirEntero);

    printf("\n\n\n\n");

    //Guardo en el archivo
    guardarArbol(mi_arbol,"arbol.arb");
    mi_otro_arbol = cargarArbol("arbol.arb");

    eliminarNodo(&mi_otro_arbol,&mi_vectorcito[3],cmp_int);
    imprimirArbolGen(mi_otro_arbol,sizeof(int),imprimirEntero);
    printf("%d",contarRamas(mi_otro_arbol));

    return 0;
}
