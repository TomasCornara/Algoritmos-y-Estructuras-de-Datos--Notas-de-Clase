#ifndef LISTA_DINAMICA_H_INCLUDED
#define LISTA_DINAMICA_H_INCLUDED

typedef struct {
    int id;
    char nombre[20];
} tPersona;

typedef struct sNodo {
    void* dato;
    unsigned tam;
    struct sNodo* siguiente;
} tNodo;

typedef tNodo* tLista;

void crearLista(tLista* lista);
int listaVacia(const tLista* lista);
int listaLlena(const tLista* lista, unsigned cantBytes);
void vaciarLista(tLista* lista);
int ponerAlComienzo(tLista* lista, const void* dato, unsigned cantBytes);
int sacarPrimeroLista(tLista* lista, void* dato, unsigned cantBytes);
int verPrimeroLista(const tLista* lista, void* dato, unsigned cantBytes);


void map(void* vec, unsigned ce, unsigned tam, void accion(void*));
void mapListas(void* lis);
void printListaRecursivo(const tNodo* nodo, void prnt(const void*));
void printNodo(const void* nodo);

#endif // LISTA_DINAMICA_H_INCLUDED
