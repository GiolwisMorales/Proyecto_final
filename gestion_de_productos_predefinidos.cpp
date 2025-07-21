#include<iostream>
#include"colaborador.h"

using namespace std;

nameproduct name[50];
int cant_product=0; 

void preRecargarNameProduct(){
	
    name[0] = { "Chevrolet", "Onix Premier", 1 };
    name[1] = { "Ferrari",   "Roma V8",       2 };
    name[2] = { "Toyota",    "Corolla Cross", 3 };
    name[3] = { "Audi",      "Q3 Sportback",  4 };
    name[4] = { "Mercedes",  "Benz E 300",    5 };
	
	cant_product=5;
}

void agregarNameProduct() {
    if (cant_product >= 50) {
        cout << "Límite de productos alcanzado.\n";
        return;
    }
    cin.ignore(); 
    cout<<"indice: "<<cant_product+1<<endl;
    nameproduct nuevo;
    cout << "Marca: ";
    getline(cin, nuevo.marca);
    cout << "Modelo: ";
    getline(cin, nuevo.modelo);
    nuevo.indice = cant_product + 1; 
    name[cant_product++] = nuevo;
    cout << "Producto agregado.\n\n";
}

void eliminarNameProduct() {
    if (cant_product == 0) {
        cout << "No hay productos para eliminar"<<endl;
        return;
    }

    
    // Leer el número del producto a eliminar
    cout << "ingrese el indice del producto a eliminar: ";
    int opcion;
    cin >> opcion;

    if (opcion < 1 or opcion > cant_product) {
        cout << "Índice inválido"<<endl;
        return;
    }

    int pos = opcion - 1;
    // Mover los productos posteriores una posición hacia la izquierda
    for (int i = pos; i < cant_product - 1; ++i) {
        name[i] = name[i + 1];
        name[i].indice = i + 1;  // reajustar índices consecutivamente
    }

    cant_product--;  // reducir contador
    cout << "Producto eliminado correctamente.\n\n";
}

 void listarName() {
    if (cant_product == 0) {
        cout << "No hay productos registrados.\n\n";
        return;
    }

    cout << "--- Productos registrados ---\n";
    for (int i = 0; i < cant_product; ++i) {
        cout << i + 1 << ". Indice: " << name[i].indice
             << " -> " << name[i].marca << " " << name[i].modelo << "\n";
    }
    cout << endl;
}

