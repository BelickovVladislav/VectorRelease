#include "Vect.h"
#include <iostream>

using namespace std;
Vect::Vect()
{
	this->init();
}

Vect::Vect(Vect & vect)
{
	this->array = vect.getArray();
	this->size = vect.getSize();
}

Vect::Vect(int * array, int size)
{
	this->array = array;
	this->size = size;
}


Vect::~Vect()
{
	delete[] array;
}

void Vect::print(char *split)
{
	cout << endl;
	for (int i = 0; i < size; i++)
		cout << array[i] << split;
	cout << endl;
}

int Vect::get(int index)
{
	return index < size && index >= 0 ? array[index] : 0;
}

int * Vect::getArray()
{
	return this->array;
}

int Vect::oddCount()
{
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] % 2 != 0)
			count++;
	}

	return count;
}

int Vect::max()
{
	int max = array[0];
	for (int i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

int Vect::getSize()
{
	return size;
}

int Vect::eventCount()
{
	return this->getSize() - this->oddCount();
}

void Vect::removeEvent()
{
	int newSize = this->oddCount();
	int *newArray = new int[newSize];
	int j = 0;
	for (int i = 0; i < size; i++)
		if (array[i] % 2 != 0)
			newArray[j++] = array[i];
	array = newArray;
	size = newSize;
}

void Vect::removeOdd()
{
	int newSize = this->eventCount();
	int *newArray = new int[newSize];
	int j = 0;
	for (int i = 0; i < size; i++)
		if (array[i] % 2 == 0)
			newArray[j++] = array[i];
	array = newArray;
	size = newSize;
}

void Vect::init()
{
	int size;
	while (true) {
		cout << "¬ведите размер вектора: ";
		cin >> size;
		if (size < 0) {
			cout << endl << "¬ведены некорректные данные, попробуйте снова";
			continue;
		}
		this->size = size;
		break;
	}
	int *array = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "¬ведите " << i << "-ый элемент массива: ";
		cin >> array[i];
	}
	this->array = array;
}
Vect Vect::operator++(int)
{
	int *newArray = new int[size];
	for (int i = 0; i < size; i++)
		newArray[i] = array[i] + 1;
	return Vect(newArray, size);
}
