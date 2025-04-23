#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define CAPACIDAD_PILA 340

typedef struct t_pila{
    char pila[CAPACIDAD_PILA];
    unsigned int tope;
} t_pila;

void crear_pila(t_pila* pila); //Crear es una funcion que no puede fallar. No retornada naa. Recibe un puntero // Asigna el tam a la estructura
int apilar(t_pila* pila, const void* dato, unsigned tam); //Const es obligatorio en este caso
int desapilar(t_pila* pila, void* dato, unsigned tam); // (AVERIGUAR) Hay un detalle que no entendi sobre el este tam
/*
Comportamiento de desapilar

1 - Si pila esta vacia -> salir
2- Copiar tam pila en una var inicial: memcpy->sizeof(td)
3- Avanza el tope sizeof
4- Copio dato con memcpy al main(?) el minimo entre la cantidad de bytes de tam_parametro y tam_pila
5- Avanzar tope tampila
6- Retornar "ok"

*/
void vaciar_pila(t_pila* pila); //Vaciar pila es una funcion que no falla, asi que debe ser void
int ver_tope(const t_pila* pila, void* dato, unsigned tam);
int pila_llena(const t_pila* pila, unsigned tam);
int pila_vacia(const t_pila* pila);

#endif // PILA_H_INCLUDED
