#include <iostream>
#include "colaborador.h"

using namespace std;

// -----------------------------
// Variables globales
// -----------------------------
const int maximo = 50;
int cant_colaboradores = 0;
datosColab colaborador[maximo];

// -----------------------------
// Funci�n: Agregar colaborador
// Solicita los datos del colaborador y lo registra si hay espacio
// -----------------------------
void agregarColaborador() {
    if (cant_colaboradores >= maximo) {
        cout << "? No se pueden agregar m�s colaboradores. L�mite alcanzado." << endl;
        return;
    }

    cin.ignore();  // Limpia el buffer
    cout << "\n--- Agregar nuevo colaborador ---\n";

    cout << "Nombres: ";
    getline(cin, colaborador[cant_colaboradores].nombres);

    cout << "Edad: ";
    cin >> colaborador[cant_colaboradores].edad;
    cin.ignore();

    cout << "C�digo: ";
    getline(cin, colaborador[cant_colaboradores].codigo);

    cout << "Tel�fono: ";
    getline(cin, colaborador[cant_colaboradores].telefono);

    cant_colaboradores++;

    cout << "? Colaborador agregado exitosamente." << endl;
}

// -----------------------------
// Funci�n: Listar colaboradores
// Muestra todos los colaboradores registrados
// -----------------------------
void listarColaboradores() {
    if (cant_colaboradores > 0) {
        cout << "\nCantidad de colaboradores: " << cant_colaboradores << endl << endl;

        for (int i = 0; i < cant_colaboradores; i++) {
            cout << "Colaborador " << i + 1 << endl;
            cout << "Nombres: " << colaborador[i].nombres << endl;
            cout << "Edad: " << colaborador[i].edad << endl;
            cout << "C�digo: " << colaborador[i].codigo << endl;
            cout << "Tel�fono: " << colaborador[i].telefono << endl << endl;
        }
    } else {
        cout << "No hay colaboradores registrados." << endl;
    }
}

// -----------------------------
// Funci�n: Modificar colaborador
// Permite editar los datos de un colaborador usando su c�digo
// -----------------------------
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
            if (!nuevoNombre.empty()) colaborador[i].nombres = nuevoNombre;

            cout << "Nuevo tel�fono (dejar vac�o para mantener): ";
            getline(cin, nuevoTelefono);
            if (!nuevoTelefono.empty()) colaborador[i].telefono = nuevoTelefono;

            cout << "Nueva edad (poner -1 para mantener): ";
            cin >> nuevaEdad;
            if (nuevaEdad != -1) colaborador[i].edad = nuevaEdad;

            cout << "\n? Colaborador modificado exitosamente." << endl;
            return;
        }
    }

    cout << "\n? No se encontr� un colaborador con ese c�digo." << endl;
}

