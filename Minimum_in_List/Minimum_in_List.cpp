#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int minimum(list<int>& list)
{
    return *min_element(list.begin(), list.end());
}
int init(char s[13], list<int>& lst)
{
    list <int> ::iterator itl;
    string s1;
    stringstream s2;
    int i = 0;
    for (i; i < 2; ++i)
    {
        s1.push_back(s[i]);
    }
    if (s1 == "-L")
    {
        int element = *lst.begin();
        lst.pop_front();
        if (lst.size() == 0)
        {
            return -1;
        }
        return minimum(lst);
    }
    if (s1 == "-R")
    {
        itl = lst.end();
        itl--;
        int element = *itl;

        lst.pop_back();
        if (lst.size() == 0)
        {
            return -1;
        }
        return minimum(lst);
    }
    while (s[i] != '\0')
    {
        s2 << s[i];
        ++i;
    }
    int value;
    s2 >> value;
    if (s1 == "+L")
    {
        lst.push_front(value);
        return minimum(lst);
    }
    if (s1 == "+R")
    {
        lst.push_back(value);
        return minimum(lst);
    }
}

int main()
{
    list <int> lst;
    int q;
    cin >> q;
    cin.ignore(32767, '\n');
    for (int i = 0; i < q; ++i)
    {
        char s[13];
        scanf("%[^\n]%*c", s);
        printf("%i\n", init(s, lst));
    }
}
