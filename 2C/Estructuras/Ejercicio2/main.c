#include <stdio.h>
#include <stdlib.h>

int calcular(int operando1, int operando2,int(*calcular)(int,int));

int sumar(int operando1, int operando2);
int multiplicar(int operando1, int operando2);
int dividir(int operando1, int operando2);
int restar(int operando1, int operando2);

int main()
{
    printf("%d",calcular(1,0,dividir));
    return 0;
}

int calcular(int operando1, int operando2,int(*calcular)(int,int)){
    return calcular(operando1,operando2);
}

int sumar(int operando1, int operando2){
    return operando1 + operando2;
}

int multiplicar(int operando1, int operando2){
    return operando1 * operando2;
}

int dividir(int operando1, int operando2){
    if(operando2 == 0){
        errno = EDOM;
        return INT_MAX;
    }

    return operando1/operando2;
}

int restar(int operando1, int operando2){
    return operando1 - operando2;
}
