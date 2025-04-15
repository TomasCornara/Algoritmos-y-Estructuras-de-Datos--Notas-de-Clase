#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define FALLO_ABRIR_ARCHIVO 2

void mostrar_entero(const void* x) {
    printf("%d", *(const int*)x);
}

int main()
{
    ///BLOQUE DECLARACIONES
    int cantidad_registros,
        i,
        buffer;
    t_vector* vector;
    FILE* px_arch;


    ///PROCESO
    //Creacion del vector
    vector = t_vector_crear(sizeof(int));


    px_arch = fopen("datos.txt","r");
    if(!px_arch) return FALLO_ABRIR_ARCHIVO;

    //Lectura de la cantidad de registros
    if (fscanf(px_arch, "%d\n", &cantidad_registros) != 1) {
        fprintf(stderr, "Error al leer la cantidad de registros.\n");
        fclose(px_arch);
        return 1; // Otro código de error
    }
    printf("Se va a leer: %d registros.\n",cantidad_registros);

    //Lectura de los registros
    for (i = 0; i < cantidad_registros; i++) {
        if (fscanf(px_arch, "%d", &buffer) != 1) {
            fprintf(stderr, "Error al leer registro %d\n", i);
            break;
        }
        t_vector_agregar(vector, &buffer);
    }

    t_vector_mostrar(vector,mostrar_entero);

    t_vector_destruir(vector);

    ///BLOQUE DE CIERRE
    fclose(px_arch);


    return 0;
}
