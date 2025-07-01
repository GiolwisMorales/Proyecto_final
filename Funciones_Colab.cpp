#include<iostream>
#include"colaborador.h"

using namespace std;

// La mï¿½xima cantidad de colaboradores que habrï¿½
const int maximo = 50;

// Contador que inicia en 0
int cant_colaboradores = 0;

// Arreglo de colaboradores
datosColab colaborador[maximo];

// ----------- FUNCIï¿½N: LISTAR COLABORADORES -----------
void listarColaboradores() {
    if (cant_colaboradores > 0) {
        cout << "Cantidad de colaboradores: " << cant_colaboradores << endl << endl;

        for (int i = 0; i < cant_colaboradores; i++) {
            cout << "Colaborador " << i + 1 << endl;
            cout << "Nombres: " << colaborador[i].nombres << endl;
            cout << "Edad: " << colaborador[i].edad << endl;
            cout << "Cï¿½digo: " << colaborador[i].codigo << endl;
            cout << "Telï¿½fono: " << colaborador[i].telefono << endl;
            cout << endl;
        }
    } else {
        cout << "No hay colaboradores registrados." << endl;
    }
}

// ----------- FUNCIï¿½N: MODIFICAR COLABORADOR -----------
void modificarColaborador() {
    if (cant_colaboradores == 0) {
        cout << "No hay colaboradores registrados." << endl;
        return;
    }
    string codigoBuscado;
    cout << "Ingrese el cï¿½digo del colaborador que desea modificar: ";
    cin.ignore();
    getline(cin, codigoBuscado);
    for (int i = 0; i < cant_colaboradores; i++) {
        if (colaborador[i].codigo == codigoBuscado) {
            cout << "\nColaborador encontrado:" << endl;
            cout << "Nombre actual: " << colaborador[i].nombres << endl;
            cout << "Edad actual: " << colaborador[i].edad << endl;
            cout << "Telï¿½fono actual: " << colaborador[i].telefono << endl;
            string nuevoNombre, nuevoTelefono;
            int nuevaEdad;
            cout << "\nNuevo nombre (dejar vacï¿½o para mantener): ";
            getline(cin, nuevoNombre);
            if (!nuevoNombre.empty()) {
                colaborador[i].nombres = nuevoNombre;
            }
            cout << "Nuevo telï¿½fono (dejar vacï¿½o para mantener): ";
            getline(cin, nuevoTelefono);
            if (!nuevoTelefono.empty()) {
                colaborador[i].telefono = nuevoTelefono;
            }
            cout << "Nueva edad (poner -1 para mantener): ";
            cin >> nuevaEdad;
            if (nuevaEdad != -1) {
                colaborador[i].edad = nuevaEdad;
            }

            cout << "\n? Colaborador modificado exitosamente." << endl;
            return;
        }
    }
    cout << "\n? No se encontrï¿½ un colaborador con ese cï¿½digo." << endl;
}

void eliminarColaborador() {
	string nombre;
	bool encontrado = false;
	cout << "\n--- ELIMINAR COLABORADOR ---"<<endl;
	cout << "Ingrese el nombre del colaborador a eliminar: ";
	getline(cin, nombre);
	for (int i = 0; i < cant_colaboradores; i++) {
		if (colaborador[i].nombres == nombre) {
			for (int j = i; j < cant_colaboradores - 1; j++) {
				colaborador[j] = colaborador[j + 1];
			}
			cant_colaboradores--;
			encontrado = true;
			cout << "* Colaborador eliminado correctamente *"<<endl;
			break;
		}
	}
    if (!encontrado) {
        cout << "Colaborador no encontrado."<<endl;
    }
}

// ----------- FUNCIï¿½N: AGREGAR COLABORADOR -----------


void agregarColaborador() {
    if (cant_colaboradores >= maximo) {
        cout << "No se pueden agregar más colaboradores (límite alcanzado)." << endl;
        return;
    }
    cout << "\n--- AGREGAR COLABORADOR ---" << endl;
    cin.ignore(); // Limpia el buffer
    cout << "Nombre: ";
    getline(cin, colaborador[cant_colaboradores].nombres);
    cout << "Edad: ";
    cin >> colaborador[cant_colaboradores].edad;
    cin.ignore(); // Limpia de nuevo
    cout << "Teléfono: ";
    getline(cin, colaborador[cant_colaboradores].telefono);
    cout << "Código: ";
    getline(cin, colaborador[cant_colaboradores].codigo);
    cant_colaboradores++;
    cout << "* Colaborador agregado correctamente *" << endl;
}

