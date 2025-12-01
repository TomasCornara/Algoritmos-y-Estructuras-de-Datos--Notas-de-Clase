#ifndef LISTA_SIMPLE_H_INCLUDED
#define LISTA_SIMPLE_H_INCLUDED

typedef struct nodo{
    void* dato;
    unsigned tam;
    struct nodo* siguiente;
}tNodo;

typedef tNodo* tLista;
typedef int (*accion)(const void*,const void*);

void crearLista(tLista* lista);
int ponerAlComienzo(tLista* lista, const void* dato, unsigned tam);
int verPrimero(const tLista* lista, void* dato, unsigned tam);
int sacarPrimero(tLista* lista, void* dato, unsigned tam);
int listaLlena(const tLista* lista, unsigned tam);
int sacarUltimoLista(tLista* lista, void* dato, unsigned tam);
int eliminar(tLista* lista, const void* clave, accion cmp);
int cmp_int(const void* elemA,const void* elemB);
int verUltimoLista(const tLista* lista, void* dato, unsigned cantBytes);
int insertarOrdenado(tLista* lista, const void* dato, unsigned cantBytes, accion cmp);
void vaciarLista(tLista* lista);
int ponerAlFinal(tLista* lista, const void* dato, unsigned tam);
void mostrarLista(const tLista* lista);
int eliminarPrimera(tLista* lista, const void* key, accion cmp);
int eliminarTodas(tLista* lista, const void* key, accion cmp);
int eliminarPosicion(tLista* lista, unsigned pos);
int insertanEnPosicion(tLista* lista, unsigned pos, const void* dato, unsigned cantBytes);
void eliminarRepetidos(tLista* lista,accion cmp);

#endif // LISTA_SIMPLE_H_INCLUDED
