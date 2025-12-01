#include <stdio.h>
#include <stdlib.h>

#include "arbolBinario.h"

typedef struct{
    unsigned cod;
    char cont[20];
}tRegistro;

int cmpInt(const void* elem1, const void* elem2){
    return *(int*)elem1 - *(int*)elem2;
}

void printInt(const void* elem){
    printf("%d",*(int*)elem);
}

int cmpReg(const void* elem1, const void* elem2){
    tRegistro* reg1 = (tRegistro*)elem1;
    tRegistro* reg2 = (tRegistro*)elem2;

    if(reg1->cod > reg2->cod) return 1;
    if(reg1->cod < reg2->cod) return -1;

    return 0;
}

void ptrReg(const void* elem){
    tRegistro* reg = (tRegistro*)elem;
    printf("%d-%s\n",reg->cod,reg->cont);
}

int main(){
    FILE* arch;
    t_Arbol mi_arbol;
    int ce, cantBytes;

    crearArbol(&mi_arbol);

    arch = fopen("archivo.bin","rb");
    if(!arch) return 0;

    fseek(arch, 0, SEEK_END);
    cantBytes = sizeof(tRegistro);
    ce = ftell(arch)/cantBytes;
    rewind(arch);

    printf("%d %d\n",ce,cantBytes);

    cargarDesdeArchivo(&mi_arbol,ce,cantBytes,arch);


    fclose(arch);
    return 0;
}
