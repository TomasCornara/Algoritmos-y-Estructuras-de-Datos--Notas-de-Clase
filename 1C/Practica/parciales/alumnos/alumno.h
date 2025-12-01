#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#define MAX_COD_CARRERA 4
#define MAX_APELLIDO 21
#define MAX_NOMBRES 21
#define MAX_MATERIAS 50
#define MAX_COD_CURSADA 7

typedef struct{
    unsigned int cod_materia;
    char cod_cursada[MAX_COD_CURSADA];
    unsigned int nota_final;
}t_materia;


typedef struct{
    t_materia materias[MAX_MATERIAS];
    unsigned int cant_materias;
} t_materias;

typedef struct{
    unsigned int dni;
    char apellido[MAX_APELLIDO];
    char nombres[MAX_NOMBRES];
    char cod_carrera[MAX_COD_CARRERA];
    t_materias materias;
} t_alumno;




int crearBache();

#endif // ALUMNO_H_INCLUDED
