#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void* array;
    unsigned ce;
    unsigned capacidad;
    unsigned tamElem;
} vector;

void crearVector(vector* vec, unsigned tamElem){
    vec->array = NULL;
    vec->tamElem = tamElem;
    vec->capacidad = 0;
    vec->ce = 0;
}

int ponerEnVector(vector* vec, const void* elemento) {
    if(vec->ce == vec->capacidad / vec->tamElem) {
        unsigned nuevaCap = (vec->capacidad == 0) ? 4 * vec->tamElem : vec->capacidad * 2;
        void* temp = realloc(vec->array, nuevaCap);
        if(!temp) return 0;
        vec->array = temp;
        vec->capacidad = nuevaCap;
    }

    memcpy((char*)vec->array + vec->ce * vec->tamElem, elemento, vec->tamElem);
    vec->ce++;
    return 1;
}

int verPos(vector* vec, void* destino, unsigned pos){
    if(pos >= vec->ce) return 0; // validación correcta
    memcpy(destino, (char*)vec->array + pos * vec->tamElem, vec->tamElem);
    return 1;
}

int main() {
    vector mi_vector;
    crearVector(&mi_vector, sizeof(int));

    for(int i = 0; i < 4; i++){
        ponerEnVector(&mi_vector, &i);
    }

    int buffer;
    if(verPos(&mi_vector, &buffer, 3)) {
        printf("%d\n", buffer); // imprime 3
    } else {
        printf("Posición inválida\n");
    }

    free(mi_vector.array); // liberar memoria dinámica
    return 0;
}
