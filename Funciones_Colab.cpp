#include<iostream>
#include"colaborador.h"

using namespace std;

// La maxima cantidad de colaboradores 
const int maximo = 50;

// Contador que inicia en 0
int cant_colaboradores = 0;

// Arreglo de colaboradores
datosColab colaborador[maximo];

//arreglo de venta por cada colaborador
ventasColab venta[maximo][1000];
//variable que registra la cantidad de ventas del colaborador designado
int cant_ventas[maximo]={0};

void preAgregarColaborador(){
	
    colaborador[0] ={"Josue Fernando Mamani Lima", 18, "930106478", 0};
    colaborador[1] ={"Juan Carlos Ramirez Torres", 23, "949659123", 1};
    colaborador[2] ={"Andres Felipe Gutierrez Navarro", 19, "956438548", 2};
    colaborador[3] ={"Diego Armando Castillo Perez", 20, "960435234", 3};
    colaborador[4] ={"Sebastian Nicolas Paredes Leon", 18, "954650786", 4};
    //contador aumenta a 5
    cant_colaboradores = 5;

}
// ----------- FUNCION PARA LISTAR COLABORADORES -----------
void listarColaboradores() {
    if (cant_colaboradores > 0) {
        cout << "Cantidad de colaboradores: " << cant_colaboradores << endl << endl;

        for (int i = 0; i < cant_colaboradores; i++) {
            cout << "Colaborador " << i + 1 << endl;
            cout << "Nombres: " << colaborador[i].nombres << endl;
            cout << "Edad: " << colaborador[i].edad << endl;
            cout << "Codigo: " << colaborador[i].codigo << endl;
            cout << "Telefono: " << colaborador[i].telefono << endl;
            cout << endl;
        }
    } else {
        cout << "No hay colaboradores registrados." << endl;
    }
}

// ----------- FUNCIONN PARA MODIFICAR COLABORADOR -----------
void modificarColaborador() {
    if (cant_colaboradores == 0) {
        cout << "No hay colaboradores registrados." << endl;
        return;
    }
    int codigoBuscado;
    cout << "Ingrese el codigo del colaborador que desea modificar: ";
    cin>> codigoBuscado;
    cin.ignore();
    for (int i = 0; i < cant_colaboradores; i++) {
        if (colaborador[i].codigo == codigoBuscado) {
            cout << "\nColaborador encontrado:" << endl;
            cout << "Nombre actual: " << colaborador[i].nombres << endl;
            cout << "Edad actual: " << colaborador[i].edad << endl;
            cout << "Telefono actual: " << colaborador[i].telefono << endl;
            string nuevoNombre, nuevoTelefono;
            int nuevaEdad;
            cout << "\nNuevo nombre (dejar vacio para mantener): ";
            getline(cin, nuevoNombre);
            if (!nuevoNombre.empty()) {
                colaborador[i].nombres = nuevoNombre;
            }
            cout << "Nuevo telefono (dejar vacio para mantener): ";
            getline(cin, nuevoTelefono);
            if (!nuevoTelefono.empty()) {
                colaborador[i].telefono = nuevoTelefono;
            }
            cout << "Nueva edad (poner -1 para mantener): ";
            cin >> nuevaEdad;
            if (nuevaEdad != -1) {
                colaborador[i].edad = nuevaEdad;
            }

            cout << "\n Colaborador modificado exitosamente." << endl;
            return;
        }
    }
    cout << "\n No se encontro un colaborador con ese codigo." << endl;
}

// ----------- FUNCION PARA ELIMINAR COLABORADOR -----------
void eliminarColaborador() {
//mostramos el codigo y nombre de los colaboradores
cout<<"lista de colaboradores \n";
for(int i=0; i<cant_colaboradores; i++){
	cout<<"codigo: "<<colaborador[i].codigo<<endl;
	cout<<"nombre: "<<colaborador[i].nombres<<endl;
	cout<<endl;
}
cout<<endl;

int cod;
//condicion para no hacer nada si hay 0 colaboradores
if(cant_colaboradores>0){
	
	cout<<"ingrese el codigo de la persona "<<endl;
	cin>>cod;
	
	cout<<"eliminaste al colaborador "<<colaborador[cod].nombres<<endl;
	if(cod>=0 and cod<cant_colaboradores){
		
		//bucle para correr los datos del arreglo
		for(int j=cod; j<cant_colaboradores-1; j++){
			colaborador[j] =colaborador[j+1];
		}
		
		cant_colaboradores--;
	}
	
	
}else{
	cout<<"no hay colaboradores "<<endl;
}

}

