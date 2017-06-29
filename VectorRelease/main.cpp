#include "Vect.h"
#include "AbstractMatrix.h"
#include "Matrix.h"
#include <ctime>
#include <iostream>
#include "locale.h"

using namespace std;
void printVectorData(Vect &vect)
{
	vect.print(" ");
	cout << "Максимальный элемент вектора " << vect.max() << endl;
	cout << "Количество нечётных элементов вектора " << vect.oddCount() << endl;
	cout << "Количество чётных элементов вектора " << vect.eventCount() << endl;
}
int main() {
	setlocale(LC_ALL, "Rus");

	int *firstArray = new int[7]{ 5,8,9,3,4,5,6 };
	int *secondArray = new int[7]{ 5,8,9,3,4,5,6 };

	Vect firstVect = Vect(firstArray, 7);
	Vect secondVect = Vect(secondArray, 7);

	cout << "Первый вектор: " << endl;
	printVectorData(firstVect);
	firstVect.removeEvent();
	cout << "Первый вектор после удаления чётных элементов" << endl;
	printVectorData(firstVect);

	cout << endl << "Второй вектор: " << endl;
	printVectorData(secondVect);
	secondVect.removeOdd();
	cout << "Второй вектор после удаления нечётных элементов" << endl;
	printVectorData(secondVect);

	cout << endl << "Увеличение второго вектора и запись в третий: " << endl;
	Vect thridVect = secondVect++;
	thridVect.print(" ");
	int size = 5;
	int** matr = new int*[size];
	for (int i = 0; i < size; i++) {
		matr[i] = new int[size];
		for (int j = 0; j < size; j++)
			matr[i][j] = rand() % (size * 2);
	}
	cout << endl << "Сортировка строк матрицы: " << endl;
	AbstractMatrix abstr = AbstractMatrix(matr, size);
	abstr.print();
	abstr.sort();
	abstr.print();
	size = 7;
	matr = new int*[size];
	for (int i = 0; i < size; i++) {
		matr[i] = new int[size];
		for (int j = 0; j < size; j++)
			matr[i][j] = rand() % (size * 2);
	}
	cout << endl << "Сортировка побочной диагонали матрицы: " << endl;
	Matrix matrix = Matrix(matr, size);
	matrix.print();
	matrix.sort();
	matrix.print();


	system("pause");
	return 0;
}