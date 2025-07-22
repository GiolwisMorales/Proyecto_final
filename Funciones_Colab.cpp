#include<iostream>
#include <iomanip>
#include <algorithm>
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
//variable para designar el idventa de cada colaborador
int contadorIDporColaborador[maximo] = {0};

int ultimoCodigoAsignado = 105;

//FUNCIONA PARA AGREGAR DE ANTEMANO CINCO COLABORADORES
void preAgregarColaborador(){
	
    colaborador[0] ={"Josue Mamani", 28, "930106478", 101, "Masculino", "14224588", 2300.0, "Lima", "Mañana"};
    colaborador[1] ={"Juan Ramirez", 31, "949659123", 102, "Masculino", "87654321", 2100.0, "Arequipa", "Tarde"};
    colaborador[2] ={"Ana Torres", 35, "956438548", 103, "Femenino", "11223344", 2600.0, "Cusco", "Noche"};
    colaborador[3] ={"Carla Mendoza", 27, "960435234", 104, "Femenino", "44332211", 2300.0, "Tacna", "Mañana"};
    colaborador[4] ={"Sebastian Paredes", 32, "954650786", 105, "Masculino", "99887766", 2100.0, "Trujillo", "Tarde"};
    //contador aumenta a 5
    cant_colaboradores = 5;

}


// ----------- FUNCION PARA LISTAR COLABORADORES -----------
void listarColaboradores() {
    cout << "\nCantidad de colaboradores: "<<cant_colaboradores<<"\n\n";

	// Encabezado superior
	cout << "┌────────┬──────────────────────┬──────┬───────────┬──────────┬───────────┬──────────┬────────┬────────────┐\n";
	cout << "│ Código │ Nombres              │ Edad │ Teléfono  │ DNI      │ Sexo      │ Sede     │ Turno  │ Sueldo     │\n";
	cout << "├────────┼──────────────────────┼──────┼───────────┼──────────┼───────────┼──────────┼────────┼────────────┤\n";

	for (int i = 0; i < cant_colaboradores; ++i) {
		cout << "│ " << left << setw(6) << colaborador[i].codigo
			<< " │ " << setw(20) << colaborador[i].nombres
			<< " │ " << setw(4) << colaborador[i].edad
			<< " │ " << setw(9) << colaborador[i].telefono
			<< " │ " << setw(8) << colaborador[i].dni
			<< " │ " << setw(9) << colaborador[i].sexo
			<< " │ " << setw(8) << colaborador[i].sede
			<< " │ " << setw(6) << colaborador[i].turno
			<< " │ S/ " << fixed << setprecision(2) << setw(7) << colaborador[i].sueldo << " │\n";
    }

    // Pie de la tabla
	cout << "└────────┴──────────────────────┴──────┴───────────┴──────────┴───────────┴──────────┴────────┴────────────┘\n";
}


