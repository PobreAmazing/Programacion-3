#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

//Prototipos

struct Nodo {
	int valor; 
	Nodo *left;
	Nodo *right;
	Nodo *padre;
};

Nodo *arbol = NULL;
int suma = 0, contar = 0, hojas = 0;

Nodo *crearNodo(int n, Nodo *padre) {
	Nodo *nuevo = new Nodo();

	nuevo->valor = n; 
	nuevo->left = nullptr; 
	nuevo->right = nullptr;
	nuevo->padre = padre;

	return nuevo;
}

void Terminales(Nodo *arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		if (arbol->left == NULL && arbol->right == NULL) {
			hojas++;
		}
		Terminales(arbol->left);
		Terminales(arbol->right);
	}
}

void Contar(Nodo *arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		contar++;
		Contar(arbol->left);
		Contar(arbol->right);
	}
}

void Sumar(Nodo *arbol) {
	if (arbol == NULL) {
		return; 
	} else {
		suma = suma + arbol->valor;
		Sumar(arbol->left);
		Sumar(arbol->right); 
	}
}

void Reemplazar(Nodo *arbol, Nodo *reemplazo) {
	if (arbol->padre) {
		if (arbol->valor == arbol->padre->left->valor) {
			arbol->padre->left = reemplazo;
		} else if (arbol->valor == arbol->padre->right->valor) {
			arbol->padre->right = reemplazo; 
		}
	}
	if (reemplazo) {
		reemplazo->padre = arbol->padre; 
	}
}

Nodo *Min(Nodo *arbol) {
	if (arbol == nullptr) {
		return NULL; 
	} else  if (arbol->left){
		return Min(arbol->left);
	} else {
		return arbol;
	}
}

void EliminarNodo(Nodo *eliminar) {
	if (eliminar->left && eliminar->right) {
		Nodo *izquierda = Min(eliminar->right);
		eliminar->valor = izquierda->valor;
		EliminarNodo(izquierda);
	} else if (eliminar->left) {
		Reemplazar(eliminar, eliminar->left);
		delete eliminar;
	} else if (eliminar->right) {
		Reemplazar(eliminar, eliminar->right);
		delete eliminar;
	} else {
		Reemplazar(eliminar, NULL);
		delete eliminar; 
	}
}

void Eliminar(Nodo *arbol, int n) {
	if (arbol == NULL) {
		return; 
	} else if (n < arbol->valor) {
		Eliminar(arbol->left, n);
	} else if (n > arbol->valor) {
		Eliminar(arbol->right, n);
	} else {
		EliminarNodo(arbol);
	}
}

bool Buscar(Nodo *arbol, int n) {
	if (arbol == NULL) {
		return false; 
	} else if (arbol->valor == n) {
		return true;
	} else if (n < arbol->valor) {
		return Buscar(arbol->left, n);
	} else if (n < arbol->valor) {
		return Buscar(arbol->right, n);
	}
}

void Mostrar(Nodo *arbol, int c) {
	if (arbol == NULL) {
		return; 
	} else {
		Mostrar(arbol->right, c++);
		for (int i = 0; i < c; i++) {
			cout << "   ";
		}
		cout << arbol->valor << endl; 
		Mostrar(arbol->left, c++);
	}
}

void Insertar(Nodo *&arbol, int n, Nodo *padre) {
	if (arbol == NULL) {
		Nodo *nuevo = crearNodo(n, padre);
		arbol = nuevo;
	} else {
		int raiz = arbol->valor; 
		if (n < raiz) {
			Insertar(arbol->left, n, padre);
		} else {
			Insertar(arbol->right, n, padre);
		}
	}
}

void Menu() {
	int num = 0, opc = 0, cont = 0;

	do {
		cout << "|----- M E N U -----|" << endl;
		cout << "[1] Insertar Nodos" << endl;
		cout << "[2] Mostrar Arbol" << endl;
		cout << "[3] Buscar en Arbol" << endl;
		cout << "[4] Eliminar Nodo" << endl;
		cout << "[5] Sumar Nodos" << endl;
		cout << "[6] Contar Nodos" << endl;
		cout << "[7] Contar Terminales" << endl;
		cout << "[8] Salir" << endl << endl;
		cout << "Seleccionar: "; cin >> opc; 

		switch (opc) {
		case 1:
			cout << "Ingrese número: "; cin >> num;
			Insertar(arbol, num, NULL);
			cout << endl << "Nodo insertado";
			break;
		case 2: 
			Mostrar(arbol, cont);
			break;
		case 3:
			cout << "Elemento a buscar: "; cin >> num; 
			if (Buscar(arbol, num) == true) {
				cout << endl << "El valor: " << num << "ha sido encontrado en el árbol";
			} else {
				cout << endl << "El valor: " << num << "no se ha sido encontrado en el árbol";
			}
			break;
		case 4:
			cout << "Elemento a eliminar: "; cin >> num; 
			Eliminar(arbol, num);
			cout << endl << "Dato eliminado"; 
			break;
		case 5: 
			Sumar(arbol);
			cout << "La suma de los nodos es: " << suma;
			break;
		case 6: 
			Contar(arbol); 
			cout << "El numero de nodos es: " << contar; 
			break;
		case 7: 
			Terminales(arbol); 
			cout << "El numero de terinales es: " << hojas;
			break;
		default:
			break;
		}
		_getch();
		system("cls");
	} while (opc != 8);
}

int main(){
	Menu();
}