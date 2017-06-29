#pragma once
#include "AbstractMatrix.h"
class Matrix :
	public AbstractMatrix
{
public:
	Matrix(int **matrix, int size);
	~Matrix();
	void sort();
};

