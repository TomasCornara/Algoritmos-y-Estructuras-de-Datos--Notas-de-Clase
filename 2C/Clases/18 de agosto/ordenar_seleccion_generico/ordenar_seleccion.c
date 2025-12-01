#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenar_seleccion.h"

void ordenarSeleccion(void* vec, size_t tam, size_t ce,int(*cmp)(const void*, const void*)){
    char* proximo_menor;
    char* fin;

    fin = (char*)vec + (ce * tam);

    while((char*)vec < fin){
        proximo_menor = encontrarMenor(vec,tam,ce,cmp);
        intercambiar(vec,proximo_menor,tam);
        vec = (char*)vec + tam;
    }
}

void* encontrarMenor(void* vec, size_t tam, size_t ce,int (*cmp)(const void*, const void*)){
    char* menor = NULL;
    char* fin;
    int res;

    fin = (char*)vec + (ce * tam);

    //El primero siempre va a ser el mejor al principio
    menor = vec;

    //Busco uno mejor
    while((char*)vec < fin){
        res = cmp(vec,menor);
        if(res > 0){
            menor = vec;
        }
        vec = (char*)vec + tam;
    }

    return menor;
}

int intMenor(const void* elemA, const void* elemB){
    int A = *(int*)elemA,
        B = *(int*)elemB;

    return (A - B) * -1;
}

void intercambiar(void* dir1,void* dir2,size_t tam){
    char aux;
    char* aux_dir1 = (char*)dir1;
    char* aux_dir2 = (char*)dir2;

    while(tam > 0){
        aux = *aux_dir1;
        *aux_dir1 = *aux_dir2;
        *aux_dir2 = aux;

        aux_dir1++;
        aux_dir2++;
        tam--;
    }
}
