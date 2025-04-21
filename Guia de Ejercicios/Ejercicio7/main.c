#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned factorial_recursivo(unsigned numero);
void mostrar_array_recursivo(char* string);
void mostrar_array_recursivo_inverso(char* string);
void mostrar_array_parcial_recursivo(char* string);
void mostrar_array_parcial_recursivo_inverso(char* string);
void mostrar_string_a_partes(char* string);
void mostrar_string_a_partes_aux(char* string, unsigned iteracion);
void mostrar_string_a_partes_inverso(char* string);
void mostrar_string_a_partes_inverso_aux(char* string, unsigned largo);
void descomposicion_numero(unsigned numero);
void descomposicion_numero_aux(char* string);
void descomposicion_numero_inverso(unsigned numero);
void descomposicion_numero_inverso_aux(char* string);

int main()
{
    ///Ejercicio 2-H
    //descomposicion_numero_inverso(1234);

    ///Ejercicio 2-G
    //descomposicion_numero(1234);

    ///Ejercicio 2-F
    //mostrar_string_a_partes_inverso("Hola");

    ///Ejercicio 2-E
    //mostrar_string_a_partes("Hola");

    ///Ejercicio 2-D
    //mostrar_array_parcial_recursivo_inverso("Hola");

    ///Ejercicio 2-C
    //mostrar_array_parcial_recursivo("Hola");

    ///Ejercicio 2-B
    //mostrar_array_recursivo_inverso("");
    //mostrar_array_recursivo_inverso("Hola");


    ///Ejercicio 2-A
    /*mostrar_array_recursivo("");
    mostrar_array_recursivo("Hola");*/

    ///Ejercicio 1
    /*printf("El factorial de 10 es %d",factorial_recursivo(10));
    printf("El factorial de 0 es %d",factorial_recursivo(0));
    printf("El factorial de 1 es %d",factorial_recursivo(1));*/
    return 0;
}

///Ejercicio 2
//H
void descomposicion_numero_inverso(unsigned numero){
    char buffer[10];
    sprintf(buffer,"%d",numero);
    descomposicion_numero_inverso_aux(buffer);
}

void descomposicion_numero_inverso_aux(char* string){
    if(!(*string)) return;

    printf("- %c\n",*string);
    descomposicion_numero_inverso_aux(++string);
}

//G
void descomposicion_numero(unsigned numero){
    char buffer[10];

    sprintf(buffer,"%d",numero);
    descomposicion_numero_aux(buffer);
}

void descomposicion_numero_aux(char* string){
    if(!(*string)) return;
    descomposicion_numero_aux(string + 1);
    printf("- %c\n",*string);
}

//F
void mostrar_string_a_partes_inverso(char* string){
    int largo_actual = strlen(string);
    mostrar_string_a_partes_inverso_aux(string,largo_actual);
}

void mostrar_string_a_partes_inverso_aux(char* string, unsigned largo){
    unsigned i;

    if(!largo) return;

    printf("- ");
    for(i = 0; i < largo; i++){
        printf("%c",*(string + i));
    }
    printf("\n");
    mostrar_string_a_partes_inverso_aux(string,largo - 1);
}

//E
void mostrar_string_a_partes(char* string){
    mostrar_string_a_partes_aux(string,1);
}

void mostrar_string_a_partes_aux(char* string, unsigned iteracion){
    int i;
    int largo_actual = strlen(string);

    if(iteracion > largo_actual) return;

    printf("- ");
    for(i = 0 ;i < iteracion;i++){
        printf("%c",*(string + i));
    }
    printf("\n");

    mostrar_string_a_partes_aux(string,iteracion + 1);
}

//D
void mostrar_array_parcial_recursivo_inverso(char* string){
    if(!(*string)) return;
    mostrar_array_parcial_recursivo_inverso(string + 1);
    printf("- %s\n",string);
}

//C
void mostrar_array_parcial_recursivo(char* string){
    if(!(*string)) return;
    printf("- %s\n",string);
    mostrar_array_parcial_recursivo(string + 1);
}

//B
void mostrar_array_recursivo_inverso(char* string){
    if(!(*string)) return;
    mostrar_array_recursivo_inverso(string + 1);
    printf("%c",*string);
}

//A
void mostrar_array_recursivo(char* string){
    if(!(*string)) return;

    printf("%c",*string);
    mostrar_array_recursivo(++string);
}

///Ejercicio 1
unsigned factorial_recursivo(unsigned numero){
    //Caso base
    if(numero == 1 || numero == 0){
        return 1;
    }

    return numero * factorial_recursivo(numero - 1);
}
