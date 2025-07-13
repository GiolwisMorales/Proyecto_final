#ifndef COLABORADOR_H
#define COLABORADOR_H

#include<string>
using namespace std;
//datos del colaborador
struct datosColab{
    string nombres;
    int edad;
    string telefono;
    int codigo;
};

extern const int maximo;
//arreglo 
extern datosColab colaborador[];
//la cantidad de personas que hay en la empresa
extern int  cant_colaboradores;


void preAgregarColaborador();
//agregamos la funciones a utilizar
void listarColaboradores();
void modificarColaborador();
void eliminarColaborador();
void agregarColaborador();

//datos de venta
struct ventasColab{
	string producto;
	int cantidad;
	float precio;
	int IDventa;
};

extern ventasColab venta[][1000];
extern int cant_ventas[];

int buscarColaboradorPorCodigo(int codi);

void agregarVenta();
void listarVentas();



//menu 3
void rendimientoColaborador();
void productoMasCaroRegistrado();
void empleadoDelMes();
void productoMasVendidoPorColaborador();
#endif

