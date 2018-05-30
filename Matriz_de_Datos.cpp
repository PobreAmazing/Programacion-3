#include <iostream>

#include <conio.h>

using namespace std;

void floyds(int b[][5])

{

int i, j, k;

for (k = 0; k < 5; k++)
{
for (i = 0; i < 5; i++)
{
for (j = 0; j < 5; j++)
{
	if ((b[i][k] * b[k][j] != 0) && (i != j))
	{
	if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
	{
	b[i][j] = b[i][k] + b[k][j];

	}

	}
}
}
}

	for (i = 0; i < 5; i++)
	{
	cout << "\n___________________________________________:";
	for (j = 0; j < 5; j++)
	{
	cout << b[i][j] << "\t";
	}
	}

}

int main()
{
	int b[5][5];
	cout << "iNGRESE VALORES DE LA MATRIZ\n\n";
	for (int i = 0; i < 5; i++)
	{
	cout << "Ingrese Valores de la " << (i + 1) << " columna" << endl;
	for (int j = 0; j < 5; j++)
	{
	cin >> b[i][j];
	}
	}

	floyds(b);

	_getch();

}