#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"

//INICIALIZACION DE UN ARBOL BINARIO
void crearArbol(arbol* head)
{
    *head = NULL;
    return;
}

//INSERSION DE UN NODO
int insertarNodo(arbol* head, const void* dato, unsigned cantBytes, int comparar(const void*,const void*))
{
    tNodo* nue;
    int cmp;

    //Busco que posicion le corresponde
    while(*head)
    {
        if((cmp = comparar(dato,(*head)->info)) < 0)  //Caso izquierda
        {
            head = &(*head)->menor;
        }
        else if(cmp > 0)   //Caso derecha
        {
            head = &(*head)->mayor;
        }
        else   //Caso repetido
        {
            return 0;
        }
    }

    //Pido memoria
    nue = malloc(sizeof(tNodo));
    if(!nue || !(nue->info = malloc(cantBytes)))
    {
        free(nue);
        return 0;
    }

    //Cargo el nodo
    memcpy(nue->info,dato,cantBytes);
    nue->tam = cantBytes;
    nue->mayor = nue->menor = NULL;

    //Enlzo el nuevo nodo
    *head = nue;

    //Todo Ok
    return 1;
}

int calcularNodos(const arbol raiz){

    //Si no tiene nada
    if(raiz == NULL) return 0;

    return 1 + calcularAltura(raiz->menor) + calcularAltura(raiz->mayor);
}

unsigned calcularAltura(const arbol raiz) {
    if (raiz == NULL) {
        return 0; // Un árbol vacío tiene altura 0
    }

    unsigned alturaMayor = calcularAltura(raiz->mayor);
    unsigned alturaMenor = calcularAltura(raiz->menor);

    // La altura es 1 + la máxima altura de los subárboles
    return 1 + (alturaMayor > alturaMenor ? alturaMayor : alturaMenor);
}

void imprimirArbolGen(const arbol raiz, int nivel, void (*imprimir)(const void*)) {
    if (!raiz) return;

    // Imprime el subárbol derecho (mayor)
    imprimirArbolGen(raiz->mayor, nivel + 1, imprimir);

    // Imprime la sangría correspondiente al nivel
    for (int i = 0; i < nivel; i++)
        printf("\t");

    imprimir(raiz->info);
    printf("\n");

    // Imprime el subárbol izquierdo (menor)
    imprimirArbolGen(raiz->menor, nivel + 1, imprimir);
}

int guardarArbol(const arbol raiz, char* nombre){
    FILE* arch;

    if(raiz == NULL) return 0;

    arch = fopen(nombre,"wb");
    if(!arch) return 0;

    guardarArbol_aux(raiz,arch);

    fclose(arch);
    return 1;
}

void guardarArbol_aux(const arbol raiz, FILE* arch) {
    char existe;

    // Escribimos una marca para saber si el nodo existe o es NULL
    if (raiz == NULL) {
        existe = 0; // 0 significa que el nodo es NULL
        fwrite(&existe, sizeof(char), 1, arch);
    } else {
        existe = 1; // 1 significa que el nodo existe
        fwrite(&existe, sizeof(char), 1, arch);

        // Guardamos los datos del nodo
        fwrite(&(raiz->tam), sizeof(unsigned), 1, arch);
        fwrite(raiz->info, raiz->tam, 1, arch);

        // Llamadas recursivas para los hijos
        guardarArbol_aux(raiz->menor, arch);
        guardarArbol_aux(raiz->mayor, arch);
    }
}

