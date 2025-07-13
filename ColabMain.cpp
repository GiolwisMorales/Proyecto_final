#include <iostream>
#include <string>
#include <windows.h>
#include "colaborador.h"
using namespace std;

int main() {
   //agregamos los 5 primeros colaboradores
    preAgregarColaborador();
    
    SetConsoleOutputCP(CP_UTF8);
    int hacer;
    string dictamen;
    do{
    	cout << "-------------------MENÚ-------------------" << endl;	//MEMU PRINCIPAL
    	cout << "[1] GESTIÓN DE COLABORADORES" << endl;
    	cout << "[2] GESTIÓN DE VENTAS" << endl;
  	 	cout << "[3] GESTIÓN DE INFORMACIÓN" <<endl;
		cout << "[4] SALIR DEL PROGRAMA" <<endl;
    	do{															//Elección
    		cout << "Elija una opción:" << endl;
			cin >> hacer;
			if(hacer>4 or hacer <1){								//Restricciones
				cout<<"Opción invalida! VUELVA A ELEGIR."<<endl;
			}
		}while(hacer>4 or hacer <1);
	
	
		if (hacer == 1) {											//Eleccion 1
        	int opcion;
        	
			do{
        		cout << "-------------OPCIONES-----------" << endl;	//Opciones de GESTION DE COLABORADORES
        		cout << "1: Agregar colaborador" << endl;
				cout << "2: Listar colaboradores" << endl;
				cout << "3: Modificar colaborador" << endl;
				cout << "4. Eliminar colaborador"<<endl;
				cout << "5: Salir de de esta pagina"<<endl;
				cout << "Elija una opción: " << endl;
				cin >> opcion;
        	
				if(opcion == 1){
					agregarColaborador();
				} else if(opcion == 2) {
					listarColaboradores();
				} else if (opcion == 3) {
					modificarColaborador();
				} else if (opcion == 4) {
					eliminarColaborador();
				} else if(opcion==5){
					cout<<"saliste de esta pagina "<<endl;
				}else {
					cout << "Opción no válida." << endl;
				}
			
			}while(opcion!=5);
			cout<<endl;
			
		} else if(hacer ==2 ){										//Eleccion 2
    		int opc;
    	
			do{
    			cout << "-------------OPCIONES-----------" << endl;	//Opciones de GESTION DE VENTAS
				cout << "1: Agregar datos de la venta" << endl;
				cout << "2: Listar las ventas" << endl;
				cout << "3: Eliminar venta" << endl;
				cout << "4. Modificar datos del producto vendido"<<endl;
				cout << "5: Salir de esta pagina"<<endl;
				cout << "Elija una opción: " << endl;
				cin>>opc;
        		if(opc==1){
        			agregarVenta();
        			
				} else if(opc==2){
					listarVentas();
					
				}else if(opc==3){
					eliminarventa();
					
				}else if(opc==4){
					modificarVenta();
				}else if(opc==5){
					cout<<"saliste de esta pagina"<<endl;
				}else{
					cout << "Opción inválida.\n";
				}
				 
			}while(opc!=5);
		cout<<endl;
		
		} else if(hacer ==3){										//Eleccion 3
			int op;
			 
			do{
				cout << "-------------OPCIONES-----------" << endl;	//Opciones de GESTION DE INFORMACION
				cout << "1:  Rendimiento de colaborador" << endl;
				cout << "2:  Producto más caro registrado" << endl;
				cout << "3:  Empleado del mes" << endl;
				cout << "4.  Producto mas vendido por colaborador"<<endl;
				cout << "5:  Salir de esta pagina"<<endl;
				cout << "Elija una opción: " << endl;
				cin>>op;
				
				if (op == 1) {
					rendimientoColaborador();
				}else if (op == 2) {
					productoMasCaroRegistrado();
				}else if (op == 3) {
					empleadoDelMes();
				}else if (op == 4) {
					productoMasVendidoPorColaborador();
				}else if(op==5){
					cout<<"saliste de esta pagina"<<endl;
				}else {
					cout << "Opción no válida." << endl;
				}

					
			}while(op != 5);
            cout<<endl;

		}else if(hacer==4){											//Eleccion 4 SALIR DEL PROGRAMA
			cout<<"PROGRAMA FINALIZADO! "<<endl;
			cout<<endl;
			
		}else{                                                      //opcion caso contrario
			cout<<"Error"<<endl;
		}
     cout<<endl; 
	}while(hacer<4 and hacer >0);

    return 0;
    
}

