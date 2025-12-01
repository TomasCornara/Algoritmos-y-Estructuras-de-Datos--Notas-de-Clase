#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int cmp_int(const void* elemA, const void* elemB){
    return *(int*)elemA - *(int*)elemB;
}

void ptr_int(const void* elem){
    printf("%d\n",*(int*)elem);
}

int main()
{
    int nums[] = {1,9,4,2,5,3,0,10};
    tLista mi_lista;

    crearLista(&mi_lista);

    for(int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++){
        ponerEnLista(&mi_lista,&nums[i],sizeof(nums[0]),cmp_int);
    }

    mapLista(&mi_lista,ptr_int);

    return 0;
}
