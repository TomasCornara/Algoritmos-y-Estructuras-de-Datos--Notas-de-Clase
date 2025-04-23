#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "pila.h"

#define EXITO_CREACION 1
#define EXITO_LECTURA 2

#define FALLO_APERTURA -1
#define FALLO_ARCHIVO -3

int crearArchivo(const char *nombreArchivo, const char *modoApertura);
int leerArchivoYCargarPila(const char *nombreArchivo, const char *modoApertura,
                           tPila *pila);

#endif // ARCHIVO_H_INCLUDED
