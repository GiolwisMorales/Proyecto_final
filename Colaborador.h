#ifndef COLABORADOR_H
#define COLABORADOR_H

#include<string>
using namespace std;
//variables para los nombres de venta 
extern string nameproduct[];
extern int cant_product;
extern int ultimoCodigoAsignado;

//estructura datos del colaborador
struct datosColab{
    string nombres;
    int edad;
    string telefono;
    int codigo;
    string sexo;
    string dni;
    float sueldo;
    string sede;
    string turno;
};

extern const int maximo;
//arreglo 
extern datosColab colaborador[];
//la cantidad de personas que hay en la empresa
extern int  cant_colaboradores;


void preAgregarColaborador();
//funciones del menu 1
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
extern int idven;
extern ventasColab venta[][1000];
extern int cant_ventas[];

int buscarColaboradorPorCodigo(int codi);
int generarIDVentaPorColaborador(int posColab);
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

//funciones para el menu 4
void preRecargarNameProduct();
void agregarNameProduct();
void eliminarNameProduct();
void mostrarProductos();
 
#endif
