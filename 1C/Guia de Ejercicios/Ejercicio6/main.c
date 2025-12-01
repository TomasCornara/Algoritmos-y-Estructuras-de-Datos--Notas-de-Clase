#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "persona.h"

#define FALLO_ABRIR_ARCHIVO 2
#define ERROR_LEER_REGISTRO 1
#define FALLO_CREAR_ARCHIVO_BINARIO 3

int main()
{
    ///BLOQUE DECLARACIONES
    int cantidad_registros,
        i;
    t_persona buffer;
    t_vector* vector;
    FILE* px_arch;

    //Para generar el archivo de registros
    int cant = 5;
    t_persona personas[5] = {
        {123456, "Alice"},
        {789012, "Bob"},
        {345678, "Charlie"},
        {901234, "David"},
        {567890, "Eve"}
    };
    px_arch = fopen("personas.bin","wb");
    if(!px_arch) return FALLO_CREAR_ARCHIVO_BINARIO;
    fwrite(&cant,sizeof(cant),1,px_arch);
    fwrite(personas,sizeof(personas),1,px_arch);
    fclose(px_arch);


    ///PROCESO
    //Creacion del vector
    vector = t_vector_crear(sizeof(t_persona));


    px_arch = fopen("personas.bin","rb");
    if(!px_arch) return FALLO_ABRIR_ARCHIVO;

    //Lectura de la cantidad de registros
    if (!fread(&cantidad_registros,sizeof(int),1,px_arch))
    {
        fprintf(stderr, "Error al leer la cantidad de registros.\n");
        fclose(px_arch);
        return 1; // Otro código de error
    }
    printf("Se va a leer: %d registros.\n",cantidad_registros);

    //Lectura de los registros
    for (i = 0; i < cantidad_registros; i++)
    {
        if (!fread(&buffer,sizeof(t_persona),1,px_arch))
        {
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
