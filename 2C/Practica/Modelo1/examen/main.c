#include <stdio.h>
#include <stdlib.h>
#include <utilitarias.h>
#include <varias.h>
#include <indice.h>

#define PATH_ARCH_ALUMNOS "../archivos/alumnos.dat"
#define PATH_ARCH_INDICE "../archivos/alumnos.idx"

void imprimirMensaje(int res);
void opAlta(FILE * arch, t_indice * pindice);
void opBaja(FILE * arch, t_indice * pindice);
void opAgregarMateria(FILE * arch, t_indice * pindice);
void opListarIndice(t_indice * pindice);
void opListarAlumnos(FILE * arch);
void opListarAlumnosOrdenado(FILE * arch, t_indice * pindice);
void opEliminarUltimoIngresado(FILE * arch, t_indice * pindice);
void opCompactarYReindexar(FILE ** arch, t_indice * pindice, const char * path);

int main()
{
    FILE * arch;
    const char opciones [][TAM_MENU] = {"ABEILMCS",
                                        "Alta",
                                        "Baja",
                                        "Agregar Materia",
                                        "Listar Indice",
                                        "Listar Alumnos",
                                        "Listar Alumnos Ordenado por DNI",
                                        "Compactar Archivo y Reindexar",
                                        "Salir"};
    char op;
    t_indice indice;

    ///Descomente esta linea para restaurar las pruebas
    restaurarPrueba_res(PATH_ARCH_ALUMNOS, PATH_ARCH_INDICE);

    arch = fopen(PATH_ARCH_ALUMNOS, "r+b");
    if (!arch)
        exit(1);

    ind_crear_res(&indice, sizeof(int), cmpDniAlumno_res);

    if(ind_cargar_res(&indice, PATH_ARCH_INDICE)==IND_ERROR)
        exit(1);
    do{
        op=menu(opciones, "Menu Principal");
        switch (op)
        {
            case 'A':
                opAlta(arch, &indice);
                break;
            case 'B':
                opBaja(arch, &indice);
                break;
            case 'E':
                opAgregarMateria(arch, &indice);
                break;
            case 'I':
                opListarIndice(&indice);
                break;
            case 'L':
                opListarAlumnos(arch);
                break;
            case 'M':
                opListarAlumnosOrdenado(arch, &indice);
                break;
            case 'C':
                opCompactarYReindexar(&arch, &indice, PATH_ARCH_ALUMNOS);
                break;
        }
    }while(op!='S');
    ind_grabar_res(&indice, PATH_ARCH_INDICE);
    ind_vaciar_res(&indice);
    fclose(arch);
    return 0;
}

void opAlta(FILE * arch, t_indice * pindice)
{
    int res;
    tAlumno alu;
    ingresarAlumno_res(&alu);
    res= alta_res(&alu, arch, pindice);
    imprimirMensaje(res);
}

void opBaja(FILE * arch, t_indice * pindice)
{
    int res;
    tAlumno alu;
    ingresarDniAlumno_res(&alu);
    res= baja_res(&alu, arch, pindice);
    imprimirMensaje(res);
}

void opAgregarMateria(FILE * arch, t_indice * pindice)
{
    int res;
    res= agregarMateria_res(arch, pindice);
    imprimirMensaje(res);
}

void opListarIndice(t_indice * pindice)
{
    printf("\n\n");
    mostrar_indice_res(pindice);
    pausa("\n\n");
}

void opListarAlumnos(FILE * arch)
{
    printf("\n\n");
    imprimirArchivo_res(arch);
    pausa("\n\n");
}

void opListarAlumnosOrdenado(FILE * arch, t_indice * pindice)
{
    printf("\n\n");
    imprimirArchivoOrdenado_res(arch, pindice);
    pausa("\n\n");
}

void opCompactarYReindexar(FILE ** arch, t_indice * pindice, const char * path)
{
    int res;
    res= compactarYReindexar_res(arch, pindice, path);
    imprimirMensaje(res);
}

void imprimirMensaje(int res)
{
    switch(res)
    {
        case TODO_OK: pausa("Operacion realizada correctamente.");
                break;
        case SIN_MEM: pausa("Error de memoria.");
                break;
        case ERROR_ARCHIVO: pausa("Error en el archivo.");
                break;
        case DUPLICADO: pausa("Resgistro duplicado.");
                break;
        case NO_EXISTE: pausa("Resgistro inexistente.");
                break;
        default: pausa("Error.");
    }
}
