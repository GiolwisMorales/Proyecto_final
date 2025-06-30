#include<iostream>
#include"colaborador.h"

using namespace std;

// La máxima cantidad de colaboradores que habrá
const int maximo = 50;

// Contador que inicia en 0
int cant_colaboradores = 0;

// Arreglo de colaboradores
datosColab colaborador[maximo];

// ----------- FUNCIÓN: LISTAR COLABORADORES -----------
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

// ----------- FUNCIÓN: MODIFICAR COLABORADOR -----------
void modificarColaborador() {
    if (cant_colaboradores == 0) {
        cout << "No hay colaboradores registrados." << endl;
        return;
    }

    string codigoBuscado;
    cout << "Ingrese el código del colaborador que desea modificar: ";
    cin.ignore();
    getline(cin, codigoBuscado);

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

            cout << "\n? Colaborador modificado exitosamente." << endl;
            return;
        }
    }

    cout << "\n? No se encontró un colaborador con ese código." << endl;
}
