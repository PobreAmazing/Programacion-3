#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

struct arbol {
	int dato; 
	arbol *izq, *der;
} *elemento, *aux, *cabecera, *ant, *aux2, *ant2;

int dato; 

int buscar(void); 
void insertar(void);
void buscarmenmay(void);
void buscarmaymen(void);
void eliminar(void); 

void main(void){
	int y, opc; 
	do{
		system("cls");
		y = 10; 
		cout << "0 - Salir\n"; 
		cout << "1 - Buscar\n";
		cout << "Cual es su opcion: \n"; 
		cin >> opc; 

		switch (opc) {
		case 1:
			cout << "\n\n Dato a buscar: "; 
			cin >> dato;
			if (buscar())
				cout << "\n\nDato no existe";
			else
				cout << "\n\nDato inexistente";
			break;

		case 2: 
			cout << "\n\nDato a insertar: "; 
			cin >> dato; 
			insertar(); 
			cout << "\n\nDato insertado";
			break;

		case 3: 
			cout << "\n\nDato a borrar: "; 
			cin >> dato; 
			eliminar();
			break;
		default:
			cout << "\n\nOpcion incorrecta"; 
			break;
		}
		if (opc) _getch();
	} while (opc);
}

int buscar(void){
	if (!cabecera) {
		cout << "No hay arbol"; 
		return(0); 
	} 
	ant = NULL; 
	aux = cabecera;
	while (aux){
		if (dato == aux->dato)
			return(1); 
		else
		{
			ant = aux; 
			if (dato > aux->dato)
				aux = aux->der;
			else
				aux = aux->izq; 
		}
	}
	return(0);
}

void insertar(void){
	if (!cabecera){
		cabecera = new(arbol); 
		cabecera->dato = dato; 
		cabecera->der = NULL; 
		cabecera->izq = NULL;
		return;
	}
	if (!buscar()){
		aux = new(arbol); 
		aux->dato = dato;
		aux->izq = NULL;
		aux->der = NULL; 
		if (dato > ant->dato)
			ant->der = aux;
		else
			ant->izq = aux;
	} else {
		cout << "\n\nDato Existente";
	}
}

void buscarmenmay(void){
	aux2 = aux->der;
	aux2 = aux; 
	while (aux2->izq){
		ant2 = aux2; 
		aux2 = aux2->izq; 
	}
	aux->dato = aux2->dato; 
	if (aux2->der)
		
}