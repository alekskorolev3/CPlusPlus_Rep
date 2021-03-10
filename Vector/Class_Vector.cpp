#include <iostream>
#include "vector.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int size, value;
	cout << "Введите 0, если не нужно указывать размер вектора. В ином случае, введите размер вектора:" << endl;
	cin >> size;
	Vector vector(size);								//Объявление вектора
	if (size)
	{
		for (int i = 0; i < size; i++)
		{
			cin >> value;
			vector.init(i, value);						//Инициализация вектора
		}
	}
	vector.push_back(1);								//Добавить элемент в конец вектора. Аргумент - значение
	vector.push_back(2);								//Добавить элемент в конец вектора. Аргумент - значение
	vector.push_back(3);								//Добавить элемент в конец вектора. Аргумент - значение
	vector.insert(1,9);									//Вставить по индексу: первый аргумент - индекс, второй - значение
	cout << "Введите значение для поиска: " << endl;	
	cin >> value;
	cout << "Элемент со значением " << value << " имеет индекс " << vector.findValue(value) << endl;			
														//Поиск элемента по значению. Возвращает индекс
	vector.del(1);										//Удалить элемент по индексу: первый аргумент - индекс
	vector.pop();										//Удалить последний элемент
	//vector.clear();									//Удалить все элементы
	Vector vector2(vector.getSize());
	vector2 = vector;									//Перегрузка оператора присваивания
	vector.print();										//Вывод вектора в консоль
}
