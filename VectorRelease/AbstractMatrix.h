#pragma once
class AbstractMatrix
{
public:
	AbstractMatrix(int **matrix, int size);
	~AbstractMatrix();
	void sort();
	void print();
protected:
	int **matrix;
	int size;
	void swap(int i, int j, int x, int y);
};

