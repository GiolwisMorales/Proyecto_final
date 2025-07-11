#include <iostream>
#include <string>
#include "colaborador.h"

using namespace std;

int main() {
    int hacer;

    
    cout << "-------------------MENU-------------------" << endl;
    cout << "[1] GESTION DE COLABORADORES" << endl;
    
    cout << "Elija una opcion" << endl;
    cin >> hacer;

    
    if (hacer == 1) {
        int opcion;
        string decision;
        
		do{

        cout << "-------------OPCIONES-----------" << endl;
        cout << "1: Agregar colaborador" << endl;
        cout << "2: Listar colaboradores" << endl;
        cout << "3: Modificar colaborador" << endl;
        cout << "4. Eliminar colaborador"<<endl;
        cout << "Elija una opcion: " << endl;
        cin >> opcion;

        if(opcion == 1){
        	agregarColaborador();
		}
		else if(opcion == 2) {
            listarColaboradores();
        } 
		else if (opcion == 3) {
            modificarColaborador();
		}
		else if (opcion == 4) {
			eliminarColaborador();
		} 
		else {
            cout << "Opcion no valida." << endl;
        }
    
	cout<<endl;
	cout<<"desea regresar a la ventana anterior? (si o no) "<<endl;
	getline(cin, decision);
	cout<<endl;
	   
    }while(decision=="no" or decision=="NO" or decision=="No");
    
    } 
    
    return 0;
}
