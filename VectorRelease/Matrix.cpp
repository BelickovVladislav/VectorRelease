#include "Matrix.h"


Matrix::Matrix(int ** matrix, int size) :AbstractMatrix(matrix, size) {
}

Matrix::~Matrix()
{
	AbstractMatrix::~AbstractMatrix();
}

void Matrix::sort()
{
	for (int i = 0, j = size - 1; i < size; i++, j--)
		for (int x = i, y = j; x < size; x++, y--)
			if (matrix[i][j] > matrix[x][y])
				swap(i, j, x, y);
}
