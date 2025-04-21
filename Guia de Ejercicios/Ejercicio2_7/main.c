#include <stdio.h>
#include <stdlib.h>
#include "sumador.h"

int main()
{
    const char *num_D32 = "90225219532773470427622490762827";
    const char *num_D30 = "979870574768300536410483290592";
    const char *num_D30B = "225219532773470427622490762827";
    const char *small_1 = "43215";
    const char *small_2 = "9319";
    char resultado[CAPACIDAD_MAXIMA];
    sumarDigitosLargos(resultado,num_D30,num_D30B);
    //sumarDigitosLargos(resultado,small_1,small_2);
    printf("%s",resultado);
    return 0;
}
