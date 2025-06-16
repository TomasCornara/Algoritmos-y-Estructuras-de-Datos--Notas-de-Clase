#include <stdio.h>
#include "emuladorDados.h"

//Esta funcion crea el archivo inicial de "participantes.dat"
int crearEstadoInicial(void){
    FILE* arch;
    unsigned cantRegistros;
    jugador registros[] = {
        {1,"El Santi"},
        {2,"Juancho"},
        {3,"Marquitos"},
        {4,"El mati"}
    };

    //Abre el archivo donde voy a escribir
    arch = fopen("participantes.dat","wb");
    if(!arch) return 0;

    //Calculo la cantidad de registros
    cantRegistros = sizeof(registros)/sizeof(registros[0]);

    //Escribe la cantidad de jugadores
    fwrite(&cantRegistros,sizeof(unsigned),1,arch);

    //Escribe los jugadores
    fwrite(registros,sizeof(registros),1,arch);

    //Cierro el archivo
    fclose(arch);

    return 1;
}
