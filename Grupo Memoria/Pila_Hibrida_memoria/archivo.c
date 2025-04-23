#include "archivo.h"
#include "empleado.h"

int crearArchivo(const char *nombreArchivo, const char *modoApertura)
{
    tEmpleado empleados[] =
    {
        {1001, 28, 85000.50, "Lucas Gomez"},
        {1002, 45, 120000.00, "Maria Fernandez"},
        {1003, 33, 97000.75, "Carlos Ramirez"},
        {1004, 22, 60000.00, "Sofia Lopez"},
        {1005, 39, 105000.20, "Diego Martinez"},
        {1006, 31, 98000.90, "Florencia Sanchez"},
        {1007, 50, 130000.00, "Ricardo Diaz"},
        {1008, 26, 71000.30, "Laura Torres"},
        {1009, 41, 115000.00, "Javier Perez"},
        {1010, 29, 90000.00, "Camila Mendez"}
    };
    FILE *arch = fopen(nombreArchivo, modoApertura);

    if (!arch)
        return FALLO_APERTURA;

    fwrite(empleados, sizeof(tEmpleado),
           sizeof(empleados) / sizeof(empleados[0]), arch);

    fclose(arch);

    return EXITO_CREACION;
}

int leerArchivoYCargarPila(const char *nombreArchivo,
                           const char *modoApertura, tPila *pila)
{
    tEmpleado empleado;
    FILE *arch = fopen(nombreArchivo, modoApertura);

    if (!arch)
        return FALLO_APERTURA;

    fread(&empleado, sizeof(tEmpleado), 1L, arch);

    while (!feof(arch))
    {
        if (apilar(pila, &empleado, sizeof(tEmpleado)) != EXITO_PILA_APILADA)
            puts("Error al intentar apilar");

        fread(&empleado, sizeof(tEmpleado), 1L, arch);
    }

    fclose(arch);

    return EXITO_LECTURA;
}
