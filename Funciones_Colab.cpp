#include<iostream>
#include"colaborador.h"

using namespace std;

// La maxima cantidad de colaboradores 
const int maximo = 50;

// Contador que inicia en 0
int cant_colaboradores = 0;

// Arreglo de colaboradores
datosColab colaborador[maximo];

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
}
cout<<endl;

int cod;
//condicion para no hacer nada si hay 0 colaboradores
if(cant_colaboradores>0){
	
	cout<<"ingrese el codigo de la persona "<<endl;
	cin>>cod;
	//disminuir el codigo
	cod--;
	cout<<"eliminaste al colaborador "<<colaborador[cod].nombres<<endl;
	if(cod>=0 and cod<cant_colaboradores){
		
		//bucle para correr los datos del arreglo
		for(int j=cod; j<cant_colaboradores-1; j++){
			colaborador[j]=colaborador[j+1];
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



 
