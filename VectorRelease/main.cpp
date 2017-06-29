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
	cout << "������������ ������� ������� " << vect.max() << endl;
	cout << "���������� �������� ��������� ������� " << vect.oddCount() << endl;
	cout << "���������� ������ ��������� ������� " << vect.eventCount() << endl;
}
int main() {
	setlocale(LC_ALL, "Rus");

	int *firstArray = new int[7]{ 5,8,9,3,4,5,6 };
	int *secondArray = new int[7]{ 5,8,9,3,4,5,6 };

	Vect firstVect = Vect(firstArray, 7);
	Vect secondVect = Vect(secondArray, 7);

	cout << "������ ������: " << endl;
	printVectorData(firstVect);
	firstVect.removeEvent();
	cout << "������ ������ ����� �������� ������ ���������" << endl;
	printVectorData(firstVect);

	cout << endl << "������ ������: " << endl;
	printVectorData(secondVect);
	secondVect.removeOdd();
	cout << "������ ������ ����� �������� �������� ���������" << endl;
	printVectorData(secondVect);

	cout << endl << "���������� ������� ������� � ������ � ������: " << endl;
	Vect thridVect = secondVect++;
	thridVect.print(" ");
	int size = 5;
	int** matr = new int*[size];
	for (int i = 0; i < size; i++) {
		matr[i] = new int[size];
		for (int j = 0; j < size; j++)
			matr[i][j] = rand() % (size * 2);
	}
	cout << endl << "���������� ����� �������: " << endl;
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
	cout << endl << "���������� �������� ��������� �������: " << endl;
	Matrix matrix = Matrix(matr, size);
	matrix.print();
	matrix.sort();
	matrix.print();


	system("pause");
	return 0;
}