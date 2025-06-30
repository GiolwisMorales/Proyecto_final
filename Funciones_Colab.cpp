#include<iostream>
#include"colaborador.h"
//la maxima cantidad de colaboradores que habra
const int maximo=50;
//no registramos ninguno asi que contador empieza de 0
int  cant_colaboradores=0 ;
//la estructurta se guarda como colaborador
datosColab colaborador[maximo];

void listarColaboradores(){
	
	if(cant_colaboradores>0){
		
		cout<<"cantidad de colaboradores: "<<cant_colaboradores<<endl;
		cout<<endl;
	
		//bucle for para mostrar los colaboradores 
		for(int i=0; i<cant_colaboradores; i++){
			//el i empieza de 0 asi que aumentamod mas 1
			cout<<"colaborador "<<i+1<<endl;
			//datos del colaborador
			cout<<"nombres: "<<colaborador[i].nombres<<endl;
			cout<<"edad: "<<colaborador[i].edad<<endl;
			cout<<"codigo: "<<colaborador[i].codigo<<endl;
			cout<<"telefono: "<<colaborador[i].telefono<<endl;
			cout<<endl;
			
		}
	}else{
		cout<<"cantidad de colaboradores: "<<cant_colaboradores<<endl;
		
	}
	 
}