#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED
#include<stdio.h>
#include<indice.h>
#include<tipos.h>


void restaurarPrueba_res(char * path_arch_alu, char* path_arch_ind);

int alta_res (tAlumno * alu, FILE * arch, t_indice* pa);
int alta (tAlumno * alu, FILE * arch, t_indice* pa);

int baja_res (tAlumno * alu, FILE * arch, t_indice* pa);
int baja (tAlumno * alu, FILE * arch, t_indice* pa);

int bajaUltimo_res (FILE * arch, t_indice* pa);
int baja_ultimo (FILE * arch, t_indice* pa);

int agregarMateria_res(FILE * arch, t_indice * pindice);
int agregar_materia(FILE * arch, t_indice * pindice);

int compactarYReindexar_res(FILE ** arch, t_indice * pindice, const char * path);
int compactar_y_reindexar(FILE ** arch, t_indice * pindice, const char * path);

void mostrar_indice_res(t_indice * pindice);
void mostrar_indice(t_indice * pindice);

void ingresarAlumno_res(tAlumno* alu);
void ingresar_alumno(tAlumno* alu);
void ingresarDniAlumno_res(tAlumno* alu);
void ingresar_dni_alumno(tAlumno* alu);
void ingresarNuevaMateria_res(tAlumno* alu);
void ingresar_nueva_materia(tAlumno* alu);
void imprimirAlumno_res(const tAlumno* alu);
void imprimir_alumno(const tAlumno* alu);
void mostrarDni_res(const void* vr);
void mostrar_dni(const tRegInd* r);
void imprimirArchivo_res(FILE * arch);
void imprimir_archivo(FILE * arch);

void imprimirArchivoOrdenado_res(FILE * arch, t_indice* pa);
void imprimir_archivo_ordenado(FILE * arch, t_indice* pa);

int cmpDniAlumno_res(const void * vr1,const void  * vr2);


#endif // UTILITARIAS_H_INCLUDED
