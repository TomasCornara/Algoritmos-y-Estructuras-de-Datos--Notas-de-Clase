#include "main.h"
//#include "estatica/pila.c"
#include "hibrida/pila.h"
int main()
{
    ///Bloque declarativo
    int unidad;
    tPila pila1, pila2, pila3;
    FILE* arch_op1;
    FILE* arch_op2;
    FILE* arch_result;

    ///Inicializacion
    arch_op1 = fopen("nro1.txt","r");
    if(!arch_op1) return -1;

    arch_op2 = fopen("nro2.txt","r");
    if(!arch_op2) return -1;

    arch_result = fopen("resultado.txt","w");
    if(!arch_result) return -1;

    crearPila(&pila1);
    crearPila(&pila2);
    crearPila(&pila3);

    ///Carga y operaciones
    cargarPila(&pila1, arch_op1);
    cargarPila(&pila2, arch_op2);

    sumarPilas(&pila1, &pila2, &pila3);

    printf("Resultado: ");
    while (!pilaVacia(&pila3))
    {
        desapilar(&pila3, &unidad, sizeof(int));
        mostrarUnidad(&unidad);
        fputc(unidad + '0',arch_result);
    }
    putchar('\n');
    printf("Resultado escrito a \"resultado.txt\"");


    ///Devoluciones
    fclose(arch_op1);
    fclose(arch_op2);
    fclose(arch_result);
    vaciarPila(&pila1);
    vaciarPila(&pila2);
    vaciarPila(&pila3);

    return EXITO;
}
