#include <csdtlib.h>
#include <cstdio.h>
#include <string.h>
#define MaxReg 127

using namespace std;

typedef struct
{
	char cod_prod[4],proveedor[31];
	int precio,cantidad;
	int esta;
}Producto;

typedef struct
{
	Producto* tabla[MaxReg];
	int numElementos;
	double factorCarga;
}TablaDispersa;

void crear(TablaDispersa *t){
	int j;

	for (j = 0; j < MaxReg; j++)
		t->tabla[j] = NULL;
	t->numElementos = 0;
	t->factorCarga = 0.0;
}

int transform(const char* clave)
{
	int j;
	int d = 0;
	for (j = 0; j < strlen(clave); j++)
	{
		d = d + clave[j];
	}
	return d;
}


int direccion(TablaDispersa t, const char* clave)
{
	int p;
	int d;

	d = transform(clave);
	p = d % MaxReg;
	while (t.tabla[p] != NULL && t.tabla[p]->esta)
	{
		p = p + 1;
		p = p%MaxReg;
	}
	return p;
}

Producto* buscar(TablaDispersa t, const char*clave)
{
	Producto* pr;
	int p;
	int d, cont;
	int encontrado;
	
	d = transform(clave);

	p = d %MaxReg;
	cont = 1;
	encontrado = 0;
	while (t.tabla[p] != NULL && !encontrado && cont <= MaxReg)
	{
		if (strcmp(t.tabla[p->cod_pro.clave) == 0
			&& (t.tabla[p]->esta))
			encontrado = 1;
		else {
			p = p + 1;
			p = p % MaxReg;
			cont = cont + 1;
		}
	}
	if (encontrado)
		pr = t.tabla[p];
	else
		pr = NULL;
	return pr;
}


void insertar(TablaDispersa * t. Producto r)
{
	Producto *p;
	int posicion;

	if ((*t).factorCarga<1)
	{
		p = buscar(*t).factorCarga < 1)
		{
			p = buscar(*t.r.cod_pro);
			if (p == NULL)
			{
				posicion = direccion(*t.r.cod_prod);
				if ((*t).tabla[posicion] == NULL)
					(*t).tabla[posicion] = (Producto*)malloc(sizeof(Producto));
				strcpy((*t).tabla[posicion]->precio = r.precio;





