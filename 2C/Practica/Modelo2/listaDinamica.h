#ifndef LISTADINAMICA_H_INCLUDED
#define LISTADINAMICA_H_INCLUDED

#define MIN(A,B) (((A)>(B))? (B):(A))

typedef struct sNodo{
    void* dato; //Lo pongo por compatibilidad nomas
    unsigned tam;
    struct sNodo* sig;
} tNodo;

typedef tNodo* tLista;
typedef int (*cmp_gen)(const void*, const void*);
typedef void (*print_func)(const void*);

void crearLista(tLista* lista);
int listaVacia(const tLista* lista);
int listaLlena(const tLista* lista, unsigned cantBytes);
int ponerEnOrden(tLista* lista, const void* dato, unsigned cantBytes, cmp_gen cmp);
void mapLista(const tLista* lista,print_func prt);
void vaciarLista(tLista* lista);
void borrarUltimo(tLista* lista);

#endif // LISTADINAMICA_H_INCLUDED
