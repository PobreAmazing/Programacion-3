#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h> 
#include <iostream>

using namespace std; 

typedef struct nodo{
	int valor; 
	nodo *sig; 
}pila;

typedef pila *ptrPila;

ptrPila inicio, final, nuevo, aux; 

void Insertar(){
	int num;
	nuevo = (pila*)malloc(sizeof(pila));
	cout << "Ingrese un valor: "; cin >> num;
	nuevo->valor = num;
	if (inicio == nullptr){
		nuevo->sig = nullptr;
		inicio = nuevo;
		final = nuevo;
	} else {
		nuevo->sig = final; 
		final = nuevo; 
	}
}

void Mostrar(){
	aux = final; 
	while (aux != nullptr){
		cout << aux->valor << "\n";
		aux = aux->sig;
	}
}

void Eliminar(){
	aux = final; 
	final = final->sig; 
	free(aux);
}

int main(){
	inicio = nullptr; final = nullptr; nuevo = nullptr; aux = nullptr;
	int op;
	while (true){
		system("cls");
		cout << "MENU DE PILA\n";
		cout << "[1] Insertar\n";
		cout << "[2] Eliminar\n";
		cout << "[3] Mostrar\n";
		cout << "Seleccionar: "; cin >> op;
		switch (op)
		{
		case 1:
			Insertar(); 
			_getch();
			break;
		case 2: 
			Eliminar();
			_getch(); 
			break; 
		case 3: 
			Mostrar(); 
			_getch();
			break; 
		default:
			break;
		}
	}
}