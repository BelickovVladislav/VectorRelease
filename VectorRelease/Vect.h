#pragma once
class Vect
{
public:
	Vect();
	Vect(Vect &vect);
	Vect(int *array, int size);
	~Vect();
	void print(char *split);
	int get(int index);
	int *getArray();
	int oddCount();
	int max();
	int getSize();
	int eventCount();
	void removeEvent();
	void removeOdd();
	Vect operator++(int);
private:
	int *array;
	int size;
	void init();
};

