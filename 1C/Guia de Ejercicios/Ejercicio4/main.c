#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "persona.h"

#define FALLO_ABRIR_ARCHIVO 2
#define ERROR_LEER_REGISTRO 1
int main()
{
    ///BLOQUE DECLARACIONES
    int cantidad_registros,
        i;
    t_persona buffer;
    t_vector* vector;
    FILE* px_arch;


    ///PROCESO
    //Creacion del vector
    vector = t_vector_crear(sizeof(t_persona));


    px_arch = fopen("personas.txt","r");
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
        if (fscanf(px_arch, "%d,%s",&buffer.legajo,buffer.nombre) != 2) {
            mostrar_persona(&buffer);
            return ERROR_LEER_REGISTRO;
        }

        t_vector_agregar(vector, &buffer);
    }

    t_vector_mostrar(vector,mostrar_persona);

    t_vector_destruir(vector);

    ///BLOQUE DE CIERRE
    fclose(px_arch);


    return 0;
}
