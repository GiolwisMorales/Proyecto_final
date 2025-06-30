#ifndef COLABORADOR_H
#define COLABORADOR_H

#include<string>
using namespace std;
//datos del colaborador
struct datosColab{
    string nombres;
    int edad;
    string telefono;
    string codigo;
};

extern const int maximo;
//arreglo 
extern datosColab colaborador[];
//la cantidad de personas que hay en la empresa
extern int  cant_colaboradores;

//agregamos la funciones a utilizar
void listarColaboradores();
void modificarColaborador();
void eliminarColaborador();


#endif

