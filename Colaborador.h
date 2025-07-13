#ifndef COLABORADOR_H
#define COLABORADOR_H

#include<string>
using namespace std;
//estructura datos del colaborador
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
//funciones del menu 3
void listarColaboradores();
void modificarColaborador();
void eliminarColaborador();
void agregarColaborador();

//estructura datos de venta
struct ventasColab{
	string producto;
	int cantidad;
	float precio;
	int IDventa;
};

//arreglo para registrar venta por colaborador
extern ventasColab venta[][1000];
extern int cant_ventas[];

int buscarColaboradorPorCodigo(int codi);

//funciones del menu 2
void agregarVenta();
void listarVentas();
void eliminarventa();
void modificarVenta();

//funciones del menu 3
void rendimientoColaborador();
void productoMasCaroRegistrado();
void empleadoDelMes();
void productoMasVendidoPorColaborador();
#endif

