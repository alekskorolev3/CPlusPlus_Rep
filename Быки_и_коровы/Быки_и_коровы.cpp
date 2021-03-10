#include <iostream>
using namespace std;
void digit(int i, int& a, int& b, int& c, int& d)
{
    d = i % 10; i /= 10;
    c = i % 10; i /= 10;
    b = i % 10; i /= 10;
    a = i % 10;
}
bool check(int i)
{
    int a, b, c, d;
    digit(i, a, b, c, d);
    if ((a >= 1) && (a <= 9) && (a != b) && (a != c) && (a != d) && (b != c) && (b != d) && (c != d))
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool match(int n1, int n2, int bulls, int cows)
{
    int a1, b1, c1, d1, a2, b2, c2, d2;
    digit(n1, a1, b1, c1, d1);
    digit(n2, a2, b2, c2, d2);
    if (bulls == ((a1 == a2) + (b1 == b2) + (c1 == c2) + (d1 == d2)) &&
        cows == ((a1 == b2) + (a1 == c2) + (a1 == d2) + (b1 == a2) + (b1 == c2) + (b1 == d2) +
            (c1 == a2) + (c1 == b2) + (c1 == d2) +
            (d1 == a2) + (d1 == b2) + (d1 == c2)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    const int Size = 9876;
    int count = 0;
    bool num[Size]{ false };
    for (int i = 0; i < Size; i++)
    {
        num[i] = check(i);
    }
    while (true)
    {
        int bulls, cows;
        int question = 0;
        while (question < Size && num[question] == true)
        {
            question++;
        }
        if (question >= Size)
        {
            cout << "Скорее всего, вы ошиблись в подсчете быков и коров. Попробуйте снова." << endl;
            return 0;
        }
        cout << question << endl;
        cout << "Введите кол-во быков и коров " << endl;
        cin >> bulls >> cows;
        count++;
        if (bulls == 4 && cows == 0)
        {
            cout << "Ваше число " << question << endl;
            cout << "Количество попыток " << count << endl;
            return 0;
        }
        for (int i = 0; i < Size; i++)
        {
            if (match(i, question, bulls, cows) == false)
            {
                num[i] = true;
            }
        }
    }
}