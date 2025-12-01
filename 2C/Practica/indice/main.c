#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "indice.h"
#define MAX_NAME 50

typedef struct {
    int dni;
    char nombre[MAX_NAME];
} tPersona;

int cmpPersona(const void* a, const void* b) {
    const tPersona* p1 = (const tPersona*)a;
    const tPersona* p2 = (const tPersona*)b;
    return p1->dni - p2->dni;
}

int cmpClavePos(const void* a, const void* b) {
    const tClavePos* cp1 = (const tClavePos*)a;
    const tClavePos* cp2 = (const tClavePos*)b;
    const tPersona* p1 = (const tPersona*)cp1->clave;
    const tPersona* p2 = (const tPersona*)cp2->clave;
    return strcmp(p1->nombre, p2->nombre);
}

int cmpNombreConClave(const void* a, const void* b) {
    const char* nombre = (const char*)a;
    const tClavePos* cp = (const tClavePos*)b;
    const tPersona* persona = (const tPersona*)cp->clave;
    return strcmp(nombre, persona->nombre);
}

void imprimirPersona(const tPersona* p) {
    printf("DNI: %d | Nombre: %s\n", p->dni, p->nombre);
}

int main() {
    int i;
    tIndice mi_indice;
    tPersona buffer;
    FILE* arch;
    tPersona mis_personas[] = {{9,"tomas"},
                               {8,"jessica"},
                               {7,"oscar"},
                               {6,"matias"},
                               {5,"federico"},
                               {4,"marcelo"},
                               {3,"juliana"},
                               {2,"graciela"},
                               {1,"cecilia"},
                               {0,"malena"}};

    ///CREACION LOTE DE PRUEBA
    arch = fopen("datos.tommy","wb");
    if(!arch) return -1;
    fwrite(mis_personas,sizeof(mis_personas),1,arch);


    ///RESOLUCION
    arch = freopen("datos.tommy","rb",arch);
    crearIndice(&mi_indice);
    i = 0;


    while(fread(&buffer,sizeof(tPersona),1,arch)){
        indexar(&mi_indice,&buffer,sizeof(tPersona),i,cmpClavePos);
        i++;
    }

    char* name = "jessica";
    printf("El indice de %s es %d",name,buscarIndice(&mi_indice,name,cmpNombreConClave));

    return 0;
}