arbol cargarArbol_aux(FILE* arch) {
    char existe = 0;
    tNodo* nuevo_nodo;

    // Lee la marca para saber si el nodo existe
    if (fread(&existe, sizeof(char), 1, arch) != 1) {
        // Si no se puede leer más, es el fin del archivo
        return NULL;
    }

    //Si la marca es 0, este era un puntero NULL. Termina esta rama.
    if (existe == 0) {
        return NULL;
    }

    //Si la marca es 1, el nodo existe. Hay que crearlo y leer sus datos.
    nuevo_nodo = (tNodo*)malloc(sizeof(tNodo));
    if (!nuevo_nodo) {
        perror("Error de memoria al crear nodo");
        return NULL; // Error crítico de memoria
    }

    // Leer el tamaño y la información del nodo
    fread(&(nuevo_nodo->tam), sizeof(unsigned), 1, arch);

    nuevo_nodo->info = malloc(nuevo_nodo->tam);
    if (!nuevo_nodo->info) {
        perror("Error de memoria para la info del nodo");
        free(nuevo_nodo);
        return NULL;
    }
    fread(nuevo_nodo->info, nuevo_nodo->tam, 1, arch);

    //Llamada recursiva para reconstruir los hijos en el mismo orden (pre-orden)
    nuevo_nodo->menor = cargarArbol_aux(arch);
    nuevo_nodo->mayor = cargarArbol_aux(arch);

    //Devuelve el nodo reconstruido con sus sub-árboles ya enlazados
    return nuevo_nodo;
}

arbol cargarArbol(const char* nombre) {
    FILE* arch = fopen(nombre, "rb");
    if (!arch) return NULL;

    arbol raiz = cargarArbol_aux(arch);

    fclose(arch);
    return raiz;
}

unsigned contarRamas(const arbol raiz){
    unsigned ramas = 0;
    contarRamas_aux(raiz,&ramas);
    return ramas;
}

void contarRamas_aux(const arbol raiz,unsigned* ramas){
    if(raiz == NULL) return;

    if(raiz->menor || raiz->mayor){
        (*ramas)++;
    }

    contarRamas_aux(raiz->menor, ramas);
    contarRamas_aux(raiz->mayor, ramas);
}

unsigned contarHojas(const arbol raiz){
    unsigned hojas = 0;
    contarHojas_aux(raiz,&hojas);
    return hojas;
}

void contarHojas_aux(const arbol raiz, unsigned* hojas){
    if(raiz == NULL) return;

    if(raiz->mayor == NULL && raiz->menor == NULL){
        (*hojas)++;
        return;
    }

    contarHojas_aux(raiz->menor,hojas);
    contarHojas_aux(raiz->mayor,hojas);
}

int eliminarNodo(arbol* raiz, const void* clave,int comparar(const void*, const void*)){
    int cmp;
    arbol nodo;

    if(*raiz == NULL) return 0;

    cmp = comparar(clave,(*raiz)->info);

    if(cmp < 0)
        return eliminarNodo(&(*raiz)->menor, clave, comparar);
    else if (cmp > 0)
        return eliminarNodo(&(*raiz)->mayor,clave,comparar);
    else {
        nodo = *raiz;

         // Caso 1: sin hijos
        if (nodo->menor == NULL && nodo->mayor == NULL) {
            free(nodo->info);
            free(nodo);
            *raiz = NULL;
        }

        // Caso 2: un solo hijo
        else if (nodo->menor == NULL || nodo->mayor == NULL) {
            arbol hijo = (nodo->menor) ? nodo->menor : nodo->mayor;
            free(nodo->info);
            free(nodo);
            *raiz = hijo;
        }

        // Caso 3: dos hijos
        else {
            arbol* reemplazo = &nodo->mayor;
            while ((*reemplazo)->menor != NULL)
                reemplazo = &(*reemplazo)->menor;

            // Copiar datos del sucesor
            free(nodo->info);
            nodo->info = malloc((*reemplazo)->tam);
            memcpy(nodo->info, (*reemplazo)->info, (*reemplazo)->tam);
            nodo->tam = (*reemplazo)->tam;

            // Eliminar sucesor
            eliminarNodo(reemplazo, (*reemplazo)->info, comparar);
        }

        return 1; // Eliminado
    }
}


void imprimirEntero(const void* dato) {
    printf("%d", *(int*)dato);
}


int cmp_int(const void* elemA, const void* elemB){
    int A;
    int B;

    A = *(int*)elemA;
    B = *(int*)elemB;

    return A - B;
}
