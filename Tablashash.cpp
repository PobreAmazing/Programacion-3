#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

///variables glovales
int dato;
string sdato;
int MAX = 5;

///prototipos
struct llave;
struct clave;
clave *nuevaC(); llave *nuevaL();
llave *recoL(); clave *recoC(clave *);
int funcHash(); void inicL();
void iniciarLlave(); llave *buscarLlave(int);
void insertarClave(llave*); void irEnLlave();
void pedirDato(); void imprimir(); void elim(); void buscar();

///funciones

struct llave {
	struct llave *s;
	struct llave *a;
	int illa;
	string lla;
	struct clave *clave;
}*inicioL, *finL, *recorrerL, *nuevoL;

struct clave {
	struct clave *a;
	struct clave *s;
	int icla;
	string cla;
}*inicioC, *finC, *recorrerC, *nuevoC;

clave *nuevaC() {
	nuevoC = new clave;
	if (nuevoC) {
		nuevoC->s = NULL;
		nuevoC->icla = dato;
		nuevoC->cla = sdato;
		nuevoC->a = NULL;
	}
	return nuevoC;
}

llave *nuevaL() {
	nuevoL = new llave;
	if (nuevoL) {
		nuevoL->a = NULL;
		nuevoL->s = NULL;
		nuevoL->illa = 0;
		nuevoL->clave = NULL;
	}
	return nuevoL;
}

int funcHash() {
	return (dato % MAX);
}

void inicL() {
	inicioL = nuevaL();
	inicioL->illa = 0;
	cout << "\n\tINGRESE LA LLAVE PARA LA POSICION 0: ";
	cin >> inicioL->lla;
}

llave *recoL() {
	recorrerL = inicioL;
	while (recorrerL->s) {
		recorrerL =recorrerL->s;
	} 
	return recorrerL;
}

clave *recoC(clave *i) {
	recorrerC = i;
	while (recorrerC->s) {
		recorrerC = recorrerC->s;
	}
	return recorrerC;
}

void iniciarLlave() {
	llave *n, *aux;
	for (int i = 0; i < MAX; i++) {
		if (!inicioL) inicL();
		else {
			n = nuevaL();
			aux = recoL();
			n->illa = i;
			cout << "\n\tINGRESE LA LLAVE PARA LA POSICION "<< i <<": ";
			cin >> n->lla;
			aux->s = n;
			n->a = aux;
		}
	}
}

llave *buscarLlave(int fH) {	
	recorrerL = inicioL;
	while (recorrerL->s) {
		if (recorrerL->illa == fH)
			return recorrerL;
		recorrerL = recorrerL->s;
	}
	return recorrerL;
}

void insertarClave(llave *a) {
	clave *n, *i;
	if (!a->clave) { a->clave = nuevaC(); }
	else {
		i = recoC(a->clave);
		n = nuevaC();
		i->s = n;
	}
}

void irEnLlave() {
	llave *insertarL;
	insertarL = buscarLlave(funcHash());
	insertarClave(insertarL);
}

void pedirDato() {
	char a[100];
	cout << "\n\n\n\n\t\t|INGRESO DE DATO|";
	cout << "\n\n\tingrese el dato para la tabla de hash:  ";
	cin >> sdato;
	dato = sdato[0];
	cout << "\t                                   residuo: " << dato % MAX;
	irEnLlave();
}

void imprimir() {
	recorrerL = inicioL;

	cout << "\n\n\n\n";
	for (int i = 0; i < 100; i++)
		cout << "-";
	for (int i = 0; i < MAX; i++) {
		cout << "\n\t" << recorrerL->illa << " " << recorrerL->lla << "\t|";
		if (recorrerL->clave) {
		recorrerC = recorrerL->clave;
			while (recorrerC) {
				cout << "\t( " << recorrerC->icla << " ) "<< recorrerC->cla << " |";
				recorrerC = recorrerC->s;
			}
		}
		cout << "\n";
		for (int i = 0; i < 100; i++)
			cout << "-";
		recorrerL = recorrerL->s;
	}
}

void buscar() {
	cout << "\n\n\t\t|BUSCAR|\n";
	cout << "\n\tingrese el valor a buscar: ";
	cin >> sdato;
	dato = sdato[0];
	recorrerL = inicioL;
	while (recorrerL){
		if (recorrerL->illa == (dato%MAX))break;
		recorrerL = recorrerL->s;
	}
	if (!recorrerL->clave)cout << "\n\tEL DATO NO ESTA EN LA LISTA...";
	else {
		recorrerC = recorrerL->clave;
		while (recorrerC){
			if (recorrerC->cla == sdato) { cout << "\n\tEL DATO SI ESTA EN LA LISTA..."; break; break; }
			recorrerC = recorrerC->s;
		}
	}
}

void elim() {
	clave *aux;
	cout << "\n\n\t\t|ELIMINAR|\n";
	cout << "\n\tingrese el valor a eliminar: ";
	cin >> sdato;
	dato = sdato[0];
	recorrerL = inicioL;
	while (recorrerL) {
		if (recorrerL->illa == (dato%MAX))break;
		recorrerL = recorrerL->s;
	}
	if (!recorrerL->clave)cout << "\n\tEL DATO NO ESTA EN LA LISTA...";
	else {
		recorrerC = recorrerL->clave;
		aux = recorrerC;
		while (recorrerC) {
			if (recorrerC->cla == sdato) {
				if (recorrerC == recorrerL->clave) recorrerL->clave = recorrerC->s;
				else { aux->s = recorrerC->s; }
				free(recorrerC);
				cout << "\n\tEL DATO BORRADO DE LA LISTA..."; 
				break; break;
			}
			aux = recorrerC;
			recorrerC = recorrerC->s;
		}
		cout << "\n\tEL DATO NO ESTA EN LA LISTA...";
	}
}

void menu() {
	int op = 1;
	while (op != 0) {
		system("cls");
		cout << "\n\n\t\t\tMENU:";
		cout << "\n\t\t1| INSERTAR";
		cout << "\n\t\t2| IMPRIMIR";
		cout << "\n\t\t3| BUSCAR";
		cout << "\n\t\t4| ELIMINAR";
		cout << "\n\t\t0| SALIR";
		cout << "\n\t\t--------------> ";
		cin >> op;
		switch (op){
		case 1:
			pedirDato();
			break;
		case 2:
			imprimir();
			_getch();
			break;
		case 3:
			buscar();
			_getch();
			break;
		case 4:
			elim();
			_getch();
			break;
		default:
			break;
		}
	}
}

int main() {

	cout << "\n\n\t\tincio del programa::";
	cout << "\n\tingrese el tamaño del vector: ";
	cin >> MAX;
	if (2 % MAX == 0)MAX = MAX + 1;

	iniciarLlave();
	system("cls");
	menu();
	_getch();
	return 0;
}
