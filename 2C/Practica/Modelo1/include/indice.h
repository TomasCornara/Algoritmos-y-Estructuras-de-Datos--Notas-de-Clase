#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#include<arbol.h>

#define IND_ERROR 0
#define IND_OK 1

typedef struct
{
    tArbolBinBusq arbol;
    int (*cmp_clave)(const void*, const void*);
    size_t tam_clave;
    char * tmp_reg_ind;
} t_indice;

/**
ind_crear
 Inicializa la estructura a índice vacío y almacena en la estructura de índice
 el tamaño de la clave genérica a utilizar y la función de comparación.
**/
void ind_crear (t_indice* ind, size_t tam_clave, int (*cmp)(const void*, const void*));
void ind_crear_res (t_indice* ind, size_t tam_clave, int (*cmp)(const void*, const void*));

/**
ind_insertar
 Inserta en orden el registro de indice según la clave.
**/
int ind_insertar (t_indice* ind, void *clave, unsigned nro_reg);
int ind_insertar_res (t_indice* ind, void *clave, unsigned nro_reg);


/**
ind_eliminar
 elimina la entrada del índice correspondiente a la clave
 y devuelve en nro_reg el número de registro asociado.
**/
int ind_eliminar (t_indice* ind, void *clave, unsigned *nro_reg);
int ind_eliminar_res (t_indice* ind, void *clave, unsigned *nro_reg);

/**
ind_buscar
 Busca la clave recibida por parámetro y devuelve
 en nro_reg el número de registro asociado.
**/
int ind_buscar (const t_indice* ind, void *clave, unsigned *nro_reg);
int ind_buscar_res (const t_indice* ind, void *clave, unsigned *nro_reg);

/**
ind_cargar
 Carga el índice a partir de un archivo binario ordenado (típicamente de extensión ‘.idx’),
 donde cada registro del archivo tiene la estructura definida, clave-nro_reg.
**/
int ind_cargar (t_indice* ind, const char* path);
int ind_cargar_res (t_indice* ind, const char* path);

/**
ind_grabar
 Graba un archivo binario ordenado (típicamente de extensión ‘.idx’)
 con el contenido del índice con la estructura clave-nro_reg.
**/
int ind_grabar (const t_indice* ind, const char* path);
int ind_grabar_res (const t_indice* ind, const char* path);


/**
ind_vaciar
 Deja el índice en su estado de vacío.
**/
void ind_vaciar (t_indice* ind);
void ind_vaciar_res (t_indice* ind);


/**
ind_recorrer
 Recorre el índice en orden y llama a acción para cada registro del mismo.
**/
int ind_recorrer (const t_indice* ind, void (*accion)(const void *, unsigned, void *), void*param);
int ind_recorrer_res (const t_indice* ind, void (*accion)(const void *, unsigned, void *), void*param);


#endif // INDICE_H_INCLUDED
