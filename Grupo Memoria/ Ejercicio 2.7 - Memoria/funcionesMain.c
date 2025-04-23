#include "main.h"

void cargarPila(tPila *pila, FILE* origen)
{
    int digito;

    while((digito = fgetc(origen)) != EOF){
        digito -= '0';
        apilar(pila, &digito, sizeof(int));
    }
}

void sumarPilas(tPila *p1, tPila *p2, tPila *resultado)
{
    int suma, digito, digito1, digito2, acarreo = 0;

    while (!pilaVacia(p1) || !pilaVacia(p2) || acarreo != 0)
    {
        digito1 = digito2 = 0;

        desapilar(p1, &digito1, sizeof(int));
        desapilar(p2, &digito2, sizeof(int));

        suma = digito1 + digito2 + acarreo;

        digito = suma % 10;
        acarreo = suma / 10;

        apilar(resultado, &digito, sizeof(int));
    }
}

void mostrarUnidad(int *unidad)
{
    printf("%d", *unidad);
}

size_t mStrlen(const char *cadena)
{
    size_t i = 0;

    while (*cadena++)
        i++;

    return i;
}
