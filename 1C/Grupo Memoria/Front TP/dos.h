#ifndef DOS_H_INCLUDED
#define DOS_H_INCLUDED
#include "pila_dinamica/pila_dinamica.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"


//CONFIGURACION DEL JUEGO
#define WIDTH 1280
#define HEIGHT 720

#define MAX_NOMBRE 31
#define MAX_CARTAS_EN_MANO 3
#define MAX_MASO 40
#define PUNTAJE_GANADOR 12

#define MAX_MAS_UNO 6
#define MAX_MAS_DOS 10
#define MAX_MENOS_UNO 8
#define MAX_MENOS_DOS 6
#define MAX_REPETIR_TURNO 6
#define MAX_ESPEJO 4


// CARTAS
#define CANTIDAD_CARTAS 6

#define MAS_UNO 1
#define MAS_DOS 2
#define MENOS_UNO -1
#define MENOS_DOS -2
#define REPETIR_TURNO 20
#define ESPEJO 50

//NIVELES DE DIFICULTAD
#define FACIL 1
#define MEDIO 2
#define DIFICIL 3

//ESTADOS DE ERROR Y EXITO
#define EXITO 2
#define ERROR_REPATIR -1


//ESTRUCTURA PARA LAS CARTAS
typedef struct{
    char descripcion[MAX_NOMBRE];
    char tipo;
}tCarta;

//typedef tPila tMaso;

//JUGADORES
typedef struct {
    tCarta cartas[MAX_CARTAS_EN_MANO];
    unsigned char cantidadCartas;
}tManoJugador;

typedef struct{
    char nombre[MAX_NOMBRE];
    short int cantidadPuntos;
    tManoJugador mano;
}tJugador;

//Jugadas
typedef struct {
    tJugador* jugador;
    tCarta jugada;
    unsigned short int turno;
}jugada;


//PROTOTIPOS JUEGO
tPila* crearMaso(tPila* maso);
void intercambio(tCarta* elem1, tCarta* elem2);
void crearJugador(tJugador* jugador);
void crearAI(tJugador* jugador);
tPila* barajarMaso(tPila* maso);
int repatirCartas(tPila* maso, tJugador* jugador1, tJugador* jugador2);

//PROTOTIPOS TABLERO
void dibujarCarta(SDL_Renderer* renderer, SDL_Texture* textura, char pos);
void dibujarMazo(SDL_Renderer* renderer, SDL_Texture* textura);
void dibujarDescarte(SDL_Renderer* renderer, SDL_Texture* textura);
void dibujarDatosJugador(tJugador* jugador, SDL_Renderer* renderer, TTF_Font* font);
void dibujarTexto(SDL_Renderer* renderer, TTF_Font* font, const char* texto, int x, int y, SDL_Color color);
void dibujarDatosMaquina(tJugador* jugador, SDL_Renderer* renderer, TTF_Font* font);

//PROTOTIPOS CONSOLA
void mostrarMenuDificultad(char* opcion);
void printBienvenida();
void printMenuPrincipal(char* opcion);
void pedirOpcion(char* opcion);
void mostrarCreditos();
void mostrarRanking();
void pedirDificultad(char* opcion);
void mostrarMenuNombre(char* nombre);

#endif // DOS_H_INCLUDED
