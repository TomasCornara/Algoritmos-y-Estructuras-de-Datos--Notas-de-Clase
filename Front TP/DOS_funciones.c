#include "dos.h"
//#include "pila_dinamica/pila_dinamica.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#define MARGIN_BORDE 10
#define MARGIN_CARTAS 70
#define ALTO_CARTA 186
#define ANCHO_CARTA 124

///FUNCIONES PARA EL MASO
//CREACION DE MASO
tPila* crearMaso(tPila* maso) {
    int i, offset = 0;
    tCarta aux[MAX_MASO];
    char descripciones[CANTIDAD_CARTAS][MAX_NOMBRE] = {
        "MAS UNO",       // índice 0
        "MAS DOS",       // índice 1
        "MENOS UNO",     // índice 2
        "MENOS DOS",     // índice 3
        "REPETIR TURNO", // índice 4
        "ESPEJO"         // índice 5
    };

    ///Crear las cartas
    //Cartas +2
    for (i = 0; i < MAX_MAS_DOS; i++) {
        aux[offset + i].tipo = MAS_DOS;
        strcpy(aux[offset + i].descripcion, descripciones[1]);
    }
    offset += i;

    //Cartas +1
    for (i = 0; i < MAX_MAS_UNO; i++) {
        aux[offset + i].tipo = MAS_UNO;
        strcpy(aux[offset + i].descripcion, descripciones[0]);
    }
    offset += i;

    //Cartas -1
    for (i = 0; i < MAX_MENOS_UNO; i++) {
        aux[offset + i].tipo = MENOS_UNO;
        strcpy(aux[offset + i].descripcion, descripciones[2]);
    }
    offset += i;

    //Cartas -2
    for (i = 0; i < MAX_MENOS_DOS; i++) {
        aux[offset + i].tipo = MENOS_DOS;
        strcpy(aux[offset + i].descripcion, descripciones[3]);
    }
    offset += i;

    //Cartas Repetir Turno
    for (i = 0; i < MAX_REPETIR_TURNO; i++) {
        aux[offset + i].tipo = REPETIR_TURNO;
        strcpy(aux[offset + i].descripcion, descripciones[4]);
    }
    offset += i;

    //Cartas Espejo
    for (i = 0; i < MAX_ESPEJO; i++) {
        aux[offset + i].tipo = ESPEJO;
        strcpy(aux[offset + i].descripcion, descripciones[5]);
    }

    for (i = 0; i < MAX_MASO; i++) {
        if (apilar(maso, &aux[i], sizeof(tCarta)) != EXITO_APILADO) {
            return NULL;
        }
    }

    return maso;
}

// BARAJAR UN MASO DE FORMA RANDOM
tPila* barajarMaso(tPila* maso){
    tCarta aux[MAX_MASO];
    int random;
    int cantidadCartas = 0;
    int i;

    if(maso == NULL){
        return NULL;
    }

    //Inicializaciones
    srand((unsigned)time(NULL)); //Este codigo genera una semilla en base a la hora
                                //Que randomiza los numeros de rand()

    //Descargo la baraja a la memoria
    while (!pilaVacia(maso) && cantidadCartas < MAX_MASO) {
        if (desapilar(maso, &aux[cantidadCartas], sizeof(tCarta)) == EXITO_DESAPILAR) {
            cantidadCartas++;
        } else {
            // Manejar error de desapilar
            return NULL;
        }
    }


    ///Des Ordenar (Barajar)
    for (i = cantidadCartas - 1; i > 0; i--) {
        random = rand() % (i + 1);
        intercambio(&aux[random], &aux[i]);
    }

    for (i = 0; i < cantidadCartas; i++) {
        if (apilar(maso, &aux[i], sizeof(tCarta)) != EXITO_APILADO) {
            return NULL;
        }
    }

    return maso;
}

