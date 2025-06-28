#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "alumno.h"
#define MIN_ALUMNOS 20

int crearBache(){
    int i, j, r;
    char aux;
    FILE* arch;
    t_alumno alumnoBuffer;
    t_materia materias[] = {{1111,"TEST01",1},
                            {2222,"TEST02",2},
                            {3333,"TEST03",3},
                            {4444,"TEST04",4},
                            {5555,"TEST05",5},
                            {6666,"TEST06",6}};

    arch = fopen("alumnos.txt","wt");
    if(!arch) return 0;

    for(i = 0; i < MIN_ALUMNOS; i++){
        // Inicializar la estructura
        memset(&alumnoBuffer, 0, sizeof(t_alumno));

        // DNI (ejemplo: empezar desde 40000000)
        alumnoBuffer.dni = 40000000 + i;

        // Apellido - crear string terminado en null
        aux = i + 65; // 'A', 'B', 'C', etc.
        alumnoBuffer.apellido[0] = aux;
        alumnoBuffer.apellido[1] = '\0'; // Terminar string

        // Nombre - crear string terminado en null
        aux = i + 97; // 'a', 'b', 'c', etc.
        alumnoBuffer.nombres[0] = aux;
        alumnoBuffer.nombres[1] = '\0'; // Terminar string

        // Código de carrera - crear string terminado en null
        aux = i + 48; // '0', '1', '2', etc.
        for(j = 0; j < MAX_COD_CARRERA - 1; j++){
            alumnoBuffer.cod_carrera[j] = aux;
        }
        alumnoBuffer.cod_carrera[MAX_COD_CARRERA - 1] = '\0'; // Terminar string

        // Materias
        r = rand() % 6; // 0 a 5 materias
        alumnoBuffer.materias.cant_materias = r; // Inicializar contador

        for(j = 0; j < r; j++){
            // Copiar la estructura completa de la materia
            memcpy(&alumnoBuffer.materias.materias[j], &materias[j], sizeof(t_materia));
        }

        // Escribir datos del alumno
        fprintf(arch,"%d,%s,%s,%s,%d\n",
                alumnoBuffer.dni,
                alumnoBuffer.apellido,
                alumnoBuffer.nombres,
                alumnoBuffer.cod_carrera,
                alumnoBuffer.materias.cant_materias);

        // Escribir materias del alumno
        for(j = 0; j < alumnoBuffer.materias.cant_materias; j++){
            fprintf(arch,"%d,%s,%d\n",
                    alumnoBuffer.materias.materias[j].cod_materia,
                    alumnoBuffer.materias.materias[j].cod_cursada,
                    alumnoBuffer.materias.materias[j].nota_final);
        }
    }

    fclose(arch);
    return 1;
}
