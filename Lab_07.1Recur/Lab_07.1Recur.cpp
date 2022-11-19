#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** z, const int rowCount, const int colCount, const int Min,
	const int Max, int i, int j);
void Print(int** z, const int rowCount, const int colCount, int i, int j);
void Sort(int** z, const int rowCount, const int colCount, int i1, int i0, int j);
void Change(int** z, const int col1, const int col2, const int rowCount, int j);
int Calc(int** z, const int rowCount, const int colCount, int& S, int& k, int i, int j);

int main()
{
	srand((unsigned)time(NULL));
	int Min = 18;
	int Max = 74;
	int rowCount = 9;
	int colCount = 6;
	int** z = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		z[i] = new int[rowCount];

	Create(z, rowCount, colCount, Min, Max, 0, 0);
	Print(z, rowCount, colCount, 0, 0);
	Sort(z, rowCount, colCount, 1, 1, 0);
	Print(z, rowCount, colCount, 0, 0);
	int S = 0;
	int k = 0;
	Calc(z, rowCount, colCount, S, k, 0, 0);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(z, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] z[i];
	delete[] z;
}

void Create(int** z, const int rowCount, const int colCount, const int Min, const int Max, int i, int j)
{
	z[i][j] = Min + rand() % (Max - Min + 1);
	if (j < colCount - 1)
		Create(z, rowCount, colCount, Min, Max, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(z, rowCount, colCount, Min, Max, i + 1, 0);
}

void Print(int** z, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << z[i][j];
	if (j < colCount - 1)
		Print(z, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(z, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}



void Sort(int** z, const int rowCount, const int colCount, int i1, int i0, int j)
{
	if ((z[0][i0] > z[0][i0 + 1])
		||
		(z[0][i0] == z[0][i0 + 1] &&
			z[1][i0] < z[1][i0 + 1])
		||
		(z[0][i0] == z[0][i0 + 1] &&
			z[1][i0] == z[1][i0 + 1] &&
			z[2][i0] < z[2][i0 + 1]))
		Change(z, i0 + 1, i0, rowCount, j);
	
	if (i0 < colCount - i1 - 1)
	{

		Sort(z, rowCount, colCount, i1, i0 + 1, j);
	}

	if (i1 < colCount - 1)
		Sort(z, rowCount, colCount, i1 + 1, 0, j);
}

	
	


void Change(int** z, const int col1, const int col2, const int rowCount, int j)
{
	int tmp = z[j][col1];
	z[j][col1] = z[j][col2];
	z[j][col2] = tmp;
	if (j < rowCount-1)
		Change(z, col1, col2, rowCount, j + 1);

}

int Calc(int** z, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
	if (!(z[i][j] % 2 != 0 || (z[i][j] % 7 == 0)))
	{
		S += z[i][j];
		k++;
		z[i][j] = 0;
	}	
	if (j < rowCount - 1)
		Calc(z, rowCount, colCount, S, k, i, j + 1);
	else
		if (i < rowCount - 1)
			Calc(z, rowCount, colCount, S, k, i + 1, 0);

	return S;
}


