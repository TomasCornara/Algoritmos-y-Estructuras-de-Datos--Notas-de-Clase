#ifndef T_VECTOR_H
#define T_VECTOR_H

typedef struct {
    void* datos;
    int tam;
    int capacidad;
    int tam_elemento;
} t_vector;

t_vector* t_vector_crear(int tam_elemento);
void t_vector_destruir(t_vector* v);
int t_vector_agregar(t_vector* v, void* elem);
int t_vector_obtener(const t_vector* v, int indice, void* destino);
int t_vector_set(t_vector* v, int indice, void* fuente);
int t_vector_tamanio(const t_vector* v);
void t_vector_mostrar(const t_vector* v, void (*mostrar)(const void*));

#endif

