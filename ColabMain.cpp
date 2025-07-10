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
        string decision;
        
		do{

        cout << "-------------OPCIONES-----------" << endl;
        cout << "Elija una opcion: " << endl;
        cout << "1: Agregar colaborador" << endl;
        cout << "2: Listar colaboradores" << endl;
        cout << "3: Modificar colaborador" << endl;
        cout << "4. Eliminar colaborador"<<endl;
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
    
	
	cout<<"¿desea realizar otra accion? (si o no) "<<endl;
	cin>>decision; 
	cout<<endl;
	   
    }while(decision=="si");
    
    } 
    
    return 0;
}
