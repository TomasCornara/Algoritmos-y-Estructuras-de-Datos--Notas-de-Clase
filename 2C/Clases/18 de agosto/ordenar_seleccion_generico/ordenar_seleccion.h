#ifndef ORDENAR_SELECCION_H_INCLUDED
#define ORDENAR_SELECCION_H_INCLUDED

void ordenarSeleccion(void* vec, size_t tam, size_t ce,int(*cmp)(const void*, const void*));
void* encontrarMenor(void* vec, size_t tam, size_t ce,int (*cmp)(const void*, const void*));
int intMenor(const void* elemA, const void* elemB);
void intercambiar(void* dir1,void* dir2,size_t tam);

#endif // ORDENAR_SELECCION_H_INCLUDED
