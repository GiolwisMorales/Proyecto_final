#include <iostream>
#include<string>
#include"colaborador.h"


using namespace std;




int main(){
	int hacer;
	//menu de opciones
	cout<<"-------------------MENU-------------------"<<endl;
		
	cout<<"Elija una opcion"<<endl;
	cout<<"[1]GESTION DE COLABORADORES"<<endl;
	//respuesta del usuario
	cin>>hacer;
	
	//condicion de acuerdo a lo que quiere el usuario
	if (hacer==1){
		int opcion;
		
		cout<<"-------------opciones-----------"<<endl;
		cout<<endl;
		cout<<"eliga una opcion: "<<endl;
		cout<<endl;
		cout<<"3: listar colaboradores"<<endl;
		
		cin>>opcion;
		
		//condicion
		if(opcion==3){
			//aplicamos la funcion para la opcion 3
			listarColaboradores();
			
		}
		
	}
	
	
}
