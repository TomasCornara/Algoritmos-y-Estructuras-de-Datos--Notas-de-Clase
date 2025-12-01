#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include <stdio.h>

#define TAM_NOMBRE_Y_APELLIDO 40

typedef struct
{
    unsigned int legajo;
    unsigned short int edad;
    float sueldo; // NOTA: NO ES IDEAL USAR UN FLOAT PARA SUELDOS
    char nomAp[TAM_NOMBRE_Y_APELLIDO];
} tEmpleado;

#endif // EMPLEADO_H_INCLUDED
