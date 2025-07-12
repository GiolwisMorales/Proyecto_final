#include <iostream>
#include <string>
#include "colaborador.h"

using namespace std;

int main() {
   //agregamos los 5 primeros colaboradores
    preAgregarColaborador();
    
    int hacer;
    string dictamen;
    do{
	
    cout << "-------------------MENU-------------------" << endl;
    cout << "[1] GESTION DE COLABORADORES" << endl;
    cout << "[2] GESTION DE VENTAS" << endl;
    cout << "[3] GESTION DE INFORMACION" <<endl;
    cout << "[4] SALIR DEL PROGRAMA" <<endl;
    
    do{
    cout << "Elija una opcion" << endl;
    cin >> hacer;
	if(hacer>4 or hacer <1){
		cout<<"opcion invalida! VUELVA A ELEGIR"<<endl;
	}
	}while(hacer>4 or hacer <1);
	
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
    
    cin.ignore();
	cout<<endl;
	cout<<"desea regresar a la ventana anterior? (si o no) "<<endl;
	getline(cin, decision);
	cout<<endl;
	   
    }while(decision=="no" or decision=="NO" or decision=="No");
    
    } else if(hacer ==2 ){
    	int opc;
    	string juicio;
    	
    	do{
		
    	cout << "-------------OPCIONES-----------" << endl;
        cout << "1: Agregar datos de la venta" << endl;
        cout << "2: Listar las ventas" << endl;
        cout << "3: Eliminar venta" << endl;
        cout << "4. Modificar datos del producto vendido"<<endl;
        cout << "Elija una opcion: " << endl;
        cin>>opc;
        
        if(opc==1){
        	
         agregarVenta();
		}
        
        
        
        cout<<endl;
	    cout<<"desea regresar a la ventana anterior? (si o no) "<<endl;
	    getline(cin, juicio);
	    cout<<endl;
        }while(juicio=="no" or juicio== "NO" or juicio=="No");
		
	} else if(hacer ==3){
		
		int op;
		string veredicto;
		
		do{
		
    	cout << "-------------OPCIONES-----------" << endl;
        cout << "1:  rendimiento de colaborador" << endl;
        cout << "2:  ranking de rendimineto" << endl;
        cout << "3:  empleado del mes" << endl;
        cout << "4.  producto mas vendido por colaborador"<<endl;
        cout << "Elija una opcion: " << endl;
        cin>>op;
        
        if(op==1){
        rendimientoColaborador();	
		}
        
         
        cout<<endl;
	    cout<<"desea regresar a la ventana anterior? (si o no) "<<endl;
	    getline(cin, veredicto);
	    cout<<endl;
	    
        }while(veredicto=="no" or veredicto== "NO" or veredicto=="No");
     
	    
	}else if(hacer==4){
		cout<<"PROGRAMA FINALIZADO! "<<endl;
	
		
	}else{
		cout<<"error"<<endl;
	}
    
   
}while(hacer<4 and hacer >0);

    return 0;
    
}

