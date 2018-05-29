#include<iostream>
#include<conio.h>

using namespace std;

struct nodo {
	int dato;
	nodo *sig;
} *ptr;

void insertar_por_cabeza(nodo *p);
void recorrer(nodo *c);
void insertar_por_cola(nodo *p);
void eliminar(int dato);

int main() {
	nodo *p = new nodo;
	p->dato = 1;

	nodo *j = new nodo;
	j->dato = 3;

	nodo *k = new nodo;
	k->dato = 6;

	nodo *h = new nodo;
	h->dato = 10;

	insertar_por_cabeza(p);
	insertar_por_cabeza(j);
	insertar_por_cabeza(k);
	insertar_por_cola(h);

	recorrer(ptr);
	eliminar(1);
	cout << "dato ya eliminado" << endl;
	recorrer(ptr);
	_getch();


}

void insertar_por_cabeza(nodo *p) {
	p->sig = ptr;
	ptr = p;
}

void recorrer(nodo *c) {
	nodo *k = c;
	while (k != NULL) {
		cout << k->dato << endl;
		k = k->sig;
	}
}

void insertar_por_cola(nodo *p) {
	if (ptr != NULL) {

		nodo *k = ptr;
		while (k->sig != NULL) {
			k = k->sig;
		}

		k->sig = p;
		p->sig = NULL;
	}
	else {
		insertar_por_cabeza(p);
	}
}

void eliminar(int dato) {
	nodo *p = ptr;

	if (p->dato == dato) {
		ptr = ptr->sig;
		delete(p);
	}
	else {
		while (p->dato != dato) {
			p = p->sig;
		}

		nodo *j = ptr;

		while (j->sig != p) {
			j = j->sig;
		}

		j->sig = p->sig;

		p->sig = NULL;
		delete(p);
	}
}