#include "AbstractMatrix.h"
#include <iomanip>
#include <iostream>

using namespace std;


AbstractMatrix::AbstractMatrix(int ** matrix, int size)
{
	this->matrix = matrix;
	this->size = size;
}

AbstractMatrix::~AbstractMatrix()
{
	delete[] matrix;
}

void AbstractMatrix::sort()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			for (int k = j; k < size; k++)
				if (matrix[i][j] > matrix[i][k])
					swap(i, j, i, k);
}

void AbstractMatrix::print()
{
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << setw(4) << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void AbstractMatrix::swap(int i, int j, int x, int y)
{
	int temp = matrix[i][j];
	matrix[i][j] = matrix[x][y];
	matrix[x][y] = temp;

}
