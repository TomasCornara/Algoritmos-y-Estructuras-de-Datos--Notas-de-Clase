#ifndef LISTA_DOBLE_H_INCLUDED
#define LISTA_DOBLE_H_INCLUDED

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;
    struct sNodo* ant;
} tNodo;

typedef tNodo* tLista;

void crearLista(tLista* p);
int vaciarLista(tLista* p);
int listaVacia(const tLista* p);
int listaLlena(const tLista* p, unsigned cantBytes);
int insertarAlFinal(tLista* p, const void* dato, unsigned cantBytes);
int insertarAlComienzo(tLista* p, const void* dato, unsigned cantBytes);
int cmpInt(const void* a,const void* b);
int insertarOrdenado(tLista* p, const void* clave, const void* dato, unsigned cantBytes, int (*cmp)(const void*, const void*));


tNodo* encontrarInicio(tLista lista);
void imprimirLista(tLista lista);
void imprimirListaReversa(tLista lista);
void liberarLista(tLista* lista);

#endif // LISTA_DOBLE_H_INCLUDED
