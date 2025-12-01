#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    tCola cola;
    char relleno[] = "12";      // 3 bytes (2 + '\0')
    char relleno2[] = "4";      // 2 bytes (1 + '\0')
    char texto0[] = "Hola";     // 5 bytes (4 + '\0')
    char texto1[] = "No";       // 3 bytes (2 + '\0')
    char buffer[14];

    crearCola(&cola);

    // Relleno para avanzar el puntero 'ultimo'
    enColar(&cola, relleno, sizeof(relleno));
    enColar(&cola, relleno2, sizeof(relleno2));

    desEnColar(&cola, buffer, sizeof(buffer));
    printf("Desencolado: %s\n", buffer);  // debe ser "12"

    enColar(&cola, texto0, sizeof(texto0));

    desEnColar(&cola, buffer, sizeof(buffer));
    printf("Desencolado: %s\n", buffer);  // debe ser "4"

    enColar(&cola, texto1, sizeof(texto1));

    desEnColar(&cola, buffer, sizeof(buffer));
    printf("Desencolado: %s\n", buffer);  // debe ser "Hola"

    desEnColar(&cola, buffer, sizeof(buffer));
    printf("Desencolado: %s\n", buffer);  // debe ser "No"

    printf("%s\n", colaVacia(&cola) ? "Vacio" : "No Vacio");

    return 0;
}
