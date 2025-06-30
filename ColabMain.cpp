#include <iostream>
#include <string>
#include "colaborador.h"

using namespace std;

int main() {
    int hacer;

    
    cout << "-------------------MENU-------------------" << endl;
    cout << "Elija una opcion" << endl;
    cout << "[1] GESTION DE COLABORADORES" << endl;
    cin >> hacer;

    
    if (hacer == 1) {
        int opcion;

        cout << "-------------OPCIONES-----------" << endl;
        cout << "Elija una opcion: " << endl;
        cout << "3: Listar colaboradores" << endl;
        cout << "4: Modificar colaborador" << endl;
        cout << "5. Eliminar colaborador"<<endl;
        cin >> opcion;

        if (opcion == 3) {
            listarColaboradores();
        } 
		else if (opcion == 4) {
            modificarColaborador();
		}
		else if (opcion == 4) {
			eliminarColaborador();
		} else {
            cout << "Opcion no valida." << endl;
        }
    } else {
        cout << "Opcion principal no valida." << endl;
    }
    return 0;
}