// ----------- FUNCIONN PARA MODIFICAR COLABORADOR -----------
void modificarColaborador() {
    if (cant_colaboradores == 0) {
        cout << "No hay colaboradores registrados." << endl;
        return;
    }
    int codigoBuscado;
    int pos;
    cout << "\nLista de colaboradores:\n";	//mostrar lista antes de modificar
    for (int i = 0; i < cant_colaboradores; i++) {
        cout << "Código: " << colaborador[i].codigo << " - Nombre: " << colaborador[i].nombres << endl;
    }
    
    do {
        cout << "\nIngrese el código del colaborador que desea modificar: ";
        cin >> codigoBuscado;
        cin.ignore();
        pos = buscarColaboradorPorCodigo(codigoBuscado);

        if (pos == -1) {
            cout << " No se encontró un colaborador con ese código. Intente nuevamente.\n";
        }
    } while (pos == -1);
    
    for (int i = 0; i < cant_colaboradores; i++) {
        if (colaborador[i].codigo == codigoBuscado) {
			cout << "\nColaborador encontrado:" << endl;
			cout << "Nombre actual: " << colaborador[i].nombres << endl;
			cout << "Edad actual: " << colaborador[i].edad << endl;
			cout << "Teléfono actual: " << colaborador[i].telefono << endl;
			cout << "Sexo actual: " << colaborador[i].sexo << endl;
			cout << "DNI actual: " << colaborador[i].dni << endl;
			cout << "Sede actual: " << colaborador[i].sede << endl;
			cout << "Turno actual: " << colaborador[i].turno << endl;
			cout << "Sueldo actual: S/ " << colaborador[i].sueldo << endl;
			string input;
			int nuevaEdad;
			float nuevoSueldo;

			cout << "\nNuevo nombre (dejar vacío para mantener): ";
			getline(cin, input);
			if (!input.empty()) colaborador[i].nombres = input;

			do {
				cout << "\nNuevo teléfono (9 dígitos, dejar vacío para mantener): ";
				getline(cin, input);
				if (input.empty()) break;
				if (input.length() == 9 && all_of(input.begin(), input.end(), ::isdigit)) {
					colaborador[i].telefono = input;
					break;
				} else {
					cout << " Teléfono inválido. Debe tener 9 dígitos numéricos.\n";
				}
			} while (true);
			
			cout << "\nNuevo sexo (dejar vacío para mantener): ";
			getline(cin, input);
			if (!input.empty()) colaborador[i].sexo = input;

			do {
				cout << "\nNuevo DNI (8 dígitos, dejar vacío para mantener): ";
				getline(cin, input);
				if (input.empty()) break;
				if (input.length() == 8 && all_of(input.begin(), input.end(), ::isdigit)) {
					colaborador[i].dni = input;
					break;
				} else {
					cout << " DNI inválido. Debe tener 8 dígitos numéricos.\n";
				}
			} while (true);

			cout << "\nNueva sede (dejar vacío para mantener): ";
			getline(cin, input);
			if (!input.empty()) colaborador[i].sede = input;

			cout << "\nNuevo turno (dejar vacío para mantener): ";
			getline(cin, input);
			if (!input.empty()) colaborador[i].turno = input;

			while (true) {
				cout << "\nNueva edad (poner -1 para mantener): ";
				string edadStr;
				getline(cin, edadStr);

				bool esValida = !edadStr.empty() && all_of(edadStr.begin(), edadStr.end(), [](char c){
					return isdigit(c) || c == '-';
				});
    			if (esValida) {
        			try {
            			nuevaEdad = stoi(edadStr);
            			if (nuevaEdad == -1) break;
            			if (nuevaEdad >= 18) {
                			colaborador[i].edad = nuevaEdad;
                			break;
            			} else {
                		cout << " La edad debe ser mayor o igual a 18 años.\n";
						}
					} catch (...) {
						cout << " Entrada inválida. Intente nuevamente.\n";
					}
				} else {
					cout << " Solo se permiten números (o -1 para mantener).\n";
				}
			}

			while (true) {
				cout << "\nNuevo sueldo (poner -1 para mantener): ";
				string sueldoStr;
				getline(cin, sueldoStr);

				bool esDecimal = !sueldoStr.empty() && all_of(sueldoStr.begin(), sueldoStr.end(), [](char c){
				return isdigit(c) || c == '.' || c == '-';
				});

				if (esDecimal) {
					try {
						nuevoSueldo = stof(sueldoStr);
						if (nuevoSueldo != -1) colaborador[i].sueldo = nuevoSueldo;
							break;
					} catch (...) {
						cout << " Sueldo inválido. Intente nuevamente.\n";
					}
				} else {
					cout << " Solo se permiten números (decimales o -1 para mantener).\n";
				}
			}

			cout << "\n Colaborador modificado exitosamente." << endl;
			return;
		}
	}
	cout << "\n No se encontró un colaborador con ese código." << endl;
	cout<<endl;
}


