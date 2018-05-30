#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct nodo {
	int nro;
	struct nodo *izq, *der;
}*ABB;

int numNodos = 0;
int numK = 0, k;


struct nodoCola {
	ABB ptr;
	struct nodoCola *sgte;
};

struct cola {
	struct nodoCola *delante;
	struct nodoCola *atras;
};

void inicializaCola(struct cola &q)
{
	q.delante = NULL;
	q.atras = NULL;
}

void encola(struct cola &q, ABB n)
{
	struct nodoCola *p;
	p = new(struct nodoCola);
	p->ptr = n;
	p->sgte = NULL;
	if (q.delante == NULL)
		q.delante = p;
	else
		(q.atras)->sgte = p;
	q.atras = p;
}

ABB desencola(struct cola &q)
{
	struct nodoCola *p;
	p = q.delante;
	ABB n = p->ptr;
	q.delante = (q.delante)->sgte;
	delete(p);
	return n;
}

ABB crearNodo(int x)
{
	ABB nuevoNodo = new(struct nodo);
	nuevoNodo->nro = x;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;

	return nuevoNodo;
}
void insertar(ABB &arbol, int x)
{
	if (arbol == NULL)
	{
		arbol = crearNodo(x);
		cout << "\n\t  Insertado..!" << endl << endl;
	}
	else if (x < arbol->nro)
		insertar(arbol->izq, x);
	else if (x > arbol->nro)
		insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		cout << arbol->nro << " ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void enOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		enOrden(arbol->izq);
		cout << arbol->nro << " ";
		enOrden(arbol->der);
	}
}

void postOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		enOrden(arbol->izq);
		enOrden(arbol->der);
		cout << arbol->nro << " ";
	}
}

void verArbol(ABB arbol, int n)
{
	if (arbol == NULL)
		return;
	verArbol(arbol->der, n + 1);

	for (int i = 0; i<n; i++)
		cout << "   ";

	numNodos++;
	cout << arbol->nro << endl;

	verArbol(arbol->izq, n + 1);
}

bool busquedaRec(ABB arbol, int dato)
{
	int r = 0;   // 0 indica que lo encontre

	if (arbol == NULL)
		return r;

	if (dato<arbol->nro)
		r = busquedaRec(arbol->izq, dato);

	else if (dato> arbol->nro)
		r = busquedaRec(arbol->der, dato);

	else
		r = 1;   // son iguales, lo encontre

	return r;
}
ABB unirABB(ABB izq, ABB der)
{
	if (izq == NULL) return der;
	if (der == NULL) return izq;

	ABB centro = unirABB(izq->der, der->izq);
	izq->der = centro;
	der->izq = izq;
	return der;
}

int contarHojas(ABB arbol)
{
	if (arbol == NULL)
	{
		return 0;
	}
	if ((arbol->der == NULL) && (arbol->izq == NULL))
	{
		return 1;
	}
	else
	{
		return contarHojas(arbol->izq) + contarHojas(arbol->der);
	}
}

void elimina(ABB &arbol, int x)
{
	if (arbol == NULL) return;

	if (x<arbol->nro)
		elimina(arbol->izq, x);
	else if (x>arbol->nro)
		elimina(arbol->der, x);

	else
	{
		ABB p = arbol;
		arbol = unirABB(arbol->izq, arbol->der);
		delete p;
	}
}

int alturaAB(ABB arbol)
{
	int AltIzq, AltDer;

	if (arbol == NULL)
		return -1;
	else
	{
		AltIzq = alturaAB(arbol->izq);
		AltDer = alturaAB(arbol->der);

		if (AltIzq>AltDer)
			return AltIzq + 1;
		else
			return AltDer + 1;
	}
}

void nodosMenoresQueK(ABB arbol, int n)
{
	if (arbol == NULL)
		return;
	nodosMenoresQueK(arbol->der, n + 1);
	if (arbol->nro<k)
		numK++;
	nodosMenoresQueK(arbol->izq, n + 1);

}


void menu()
{
	//system("cls");
	cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";
	cout << "\t [1]  Insertar elemento                  \n";
	cout << "\t [2]  Mostrar arbol                      \n";
	cout << "\t [3]  Recorridos           \n";
	cout << "\t [4]  Buscar elemento                    \n";
	cout << "\t [5]  Eliminar elemento                  \n";
	cout << "\t [6]  Contar los nodos					\n";
	cout << "\t [7]  Altura del arbol					\n";
	cout << "\t [8]  contar hojas                            \n";
	cout << "\t [9]  SALIR                              \n";
	cout << "\n\t Ingrese opcion : ";
}

void menu2()
{
	//system("cls");   // para limpiar pantalla
	cout << endl;
	cout << "\t [1] En Orden     \n";
	cout << "\t [2] Pre Orden    \n";
	cout << "\t [3] Post Orden   \n";
	cout << "\n\t     Opcion :  ";
}

int main()
{
	ABB arbol = NULL;
	int x;
	int op, op2;


	//system("color f9");   // poner color a la consola
	do
	{
		menu();  cin >> op;
		cout << endl;

		switch (op)
		{
		case 1:
			system("cls");
			cout << " Ingrese valor : ";  cin >> x;
			insertar(arbol, x);
			break;

		case 2:
			system("cls");
			verArbol(arbol, 0);
			break;

		case 3:
			system("cls");
			menu2();  cin >> op2;

			if (arbol != NULL)
			{
				switch (op2)
				{
				case 1:
					enOrden(arbol); break;
				case 2:
					preOrden(arbol); break;
				case 3:
					postOrden(arbol); break;
				}
			}
			else
				cout << "\n\t Arbol vacio..!";
			break;

		case 4:
			system("cls");
			bool band;

			cout << " Valor a buscar: "; cin >> x;

			band = busquedaRec(arbol, x);

			if (band == 1)
				cout << "\n\tEncontrado...";
			else
				cout << "\n\tNo encontrado...";
			break;

		case 5:
			system("cls");
			cout << " Valor a eliminar: "; cin >> x;
			elimina(arbol, x);
			cout << "\n\tEliminado..!";
			break;

		case 6: 
			system("cls");

			verArbol(arbol, 0);
			cout << "\n\n El numero de nodos es : ";
			cout << numNodos;
			break;


		case 7:
			int h;
			h = alturaAB(arbol);
			cout << " La altura es : " << h << endl;
			break;

		case 8:  
			cout << " Ingrese k: "; cin >> k;
			nodosMenoresQueK(arbol, 0);
			cout << " Son  " << numK << "  numeros";
			break;

		case 9:
		exit(0);
		}

		cout << "\n\n\n";
		//system("pause");  // hacer pausa y presionar una tecla para continuar
	} while (op != 9);

}