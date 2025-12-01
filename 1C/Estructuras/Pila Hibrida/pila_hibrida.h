#ifndef PILA_HIBRIDA_INCLUDED
#define PILA_HIBRIDA_INCLUDED

#define CAPACIDAD_PILA 7

typedef struct t_pila{
    void* pila[CAPACIDAD_PILA];
    unsigned int tope;
} t_pila;

void crear_pila(t_pila* pila);
int apilar(t_pila* pila, const void* dato, unsigned tam);
int desapilar(t_pila* pila, void* dato, unsigned tam);
void vaciar_pila(t_pila* pila);
int ver_tope(const t_pila* pila, void* dato, unsigned tam);
int pila_llena(const t_pila* pila);
int pila_vacia(const t_pila* pila);

#endif // PILA_HIBRIDA_INCLUDED
