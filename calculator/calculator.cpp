#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <vector>
using namespace std;
int priority(string a)									//Функция расстановки приоритетов арифметических операций
{
	if (a == "^")
	{
		return 4;
	}
	if (a == "*" || a == "/")
	{
		return 3;
	}
	if (a == "+" || a == "-")
	{
		return 2;
	}
	else
	{
		return 1;
	}
}
vector <string> expr(const string s, const int size)				//Функция для получения обратной польской строки
{
	stack <char> stack;
	vector <string> v;
	string buff;
	string stack_top;

	int stack_priority = 0, string_priority = 0;
	for (int i = 0; i < size; i++)
	{
		if (s[i] != ' ')
		{
			if ((s[i] >= '0') && (s[i] <= '9'))
			{
				while ((s[i] >= '0') && (s[i] <= '9'))
				{
					buff.push_back(s[i]);
					i++;
				}
				i--;
				v.push_back(buff);
				buff.clear();
				if (i >= size)
				{
					break;
				}
				continue;
			}
			if (s[i] == '(')
			{
				stack.push(s[i]);
				continue;
			}

			if (s[i] == ')')
			{
				stack_top = stack.top();
				while (stack_top != "(")
				{
					stack_top = stack.top();
					if (stack_top != "(")
					{
						v.push_back(stack_top);
					}
					stack.pop();
				}
				continue;
			}
			if (s[i] == '-')
			{
				if (stack.empty())
				{
					v.push_back("0");
					stack.push('-');
					continue;
				}
				else
				{
					if (s[i - 1] < '0' || s[i - 1] >'9')
					{
						v.push_back("0");
						stack.push('-');
						continue;
					}
				}
			}
			if (!stack.empty())
			{
				stack_top = stack.top();
				stack_priority = priority(stack_top);
				string b;
				b.push_back(s[i]);
				string_priority = priority(b);
				while (stack_priority >= string_priority)
				{
					v.push_back(stack_top);
					stack.pop();
					if (!stack.empty())
					{
						stack_top = stack.top();
						stack_priority = priority(stack_top);
					}
					else {break;}
				}
				if (i > size)
				{
					break;
				}
				stack.push(s[i]);
			}
			else
			{
				stack.push(s[i]);
			}
		}
		else
		{
			continue;
		}
		
	}
	while (!stack.empty())					
	{
		string a;
		a.push_back(stack.top());
		v.push_back(a);
		stack.pop();
	}
	/*for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}*/
	return v;								//Возврат ОПЗ
}
int calc(vector <string> s)							//Вычисление выражения, записанного в форме ОПЗ
{
	stack <long long int> stack;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] != "+") && (s[i] != "-") && (s[i] != "*") && (s[i] != "/") && (s[i] != "^"))
		{
			stack.push(stoi(s[i]));
		}
		else
		{
			int right_op = stack.top();
			stack.pop();
			int left_op = stack.top();
			stack.pop();
			if (s[i] == "+")
			{
				stack.push(left_op + right_op);
			}
			if (s[i] == "-")
			{
				stack.push(left_op - right_op);
			}
			if (s[i] == "*")
			{
				stack.push(left_op * right_op);
			}
			if (s[i] == "/")
			{
				stack.push(left_op / right_op);
			}
			if (s[i] == "^")
			{
				stack.push(pow(left_op, right_op));
			}
		}
	}
	return stack.top();								//Возврат ответа
}
int main()
{
	string s;
	getline(cin, s, '\n');							//Ввод выражения
	//cout << expr(s, s.size()) << endl;			//Вывод обратной польской записи

	cout << calc(expr(s, s.size()));				//Вывод подсчитанного значения
}