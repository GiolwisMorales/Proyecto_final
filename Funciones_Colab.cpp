#include<iostream>
#include"colaborador.h"

using namespace std;

// La m�xima cantidad de colaboradores que habr�
const int maximo = 50;

// Contador que inicia en 0
int cant_colaboradores = 0;

// Arreglo de colaboradores
datosColab colaborador[maximo];

// ----------- FUNCI�N: LISTAR COLABORADORES -----------
void listarColaboradores() {
    if (cant_colaboradores > 0) {
        cout << "Cantidad de colaboradores: " << cant_colaboradores << endl << endl;

        for (int i = 0; i < cant_colaboradores; i++) {
            cout << "Colaborador " << i + 1 << endl;
            cout << "Nombres: " << colaborador[i].nombres << endl;
            cout << "Edad: " << colaborador[i].edad << endl;
            cout << "C�digo: " << colaborador[i].codigo << endl;
            cout << "Tel�fono: " << colaborador[i].telefono << endl;
            cout << endl;
        }
    } else {
        cout << "No hay colaboradores registrados." << endl;
    }
}

// ----------- FUNCI�N: MODIFICAR COLABORADOR -----------
void modificarColaborador() {
    if (cant_colaboradores == 0) {
        cout << "No hay colaboradores registrados." << endl;
        return;
    }
    string codigoBuscado;
    cout << "Ingrese el c�digo del colaborador que desea modificar: ";
    cin.ignore();
    getline(cin, codigoBuscado);
    for (int i = 0; i < cant_colaboradores; i++) {
        if (colaborador[i].codigo == codigoBuscado) {
            cout << "\nColaborador encontrado:" << endl;
            cout << "Nombre actual: " << colaborador[i].nombres << endl;
            cout << "Edad actual: " << colaborador[i].edad << endl;
            cout << "Tel�fono actual: " << colaborador[i].telefono << endl;
            string nuevoNombre, nuevoTelefono;
            int nuevaEdad;
            cout << "\nNuevo nombre (dejar vac�o para mantener): ";
            getline(cin, nuevoNombre);
            if (!nuevoNombre.empty()) {
                colaborador[i].nombres = nuevoNombre;
            }
            cout << "Nuevo tel�fono (dejar vac�o para mantener): ";
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
    cout << "\n? No se encontr� un colaborador con ese c�digo." << endl;
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