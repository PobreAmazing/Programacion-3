#include<iostream>
using namespace std;

struct nodo {
	char nro[50];
	//char nro1[10];
	//char nro2[10];
	struct nodo *sgte;
};

struct cola {
	nodo *delante;
	nodo *atras;
};

void encolar(struct cola &q, char valor) {
	struct nodo *aux = new(struct nodo);
	aux->nro[50] = valor;
	aux->sgte = NULL;

	//aux->nro1[10] = valor1;
	//aux->sgte = NULL;

	//aux->nro2[10] = valor2;
	//aux->sgte = NULL;

	if (q.delante == NULL)
		q.delante = aux;
	else
		(q.atras)->sgte = aux;
	q.atras = aux;
}

int  desencolar(struct cola &q) {
	int num;
	struct nodo *aux;

	aux = q.delante;
	num = aux->nro[50];
	q.delante = (q.delante)->sgte;
	delete(aux);
	return num;
}

void muestraCola(struct cola q) {
	struct nodo *aux;
	aux = q.delante;

	while (aux != NULL) {
		cout << "  " << aux->nro;
		aux = aux->sgte;
	}
}

void vaciaCia(struct cola &q) {
	struct nodo *aux;

	while (q.delante != NULL) {
		aux = q.delante;
		q.delante = aux->sgte;

		delete(aux);
	}

	q.delante = NULL;
	q.atras = NULL;
}


void menu() {
	cout << "\n\t IMPLEMENTACION DE COLAS EN C++ \n\n";
	cout << "1. ENCOLAR                " << endl;
	cout << "2. DESENCOLAR                   " << endl;
	cout << "3. MOSTRAR COLA                 " << endl;
	cout << "4. VACIAR COLA                  " << endl;
	cout << "5. SALIR                " << endl;
}

int main() {
	struct cola q;

	q.delante = NULL;
	q.atras = NULL;

	char dato[10];
	char dato1[10];
	char dato2[10];
	int op;
	int x;
	system("color 0b");
	do {
		menu(); cin >> op;

		switch (op) {
		case 1:
			system("cls");
			cout << "NOMBRE DE ARCHIVO A ENCOLAR: " << endl;
			cin >> dato;
			encolar(q, dato[10]);

			cout << "NOMBRE DE USUARIO: " << endl;
			cin >> dato1;
			encolar(q, dato1[10]);

			cout << "PAGINAS: " << endl;
			cin >> dato2;
			encolar(q, dato2[10]);

			cout << "\n\n\t NUMERO:  " << dato << " "<< dato1 <<" "<<dato2 <<" encolando... \n\n";
			break;

		case 2:
			system("cls");
			x = desencolar(q);
			cout << "\n\n\t NUMERO:  " << x << "Desencolado.. \n\n";
			break;

		case 3:
			system("cls");
			cout << "\n\n MOSTRANDO COLA\n\n";
			if (q.delante != NULL) muestraCola(q);
			else cout << "\n\n\t Cola vacia... !" << endl;
			break;

		case 4:
			system("cls");
			vaciaCia(q);
			cout << "\n\n\t HECHO...\n\n";
		}
		cout << endl << endl;
		system("pause"); system("cls");

	} while (op != 5);
}









