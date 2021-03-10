#include <iostream>
using namespace std;
void calculate()
{
	int x;
	int y;
	char a;
	switch (a)
	{
	case 1:
		cout << x * y << endl;
		break;
	case 2:
		cout << x / y << endl;
		break;
	case 3:
		cout << x + y << endl;
		break;
	case 4:
		cout << x - y << endl;
		break;
	default: cout << "oshibka" << endl;
	
	}
}
int main()
{
	int x;
	int y;
	char a;
	cin >> x;
	cin >> y;
	cin >> a;
	cout <<x<<  a<<y <<calculate(x, y, op) << endl;
	return 0;
}