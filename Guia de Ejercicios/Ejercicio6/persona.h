#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#define NOMBRE_MAXIMO 30

typedef struct t_persona{
    unsigned legajo;
    char nombre[NOMBRE_MAXIMO];
} t_persona;

void mostrar_persona(const void* elem){
    t_persona* persona = (t_persona*)elem;
    printf("[%d - %s]",persona->legajo,persona->nombre);
};

#endif // PERSONA_H_INCLUDED
