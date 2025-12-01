#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "listaDinamica.h"
#include "listaVideojuegos.h"


int main()
{
    srand(time(NULL));

    tTop mi_top;

    crearTop(&mi_top);

    for(int i = 0; i < 50; i++){
        tRegistro nuevo_registro;
        randomizarRegistro(&nuevo_registro);
        ponerEnTop(&mi_top,&nuevo_registro);
    }

    mostrarTop(&mi_top);


    return 0;
}
