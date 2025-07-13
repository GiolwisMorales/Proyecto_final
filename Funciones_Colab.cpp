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

//FUNCIONA PARA AGREGAR DE ANTEMANO CINCO COLABORADORES
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
            cout << "Código: " << colaborador[i].codigo << endl;
            cout << "Teléfono: " << colaborador[i].telefono << endl;
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
    cout << "Ingrese el código del colaborador que desea modificar: ";
    cin>> codigoBuscado;
    cin.ignore();
    for (int i = 0; i < cant_colaboradores; i++) {
        if (colaborador[i].codigo == codigoBuscado) {
            cout << "\nColaborador encontrado:" << endl;
            cout << "Nombre actual: " << colaborador[i].nombres << endl;
            cout << "Edad actual: " << colaborador[i].edad << endl;
            cout << "Teléfono actual: " << colaborador[i].telefono << endl;
            string nuevoNombre, nuevoTelefono;
            int nuevaEdad;
            cout << "\nNuevo nombre (dejar vacío para mantener): ";
            getline(cin, nuevoNombre);
            if (!nuevoNombre.empty()) {
                colaborador[i].nombres = nuevoNombre;
            }
            cout << "Nuevo teléfono (dejar vacío para mantener): ";
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
    cout << "\n No se encontró un colaborador con ese código." << endl;
}


// ----------- FUNCION PARA ELIMINAR COLABORADOR -----------
void eliminarColaborador() {
//mostramos el codigo y nombre de los colaboradores
cout<<"Lista de colaboradores \n";
for(int i=0; i<cant_colaboradores; i++){
	cout<<"Código: "<<colaborador[i].codigo<<endl;
	cout<<"Nombre: "<<colaborador[i].nombres<<endl;
	cout<<endl;
}
cout<<endl;

int cod;
//condicion para no hacer nada si hay 0 colaboradores
if(cant_colaboradores>0){
	
	cout<<"Ingrese el código de la persona "<<endl;
	cin>>cod;
	
	cout<<"Eliminaste al colaborador "<<colaborador[cod].nombres<<endl;
	if(cod>=0 and cod<cant_colaboradores){
		
		//bucle para correr los datos del arreglo
		for(int j=cod; j<cant_colaboradores-1; j++){
			colaborador[j] =colaborador[j+1];
		}
		
		cant_colaboradores--;
	}
	
	
}else{
	cout<<"No hay colaboradores "<<endl;
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

    cout << "Ingrese teléfono: ";
    getline(cin, nuevo.telefono);

    cout << "Ingrese código: ";
    cin>> nuevo.codigo;
    cin.ignore();
    colaborador[cant_colaboradores] = nuevo;
    cant_colaboradores++;

    cout << " Colaborador agregado correctamente.\n";
}


//FUNCION PARA AGREGAR LAS VENTAS DE UN COLABORADOR DESIGNADO
void agregarVenta(){
	
		int codi;
        	cout<<"Ingrese su código de colaborador: "<<endl;
        	cin>>codi;
        	cin.ignore();
        	int pos = buscarColaboradorPorCodigo(codi);
        	if(pos != -1){
        		int can=cant_ventas[pos];
        		
        		cout<<"Colaborador "<<colaborador[pos].nombres <<" registrado"<<endl;
        		cout<<"Ingrese el nombre del producto: ";
        		getline(cin, venta[pos][can].producto);
        		cout<<"Ingrese el precio del producto: ";
        		cin>>venta[pos][can].precio;
        		cin.ignore();
        		cout<<"Ingrese la cantidad de ventas: ";
        		cin>>venta[pos][can].cantidad;
        		cin.ignore();
        		cout<<"Ingrese el ID de venta: ";
        		cin>>venta[pos][can].IDventa;
        		cout<<"La venta se registró correctamente."<<endl;
        		
        		cant_ventas[pos]++; //incrementa el contador de ventas de forma individual
				}else{
					cout<<"Colaborador no encontrado "<<endl;
				}
			
}


//FUNCION PARA BUSCAR A UN COLABORADOR POR EL CODIGO(IMPORTANTE PARA EL MENU 2 Y 3)
int buscarColaboradorPorCodigo(int codigo) {
    for (int i = 0; i < cant_colaboradores; i++) {
        if (colaborador[i].codigo == codigo) {
            return i;
        }
    }
    return -1; // no encontrado
}


//FUNCION PARA LISTAR LAS VENTAS DE UN COLABORADOR DESIGNADO
void listarVentas() {
	cout << "\n--- LISTADO DE VENTAS POR COLABORADOR ---\n";
	int codigo;
	cout << "Ingrese el código del colaborador: ";
	cin >> codigo;
	int pos = buscarColaboradorPorCodigo(codigo);
	if (pos == -1) {
		cout << "No se encontró ningún colaborador con ese código.\n";
		return;
	}
	if (cant_ventas[pos] == 0) {
		cout << "\nColaborador: " << colaborador[pos].nombres
		<< " (Código: " << colaborador[pos].codigo << ")\n";
		cout << "No tiene ventas registradas.\n";
		return;
	}
	cout << "\nColaborador: " << colaborador[pos].nombres
		<< " (Código: " << colaborador[pos].codigo << ")\n";
	for (int j = 0; j < cant_ventas[pos]; j++) {
		cout << "  ID Venta: "     << venta[pos][j].IDventa << endl;
		cout << "  Producto: "     << venta[pos][j].producto << endl;
		cout << "  Precio: S/ "    << venta[pos][j].precio << endl;
		cout << "  Cantidad: "     << venta[pos][j].cantidad << endl;
		cout << "---------------------------\n";
	}
}


//FUNCION PARA ELIMINAR LA VENTA DE UN COLABORADOR DESIGNADO
void eliminarventa(){
	
	int codigo;
	cout<<"ingrese el codigo del colaborador: ";
	cin>>codigo;
	
	int p = buscarColaboradorPorCodigo(codigo);
	
	if(p==-1){
		cout<<"colaborador no encotrado "<<endl;
		return;
	}
	
	if(cant_ventas[p]==0){
		cout<<"no hay ventas registradas por el colaborador "<<endl;
		return;
	}
	
	cout<<"ventas realizadas por el colaborador "<<colaborador[p].nombres<<" :"<<endl;
	 for (int i = 0; i < cant_ventas[p]; ++i) {
        cout << "ID de venta: "    << venta[p][i].IDventa
             << " | Producto: "    << venta[p][i].producto
             << " | Precio: S/ "   << venta[p][i].precio
             << " | Cantidad: "    << venta[p][i].cantidad << "\n";
    }
     
     int idv;
     cout<<"ingrese el IDventa del producto a eliminar: ";
     cin>> idv;
     
     
    int idx = -1;
    for (int i = 0; i < cant_ventas[p]; ++i) {
        if (venta[p][i].IDventa == idv) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "No se encontró una venta con ese ID.\n";
        return;
    }

    // Desplazar ventas y decrementar contador
    for (int j = idx; j < cant_ventas[p] - 1; ++j) {
        venta[p][j] = venta[p][j + 1];
    }
    cant_ventas[p]--;
    cout << "Venta con ID " << idv << " eliminada correctamente.\n";
}


//FUNCION PARA MODIFICAR LOS DATOS DE VENTA DE UN COLABORADOR
void modificarVenta() {
	int codigo;
	cout << "\nIngrese el código del colaborador: ";
	cin >> codigo;
	int p = buscarColaboradorPorCodigo(codigo);
	if (p == -1) {
		cout << "Colaborador no encontrado.\n";
		return;
	}
	if (cant_ventas[p] == 0) {
		cout << "No hay ventas registradas para el colaborador "
			<< colaborador[p].nombres << ".\n";
		return;
	}

	cout << "Ventas registradas por " << colaborador[p].nombres << ":\n";
	for (int i = 0; i < cant_ventas[p]; ++i) {
		cout << "ID Venta: " << venta[p][i].IDventa
			<< " | Producto: " << venta[p][i].producto
			<< " | Precio: S/ " << venta[p][i].precio
			<< " | Cantidad: " << venta[p][i].cantidad << "\n";
    }
	int idv;
	cout << "\nIngrese el ID de la venta que desea modificar: ";
    cin >> idv;
	int idx = -1;
	for (int i = 0; i < cant_ventas[p]; ++i) {
		if (venta[p][i].IDventa == idv) {
			idx = i;
			break;
		}
	}

	if (idx == -1) {
		cout << "No se encontró una venta con ese ID.\n";
		return;
	}
	cout << "\nIngrese los nuevos datos para la venta:\n";
	cout << "Nuevo nombre de producto: ";
	cin.ignore();
	getline(cin, venta[p][idx].producto);
	cout << "Nuevo precio: ";
	cin >> venta[p][idx].precio;
	cout << "Nueva cantidad: ";
	cin >> venta[p][idx].cantidad;

	cout << "Venta modificada exitosamente.\n";
}



//menu 3
//en esta funcion lo que se quiere es que se sume todos las ventas realizada osea la cantidad * el precio y sumarlo pero eso de acuerdo al colaborador asignado
void rendimientoColaborador(){
	int codig;
	
	cout<<"Ingrese el código del colaborador "<<endl;
	cin>>codig;
	cin.ignore();
	
	int per= buscarColaboradorPorCodigo(codig); 
	
	if(per != -1){
		int total=0;
		int rendimiento=0;
		int aux;
		
		cout<<"El rendimiento del colaborador: "<<colaborador[per].nombres<<" es: "<<endl;
		
		for(int i=0; i<cant_ventas[per]; i++){
			aux=venta[per][i].cantidad*venta[per][i].precio;
			total=total+ aux;
		}
		
		rendimiento = total / 1000;
        int sobrante = total % 1000;
	 
		cout<<rendimiento<<endl;
		cout<<"Acumulacion de ventas: "<<sobrante<<" soles"<<endl;
		
	}else{
		cout<<"Colaborador no encontrado!"<<endl;	
	}
	
}


//FUNCION PARA MOSTRAR EL PRODUCTO MAS CARO REGISTRADO POR EL PROGRAMA
 void productoMasCaroRegistrado() {
    if (cant_colaboradores == 0) {
        cout << "No hay colaboradores registrados.\n";
        return;
    }

    bool encontrado = false;
    float precioMax = 0.0;
    int colMax = -1, ventaMax = -1;

    // Recorre todos los colaboradores y sus ventas
    for (int i = 0; i < cant_colaboradores; i++) {
        for (int j = 0; j < cant_ventas[i]; j++) {
            float precioActual = venta[i][j].precio;
            
            if (!encontrado or precioActual > precioMax) {
            	
                encontrado = true;
                precioMax = precioActual;
                colMax = i;
                ventaMax = j;
            }
        }
    }

    if (encontrado) {
        ventasColab&v = venta[colMax][ventaMax];
        cout << "Producto más caro registrado:\n";
        cout << "Colaborador: " << colaborador[colMax].nombres << "\n";
        cout << "Producto: "     << v.producto << "\n";
        cout << "Precio: S/ "    << precioMax << "\n";
        cout << "Cantidad vendida: " << v.cantidad << "\n";
        cout << "ID de venta: "  << v.IDventa << "\n";
    } else {
        cout << "Aún no se ha registrado ninguna venta.\n";
    }
}


//FUNCION PARA MOSTRAR AL EMPLEADO CON MAYOR RENDIMIENTO EN TODO EL PROGRAMA
void empleadoDelMes() {
    if (cant_colaboradores == 0) {
        cout << "No hay colaboradores registrados.\n";
        return;
    }

    int mejorColab = -1;
    float mayorMonto = 0;

    for (int i = 0; i < cant_colaboradores; ++i) {
        float total = 0;
        for (int j = 0; j < cant_ventas[i]; ++j) {
            total += venta[i][j].precio * venta[i][j].cantidad;
        }

        if (total > mayorMonto || mejorColab == -1) {
            mejorColab = i;
            mayorMonto = total;
        }
    }

    if (mejorColab != -1) {
        cout << "Empleado del mes \n";
        cout << "Nombre: " << colaborador[mejorColab].nombres << "\n";
        cout << "Código: " << colaborador[mejorColab].codigo << "\n";
        cout << "Total vendido: S/ " << mayorMonto << "\n";
    } else {
        cout << "No hay ventas registradas a�n.\n";
    }
}


//FUNCION PARA MOSTRAR EL PRODUCTO MAS CARO VENDIDO POR UN COLABORADOR DESIGNADO
void productoMasVendidoPorColaborador() {
    if (cant_colaboradores == 0) {
        cout << "No hay colaboradores registrados.\n";
        return;
    }

    int codigo;
    cout << "Ingrese el código del colaborador: ";
    cin >> codigo;

    int pos = buscarColaboradorPorCodigo(codigo);
    if (pos == -1) {
        cout << "Colaborador no encontrado.\n";
        return;
    }

    if (cant_ventas[pos] == 0) {
        cout << "Este colaborador no tiene ventas registradas.\n";
        return;
    }

    int mayorIdx = 0;
    for (int i = 1; i < cant_ventas[pos]; ++i) {
        if (venta[pos][i].cantidad > venta[pos][mayorIdx].cantidad) {
            mayorIdx = i;
        }
    }
    
    cout << "Producto más vendido por " << colaborador[pos].nombres << ":\n";
    cout << "Producto: " << venta[pos][mayorIdx].producto << "\n";
    cout << "Cantidad: " << venta[pos][mayorIdx].cantidad << "\n";
    cout << "ID Venta: " << venta[pos][mayorIdx].IDventa << "\n";
}

//FIN DE LAS FUNCIONES