// ----------- FUNCION PARA ELIMINAR COLABORADOR -----------
void eliminarColaborador() {
//mostramos el codigo y nombre de los colaboradores
	cout << "\nLista de colaboradores registrados:\n";
	for (int i = 0; i < cant_colaboradores; i++) {
		cout << "Código: " << colaborador[i].codigo << " - "
			<< colaborador[i].nombres << endl;
	}
	cout<<endl;
	int cod;
	int pos = -1;
	//condicion si hay 0 colaboradores
	if(cant_colaboradores>0){
	//bucle para reintentar
	do {
        cout << "Ingrese el código de la persona: ";
        cin >> cod;
        pos = buscarColaboradorPorCodigo(cod);
        if (pos == -1) {
            cout << "Código no existe. Intente nuevamente.\n";
        }
    } while (pos == -1);

	cout<<" Eliminaste al colaborador. "<<colaborador[pos].nombres<<endl;
	if(pos>=0 and pos<cant_colaboradores){
		
		//bucle para correr los datos del arreglo
		for(int j=pos; j<cant_colaboradores-1; j++){
			colaborador[j] =colaborador[j+1];
			
			 // mover ventas
            for(int k = 0; k < cant_ventas[j+1]; ++k){
            venta[j][k] = venta[j+1][k];
            }
            cant_ventas[j] = cant_ventas[j+1];
        }
		
		cant_colaboradores--;
		cant_ventas[cant_colaboradores] = 0;
	}
	
	}else{
	cout<<"No hay colaboradores.\n"<<endl;
	}
}


// ----------- FUNCION PARA AGREGAR COLABORADOR -----------

void agregarColaborador() {
	cout<<"\n Agregando nuevo colaborador:\n";
	if (cant_colaboradores >= maximo) {
		cout << "No se pueden agregar más colaboradores (límite alcanzado)." << endl;
		return;
	}

	datosColab nuevo;

	cin.ignore();
	cout << "Ingrese nombres: ";
	getline(cin, nuevo.nombres);

	string entradaEdad;
	bool edadValida;
	do {
		edadValida = true;
		cout << "Ingrese edad: ";
		getline(cin, entradaEdad);
		if (!all_of(entradaEdad.begin(), entradaEdad.end(), ::isdigit)) {
			cout << "Edad inválida. Ingrese solo números.\n";
			edadValida = false;
		} else {
			nuevo.edad = stoi(entradaEdad);
			if (nuevo.edad < 18) {
				cout << "Edad mínima permitida: 18 años.\n";
				edadValida = false;
			}
		}
	} while (!edadValida);

	do {
		cout << "Ingrese teléfono (9 dígitos): ";
		getline(cin, nuevo.telefono);
	} while (nuevo.telefono.length() != 9 || !all_of(nuevo.telefono.begin(), nuevo.telefono.end(), ::isdigit));
	
	cout << "Ingrese sexo (Masculino/Femenino): ";
	getline(cin, nuevo.sexo);

	do {
		cout << "Ingrese DNI (8 dígitos): ";
		getline(cin, nuevo.dni);
	} while (nuevo.dni.length() != 8 || !all_of(nuevo.dni.begin(), nuevo.dni.end(), ::isdigit));

	string entradaSueldo;
	bool sueldoValido;
	do {
		sueldoValido = true;
		cout << "Ingrese sueldo (S/): ";
		getline(cin, entradaSueldo);
		try {
			nuevo.sueldo = stof(entradaSueldo);
			if (nuevo.sueldo <= 0) {
				cout << "El sueldo debe ser mayor que 0.\n";
				sueldoValido = false;
			}
		} catch (...) {
			cout << "Sueldo inválido. Ingrese solo números.\n";
			sueldoValido = false;
		}
	} while (!sueldoValido);

	cout << "Ingrese sede: ";
	getline(cin, nuevo.sede);

	cout << "Ingrese turno (Mañana/Tarde/Noche): ";
	getline(cin, nuevo.turno);

	// Asignación automática del código
	ultimoCodigoAsignado++;
	nuevo.codigo = ultimoCodigoAsignado;
	colaborador[cant_colaboradores] = nuevo;
	cant_colaboradores++;
	cout << " Colaborador agregado correctamente. Código asignado: " << nuevo.codigo;
	cout<<endl;
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
        		
        		venta[pos][can].IDventa = generarIDVentaPorColaborador(pos);
        		 
        		cout<<"Colaborador "<<colaborador[pos].nombres <<" registrado"<<endl;
        		//ingresamos el nombre y comprobamos si hay un producto guardado con su nombre
        		cout<<"ingrese el nombre del producto:"<<endl;
        		string name;
        		getline(cin, name);
        		int nom=-1;
        		for(int i=0; i<cant_product; i++){
        			if(nameproduct[i]==name){
        				nom=i;
        				break;
					}
					
				}
				if (nom == -1) {
                cout << "Producto no encontrado." << endl;
                return; 
                }
				
        		cout<<"ID de venta asignado: ";
        		cout<< venta[pos][can].IDventa << endl;
        		cout<<"Nombre del producto: ";
        		venta[pos][can].producto=nameproduct[nom];
        		cout<<venta[pos][can].producto<<endl;
        		cout<<"Ingrese el precio del producto: ";
        		cin>>venta[pos][can].precio;
        		cin.ignore();
        		cout<<"Ingrese la cantidad de ventas: ";
        		cin>>venta[pos][can].cantidad;
        		cin.ignore();
        	 
        		cout<<"La venta se registró correctamente."<<endl;
        		
        		cant_ventas[pos]++; //incrementa el contador de ventas de forma individual
        		
				}else{
					cout<<"Colaborador no encontrado "<<endl;
				}
		cout<<endl;	
}


