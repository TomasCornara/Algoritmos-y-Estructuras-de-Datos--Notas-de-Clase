#include "main.h"
#include "pila.h"
#include "empleado.h"
#include "archivo.h"

int main()
{
    const char *nombreArchivo = "datos.dat", *modoAperturaEscritura = "wb",
                *modoAperturaLectura = "rb";
    tPila pila;
    tEmpleado auxEmpleado;

    /*crearPila(&pila);

    if (crearArchivo(nombreArchivo, modoAperturaEscritura) != EXITO_CREACION)
    {
        vaciarPila(&pila);

        fprintf(stderr, "Error al intentar escribir el archivo\n");

        return FALLO_ARCHIVO;
    }

    if (leerArchivoYCargarPila(nombreArchivo, modoAperturaLectura,
                               &pila) != EXITO_LECTURA)
    {
        vaciarPila(&pila);

        fprintf(stderr, "Error al intentar leer el archivo\n");

        return FALLO_ARCHIVO;
    }

    while (verTope(&pila, &auxEmpleado, sizeof(tEmpleado)) == EXITO_VER_TOPE)
    {
        printf("Legajo: %u, Edad: %hu, Sueldo: %.2f, Nombre y Apellido: %s\n",
               auxEmpleado.legajo, auxEmpleado.edad, auxEmpleado.sueldo,
               auxEmpleado.nomAp);

        if (desapilar(&pila, &auxEmpleado, sizeof(tEmpleado))
                != EXITO_PILA_DESAPILADA)
            puts("Pila vacia");
    }

    vaciarPila(&pila);

    /// --- TEST: llamada intencional con pila nula --- */
    printf("\nProbando desapilar con pila NULL:\n");
    printf("%d", desapilar(&pila, &auxEmpleado, sizeof(tEmpleado)));

    return EXITO;
}