// ----------- FUNCION PARA AGREGAR COLABORADOR -----------


void agregarColaborador() {
    if (cant_colaboradores >= maximo) {
        cout << "No se pueden agregar más colaboradores (límite alcanzado)." << endl;
        return;
    }

    datosColab nuevo;

    cin.ignore();
    cout << "Ingrese nombres: ";
    getline(cin, nuevo.nombres);

    cout << "Ingrese edad: ";
    cin >> nuevo.edad;
    cin.ignore();

    cout << "Ingrese telefono: ";
    getline(cin, nuevo.telefono);

    cout << "Ingrese codigo: ";
    cin>> nuevo.codigo;
    cin.ignore();
    colaborador[cant_colaboradores] = nuevo;
    cant_colaboradores++;

    cout << " Colaborador agregado correctamente.\n";
}



void agregarVenta(){
	
		int codi;
        	cout<<"ingrese su codigo de colaborador: "<<endl;
        	cin>>codi;
        	cin.ignore();
        	int pos = buscarColaboradorPorCodigo(codi);
        	if(pos != -1){
        		int can=cant_ventas[pos];
        		
        		cout<<"colaborador "<<colaborador[pos].nombres <<" registrado"<<endl;
        		cout<<"ingrese el nombre del producto: ";
        		getline(cin, venta[pos][can].producto);
        		cout<<"ingrese el precio del producto: ";
        		cin>>venta[pos][can].precio;
        		cin.ignore();
        		cout<<"ingrese la cantidad de cantidad de ventas: ";
        		cin>>venta[pos][can].cantidad;
        		cin.ignore();
        		cout<<"ingrese el ID de venta: ";
        		cin>>venta[pos][can].IDventa;
        		cout<<endl;
        		
        		cant_ventas[pos]++; //incrementa el contador de ventas de forma individual
				}else{
					cout<<"colaborador no encontrado "<<endl;
				}
			
}

int buscarColaboradorPorCodigo(int codigo) {
    for (int i = 0; i < cant_colaboradores; i++) {
        if (colaborador[i].codigo == codigo) {
            return i;
        }
    }
    return -1; // no encontrado
}





//menu 3
//en esta funcion lo que se quiere es que se sume todos las ventas realizada osea la cantidad * el precio y sumarlo pero eso de acuerdo al colaborador asignado
void rendimientoColaborador(){
	int codig;
	
	cout<<"ingrese el codigo del colaborador "<<endl;
	cin>>codig;
	cin.ignore();
	
	int per= buscarColaboradorPorCodigo(codig); 
	
	if(per != -1){
		int total=0;
		int rendimiento=0;
		int aux;
		
		cout<<"el rendimiento del colaborador: "<<colaborador[per].nombres<<" es: "<<endl;
		
		for(int i=0; i<cant_ventas[per]; i++){
			aux=venta[per][i].cantidad*venta[per][i].precio;
			total=total+ aux;
		}
		
		rendimiento = total / 1000;
        int sobrante = total % 1000;
	 
		cout<<rendimiento<<endl;
		cout<<"aumulacion de ventas: "<<sobrante<<" soles"<<endl;
		
	}else{
		cout<<"colaborador no encontrado!"<<endl;	
	}
	
}

void rankingDeRendimiento() {
    cout << "Funci�n rankingDeRendimiento en desarrollo...\n";
    //Para colaboradores seg�n ventas totales y mostrar el ranking
}

void empleadoDelMes() {
    cout << "Funci�n empleadoDelMes en desarrollo...\n";
    // Para determinar al colaborador con mejor rendimiento
}

void productoMasVendidoPorColaborador() {
    cout << "Funci�n productoMasVendidoPorColaborador en desarrollo...\n";
    //Para mostrar el producto con mayor cantidad vendida por colaborador
}