//FUNCION PARA BUSCAR A UN COLABORADOR POR EL CODIGO(IMPORTANTE PARA EL MENU 1, 2 Y 3)
int buscarColaboradorPorCodigo(int codigo) {
    for (int i = 0; i < cant_colaboradores; i++) {
        if (colaborador[i].codigo == codigo) {
            return i;
        }
    }
    return -1; // no encontrado
}

//FUNCIONA PARA DESIGNAR UN ID A CADA VENTA DE UN COLABORADOR DE FORMA INDEPENDIENTE
 int generarIDVentaPorColaborador(int posColab) {
    return contadorIDporColaborador[posColab]++;
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
	cout<<endl;
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
    
    cout<<endl;
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
	cout<<endl;
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
	cout<<endl;
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
    
    cout<<endl;
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
    cout<<endl;
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
    cout<<endl;
}

using namespace std;

string nameproduct[50];
int cant_product=0;

void preRecargarNameProduct(){
	
    nameproduct[0] = "Chevrolet Onix Premier";
    nameproduct[1] = "Ferrari Roma V8";
    nameproduct[2] = "Toyota Corolla Cross";
    nameproduct[3] = "Audi Q3 Sportback";
    nameproduct[4] = "Mercedes Benz E 300";

	
	cant_product=5;
}

void agregarNameProduct(){
    if (cant_product >= 50) {
        cout << "Límite de productos alcanzado.\n";
        return;
    }
    cin.ignore(); 
    
    cout<<"ingrese el el nombre y modelo del carro"<<endl;
    getline(cin, nameproduct[cant_product]);
    
    cant_product++;
}

void eliminarNameProduct(){
	
     if (cant_product == 0) {
        cout << "No hay productos para eliminar.\n";
        return;
    }

    string nombre;
    cin.ignore(); // Limpiar el búfer por si hay restos de input
    cout << "Ingrese el nombre y modelo exacto del producto a eliminar: ";
    getline(cin, nombre);

    bool encontrado = false;

    for (int i = 0; i < cant_product; i++) {
        if (nameproduct[i] == nombre) {
            // Mover todos los elementos hacia atrás para sobreescribir el eliminado
            for (int j = i; j < cant_product - 1; j++) {
                nameproduct[j] = nameproduct[j + 1];
            }
            cant_product--; // Reducir el contador
            encontrado = true;
            cout << "Producto eliminado correctamente.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}


 void mostrarProductos(){
    cout << "\nLista de productos:\n";
    for (int i = 0; i < cant_product; i++) {
        cout << i + 1 << ". " << nameproduct[i] << endl;
    }
}
//FIN DE LAS FUNCIONES
