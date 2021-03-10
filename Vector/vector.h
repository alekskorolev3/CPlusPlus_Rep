#include <iostream>
using namespace std;
class Vector
{
private:
	int* array = new int[1];
	int size = 1;
public:
	Vector(int s = 1)
	{
		size = s;
		if (s == 0)
		{
			size = 1;
		}
		array = new int[size];
		/*for (int i = 0; i < size; i++)
		{
			array[i] = 0;
		}*/
	}
	Vector& operator= (const Vector& vector)
	{
		// ¬ыполн€ем копирование значений
		for (int i = 0; i < size; i++)
		{
			*(array + i) = vector.array[i];
		}
		// ¬озвращаем текущий объект, чтобы иметь возможность св€зать в цепочку выполнение нескольких операций присваивани€
		return *this;
	}
	void init(int index, int value)
	{
		array[index] = value;
	}
	void push_back(int element)
	{
		array[size - 1] = element;
		int* buff = new int[size];
		for (int i = 0; i < size; i++)
		{
			*(buff + i) = *(array + i);
		}
		delete[] array;
		size++;
		array = new int[size];
		for (int i = 0; i < size - 1; i++)
		{
			*(array + i) = *(buff + i);
		}
		delete[] buff;
	}
	void insert(int index, int value)
	{
		size++;
		int* buff = new int[size];
		for (int i = 0; i < index; i++)
		{
			*(buff + i) = *(array + i);
		}
		*(buff + index) = value;
		for (int i = index + 1; i < size; i++)
		{
			*(buff + i) = *(array + i - 1);
		}
		delete[] array;
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			*(array + i) = *(buff + i);
		}
		delete[] buff;
	}
	void del(int index)
	{
		size--;
		int* buff = new int[size];
		for (int i = 0; i < index; i++)
		{
			*(buff + i) = *(array + i);
		}
		for (int i = index + 1; i < size; i++)
		{
			*(buff + i - 1) = *(array + i);
		}
		delete[] array;
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			*(array + i) = *(buff + i);
		}
		delete[] buff;
	}
	void clear()
	{
		delete[] array;
		array = new int[1];
	}
	void pop()
	{
		size--;
		int* buff = new int[size];
		for (int i = 0; i < size; i++)
		{
			*(buff + i) = *(array + i);
		}
		delete[] array;
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			*(array + i) = *(buff + i);
		}
		delete[] buff;
	}
	int findValue(int value)
	{
		for (int i = 0; i < size; i++)
		{
			if (*(array + i) == value)
			{
				return i;
			}
		}
	}
	int getSize()
	{
		return size;
	}
	void print()
	{
		for (int i = 0; i < size - 1; i++)
		{
			cout << *(array + i) << " ";
		}
		cout << endl;
	}
	~Vector()
	{
		delete[] array;
	}
};