// REPATIR MANO INICIAL
int repatirCartas(tPila* maso, tJugador* jugador1, tJugador* jugador2){
    int i;

    //Chequeo que haya algo que repatir
    if(pilaVacia(maso)){
        return ERROR_REPATIR;
    }

    ///JUGADORES
    ///NOTA: Dado a que es un juego digital, no tiene sentido alternarse entre jugadores para repattir
    //Carga del jugador 1
    for(i = 0; i < MAX_CARTAS_EN_MANO; i++){
        desapilar(maso, &(jugador1->mano.cartas[i]), sizeof(tCarta));
        jugador1->mano.cantidadCartas++;
    }

    //Carga del jugador 2
    for(i = 0; i < MAX_CARTAS_EN_MANO; i++){
        desapilar(maso, &(jugador2->mano.cartas[i]), sizeof(tCarta));
        jugador2->mano.cantidadCartas++;
    }

    return EXITO;
}


//INTERCAMBIO
void intercambio(tCarta* elem1, tCarta* elem2){
    tCarta temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

///FUNCIONES PARA EL JUGADOR
// Inicializacion jugador
void crearJugador(tJugador* jugador){
    jugador->nombre[MAX_NOMBRE - 1] = '\0';
    jugador->cantidadPuntos = 0;
    jugador->mano.cantidadCartas = 0;
}

// Inicializa a la AI
void crearAI(tJugador* jugador) {
    int random;
    char* nombres[] = { // Nombres posibles de AIs
        "JARVIS",
        "Cortana",
        "TARS",
        "MemoriaGPT",
        "404 NOT FOUND",
        "Ramon",
        "HAL 9001",
        "GLADOS",
        "Wheatley"
    };

    srand((unsigned)time(NULL));
    random = rand() % (sizeof(nombres) / sizeof(nombres[0]));

    crearJugador(jugador);
    strcpy(jugador->nombre, nombres[random]);
}

//Esta funcion altera los puntos de un jugador en funcion de una carta que se recibe
void alterarPuntos(tJugador* jugador, tCarta* carta){
    if(carta->tipo == ESPEJO) return;
    if(carta->tipo == REPETIR_TURNO) return;

    jugador->cantidadPuntos += (short int)carta->tipo;
}

///TABLERO
//NOTA: ESTO ES UN PLACE HOLDER - FALTA IMPLEMENTAR LOGICA PARA ESTE MASO, POSIBLEMENTE NECESITE MAS PARAMETROS
void dibujarMazo(SDL_Renderer* renderer, SDL_Texture* textura){
    SDL_Rect dst = {(WIDTH/2) - (ANCHO_CARTA/2) + MARGIN_CARTAS, HEIGHT/2 - (ALTO_CARTA/2), ANCHO_CARTA, ALTO_CARTA};
    SDL_RenderCopy(renderer, textura, NULL, &dst);
}
//NOTA: ESTO ES UN PLACE HOLDER - FALTA IMPLEMENTAR LOGICA PARA ESTE MASO, POSIBLEMENTE NECESITE MAS PARAMETROS
void dibujarDescarte(SDL_Renderer* renderer, SDL_Texture* textura){
    SDL_Rect dst = {(WIDTH/2) - 2*(ANCHO_CARTA) + MARGIN_CARTAS, HEIGHT/2 - (ALTO_CARTA/2), ANCHO_CARTA, ALTO_CARTA};
    SDL_RenderCopy(renderer, textura, NULL, &dst);
}

//NOTA: Para poner una carta en el centro, la distancia en X es -mas o menos- en 558.
//Que es = (1280 (ancho de la pantalla) / 2) - (165 (ancho de una carta) / 2)
void dibujarCarta(SDL_Renderer* renderer, SDL_Texture* textura, char pos) {
    int x; // <<<--- Distancia desde el borde izquierdo
    int y; // <<<---- Distancia desde el borde superior

    //DECIDE DONDE DIBUJAR EN FUNCION DE LA POSICION
    switch(pos)
    {
        //Parte superior - Jugador 1
        case 0:
            x = ((WIDTH/2) - (ANCHO_CARTA/2)) - ANCHO_CARTA - MARGIN_CARTAS;
            y = MARGIN_BORDE;
            break;
        case 1:
            x = (WIDTH/2) - (ANCHO_CARTA/2);
            y = MARGIN_BORDE;
            break;
        case 2:
            x = ((WIDTH/2) - (ANCHO_CARTA/2)) + ANCHO_CARTA + MARGIN_CARTAS;
            y = MARGIN_BORDE;
            break;

        //Parte inferior - Jugador 2
        case 3:
            x = ((WIDTH/2) - (ANCHO_CARTA/2)) - ANCHO_CARTA - MARGIN_CARTAS;
            y = HEIGHT - ALTO_CARTA - MARGIN_BORDE;
            break;
        case 4:
            x = (WIDTH/2) - (ANCHO_CARTA/2);
            y = HEIGHT - ALTO_CARTA - MARGIN_BORDE;
            break;
        case 5:
            x = ((WIDTH/2) - (ANCHO_CARTA/2)) + ANCHO_CARTA + MARGIN_CARTAS;
            y = HEIGHT - ALTO_CARTA - MARGIN_BORDE;
            break;
    }

    SDL_Rect dst = { x, y, ANCHO_CARTA, ALTO_CARTA};
    SDL_RenderCopy(renderer, textura, NULL, &dst);
}


void dibujarDatosMaquina(tJugador* jugador, SDL_Renderer* renderer, TTF_Font* font){
    SDL_Color color = {255, 255, 255}; //Color blanco
    char puntos[7];

    // Dibuja nombre
    dibujarTexto(renderer, font, jugador->nombre, 280, 70, color);

    //Paso los puntos a texto
    sprintf(puntos,"%hd",jugador->cantidadPuntos);

    // Dibuja puntos debajo del nombre
    dibujarTexto(renderer, font, puntos, 280, 120, color);
}

void dibujarDatosJugador(tJugador* jugador, SDL_Renderer* renderer, TTF_Font* font){
    SDL_Color color = {255, 255, 255}; //Color blanco
    char puntos[7];

    // Dibuja nombre
    dibujarTexto(renderer, font, jugador->nombre, 1000, 600, color);

    //Paso los puntos a texto
    sprintf(puntos,"%hd",jugador->cantidadPuntos);

    // Dibuja puntos debajo del nombre
    dibujarTexto(renderer, font, puntos, 1000, 650, color);
}


void dibujarTexto(SDL_Renderer* renderer, TTF_Font* font, const char* texto, int x, int y, SDL_Color color) {
    //Nota: El proceso de dibujado de SDL es el siguiente
    // Dibuja la font sobre una superficie-> Lo manda a una textura (que es con lo que dibuja SDL)
    // -> Lo "copia"sobre el renderer.
    SDL_Surface* superficie;
    SDL_Texture* textura;
    SDL_Rect destino;


    //Pase a superficie
    superficie = TTF_RenderText_Blended(font, texto, color);

    //Pase a textura
    textura = SDL_CreateTextureFromSurface(renderer, superficie);

    //Creacion destino
    destino.x = x;
    destino.y = y;
    destino.w = superficie->w;
    destino.h = superficie->h;

    //Copia al renderer
    SDL_RenderCopy(renderer, textura, NULL, &destino);

    //Libera
    SDL_FreeSurface(superficie);
    SDL_DestroyTexture(textura);
}


///CONSOLA
void printBienvenida(){
    system("cls");
    printf(
        "##############################################################\n"
        "                                                              \n"
        "                  #####    ####    ####   ##                 \n"
        "                  ##  ##  ##  ##  ##      ##                 \n"
        "                  ##  ##  ##  ##   ####   ##                 \n"
        "                  ##  ##  ##  ##      ##                     \n"
        "                  #####    ####   #####   ##                 \n"
        "                                                              \n"
        "##############################################################\n"
        "\t\tIng. Informatica - UNLAM\n"
        "\t\t\tGRUPO: Memoria\n"
    );
}

void printMenuPrincipal(char* opcion) {
    system("cls");
    printf(
        "##############################################################\n"
        "                                                              \n"
        "                       MENU PRINCIPAL                         \n"
        "                                                              \n"
        "                       [A] JUGAR                              \n"
        "                       [B] VER RANKING                        \n"
        "                       [C] SALIR                              \n"
        "                                                              \n"
        "                       [M] CREDITOS                           \n"
        "                                                              \n"
        "##############################################################\n"
    );
    pedirOpcion(opcion);
}

void pedirOpcion(char* opcion){

    printf("Ingrese opcion: ");

    fflush(stdin);

    scanf("%c", opcion);

    *opcion = toupper(*opcion);
    while (*opcion != 'A' && *opcion != 'B' && *opcion != 'C' && *opcion != 'M') {
        system("cls");
        printf("Opcion invalida! Intente de nuevo.");
        sleep(2); //Espero dos segundos
        printMenuPrincipal(opcion);
        return;
    }
}

void mostrarCreditos(){
    system("cls");
    printf(
        "##############################################################\n"
        "                                                              \n"
        "                         CREDITOS                             \n"
        "                                                              \n"
        "             Ing. Informatica - UNLAM                         \n"
        "             Grupo: Memoria                                   \n"
        "             Integrantes:                                     \n"
        "                       - Ignacio Torrente                     \n"
        "                       - Ian Marquez                          \n"
        "                       - Ramiro Belfiore                      \n"
        "                       - Tomas Cornara                        \n"
        "                                                              \n"
        "             Profesores:                                      \n"
        "                       - Renata Guatelli                      \n"
        "                       - Giselle Gonzales                     \n"
        "   1er Cuatrimestre                                    2025   \n"
        "##############################################################\n"
    );
    sleep(5);
}

void mostrarRanking(){
    system("cls");
    printf(
        "##############################################################\n"
        "                                                              \n"
        "                          RANKING                             \n"
        "                                                              \n"
        "##############################################################\n");

    ///FALTA IMPLEMENTACION
    sleep(2); //Espero dos segundos
}

void mostrarMenuDificultad(char* opcion){
    system("cls");
    printf(
        "##############################################################\n"
        "                                                              \n"
        "                  SELECCIONE LA DIFICULTAD                    \n"
        "                                                              \n"
        "             [1] Facil                                        \n"
        "             [2] Media                                        \n"
        "             [3] Dificil                                      \n"
        "                                                              \n"
        "##############################################################\n"
    );
    pedirDificultad(opcion);
}

void pedirDificultad(char* opcion){
    printf("Ingrese opcion: ");
    scanf(" %c", opcion);
    //*opcion = toupper(*opcion);
    while (*opcion != '1' && *opcion != '2' && *opcion != '3') {
        system("cls");
        printf("Opcion invalida! Intente de nuevo.");
        sleep(2); //Espero dos segundos
        mostrarMenuDificultad(opcion);
    }
}

void mostrarMenuNombre(char* nombre){
    char* saltoDeLinea;

    system("cls");
    printf(
        "##############################################################\n"
        "                                                              \n"
        "                                                              \n"
        "             INGRESE SU NOMBRE DE USUARIO                     \n"
        "                 (maximo 30 caracteres)                       \n"
        "                                                              \n"
        "                                                              \n"
        "                                                              \n"
        "##############################################################\n"
    );
    printf("Ingrese usuario: ");

    fflush(stdin); /// << -- Esto creo que no es ANSI C?
                /// El tema es que sin esto se rompe el fgets, chequear
    fgets(nombre,MAX_NOMBRE,stdin);

    //Elimino el salto de linea si es que lo hubo
    saltoDeLinea = strchr(nombre, '\n');
    if (saltoDeLinea) *saltoDeLinea = '\0';
}
